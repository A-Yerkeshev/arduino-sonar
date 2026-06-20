#include "app_display.h"
#include "../drv/drv_oled.h"

sonar_status_t app_display_init(void) {
    return drv_oled_init();
}

void app_display_update(drv_ultrasonic_result_t result) {
    if (result.status == SONAR_OK) {
        drv_oled_show_distance(result.dist_cm);
    } else {
        drv_oled_show_error(result.status);
    }
}
