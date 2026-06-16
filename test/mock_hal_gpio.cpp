#include "mock_hal_gpio.h"

static uint32_t s_pulse_duration = 0;

void mock_hal_pulse_in(uint32_t duration_us) { s_pulse_duration = duration_us; }

uint32_t        hal_micros(void)                               { return 0; }
void            hal_delay_ms(uint32_t)                         {}
void            hal_delay_us(uint32_t)                         {}
sonar_status_t  hal_pin_mode(uint8_t, hal_pin_dir_t)           { return SONAR_OK; }
sonar_status_t  hal_pin_write(uint8_t, hal_pin_level_t)        { return SONAR_OK; }
hal_pin_level_t hal_pin_read(uint8_t)                          { return hal_pin_level_t::LVL_LOW; }
const char     *hal_last_error(void)                           { return ""; }

hal_pulse_result_t hal_pulse_in(uint8_t, hal_pin_level_t, uint32_t) {
    hal_pulse_result_t result = { SONAR_ERR_GENERIC, 0 };
    if (s_pulse_duration > 0) {
        result.status      = SONAR_OK;
        result.duration_us = s_pulse_duration;
    } else {
        result.status = SONAR_ERR_TIMEOUT;
    }
    return result;
}
