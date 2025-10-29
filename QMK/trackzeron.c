#include "trackzeron.h"
#include <avr/eeprom.h>

uint8_t active_profile = PROFILE_1;

void keyboard_pre_init_user(void) {
    setPinInputHigh(F6);      // HIGH = pressed
    setPinInputHigh(F7);      // HIGH = pressed
    setPinOutput(LED_1);      // C5
    writePinHigh(LED_1);      // Default OFF
}

void keyboard_post_init_user(void) {
    // Restore saved profile from EEPROM
    eeprom_read_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
    default_layer_set(1UL << active_profile);
    update_leds_from_profile();

    // Ensure pointing device and HID are ready
    pointing_device_init();
    pointing_device_task();
    send_keyboard_report();
}

void matrix_scan_user(void) {
    bool f6_pressed = readPin(F6);
    bool f7_pressed = readPin(F7);

    uint8_t new_profile = active_profile;

    if (f7_pressed) {
        new_profile = PROFILE_1;
    } else if (f6_pressed) {
        new_profile = PROFILE_2;
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
        writePinLow(LED_1);  // LED ON
    } else {
        writePinHigh(LED_1); // LED OFF
    }
}
