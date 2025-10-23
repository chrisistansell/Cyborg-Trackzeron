// Copyright 2023 Coaleyed

#include QMK_KEYBOARD_H
#include "config.h"
#include "trackzeron.h"

// ─────────────────────────────────────────────────────────────
// Suspend tracking
// ─────────────────────────────────────────────────────────────
bool suspended = false;

// ─────────────────────────────────────────────────────────────
// Keymaps
// ─────────────────────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {         
    [PROFILE_1] = {
        //          index    middle    ring       pinky         
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_LEFT_GUI, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },

    [PROFILE_2] = {
        //          index    middle    ring       pinky         
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },
};

// ─────────────────────────────────────────────────────────────
// Wake from suspend
// ─────────────────────────────────────────────────────────────
void suspend_wakeup_task(void) {
    if (suspended) {
        register_code(KC_SYSTEM_WAKE);
        unregister_code(KC_SYSTEM_WAKE);
        suspended = false;
    }
}

// ─────────────────────────────────────────────────────────────
// Key event handler
// ─────────────────────────────────────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN1:
            if (record->event.pressed) {
                suspend_wakeup_task();
            }
            break;
    }
    return true;
}
