/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "adc_driver.h"
#include "x12s_adc_driver.h"
#include "delays_driver.h"

#include "stm32_hal_ll.h"
#include "hal.h"


#define ADC_CS_HIGH()                  LL_GPIO_SetOutputPin(ADC_SPI_GPIO, ADC_SPI_PIN_CS)
#define ADC_CS_LOW()                   LL_GPIO_ResetOutputPin(ADC_SPI_GPIO, ADC_SPI_PIN_CS)

#define RESETCMD                       0x4000
#define MANUAL_MODE                    0x1000 // manual mode channel 0
#define MANUAL_MODE_CHANNEL(x)         (MANUAL_MODE | ((x) << 7))

uint16_t SPIx_ReadWriteByte(uint16_t value)
{
  while (!LL_SPI_IsActiveFlag_TXE(ADC_SPI));
  LL_SPI_TransmitData16(ADC_SPI, value);

  while (!LL_SPI_IsActiveFlag_RXNE(ADC_SPI));
  return LL_SPI_ReceiveData16(ADC_SPI);
}

static void ADS7952_Init()
{
  LL_GPIO_InitTypeDef pinInit;
  LL_GPIO_StructInit(&pinInit);

  pinInit.Pin = ADC_SPI_PIN_MISO | ADC_SPI_PIN_SCK | ADC_SPI_PIN_MOSI;
  pinInit.Mode = LL_GPIO_MODE_ALTERNATE;
  pinInit.Alternate = ADC_GPIO_AF;
  LL_GPIO_Init(ADC_SPI_GPIO, &pinInit);

  pinInit.Pin = ADC_SPI_PIN_CS;
  pinInit.Mode = LL_GPIO_MODE_OUTPUT;
  pinInit.Alternate = LL_GPIO_AF_0;
  LL_GPIO_Init(ADC_SPI_GPIO, &pinInit);

  LL_SPI_DeInit(ADC_SPI);

  LL_SPI_InitTypeDef spiInit;
  LL_SPI_StructInit(&spiInit);

  spiInit.TransferDirection = LL_SPI_FULL_DUPLEX;
  spiInit.Mode = LL_SPI_MODE_MASTER;
  spiInit.DataWidth = LL_SPI_DATAWIDTH_16BIT;
  spiInit.NSS = LL_SPI_NSS_SOFT;
  spiInit.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8;
  LL_SPI_Init(ADC_SPI, &spiInit);

  LL_SPI_Enable(ADC_SPI);

  LL_SPI_DisableIT_TXE(ADC_SPI);
  LL_SPI_DisableIT_RXNE(ADC_SPI);

  ADC_CS_HIGH();
  delay_01us(1);
  ADC_CS_LOW();
  SPIx_ReadWriteByte(RESETCMD);
  ADC_CS_HIGH();
  delay_01us(1);
  ADC_CS_LOW();
  SPIx_ReadWriteByte(MANUAL_MODE);
  ADC_CS_HIGH();
}

extern const etx_hal_adc_driver_t _adc_driver;

static bool x12s_adc_init()
{
  // init SPI ADC
  ADS7952_Init();

  // init onboard ADC
  return _adc_driver.init();
}

static void adcReadSPIDummy()
{
  // A dummy command to get things started
  // (because the sampled data is lagging behind for two command cycles)
  ADC_CS_LOW();
  delay_01us(1);
  SPIx_ReadWriteByte(MANUAL_MODE_CHANNEL(0));
  ADC_CS_HIGH();
  delay_01us(1);
}

static uint32_t adcReadNextSPIChannel(uint8_t index, const stm32_adc_input_t* inputs,
                                      const uint8_t* chan, uint8_t nconv)
{
  uint32_t result = 0;

  // This delay is to allow charging of ADC input capacitor
  // after the MUX changes from one channel to the other.
  // It was determined experimentally. Biggest problem seems to be
  // the cross-talk between A4:S1 and A5:MULTIPOS. Changing S1 for one extreme
  // to the other resulted in A5 change of:
  //
  //        delay value       A5 change     Time needed for adcRead()
  //          1               16            0.154ms - 0.156ms
  //         38               5             0.197ms - 0.199ms
  //         62               0             0.225ms - 0.243ms
  delay_01us(40);

  for (uint8_t i = 0; i < 4; i++) {
    ADC_CS_LOW();
    delay_01us(1);

    // command is changed to the next index for the last two readings
    // (because the sampled data is lagging behind for two command cycles)
    uint8_t chan_idx = (i > 1 ? index + 1 : index) % nconv;

    auto input_idx = chan[chan_idx];
    auto spi_chan = inputs[input_idx].ADC_Channel;
    
    uint16_t val = (0x0fff & SPIx_ReadWriteByte(MANUAL_MODE_CHANNEL(spi_chan)));

#if defined(JITTER_MEASURE)
    if (JITTER_MEASURE_ACTIVE()) {
      rawJitter[index].measure(val);
    }
#endif

    ADC_CS_HIGH();
    delay_01us(1);
    result += val;
  }

  return result >> 2;
}

bool x12s_adc_start_read()
{
  // start onboard ADC
  _adc_driver.start_conversion();

  adcReadSPIDummy();
  adcReadSPIDummy();

  return true;
}

void x12s_adc_wait_completion()
{
  auto spi_adc = adc_spi_get();
  auto spi_channels = spi_adc->n_channels;
  auto chans = spi_adc->channels;
  auto inputs = adc_get_inputs();
  
  // Fetch buffer from generic ADC driver
  auto adcValues = getAnalogValues();
  
  // At this point, the first conversion has been started
  // in x12s_adc_start_read()

  // for each SPI channel
  for (uint32_t i = 0; i < spi_channels; i++) {
    
    // read SPI channel
    auto input_channel = chans[i];
    auto adc_value = adcReadNextSPIChannel(i, inputs, chans, spi_channels);

    if (inputs[input_channel].inverted)
      adcValues[input_channel] = ADC_INVERT_VALUE(adc_value);
    else
      adcValues[input_channel] = adc_value;
  }

  // onboard ADC
  _adc_driver.wait_completion();
}

const etx_hal_adc_driver_t x12s_adc_driver = {
  _adc_driver.inputs,
  x12s_adc_init,
  x12s_adc_start_read,
  x12s_adc_wait_completion
};
