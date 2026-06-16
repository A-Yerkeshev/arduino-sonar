/**
 * hal_oled.h — OLED display HAL interface.
 *
 * Wraps U8x8lib for the SSD1306 128×64 display over hardware I2C.
 */

#ifndef HAL_OLED_H
#define HAL_OLED_H

#include "../globals.h"

/**
 * Initialize the SSD1306 OLED over hardware I2C.
 *
 * @pre  hal_init() called.
 * @return SONAR_OK on success, SONAR_ERR_HAL if the display does not respond.
 */
sonar_status_t hal_oled_init(void);

/**
 * Clear all pixels on the display.
 * Failure is not detectable: U8x8lib does not surface I2C write errors.
 */
void hal_oled_clear(void);

/**
 * Move the text cursor to character-grid position (col, row).
 * Cannot fail: sets internal U8x8lib state only, no I2C involved.
 */
void hal_oled_set_cursor(uint8_t col, uint8_t row);

/**
 * Print a null-terminated string at the current cursor position.
 * Failure is not detectable: U8x8lib does not surface I2C write errors.
 */
void hal_oled_print_str(const char *str);

#endif /* HAL_OLED_H */
