#pragma once

#include "quantum.h"

// Profile definitions
#define PROFILE_1 0
#define PROFILE_2 1

// LED pin assignment
#define LED_1 C5

// EEPROM address for storing active profile
#define PROFILE_EEPROM_ADDR 0

// Externally accessible profile state
extern uint8_t active_profile;

// Function prototypes
void update_leds_from_profile(void);
