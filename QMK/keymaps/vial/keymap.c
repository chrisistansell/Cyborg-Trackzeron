// Copyright 2023 Coaleyed

#include QMK_KEYBOARD_H
#include "config.h"
#include "trackzeron.h"

// ─────────────────────────────────────────────────────────────
// Keymaps
// ─────────────────────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {         
    [PROFILE_1] = {
        //          index    middle    ring       pinky         
        {_______, MS_WHLU, KC_PGUP, KC_EQL,  KC_LEFT_GUI, _______, _______},
        {_______, MS_WHLD, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },

    [PROFILE_2] = {
        //          index    middle    ring       pinky         
        {_______, MS_WHLU, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, MS_WHLD, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______}
        //^ Pinky, Index, Thumb
    },
};

// ─────────────────────────────────────────────────────────────
// Key event handler
// ─────────────────────────────────────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MS_BTN1:
            if (record->event.pressed) {
                // Optional: harmless HID event to ensure wake
                tap_code16(KC_NO);
            }
            break;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
// Wake from suspend: clear stuck key state
// ─────────────────────────────────────────────────────────────
void suspend_wakeup_init_user(void) {
    clear_keyboard();           // Flush any held keys
    send_keyboard_report();     // Send clean report to host
    wait_ms(100);               // Optional: give host time to sync
}
