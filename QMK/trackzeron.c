#include "trackzeron.h"
#include <avr/eeprom.h>
#include "host.h"
#include "pointing_device.h"
#include "timer.h"

uint8_t active_profile = PROFILE_1;

bool host_ready = false;
bool flushed_hid = false;
uint32_t host_ready_time = 0;

void keyboard_pre_init_user(void) {
    setPinInputHigh(F6);
    setPinInputHigh(F7);
    setPinOutput(LED_1);
    setPinOutput(LED_2);
    writePinHigh(LED_1);  // LED_1 ON (active-high)
    writePinHigh(LED_2);  // LED_2 OFF (active-low)
}

void keyboard_post_init_user(void) {
    eeprom_read_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
    default_layer_set(1UL << active_profile);
    update_leds_from_profile();
    pointing_device_set_cpi(900);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!host_ready && (mouse_report.x || mouse_report.y || mouse_report.v || mouse_report.h)) {
        host_ready = true;
        host_ready_time = timer_read32();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (!host_ready && is_keyboard_master()) {
        host_ready = true;
        host_ready_time = timer_read32();
    }

    if (host_ready && !flushed_hid) {
        flushed_hid = true;
        clear_keyboard();
        send_keyboard_report();
        host_ready_time = timer_read32();
    }

    if (!host_ready || timer_elapsed32(host_ready_time) < 200) return;

    bool f6_pressed = readPin(F6);
    bool f7_pressed = readPin(F7);

    uint8_t new_profile = active_profile;
    if (f7_pressed) {
        new_profile = PROFILE_1;
    } else if (f6_pressed) {
        new_profile = PROFILE_3;
    }

    if (new_profile != active_profile) {
        active_profile = new_profile;
        default_layer_set(1UL << active_profile);
        eeprom_update_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
        update_leds_from_profile();
    }
}

void update_leds_from_profile(void) {
    if (get_highest_layer(default_layer_state) == PROFILE_1) {
        writePinLow(LED_2);  // LED_2 ON (active-low)
    } else {
        writePinHigh(LED_2); // LED_2 OFF
    }
}

bool pmw33xx_check_signature(uint8_t sensor) {
    return true;
}
