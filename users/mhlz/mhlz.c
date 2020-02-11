#include "mhlz.h"

#include QMK_KEYBOARD_H

#ifdef INCLUDE_DEFAULT_COMBOS

enum combos {
    JK_LAYER,
    FD_LAYER,
};

const uint16_t PROGMEM jk_combo[] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM fd_combo[] = { KC_F, KC_D, COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
    [JK_LAYER] = COMBO_ACTION(jk_combo),
    [FD_LAYER] = COMBO_ACTION(fd_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }

    switch (combo_index) {
        case FD_LAYER:
        case JK_LAYER:
            set_oneshot_layer(PUNC, ONESHOT_START);
            break;
    }
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    if (is_oneshot_layer_active() && record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }

    return true;
}

#endif

