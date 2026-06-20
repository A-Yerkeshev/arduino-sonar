/**
 * app_display.h — Display application logic interface.
 *
 * Owns screen update policy. Depends on drv_oled.
 */

#ifndef APP_DISPLAY_H
#define APP_DISPLAY_H

#include "../globals.h"
#include "../drv/drv_ultrasonic.h"

/**
 * Initialize the display subsystem.
 *
 * @return SONAR_OK on success, SONAR_ERR_HAL if the display does not respond.
 */
sonar_status_t app_display_init(void);

/**
 * Update the display based on the latest measurement result.
 *   SONAR_OK               → distance reading
 *   SONAR_ERR_TIMEOUT      → "No target detected"
 *   SONAR_ERR_OUT_OF_RANGE → "Target outside range"
 *   other                  → "Error"
 */
void app_display_update(drv_ultrasonic_result_t result);

#endif /* APP_DISPLAY_H */
