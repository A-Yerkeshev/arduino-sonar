#include "hal_gpio.h"
#include <Arduino.h>

uint32_t hal_micros(void)          { return micros(); }
void     hal_delay_ms(uint32_t ms) { delay(ms); }
void     hal_delay_us(uint32_t us) { delayMicroseconds(us); }

static const char *s_last_error = "";

const char *hal_last_error(void) { return s_last_error; }

sonar_status_t hal_pin_mode(uint8_t pin, hal_pin_dir_t mode) {
    sonar_status_t status = SONAR_ERR_GENERIC;
    if      (mode == hal_pin_dir_t::DIR_OUTPUT) { pinMode(pin, OUTPUT); status = SONAR_OK; }
    else if (mode == hal_pin_dir_t::DIR_INPUT)  { pinMode(pin, INPUT);  status = SONAR_OK; }
    else { s_last_error = "hal_pin_mode: invalid direction"; status = SONAR_ERR_ARG; }
    return status;
}

sonar_status_t hal_pin_write(uint8_t pin, hal_pin_level_t value) {
    sonar_status_t status = SONAR_ERR_GENERIC;
    if      (value == hal_pin_level_t::LVL_HIGH) { digitalWrite(pin, HIGH); status = SONAR_OK; }
    else if (value == hal_pin_level_t::LVL_LOW)  { digitalWrite(pin, LOW);  status = SONAR_OK; }
    else { s_last_error = "hal_pin_write: invalid level"; status = SONAR_ERR_ARG; }
    return status;
}

hal_pin_level_t hal_pin_read(uint8_t pin) {
    return digitalRead(pin) == HIGH ? hal_pin_level_t::LVL_HIGH : hal_pin_level_t::LVL_LOW;
}

hal_pulse_result_t hal_pulse_in(uint8_t pin, hal_pin_level_t level, uint32_t timeout_us) {
    hal_pulse_result_t result = { SONAR_ERR_GENERIC, 0 };
    if (level == hal_pin_level_t::LVL_HIGH || level == hal_pin_level_t::LVL_LOW) {
        uint8_t arduino_level = (level == hal_pin_level_t::LVL_HIGH) ? HIGH : LOW;
        uint32_t duration = pulseIn(pin, arduino_level, timeout_us);
        if (duration > 0) {
            result.status      = SONAR_OK;
            result.duration_us = duration;
        } else {
            result.status = SONAR_ERR_TIMEOUT;
        }
    } else {
        s_last_error = "hal_pulse_in: invalid level";
        result.status = SONAR_ERR_ARG;
    }
    return result;
}
