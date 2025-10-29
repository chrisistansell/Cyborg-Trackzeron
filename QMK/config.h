// Copyright 2023 Coaleyed.

#pragma once

// ─────────────────────────────────────────────────────────────
// Pointing Device (PMW3360) Settings
// ─────────────────────────────────────────────────────────────
#define USB_POLLING_INTERVAL_MS 1         // Fast HID updates
#define POINTING_DEVICE_CS_PIN B0
#define POINTING_DEVICE_INVERT_Y
#define DPI 1000
#define PMW33XX_LIFTOFF_DISTANCE 0x02     // Optional: 2mm liftoff

// ─────────────────────────────────────────────────────────────
// Power Management
// ─────────────────────────────────────────────────────────────
#define USB_SUSPEND_WAKEUP  // Wake host on key or mouse input