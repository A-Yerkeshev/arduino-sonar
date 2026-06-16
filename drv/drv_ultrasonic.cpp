#include "drv_ultrasonic.h"

sonar_status_t drv_ultrasonic_init(void) {
    return SONAR_OK;
}

drv_ultrasonic_result_t drv_ultrasonic_measure(void) {
    drv_ultrasonic_result_t result = { SONAR_ERR_GENERIC, 0 };
    return result;
}
