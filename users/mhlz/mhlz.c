#include "mhlz.h"
#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

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

static int my_combo_layer_state = 0;
static uint16_t my_combo_press_start = 0;

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch (combo_index) {
        case FD_LAYER:
        case JK_LAYER:
            if (pressed) {
                switch (my_combo_layer_state) {
                    case 0:
                        my_combo_layer_state = 1;
                        my_combo_press_start = timer_read();
                        layer_on(PUNC);
#ifdef CONSOLE_ENABLE
                        uprintf("layer state is now 1, punc layer on\n");
#endif
                        break;

                }
                return;
            }

            layer_off(PUNC);
            switch (my_combo_layer_state) {
                case 1:
#ifdef CONSOLE_ENABLE
                    uprintf("layer state is 1\n");
#endif
                    if (timer_read() - my_combo_press_start < 300) {
#ifdef CONSOLE_ENABLE
                        uprintf("timer did not run out, activating one shot\n");
#endif
                        set_oneshot_layer(PUNC, ONESHOT_START);
                    }
                    break;
            }
#ifdef CONSOLE_ENABLE
            uprintf("layer state is now 0, punc layer off\n");
#endif
            my_combo_layer_state = 0;
            break;
    }
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    if (is_oneshot_layer_active() && record->event.pressed) {
#ifdef CONSOLE_ENABLE
        uprintf("oneshot deactivated\n");
#endif
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }

    if (my_combo_layer_state == 1 && record->event.pressed) {
#ifdef CONSOLE_ENABLE
        uprintf("button pressed while in state 1, now in state 2\n");
#endif
        my_combo_layer_state = 2;
    }

    return true;
}

#endif

