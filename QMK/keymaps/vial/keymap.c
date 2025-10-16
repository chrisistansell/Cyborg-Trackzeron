#include QMK_KEYBOARD_H
#include "config.h"
#include "trackzeron.h"

// Suspend state
bool suspended = false;

// DIP switch state
bool dip_switch_map[DIP_SWITCH_COUNT] = {false};

// Layer names
#define PROFILE_1               0
#define SECOND_LAYER_PROFILE_1  1
#define PROFILE_2               2
#define SECOND_LAYER_PROFILE_2  3

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
        {_______, KC_WH_U, KC_PGUP, KC_EQL,  KC_PAST, _______, _______},
        {_______, KC_WH_D, KC_PGDN, KC_MINS, KC_PSLS, _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, _______},
        {KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, MO(SECOND_LAYER_PROFILE_2)}       
    },

    [SECOND_LAYER_PROFILE_2] = {
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______},
        {_______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______},
        {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______}
    },
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        layer_clear();

        if (active) {
            layer_on(PROFILE_1);  // DIP ON → PROFILE_1
            dip_switch_map[0] = true;
        } else {
            layer_on(PROFILE_2);  // DIP OFF → PROFILE_2
            dip_switch_map[0] = false;
        }

        update_leds_based_on_layer();
    }
    return true;
}

void keyboard_post_init_user(void) {
    report_mouse_t mouse_report = pointing_device_get_report();
    mouse_report.x = 1;
    mouse_report.y = 0;
    pointing_device_set_report(mouse_report);
    pointing_device_send();
}
