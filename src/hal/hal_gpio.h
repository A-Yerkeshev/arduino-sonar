/**
 * hal_gpio.h — GPIO and timing HAL interface.
 *
 * Wraps Arduino digital I/O and timing primitives.
 */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "../globals.h"

#define HAL_PIN_ULTRASONIC   7u

enum class hal_pin_level_t : uint8_t { LVL_LOW = 0, LVL_HIGH = 1 };
enum class hal_pin_dir_t   : uint8_t { DIR_INPUT = 0, DIR_OUTPUT = 1 };

uint32_t hal_micros(void);

/**
 * Timer-based; suitable for delays >= 1 ms (e.g. sample interval).
 * Cannot fail: pure timer wait with no hardware interaction that can error.
 */
void hal_delay_ms(uint32_t ms);

/**
 * Busy-wait; for short precision delays only (e.g. ultrasonic trigger, 2–5 µs).
 * Do not use for delays > ~16 ms.
 * Cannot fail: pure busy-wait loop with no hardware interaction that can error.
 */
void hal_delay_us(uint32_t us);

sonar_status_t  hal_pin_mode(uint8_t pin, hal_pin_dir_t mode);
sonar_status_t  hal_pin_write(uint8_t pin, hal_pin_level_t value);
hal_pin_level_t hal_pin_read(uint8_t pin);

/**
 * Return a string describing the last argument error, or "" if none.
 * Valid until the next hal_* call that sets an error.
 */
const char *hal_last_error(void);

typedef struct {
    sonar_status_t status;
    uint32_t       duration_us;
} hal_pulse_result_t;

/**
 * Measure the duration of a pulse on `pin`.
 *
 * @pre  pin must be configured as hal_pin_dir_t::DIR_INPUT.
 * @param level       hal_pin_level_t::LVL_HIGH or LVL_LOW — the pulse polarity to measure.
 * @param timeout_us  Maximum time to wait in microseconds.
 * @return result.status:      SONAR_OK or SONAR_ERR_TIMEOUT.
 * @return result.duration_us: pulse width in microseconds on SONAR_OK; 0 on timeout.
 */
hal_pulse_result_t hal_pulse_in(uint8_t pin, hal_pin_level_t level, uint32_t timeout_us);

#endif /* HAL_GPIO_H */
