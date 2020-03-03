#pragma once

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define NUM_FG 6 // Number of foreground colors 

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES  // reacts to keypresses (will slow down matrix scan by a lot)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
#	define RGB_MATRIX_STARTUP_VAL 150 // default brightness
#endif

#define _DAN_HSV_ORANGE  	16, 255, 255 	// ORANGE
#define _DAN_HSV_PURPLE 	191, 255, 255  	// PURPLE
#define _DAN_HSV_OFF 		0, 0, 0     	// OFF

#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"zbP6M/xKD0R"