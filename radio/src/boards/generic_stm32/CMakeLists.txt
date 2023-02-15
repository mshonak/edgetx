
# generate hardware struct defs
AddHWGenTarget(${HW_DESC_JSON} stm32_switches stm32_switches.inc)
AddHWGenTarget(${HW_DESC_JSON} stm32_adc_inputs stm32_adc_inputs.inc)
AddHWGenTarget(${HW_DESC_JSON} hal_adc_inputs hal_adc_inputs.inc)

set(FIRMWARE_SRC ${FIRMWARE_SRC}
  ${CMAKE_CURRENT_BINARY_DIR}/stm32_switches.inc
  ${CMAKE_CURRENT_BINARY_DIR}/stm32_adc_inputs.inc
  ${CMAKE_CURRENT_BINARY_DIR}/hal_adc_inputs.inc
  ${CMAKE_CURRENT_BINARY_DIR}/${HW_DESC_JSON}
  )

set(FIRMWARE_SRC
  ${FIRMWARE_SRC}
  boards/generic_stm32/module_ports.cpp
  boards/generic_stm32/aux_ports.cpp
  boards/generic_stm32/sport_update.cpp
  boards/generic_stm32/intmodule_heartbeat.cpp
  boards/generic_stm32/analog_inputs.cpp
  boards/generic_stm32/switches.cpp
)
