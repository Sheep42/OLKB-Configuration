#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "rgb_matrix.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_0_0_255,
  HSV_0_255_255,
  HSV_22_252_246,
  HSV_215_255_128,
  HSV_86_255_128,
  HSV_0_0_0,
  HSV_18_255_108,
  HSV_172_255_255,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
  _VIM,
  _MOUSE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_planck_grid(KC_ESCAPE,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPACE,KC_TAB,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_UP,RSFT_T(KC_ENTER),TT(4),KC_LCTRL,KC_LGUI,KC_LALT,TT(1),KC_SPACE,KC_NO,TT(2),KC_SLASH,KC_LEFT,KC_DOWN,KC_RIGHT),

  [_LOWER] = LAYOUT_planck_grid(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MINUS,KC_EQUAL,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT),

  [_RAISE] = LAYOUT_planck_grid(KC_PSCREEN,KC_TRANSPARENT,RCTL(KC_W),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_INSERT,KC_DELETE,RCTL(KC_BSPACE),KC_TRANSPARENT,RCTL(KC_A),RCTL(KC_S),RCTL(KC_D),RCTL(KC_F),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_PGUP,KC_TRANSPARENT,LSFT_T(KC_CAPSLOCK),RCTL(KC_Z),RCTL(KC_X),RCTL(KC_C),RCTL(KC_V),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_PGDOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_TRANSPARENT,WEBUSB_PAIR,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_ADJUST] = LAYOUT_planck_grid(RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,AU_TOG,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,MU_TOG,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAD,KC_TRANSPARENT,RGB_VAI),

  [_FN] = LAYOUT_planck_grid(KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(5),KC_TRANSPARENT,KC_TRANSPARENT,TO(6),KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_MEDIA_NEXT_TRACK),

  [_VIM] = LAYOUT_planck_grid(TO(0),KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_MOUSE] = LAYOUT_planck_grid(TO(0),KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT),

};

/* 
   * ,-----------------------------------------------------------.
   * |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |
   * |----+----+----+----+----+----+----+----+----+----+----+----|
   * | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
   * |----+----+----+----+----+----+----+----+----+----+----+----|
   * | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 |
   * |----+----+----+----+----+----+----+----+----+----+----+----|
   * | 36 | 37 | 38 | 39 | 40 |    41   | 42 | 43 | 44 | 45 | 46 |
   * `-----------------------------------------------------------'
   *
   * Set indices below of LED's you want for each colormap.
   *
   *
   *  ORANGE: Special Character Keys / Mouse Clicks
   *    Backspace
   *    Enter
   *    ESC
   *    Tab
   *
   *  TEAL/SPRINGGREEN: Standarfd Keys / Symbols
   *
   * PURPLE: Modifiers / Secondary Symbols
   *   Shift
   *   Ctrl
   *   Alt
   *   OS
   *   + / -
   *   _ / =
   *   [] / {}
   *   BKSLH / PIPE
   *   BKTICK / TILDE
   *
   * BLUE: Keyboard functions
   *   RAISE
   *   LOWER
   *   FN Toggled On
   *   Toggle VIM
   *   Toggle MOUSE
   *
   * GREEN: System Keys
   *   Delete
   *   Insert
   *   PgUp
   *   PgDown
   *   Home
   *   End
   *   PrtScrn
   *   Media Keys
   *
   * RED: Keyboard Reset
   * 
   * MAGENTA: RGB Controls
   * 
   * WHITE: Other
   *   Space
   *   Movement Keys
   *   FN Toggled Off
   *   F-Keys
   *   Number Keys
   *   Macros
   *
   * 
   * For each colormap you define, you need to create an array containing the indices you want
   * each color to apply to. 
   *
   * Each array MUST end with a -1, or else the setting functions won't loop. For example:
   *
   *   [_MY_LAYER] = {
   *     {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1},
   *     {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, -1},
   *     {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1}
   *   };
   *
   * The above entry will create a colormap for layer _MY_LAYER, which applies color A to the top row, 
   * color B to the next row, color C to the next row, and leaves Background for the bottom row.
   *
   * Any LED whose index doesn't appear in the array for a given colormap will automatically get the 
   * background color. For example, if your background color is RED and your array is empty (save 
   * for -1's), then the whole board will light up RED.
   *
   * NOTE: Make sure that ALL of your layers have a color map defined
   * and that each color map defines a set for each of your FG colors,
   * even if it's unused. See how my existing colormaps are defined
 */

