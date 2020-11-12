#include "mhlz.h"
#include "ergodox_ez.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
      // left hand
      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_VOLD,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     C(KC_F11),
      KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,  KC_B,     KC_MOPC,
      KC_HYPR,  KC_HYP,   KC_RALT,  KC_LALT,  KC_LGUI,

                                              KC_MPLY,  KC_MUTE,
                                                                  KC_F14,
                                              KC_SPC,   KC_BSPC,  KC_MOPC,



      // right hand
      KC_VOLU,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DLR,
      C(KC_F12),KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
                KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
      KC_MOPC,  KC_N,     KC_M,  KC_COMM,  KC_DOT,   KC_SLASH, KC_RSFT,
                          KC_LGUI,  KC_LALT,  KC_NO,    KC_NO,    KC_MONU,

                                              KC_VOLD,  KC_VOLU,
                                              KC_F15,
                                              KC_MOPC,  KC_DEL,   KC_ENTER
  ),
  [GAME] = LAYOUT_ergodox(
      // left hand
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  KC_F,     _______,
      _______,  _______,  _______,  _______,  KC_V,     _______,  _______,
      _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                                                  _______,
                                              _______,  _______, _______,



      // right hand
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
                _______,  KC_J,     _______,  _______,  _______,  _______,
      _______,  _______,  KC_M,     _______,  _______,  _______,  _______,
                          _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                              _______,
                                              _______,  _______,  _______
  ),
  [SIMU] = LAYOUT_ergodox(
      // left hand
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,
      _______,  KC_Y,     _______,  _______,  KC_V,     _______,  _______,
      _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                                                  _______,
                                              _______,  _______,  _______,

      // right hand
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  KC_Z,     _______,  _______,  _______,  _______,  _______,
                _______,  KC_PENT,  KC_PGDN,  KC_END,   _______,  _______,
      _______,  _______,  KC_M,     _______,  _______,  _______,  _______,
                          _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                              _______,
                                              _______,  _______,  _______
  ),
  [PUNC] = LAYOUT_ergodox(
      // left hand
      KC_TOBA,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_NO,
      _______,  KC_NO,    KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_ASTR,  _______,
      _______,  KC_AT,    KC_EQL,   KC_LPRN,  KC_RPRN,  KC_EXLM,
      _______,  KC_NO,    KC_CIRC,  KC_PERC,  KC_UNDS,  KC_NO,    _______,
      _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                                                  _______,
                                              _______,  _______,  _______,



      // right hand
      _______,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
      KC_F12,   KC_HASH,  KC_GRV,   KC_LBRC,  KC_RBRC,  KC_TILD,  _______,
                KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_DLR,   _______,
      _______,  KC_NO,    KC_MINUS, KC_AMPR,  KC_NO,    KC_NO,    _______,
                          _______,  _______,  _______,  _______,  _______,

                                              _______,  TO(CNFG),
                                              _______,
                                              _______,  _______,  _______
  ),
  [NUMB] = LAYOUT_ergodox(
      // left hand
      KC_TOBA,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______,  _______,
      _______,  KC_KP_0,  KC_KP_4,  KC_KP_5,  KC_KP_6,  _______,
      _______,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                                                  _______,
                                              _______,  _______,  _______,



      // right hand
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
                          _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                              _______,
                                              _______,  _______,  _______
  ),
  [CNFG] = LAYOUT_ergodox(
      // left hand
      KC_TOBA,  TO(GAME), TO(SIMU), _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                                                  _______,
                                              _______,  _______,  _______,



      // right hand
      _______,  _______,  _______,  _______,  _______,  _______,  RESET,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,
                          _______,  _______,  _______,  _______,  _______,

                                              _______,  _______,
                                              _______,
                                              _______,  _______,  _______
  )
};

uint32_t layer_state_set_user(uint32_t state) {
   uint8_t layer = biton32(state);

   ergodox_board_led_off();
   ergodox_right_led_1_off();
   ergodox_right_led_2_off();
   ergodox_right_led_3_off();

#ifdef COMBO_ENABLE
   combo_enable();
#endif

   switch(layer) {
     case BASE:
       break;
     case SIMU:
     case GAME:
       ergodox_right_led_1_on();
#ifdef COMBO_ENABLE
       combo_disable();
#endif
       break;
     case PUNC:
       ergodox_right_led_2_on();
       break;
     case NUMB:
       ergodox_right_led_1_on();
       ergodox_right_led_2_on();
       break;
     case CNFG:
       ergodox_right_led_1_on();
       ergodox_right_led_2_on();
       ergodox_right_led_3_on();
       break;
   }

   return state;
};

