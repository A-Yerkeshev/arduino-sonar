/**
 * drv_ultrasonic.h — Ultrasonic ranger driver interface.
 *
 * Handles trigger/echo timing and converts pulse width to distance in cm.
 * Depends on hal_gpio.
 */

#ifndef DRV_ULTRASONIC_H
#define DRV_ULTRASONIC_H

#include "../hal/hal_gpio.h"

/**
 * Initialize the ultrasonic ranger (configure SIG pin direction).
 *
 * @return SONAR_OK always — pin configuration on ATmega328P cannot fail.
 */
sonar_status_t drv_ultrasonic_init(void);

typedef struct {
    sonar_status_t status;
    uint16_t       dist_cm;
} drv_ultrasonic_result_t;

/**
 * Measure distance to target.
 *
 * @pre  drv_ultrasonic_init() called.
 * @return result.status:  SONAR_OK, SONAR_ERR_TIMEOUT, or SONAR_ERR_OUT_OF_RANGE.
 * @return result.dist_cm: distance in [SONAR_MIN_RANGE_CM, SONAR_MAX_RANGE_CM]
 *                         on SONAR_OK; 0 on error.
 */
drv_ultrasonic_result_t drv_ultrasonic_measure(void);

#endif /* DRV_ULTRASONIC_H */
