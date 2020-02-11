#pragma once

#include QMK_KEYBOARD_H

#define BASE 0
#define GAME 1
#define SIMU 2
#define PUNC 3
#define NUMB 4
#define CNFG 5

#define KC_VPNC LT(PUNC, KC_V)
#define KC_MPNC LT(PUNC, KC_M)
#define KC_MOPC MO(PUNC)
#define KC_MONU MO(NUMB)
#define KC_HYP  HYPR(KC_P)
#define KC_TOBA TO(BASE)

