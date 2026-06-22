/**
 * app_sonar.h — Sonar application logic interface.
 *
 * Orchestrates the measurement cycle. Depends on drv_ultrasonic.
 */

#ifndef APP_SONAR_H
#define APP_SONAR_H

#include "../globals.h"
#include "../drv/drv_ultrasonic.h"

/**
 * Perform one measurement cycle.
 *
 * @return result.status:  SONAR_OK, SONAR_ERR_TIMEOUT, or SONAR_ERR_OUT_OF_RANGE.
 * @return result.dist_cm: distance in [SONAR_MIN_RANGE_CM, SONAR_MAX_RANGE_CM]
 *                         on SONAR_OK; 0 on error.
 */
drv_ultrasonic_result_t app_sonar_tick(void);

#endif /* APP_SONAR_H */
