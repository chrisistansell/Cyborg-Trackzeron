#include "trackzeron.h"
#include <avr/eeprom.h>
#include "host.h"              // For is_keyboard_master()
#include "pointing_device.h"   // For mouse movement tracking
#include "timer.h"             // For debounce timing

// ─────────────────────────────────────────────────────────────
// Persistent profile state and host readiness tracking
// ─────────────────────────────────────────────────────────────
uint8_t active_profile = PROFILE_1;
bool host_ready = false;           // True when host is ready to receive input
bool flushed_hid = false;          // True once we've sent a neutral report
uint32_t host_ready_time = 0;      // Timestamp when host became ready

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
    eeprom_read_block(&active_profile, (void*)PROFILE_EEPROM_ADDR, sizeof(active_profile));
    default_layer_set(1UL << active_profile);
    update_leds_from_profile();
    pointing_device_set_cpi(900);
}

// ─────────────────────────────────────────────────────────────
// Mouse movement triggers host readiness if not already set
// ─────────────────────────────────────────────────────────────
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!host_ready && (mouse_report.x || mouse_report.y || mouse_report.v || mouse_report.h)) {
        host_ready = true;
        host_ready_time = timer_read32();
    }
    return mouse_report;
}

// ─────────────────────────────────────────────────────────────
// Main scan loop: handles profile switching via buttons
// ─────────────────────────────────────────────────────────────
void matrix_scan_user(void) {
    // Detect host readiness via USB enumeration
    if (!host_ready && is_keyboard_master()) {
        host_ready = true;
        host_ready_time = timer_read32();
    }

    // Flush HID once when host becomes ready
    if (host_ready && !flushed_hid) {
        flushed_hid = true;
        clear_keyboard();        // Flush any stuck keys
        send_keyboard_report();  // Send neutral HID report
        host_ready_time = timer_read32();  // Reset debounce timer
    }

    // Debounce input for 200ms after host readiness
    if (!host_ready || timer_elapsed32(host_ready_time) < 200) return;

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
