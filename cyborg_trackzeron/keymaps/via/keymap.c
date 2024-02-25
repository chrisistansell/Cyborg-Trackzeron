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
// Layer names
#include QMK_KEYBOARD_H

// Layer names
#define BASE_LAYER   0
#define SECOND_LAYER 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {         
    [0] = {
      //         index    middle    ring       pinky         
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {KC_KP_6, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, _______, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },

    [1] = {
        //         index    middle    ring       pinky         
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {KC_KP_6, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, _______, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },
};