/* Copyright 2023 Coaleyed.*/
#pragma once

// #define ROTATIONAL_TRANSFORM_ANGLE 0
#define POINTING_DEVICE_INVERT_Y

/* PMW3360 Settings */
#define POINTING_DEVICE_CS_PIN B0

/* Set Mouse DPI Speed */
#define DPI 1200

#define USB_MAX_POWER_CONSUMPTION 100

/* Set Liftoff Distance 0x02 2mm Default */
#define PMW33XX_LIFTOFF_DISTANCE 0x02

// DIP switch configuration
#define DIP_SWITCH_MATRIX_GRID { {1,6} } 
#define DIP_SWITCH_COUNT 1
#define DIP_SWITCH_1 F7

#define SUSPEND_POWER_DOWN
