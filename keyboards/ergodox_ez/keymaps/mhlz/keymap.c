#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

#define BASE 0
#define GAME 1
#define PUNC 2
#define NUMB 3
#define RSET 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
      // left hand
      KC_ESCAPE,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,          KC_KP_6,
      LT(PUNC, KC_TAB),         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,             KC_TRANSPARENT,
      KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
      KC_LSFT,        KC_Z,           KC_X,           KC_C,           LT(PUNC, KC_V),           KC_B,             MO(PUNC),
      KC_HYPR, HYPR(KC_P), KC_TRANSPARENT, KC_LALT,        KC_LGUI,

                                                KC_MEDIA_PLAY_PAUSE,  KC_AUDIO_MUTE,
                                                                      KC_F14,
                                              KC_SPACE,   KC_BSPACE,  MO(PUNC),



      // right hand
      KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,          KC_KP_0,        KC_TRANSPARENT,     KC_TRANSPARENT,
      KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,             KC_O,           KC_P,               LT(PUNC, KC_BSLASH),
                      KC_H,           KC_J,           KC_K,             KC_L,           KC_SCOLON,          LCTL_T(KC_QUOTE),
      MO(PUNC),       KC_N,           LT(PUNC, KC_M),           KC_COMMA,         KC_DOT,         KC_SLASH,           KC_LSFT,
                                      KC_LGUI,        KC_LALT,   KC_TRANSPARENT, KC_TRANSPARENT,     MO(NUMB),

                                                KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,
                                                KC_F15,
                                                MO(PUNC),            KC_DELETE,     KC_ENTER
  ),
  [GAME] = LAYOUT_ergodox(
      // left hand
      KC_ESCAPE,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,         KC_KP_6,
      KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,            KC_TRANSPARENT,
      KC_TRANSPARENT, CTL_T(KC_A),    ALT_T(KC_S),    GUI_T(KC_D),    SFT_T(KC_F),     ALL_T(KC_G),
      KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,             KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                KC_MEDIA_PLAY_PAUSE,  KC_AUDIO_MUTE,
                                                                      KC_F14,
                                LT(PUNC,KC_SPACE), KC_BSPACE,            KC_DELETE,



      // right hand
      KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,          KC_KP_0,        KC_TRANSPARENT,     KC_TRANSPARENT,
      KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,             KC_O,           KC_P,               KC_TRANSPARENT,
                      ALL_T(KC_H),    RSFT_T(KC_J),   RGUI_T(KC_K),     RALT_T(KC_L),   RCTL_T(KC_SCOLON),  KC_QUOTE,
      KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,         KC_DOT,         KC_SLASH,           KC_TRANSPARENT,
                                      KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,

                                                KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,
                                                KC_F15,
                                                KC_DELETE,            LT(NUMB,KC_TAB),     LT(PUNC,KC_ENTER)
  ),
  [PUNC] = LAYOUT_ergodox(
      // left hand
      TO(BASE),       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,            KC_F6,
      KC_TRANSPARENT, KC_NO,          KC_LBRC,        KC_RBRC,        KC_PLUS,        KC_ASTR,          KC_TRNS,
      KC_TRANSPARENT, KC_AT,          KC_EQL,         KC_LPRN,        KC_RPRN,        KC_EXLM,
      KC_TRANSPARENT, KC_NO,          KC_CIRC,        KC_PERC,        KC_UNDS,        KC_NO,            KC_TRNS,
      KC_TRANSPARENT, KC_TRNS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                  KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,



      // right hand
      KC_F6,          KC_F7,          KC_F8,          KC_F9,            KC_F10,         KC_F11,             KC_F12,
      KC_TRANSPARENT, KC_HASH,        KC_GRV,         KC_LCBR,          KC_RCBR,        KC_TILD,            KC_TRANSPARENT,
                      KC_LEFT,        KC_DOWN,        KC_UP,            KC_RIGHT,       KC_DLR,             KC_TRANSPARENT,
      KC_TRANSPARENT, KC_NO,          KC_MINUS,       KC_AMPR,          KC_NO,          KC_NO,              KC_TRANSPARENT,

                                      KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,

                                                KC_TRANSPARENT,    TO(RSET),
                                                KC_TRANSPARENT,
                                                KC_TRANSPARENT,            KC_TRANSPARENT,     KC_TRANSPARENT
  ),
  [NUMB] = LAYOUT_ergodox(
      // left hand
      TO(BASE),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_TRANSPARENT,   KC_TRANSPARENT,
      KC_TRANSPARENT, KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT,   KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                  KC_TRANSPARENT,
                                KC_KP_0, KC_TRANSPARENT,   KC_TRANSPARENT,



      // right hand
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                KC_TRANSPARENT,    KC_TRANSPARENT,
                                                KC_TRANSPARENT,
                                                KC_TRANSPARENT,            KC_TRANSPARENT,     KC_TRANSPARENT
  ),

  [RSET] = LAYOUT_ergodox(TO(BASE),KC_LSHIFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

void matrix_scan_user(void) {
  if (keyboard_report->mods & (MOD_BIT(KC_LSFT))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_RSFT))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_LCTRL))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_RCTRL))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_LALT))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_RALT))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_LGUI))) {
    ergodox_right_led_3_on();
  } else if (keyboard_report->mods & (MOD_BIT(KC_RGUI))) {
    ergodox_right_led_3_on();
  } else {
    int layer = biton32(layer_state);
    if (layer != RSET) {
      ergodox_right_led_3_off();
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch(layer) {
      case BASE:
        break;
      case GAME:
        ergodox_right_led_1_on();
        break;
      case PUNC:
        ergodox_right_led_2_on();
        break;
      case NUMB:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case RSET:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    }

    return state;

};
