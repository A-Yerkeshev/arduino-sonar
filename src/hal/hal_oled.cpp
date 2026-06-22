#include "hal_oled.h"
#include <Arduino.h>
#include <U8x8lib.h>

static U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

sonar_status_t hal_oled_init(void) {
    sonar_status_t status = SONAR_ERR_GENERIC;
    u8x8.setBusClock(100000);
    if (u8x8.begin()) {
        u8x8.setFlipMode(1);
        u8x8.setFont(u8x8_font_chroma48medium8_r);
        status = SONAR_OK;
    } else {
        status = SONAR_ERR_HAL;
    }
    return status;
}

void hal_oled_clear(void) {
    u8x8.clearDisplay();
}

void hal_oled_set_cursor(uint8_t col, uint8_t row) {
    u8x8.setCursor(col, row);
}

void hal_oled_print_str(const char *str) {
    u8x8.print(str);
}
