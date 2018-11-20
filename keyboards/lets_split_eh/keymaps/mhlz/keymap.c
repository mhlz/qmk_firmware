#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0
#define PUNC 1
#define NUMB 2
#define RSET 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | C(') |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Hypr | Ralt | Lalt | GUI  |Space |Enter | GUI  | LAlt |      |   \  |T(Nmb)|
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLASH, \
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, LCTL_T(KC_QUOTE),  \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    LT(PUNC, KC_V),  KC_B,   KC_N,   LT(PUNC, KC_M),  KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, \
  MO(NUMB),  KC_HYPR, KC_LALT, KC_LGUI, KC_SPC, KC_BSPC, KC_ESC, KC_ENT, KC_LGUI, KC_LALT, KC_RALT,   MO(NUMB)  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[PUNC] = LAYOUT( \
  TO(BASE),KC_NO,    KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_HASH, KC_GRV,  KC_LBRC, KC_RBRC, KC_TILD, KC_DEL,  \
  _______, KC_AT,    KC_EQL,  KC_LPRN, KC_RPRN, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_DLR,  _______, \
  _______, KC_NO,    KC_CIRC, KC_PERC, KC_UNDS, KC_NO,   KC_NO,   KC_MINUS,KC_AMPR, KC_NO,   KC_NO,   KC_TRNS, \
  _______, _______,  _______, _______, _______, KC_TRNS, KC_TRNS, _______, KC_TRNS, KC_TRNS, KC_TRNS, TO(RSET)  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[NUMB] = LAYOUT( \
  TO(BASE),  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F14,   KC_F15, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  KC_TRNS,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_NO,  KC_NO,  KC_NO, KC_NO, KC_MUTE, _______, KC_TRNS, \
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_TRNS, KC_TRNS, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_TRNS  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |T(BASE|      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[RSET] = LAYOUT( \
  TO(BASE),  _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_TRNS,  RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_STEP, \
  RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS    \
),
};

void switch_rgb_light(int layer) {
  RGB_DIRTY = true;
  rgblight_enable();
  switch(layer) {
    case BASE:
      rgblight_sethsv_cyan();
      break;
    case PUNC:
      rgblight_sethsv(120, 255, 255);
      break;
    case NUMB:
      rgblight_sethsv_orange();
      break;
    case RSET:
      rgblight_sethsv_red();
      break;
  }
}

void matrix_init_user (void) {
  rgblight_enable();
}

int lastLayer = -1;

void matrix_scan_user(void) {
  int layer = biton32(layer_state);
  if (layer != lastLayer) {
    switch_rgb_light(layer);
  }
  layer = lastLayer;
}

