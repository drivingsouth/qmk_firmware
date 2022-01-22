/* Copyright 2021 Kyle McCreery
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
#include <stdio.h>
#include "quantum.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
	_FN2,
	_FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    DF(0),   KC_1,    KC_2,    KC_3,
    DF(1),   KC_Q,    KC_W,    KC_E,
    DF(2),   KC_A,    KC_S,    KC_D,
    MO(1),   KC_Z,    KC_X,    KC_C
    ),
    [_FN1] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FN2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
        oled_set_cursor(0, 0);

        char oled_string[32];
        sprintf( oled_string, "L%d", (int)layer_state );
        oled_write_P(PSTR(oled_string), false);
//        oled_write_P(PSTR("OLED"), false);
//      uprintf("OLED: layer: %u\n", layer_state);
/*    if (layer_state == 0) {
        oled_set_cursor(0, 3);
        oled_write_P(PSTR("moji"), false);
        uprintf("OLED: layer: %u\n", layer_state);
        //oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
        // oled_scroll_left();
    } else {
        // uprintf("OLED: layer: logo2 right %u\n", layer_state);
        oled_write_raw_P(qmk_logo2, sizeof(qmk_logo2));
        // oled_scroll_right();
    }
*/
    return true;
}
#endif  // OLED_DRIVER_ENABLE