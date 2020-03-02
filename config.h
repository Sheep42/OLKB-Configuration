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
#   define RGB_MATRIX_KEYPRESSES  // reacts to keypresses (will slow down matrix scan by a lot)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
#	define RGB_MATRIX_STARTUP_VAL 150 // default brightness
#endif

#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"zbP6M/xKD0R"