// Define our color map
const int _RGB_COLORMAP[][NUM_FG][DRIVER_LED_TOTAL] = {
  [_BASE] = {
    // ORANGE
    { 
      0,  11, 
      12,
      35,
      -1
    },
    // TEAL
    {
      1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
      13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
      25, 26, 27, 28, 29, 30, 31, 32, 33,
      43, 45,
      -1 
    },
    // PURPLE
    {
      24,
      37, 38, 39,
      -1
    },
    // WHITE
    {
      34,
      36, 41, 44, 45, 46,
      -1
    },
    // BLUE
    { 
      40, 42,
      -1 
    }, 
    // UNUSED
    { -1 }
  },
  
  [_LOWER] = {
    // ORANGE
    { 
      11, 
      35,
      -1 
    } ,
    // TEAL
    { -1 },
    // PURPLE
    {
      0,
      19, 20, 21, 22, 23,
      24,
      37, 38, 39,
      -1
    },
    // WHITE
    {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
      34,
      36, 41, 44, 45, 46,
      -1 
    },
    // BLUE
    { 
      40, 42,
      -1 
    },
    // UNUSED
    { -1 },
  },

  [_RAISE] = {
    // ORANGE
    { 
      35,
      -1 
    } ,
    // RED
    { 
      38,
      -1
    },
    // GREEN
    {
      0,  9, 10,
      21, 22,
      33, 34,
      -1 
    },
    // PURPLE
    {
      24,
      37, 39,
      -1
    },
    // WHITE
    {
      2,  11,
      13, 14, 15, 16, 
      25, 26, 27, 28,
      36,
      -1
    },
    // BLUE
    {
      40, 41, 42,
      -1 
    } 
  },

  [_ADJUST] = {
    // RED
    { 
      0,
      -1
    },
    // BLUE
    {
      13,
      31,
      40, 42,
      -1 
    },
    // MAGENTA
    { 
      44, 46,
      -1 
    },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
  },

  [_FN] = {
    // WHITE
    { 
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
      -1
    },
    // BLUE
    {
      28, 
      31,
      36,
      -1 
    },
    // GREEN
    { 
      34,
      41, 44, 45, 46,
      -1 
    },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
  },

  [_VIM] = {
    // WHITE
    { 
      2,
      13, 14, 15,
      18, 19, 20, 21,
      -1
    },
    // BLUE
    {
      0,
      -1 
    },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
  },

  [_MOUSE] = {
    // WHITE
    { 
      2,
      13, 14, 15,
      34,
      44, 45, 46,
      -1
    },
    // ORANGE
    {
      1,  3,
      22,
      33, 35,
      -1 
    },
    // BLUE
    { 
      0,
      -1 
    },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
    // UNUSED
    { -1 },
  },
};

// Define our palette map
const uint8_t _RGB_PALETTE[][NUM_FG + 1][3] = {
  [_BASE] = {
    { _DAN_HSV_ORANGE },
    { HSV_SPRINGGREEN },
    { _DAN_HSV_PURPLE },
    { HSV_WHITE },
    { HSV_BLUE },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF }, // default
  },

  [_LOWER] = {
    { _DAN_HSV_ORANGE },
    { HSV_SPRINGGREEN },
    { _DAN_HSV_PURPLE },
    { HSV_WHITE },
    { HSV_BLUE },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
  },

  [_RAISE] = {
    { _DAN_HSV_ORANGE },
    { HSV_RED },
    { HSV_GREEN },
    { _DAN_HSV_PURPLE },
    { HSV_WHITE },
    { HSV_BLUE },
    { _DAN_HSV_OFF }, // default
  },

  [_ADJUST] = {
    { HSV_RED },
    { HSV_BLUE },
    { HSV_MAGENTA },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
  },

  [_FN] = {
    { HSV_WHITE },
    { HSV_BLUE },
    { HSV_GREEN },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
  },

  [_VIM] = {
    { HSV_WHITE },
    { HSV_BLUE },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
  },

  [_MOUSE] = {
    { HSV_WHITE },
    { _DAN_HSV_ORANGE },
    { HSV_BLUE },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
    { _DAN_HSV_OFF },
  },
};

