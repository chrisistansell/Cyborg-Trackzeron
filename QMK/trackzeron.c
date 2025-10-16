#include "trackzeron.h"
#include "quantum.h"

#ifdef DEBUG_TRACKZERON
#    include "print.h"
#endif

extern bool suspended;
extern bool dip_switch_map[DIP_SWITCH_COUNT];

bool gesture_enabled = false;

void keyboard_pre_init_user(void) {
    setPinOutput(DIP_SWITCH_LED_PIN);  // F6
    setPinOutput(PROFILE_LED_PIN);     // C5

    #ifdef DEBUG_TRACKZERON
    uprintf("Pins initialized\n");
    #endif
}

void update_leds_based_on_layer(void) {
    uint8_t active_layer = get_highest_layer(layer_state);

    if (active_layer == PROFILE_1 || active_layer == SECOND_LAYER_PROFILE_1) {
        writePinLow(DIP_SWITCH_LED_PIN);   // LED 1 ON
        writePinHigh(PROFILE_LED_PIN);     // LED 2 OFF
    } else {
        writePinHigh(DIP_SWITCH_LED_PIN);  // LED 1 OFF
        writePinLow(PROFILE_LED_PIN);      // LED 2 ON
    }

    #ifdef DEBUG_TRACKZERON
    uprintf("LED updated: active_layer = %d\n", active_layer);
    #endif
}

void toggle_gesture_support(void) {
    gesture_enabled = !gesture_enabled;

    #ifdef DEBUG_TRACKZERON
    uprintf("Gesture support: %s\n", gesture_enabled ? "ENABLED" : "DISABLED");
    #endif
}

#ifdef ENABLE_SENSOR_DEBUG
void print_sensor_status(void) {
    uprintf("Sensor status: [stub]\n");
}
#endif

void suspend_power_down_user(void) {
    suspended = true;
    update_leds_based_on_layer();

    #ifdef DEBUG_TRACKZERON
    uprintf("Suspend: LED state updated\n");
    #endif
}

void suspend_wakeup_init_user(void) {
    suspended = false;

    if (dip_switch_map[0]) {
        layer_clear();
        layer_on(PROFILE_1);  // DIP ON → PROFILE_1
    } else {
        layer_clear();
        layer_on(PROFILE_2);  // DIP OFF → PROFILE_2
    }

    update_leds_based_on_layer();

    #ifdef DEBUG_TRACKZERON
    uprintf("Wakeup: Profile reapplied and LED updated\n");
    #endif
}
