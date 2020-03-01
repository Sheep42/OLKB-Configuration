#pragma once

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define NUM_LIGHTS 47
#define NUM_FG 6 // Number of foreground colors 
#define NUM_RGB 3

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES  // reacts to keypresses (will slow down matrix scan by a lot)
// #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (not recommened)
// #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
#    undef RGB_MATRIX_LED_PROCESS_LIMIT
#    undef RGB_MATRIX_LED_FLUSH_LIMIT
#endif

#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"zbP6M/xKD0R"