// TODO: Specific key functionality
// to go here
// 
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   }
//   return true;
// }

#ifdef AUDIO_ENABLE
  bool muse_mode = false;
  uint8_t last_muse_note = 0;
  uint16_t muse_counter = 0;
  uint8_t muse_offset = 70;
  uint16_t muse_tempo = 50;

  void encoder_update(bool clockwise) {
      if (muse_mode) {
          if (IS_LAYER_ON(_RAISE)) {
              if (clockwise) {
                  muse_offset++;
              } else {
                  muse_offset--;
              }
          } else {
              if (clockwise) {
                  muse_tempo+=1;
              } else {
                  muse_tempo-=1;
              }
          }
      } else {
          if (clockwise) {
          #ifdef MOUSEKEY_ENABLE
              register_code(KC_MS_WH_DOWN);
              unregister_code(KC_MS_WH_DOWN);
          #else
              register_code(KC_PGDN);
              unregister_code(KC_PGDN);
          #endif
          } else {
          #ifdef MOUSEKEY_ENABLE
              register_code(KC_MS_WH_UP);
              unregister_code(KC_MS_WH_UP);
          #else
              register_code(KC_PGUP);
              unregister_code(KC_PGUP);
          #endif
          }
      }
  }

  void matrix_scan_user(void) {
    #ifdef AUDIO_ENABLE
        if (muse_mode) {
            if (muse_counter == 0) {
                uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
                if (muse_note != last_muse_note) {
                    stop_note(compute_freq_for_midi_note(last_muse_note));
                    play_note(compute_freq_for_midi_note(muse_note), 0xF);
                    last_muse_note = muse_note;
                }
            }
            muse_counter = (muse_counter + 1) % muse_tempo;
        }
    #endif
  }

  bool music_mask_user(uint16_t keycode) {
      switch (keycode) {
      case RAISE:
      case LOWER:
          return false;
      default:
          return true;
      }
  }
#endif

// Controls raise / lower / adjust LEDs
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void set_layer_bg_color( uint8_t palette[][3] ) {
  // Set background. 
  // Assumes background is the last defined color in the palette 
  uint8_t val = ( palette[NUM_FG][0] > 0 || palette[NUM_FG][1] > 0 ) ? rgb_matrix_config.hsv.v : palette[NUM_FG][2];

  HSV hsv = { 
    .h = palette[NUM_FG][0],
    .s = palette[NUM_FG][1],
    .v = val
  };

  RGB rgb = hsv_to_rgb( hsv );

  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }

}

/* Color setting funcs--Assume the index arrays have -1 as a sentinel */
void custom_set_rgb( const int per_layer_ind[][DRIVER_LED_TOTAL], uint8_t palette[][3] ) {

  for (int i = 0; i < NUM_FG; i++) {

    HSV hsv = {
      .h = palette[i][0],
      .s = palette[i][1],
      .v = rgb_matrix_config.hsv.v
    };

    RGB rgb = hsv_to_rgb( hsv );

    for(int j = 0; per_layer_ind[i][j] != -1 ; j++) 
      rgb_matrix_set_color( per_layer_ind[i][j], rgb.r, rgb.g, rgb.b );

  }
}

void rgb_matrix_indicators_user(void) {
  
  // assign colors based on 
  // current layer and the
  // defined color maps
  uint8_t palette[NUM_FG + 1][3];
  uint8_t layer = biton32( layer_state );

  for (int i = 0; i <= NUM_FG; i++) {
    for (int j = 0; j < 3; j++) {
      palette[i][j] = _RGB_PALETTE[layer][i][j];
    }
  }

  set_layer_bg_color( palette );
  custom_set_rgb(  _RGB_COLORMAP[layer], palette );

}