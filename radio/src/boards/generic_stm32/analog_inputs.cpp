/*
 * Copyright (C) EdgeTx
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

#include "analog_inputs.h"
#include "stm32_hal_adc.h"

#include "hal.h"

#if defined(ADC_SPI)
  #include "ads79xx.h"
#endif

// generated files
#include "stm32_adc_inputs.inc"
#include "hal_adc_inputs.inc"

#include "definitions.h"
#include <string.h>

constexpr uint8_t n_ADC = DIM(_ADC_adc);
constexpr uint8_t n_ADC_spi = DIM(_ADC_spi);
constexpr uint8_t n_GPIO = DIM(_ADC_GPIOs);
constexpr uint8_t n_inputs = DIM(_ADC_inputs);

static int8_t _vbat_input;
static int8_t _vrtc_input;

static int8_t _find_input_name(const char* name)
{
  for (uint8_t i = 0; i < n_inputs; i++) {
    if (!strcmp(_ADC_inputs[i].name, name)) return i;
  }

  return -1;
}

static bool adc_init()
{
  _vbat_input = _find_input_name("VBAT");
  _vrtc_input = _find_input_name("RTC_BAT");

  bool success = stm32_hal_adc_init(_ADC_adc, n_ADC, _ADC_inputs, _ADC_GPIOs, n_GPIO);
#if defined(ADC_SPI)
  if (n_ADC_spi > 0) ads79xx_init(&_ADC_spi[0]);
#endif
  return success;
}

static bool adc_start_read()
{
  bool success = stm32_hal_adc_start_read(_ADC_adc, n_ADC, _ADC_inputs, n_inputs);
#if defined(ADC_SPI)
  if (n_ADC_spi > 0) {
    success = success && ads79xx_adc_start_read(&_ADC_spi[0], _ADC_inputs);
  }
#endif
  return success;
}

static void adc_wait_completion()
{
#if defined(ADC_SPI)
  // ADS79xx does all the work in the completion function
  // so it's probably better to poll it first
  if (n_ADC_spi > 0) ads79xx_adc_wait_completion(&_ADC_spi[0], _ADC_inputs);
#endif
  stm32_hal_adc_wait_completion(_ADC_adc, n_ADC, _ADC_inputs, n_inputs);
}

const etx_hal_adc_driver_t _adc_driver = {
  _hal_inputs,
  adc_init,
  adc_start_read,
  adc_wait_completion
};

