/* Copyright 2023 Coaleyed */

#pragma once

#include "quantum.h"
#include "analog.h"

// Layer definitions
#define PROFILE_1               0
#define SECOND_LAYER_PROFILE_1  1
#define PROFILE_2               2
#define SECOND_LAYER_PROFILE_2  3

// Pin mappings
#define DIP_SWITCH_LED_PIN F6  // LED 1
#define PROFILE_LED_PIN C5     // LED 2
#define DIP_SWITCH_1_PIN F7
#define DIP_SWITCH_COUNT 1

// Function prototypes
void update_leds_based_on_layer(void);
void print_sensor_status(void);
void toggle_gesture_support(void);
void keyboard_pre_init_user(void);

// Global flags
extern bool gesture_enabled;
