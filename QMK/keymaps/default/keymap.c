/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 * Copyright 2020 MK
 * Copyright 2023 Coaleyed
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "config.h"  // Include your configuration file
#include "quantum.h"

// Suspend Settings
bool suspended = false; // Keep track of the system's suspend state

     // Pinout Map - Teensy 2.0++
     // ,------------------------------------------------------------------------------------.
     // |       |     | C0/13 |Index|  D3/6  |Middle| F5/38 |Ring| E6/30 |Pinky|             |       Profile    LED
     // |------------------ -----------------------------------------------------------------|     ,-------------------.
     // |       |     | E1/12 |Index|  D2/5  |Middle| F4/37 |Ring| E7/29 |Pinky|             |     |  F6/39  | C5/C18  |  
     // |------------------------------------------------------------------------------------|     |-------------------|
     // |       |     | E0/11 |Index|  D1/4  |Middle| F3/36 |Ring| B4/24 |Pinky|             |     |  F7/40  | C6/C19  |
     // |------------------------------------------------------------------------------------|     `-------------------'
     // | C1/14 |Index| D5/8  |Index|  D0/3  |Middle| F2/35 |Ring| B5/23 |Pinky| F0/33 |Pinky|  
     // |------------------------------------------------------------------------------------|
     // | C2/15 |Thumb| D4/7  |Index|  B7/2  |Middle| F1/34 |Ring| B6/22 |Pinky|             |
     // `------------------------------------------------------------------------------------'

// Layer names
#define PROFILE_1             0
#define SECOND_LAYER_PROFILE_1 1
#define PROFILE_2             2
#define SECOND_LAYER_PROFILE_2 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {         
    [PROFILE_1] = {
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, MO(SECOND_LAYER_PROFILE_1)}
    },

    [SECOND_LAYER_PROFILE_1] = {
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______},
        {_______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______}
    },

    [PROFILE_2] = {
        {_______, KC_HOME, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_END , KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_6, KC_KP_5, KC_KP_4, KC_KP_3, KC_KP_2, KC_KP_1, _______},
        {KC_TAB,  KC_KP_0, KC_KP_9, KC_KP_8, KC_KP_7, _______, MO(SECOND_LAYER_PROFILE_2)}
    },

    [SECOND_LAYER_PROFILE_2] = {
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______},
        {_______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______}
    },
};

bool dip_switch_map[1] = {false}; // Initialize the single switch to OFF

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        // Dip switch 1 actions
        if (active) {
            // Dip switch 1 is ON (Layer 3)
            layer_on(PROFILE_2);
            // Turn off LED2 (C5) when dip switch is pressed
            writePinLow(C5);
            dip_switch_map[0] = true; // Update dip switch state
        } else {
            // Dip switch 1 is OFF (Layer 1), activate PROFILE_1
            layer_off(PROFILE_2);
            layer_on(PROFILE_1);
            // Turn on both LEDs
            writePinHigh(C5);
            dip_switch_map[0] = false; // Update dip switch state
        }
    }
    // Add more cases for other dip switches if needed

    // Default case (no need to handle for a single switch)
    return true;
}
