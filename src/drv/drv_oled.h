/**
 * drv_oled.h — OLED display driver interface.
 *
 * Owns screen layout and text rendering. Depends on hal_oled.
 */

#ifndef DRV_OLED_H
#define DRV_OLED_H

#include "../globals.h"

sonar_status_t drv_oled_init(void);

/**
 * Render distance on the display: "Target is X cm away".
 *
 * @pre  drv_oled_init() called successfully.
 */
void drv_oled_show_distance(uint16_t dist_cm);

/**
 * Render an error message on the display.
 *   SONAR_ERR_TIMEOUT      → "No target detected"
 *   SONAR_ERR_OUT_OF_RANGE → "Target outside range"
 *   other                  → "Error: <description>"
 *
 * @pre  drv_oled_init() called successfully.
 */
void drv_oled_show_error(sonar_status_t err);

#endif /* DRV_OLED_H */
