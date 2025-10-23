// Copyright 2023 Coaleyed.

#pragma once

// ─────────────────────────────────────────────────────────────
// Pointing Device (PMW3360) Settings
// ─────────────────────────────────────────────────────────────
#define USB_POLLING_INTERVAL_MS 1
#define POINTING_DEVICE_CS_PIN B0
#define POINTING_DEVICE_INVERT_Y
#define DPI 1000
#define PMW33XX_LIFTOFF_DISTANCE 0x02  // Optional: 2mm liftoff

// ─────────────────────────────────────────────────────────────
// Power Management
// ─────────────────────────────────────────────────────────────
#define USB_MAX_POWER_CONSUMPTION 100  // Conservative for BIOS compatibility
#define KC_WAKE_UP_FROM_SUSPEND KC_BTN1
#define SUSPEND_POWER_DOWN
#define USB_SUSPEND_WAKEUP
