#include "drv_oled.h"
#include "../hal/hal_oled.h"
#include <stdio.h>

sonar_status_t drv_oled_init(void) {
    return hal_oled_init();
}

void drv_oled_show_distance(uint16_t dist_cm) {
    char line1[17];
    char line2[17];
    char tmp[17];
    snprintf(line1, sizeof(line1), "%-16s", "Target is");
    snprintf(tmp,   sizeof(tmp),   "%u cm away", dist_cm);
    snprintf(line2, sizeof(line2), "%-16s", tmp);
    hal_oled_set_cursor(0, 1);
    hal_oled_print_str(line1);
    hal_oled_set_cursor(0, 2);
    hal_oled_print_str(line2);
}

void drv_oled_show_error(sonar_status_t err) {
    char line1[17];
    char line2[17];
    if (err == SONAR_ERR_TIMEOUT) {
        snprintf(line1, sizeof(line1), "%-16s", "No target");
        snprintf(line2, sizeof(line2), "%-16s", "detected");
    } else if (err == SONAR_ERR_OUT_OF_RANGE) {
        snprintf(line1, sizeof(line1), "%-16s", "Target");
        snprintf(line2, sizeof(line2), "%-16s", "outside range");
    } else {
        snprintf(line1, sizeof(line1), "%-16s", "Error:");
        snprintf(line2, sizeof(line2), "%-16s", "Error");
    }
    hal_oled_set_cursor(0, 1);
    hal_oled_print_str(line1);
    hal_oled_set_cursor(0, 2);
    hal_oled_print_str(line2);
}
