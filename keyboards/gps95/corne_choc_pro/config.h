#pragma once
//pins
#define USB_VBUS_PIN GP13
#define SERIAL_USART_TX_PIN GP12
#define SPLIT_HAND_PIN GP21

//for homerow mods
#define TAPPING_TERM 175  //default 200
#define PERMISSIVE_HOLD   // Triggers mod if you tap another key while holding.
#define FLOW_TAP_TERM 150 // Disables holds when typing quickly.

//keyboard
#define MK_3_SPEED//3 speed mode instead of accel

// ---- Cursor: pixels per step / ms between steps ----
// ACL0
#define MK_C_OFFSET_0   4    // default 1
#define MK_C_INTERVAL_0 16   // default 32
// ACL1
#define MK_C_OFFSET_1   12   // default 4
#define MK_C_INTERVAL_1 16   // default 16
// ACL2
#define MK_C_OFFSET_2   32   // default 32
#define MK_C_INTERVAL_2 16   // default 16

// ---- Scroll: steps per scroll action / ms between steps (lower interval = faster) ----
// ACL0 (matches old ACL1 scroll speed)
#define MK_W_OFFSET_0   1    // default 1
#define MK_W_INTERVAL_0 120  // default 360
// ACL1 (a bit faster)
#define MK_W_OFFSET_1   1    // default 1
#define MK_W_INTERVAL_1 60   // default 120
// ACL2 (unchanged)
#define MK_W_OFFSET_2   1    // default 1
#define MK_W_INTERVAL_2 20   // default 20

//multiple base layers
#define SPLIT_LAYER_STATE_ENABLE

//features
#define RGB_MATRIX_SLEEP
#define SPLIT_LED_STATE_ENABLE
#define USB_SUSPEND_WAKEUP_DELAY 200

/* RP2040- and hardware-specific config */
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64