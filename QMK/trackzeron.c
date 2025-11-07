#include "trackzeron.h"
#include <avr/eeprom.h>
#include "host.h"              // For is_keyboard_master()
#include "pointing_device.h"   // For mouse movement tracking

// ─────────────────────────────────────────────────────────────
// Persistent profile state and host readiness flag
// ─────────────────────────────────────────────────────────────
uint8_t active_profile = PROFILE_1;  // Current active layer profile
bool host_ready = false;            // Tracks whether USB host is ready to receive input

// ─────────────────────────────────────────────────────────────
// Hardware pin setup before USB starts
// ─────────────────────────────────────────────────────────────
void keyboard_pre_init_user(void) {
    setPinInputHigh(F6);      // Button input: HIGH = pressed
    setPinInputHigh(F7);      // Button input: HIGH = pressed
    setPinOutput(LED_1);      // LED output pin
    writePinHigh(LED_1);      // Default LED state = OFF
}

// ─────────────────────────────────────────────────────────────
// Restore profile and configure mouse after USB starts
// ─────────────────────────────────────────────────────────────
void keyboard_post_init_user(void) {
    // Load saved profile from EEPROM
    eeprom_read_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
    default_layer_set(1UL << active_profile);  // Activate saved layer
    update_leds_from_profile();                // Update LED to match profile

    // Set PMW3360 sensor DPI
    pointing_device_set_cpi(900);
}

// ─────────────────────────────────────────────────────────────
// Mouse movement triggers host readiness if not already set
// ─────────────────────────────────────────────────────────────
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!host_ready && (mouse_report.x || mouse_report.y || mouse_report.v || mouse_report.h)) {
        host_ready = true;
        clear_keyboard();        // Flush any stuck keys
        send_keyboard_report();  // Send neutral HID report
    }
    return mouse_report;
}

// ─────────────────────────────────────────────────────────────
// Main scan loop: handles profile switching via buttons
// ─────────────────────────────────────────────────────────────
void matrix_scan_user(void) {
    // USB host readiness check
    if (!host_ready && is_keyboard_master()) {
        host_ready = true;
        clear_keyboard();        // Flush any stuck keys
        send_keyboard_report();  // Send neutral HID report
    }

    if (!host_ready) return;  // Skip input until host is ready

    // Read button states
    bool f6_pressed = readPin(F6);
    bool f7_pressed = readPin(F7);

    // Determine new profile based on button press
    uint8_t new_profile = active_profile;
    if (f7_pressed) {
        new_profile = PROFILE_1;
    } else if (f6_pressed) {
        new_profile = PROFILE_2;
    }

    // If profile changed, update layer, EEPROM, and LED
    if (new_profile != active_profile) {
        active_profile = new_profile;
        default_layer_set(1UL << active_profile);
        eeprom_update_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
        update_leds_from_profile();
    }
}

// ─────────────────────────────────────────────────────────────
// LED feedback based on active profile
// ─────────────────────────────────────────────────────────────
void update_leds_from_profile(void) {
    if (get_highest_layer(default_layer_state) == PROFILE_1) {
        writePinLow(LED_1);  // LED ON for PROFILE_1
    } else {
        writePinHigh(LED_1); // LED OFF for PROFILE_2
    }
}

// ─────────────────────────────────────────────────────────────
// Stub for PMW3360 sensor signature check
// ─────────────────────────────────────────────────────────────
bool pmw33xx_check_signature(uint8_t sensor) {
    return true;
}
