#include "drv_oled.h"
#include "../hal/hal_oled.h"
#include <stdio.h>

sonar_status_t drv_oled_init(void) {
    return hal_oled_init();
}

void drv_oled_show_distance(uint16_t dist_cm) {
    char line1[17] = "Target is";
    char line2[17];
    snprintf(line2, sizeof(line2), "%u cm away", dist_cm);
    hal_oled_clear();
    hal_oled_set_cursor(0, 1);
    hal_oled_print_str(line1);
    hal_oled_set_cursor(0, 2);
    hal_oled_print_str(line2);
}

void drv_oled_show_error(sonar_status_t err) {
    const char *line1 = "Error:";
    const char *line2;
    if      (err == SONAR_ERR_TIMEOUT)      { line1 = "No target"; line2 = "detected"; }
    else if (err == SONAR_ERR_OUT_OF_RANGE) { line1 = "Target";    line2 = "outside range"; }
    else                                    {                       line2 = "unknown error"; }
    hal_oled_clear();
    hal_oled_set_cursor(0, 1);
    hal_oled_print_str(line1);
    hal_oled_set_cursor(0, 2);
    hal_oled_print_str(line2);
}
