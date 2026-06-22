/**
 * globals.h — Project-wide types and constants shared across all layers.
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>

typedef enum {
    SONAR_ERR_GENERIC      = 0,
    SONAR_OK               = 1,
    SONAR_ERR_TIMEOUT      = 2,
    SONAR_ERR_OUT_OF_RANGE = 3,
    SONAR_ERR_HAL          = 4,
    SONAR_ERR_ARG          = 5,
} sonar_status_t;

#define SONAR_MIN_RANGE_CM         2u
#define SONAR_MAX_RANGE_CM       400u
#define SONAR_TRIGGER_US           5u
#define SONAR_ECHO_TIMEOUT_US  30000u
#define SONAR_SAMPLE_INTERVAL_MS 250u

#endif /* GLOBALS_H */
