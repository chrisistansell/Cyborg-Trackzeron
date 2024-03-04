/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 * Copyright 2020 MK
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

// Dip Switch Mapping
#define DIP_SWITCH_LAYER_MAP_SIZE 2

// Layer names
#define PROFILE_1             0
#define SECOND_LAYER_PROFILE_1 1
#define PROFILE_2             2
#define SECOND_LAYER_PROFILE_2 3

const uint8_t dip_switch_layer_map[DIP_SWITCH_LAYER_MAP_SIZE] = {
    [0] = PROFILE_1, // Layer 1
    [1] = PROFILE_2  // Layer 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {         
    [PROFILE_1] = {
        //          index    middle    ring       pinky         
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, MO(SECOND_LAYER_PROFILE_1)}
        //^ Pinky, Index, Thumb
    },

    [SECOND_LAYER_PROFILE_1] = {
        // Define the keymap for the second layer of profile 1 here
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______},
        {_______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______}
        //^ Pinky, Index, Thumb
    },

    [PROFILE_2] = {
        //          index    middle    ring       pinky         
        {_______, KC_HOME, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_END , KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_6, KC_KP_5, KC_KP_4, KC_KP_3, KC_KP_2, KC_KP_1, _______},
        {KC_TAB,  KC_KP_0, KC_KP_9, KC_KP_8, KC_KP_7, _______, MO(SECOND_LAYER_PROFILE_2)}
        //^ Pinky, Index, Thumb
    },

    [SECOND_LAYER_PROFILE_2] = {
        // Define the keymap for the second layer of profile 2 here
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______},
        {_______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______}
        //^ You can customize this keymap for the second layer of profile 2
    },
};

void suspend_wakeup_task(void) {
    if (suspended) {
        // Code to wake up from suspend
        // This can include sending a specific keypress or using a wake-up API
        // For example, you might send a key press like this:
        register_code(KC_SYSTEM_WAKE); // Replace KC_SYSTEM_WAKE with the appropriate keycode for waking up the system
        unregister_code(KC_SYSTEM_WAKE);

        suspended = false; // Update the state
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN1: // Example: Left mouse button
            if (record->event.pressed) {
                suspend_wakeup_task();
            }
            break;
        // Add cases for other keys or mouse buttons if needed
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index < DIP_SWITCH_LAYER_MAP_SIZE) {
        // Get the corresponding layer from the map
        uint8_t target_layer = dip_switch_layer_map[index];

        if (active) {
            // Dip switch is ON, activate the target layer
            layer_on(target_layer);
            // Turn off LED2 (C5) when dip switch is pressed
            writePinLow(C5);
        } else {
            // Dip switch is OFF, deactivate the target layer
            layer_off(target_layer);
            // Turn on both LEDs
            writePinHigh(C5);
        }
        return true; // Return a value here
    }
    // Handle the case where index is out of bounds
    return false; // Return a value here
}