/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Drashna Jael're  <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "mhlz.h"
#include "version.h"

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_VOLD,           KC_VOLU, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DLR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    C(KC_F11),       C(KC_F12), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MOPC,           KC_MOPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_HYPR, KC_HYP,  KC_RALT, KC_LALT, KC_LGUI,          KC_MOPC,          KC_MOPC,           KC_RGUI, KC_LALT, KC_NO,   KC_NO,   KC_MONU,
                                            KC_SPC,  KC_BSPC, KC_MOPC,           KC_MOPC, KC_TAB,  KC_ENT
    ),

    [GAME] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [PUNC] = LAYOUT_moonlander(
        KC_TOBA, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_NO,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, _______,           KC_F12,  KC_HASH, KC_GRV,  KC_LBRC, KC_RBRC, KC_TILD, _______,
        _______, KC_AT,   KC_EQL,  KC_LPRN, KC_RPRN, KC_EXLM, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_DLR,  _______,
        _______, KC_NO,   KC_CIRC, KC_PERC, KC_UNDS, KC_NO,                               KC_NO,   KC_MINUS,KC_AMPR, KC_NO,   KC_NO,   _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUMB] = LAYOUT_moonlander(
        KC_TOBA, _______, KC_SLSH, KC_ASTR, KC_MINUS,KC_LPRN, KC_RPRN,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_EQL,  _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,                              _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______,          _______,           TO(CNFG),         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [CNFG] = LAYOUT_moonlander(
        KC_TOBA, TO(GAME),_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    )

};

HSV last_hsv = { 0 };
uint8_t last_layer = BASE;
uint8_t last_mode = 0;

void rgb_matrix_indicators_user() {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer == PUNC) {
        rgb_matrix_set_color_all(0, 0, 255);
    }

    if (layer == NUMB) {
        rgb_matrix_set_color_all(0, 0, 0);
        rgb_matrix_set_color(0, 255, 255, 255);
        rgb_matrix_set_color(71, 255, 255, 0);
        rgb_matrix_set_color(7, 0, 255, 0);
        rgb_matrix_set_color(8, 0, 255, 0);
        for (int i = 10; i < 14; i++) {
            rgb_matrix_set_color(i, 0, 255, 0);
        }
        for (int i = 15; i < 19; i++) {
            rgb_matrix_set_color(i, 0, 255, 0);
        }
        for (int i = 20; i < 24; i++) {
            rgb_matrix_set_color(i, 0, 255, 0);
        }
        for (int i = 25; i < 29; i++) {
            rgb_matrix_set_color(i, 0, 255, 0);
        }
        rgb_matrix_set_color(29, 0, 255, 0);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    uint8_t layer = get_highest_layer(state);

#ifdef COMBO_ENABLE
   combo_enable();
#endif

    switch (layer) {
        case BASE:
            break;
        case GAME:
            ML_LED_3(1);
            ML_LED_6(1);
#ifdef COMBO_ENABLE
           combo_disable();
#endif
            break;
        case PUNC:
            ML_LED_1(1);
            ML_LED_4(1);
            break;
        case NUMB:
            ML_LED_2(1);
            ML_LED_5(1);
            break;
        case CNFG:
            ML_LED_1(true);
            ML_LED_2(true);
            ML_LED_3(true);
            ML_LED_4(true);
            ML_LED_5(true);
            ML_LED_6(true);
            break;
        default:
            break;
    }

    return state;
}
