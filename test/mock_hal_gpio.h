/**
 * mock_hal_gpio.h — Test double for hal_gpio, for host-side unit tests.
 *
 * Provides the same interface as hal_gpio.h. Callers inject synthetic
 * pulse results via mock_set_pulse_result().
 */

#ifndef MOCK_HAL_GPIO_H
#define MOCK_HAL_GPIO_H

#include "../src/hal/hal_gpio.h"

void mock_hal_pulse_in(uint32_t duration_us);

#endif /* MOCK_HAL_GPIO_H */
