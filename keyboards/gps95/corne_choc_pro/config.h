#pragma once
//pins
#define USB_VBUS_PIN GP13
#define SERIAL_USART_TX_PIN GP12
#define SPLIT_HAND_PIN GP21
//features
#define RGB_MATRIX_SLEEP
#define SPLIT_LED_STATE_ENABLE
#define USB_SUSPEND_WAKEUP_DELAY 200
/* RP2040- and hardware-specific config */
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64