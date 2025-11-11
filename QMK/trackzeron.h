#pragma once

#include "quantum.h"

#define PROFILE_1 0
#define PROFILE_2 1

#define LED_1 C6  // Always ON (active-high)
#define LED_2 C5  // Profile indicator (active-low)

#define PROFILE_EEPROM_ADDR 0

extern uint8_t active_profile;

void update_leds_from_profile(void);
