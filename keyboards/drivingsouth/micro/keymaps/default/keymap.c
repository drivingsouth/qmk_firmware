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
    DF(0),   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,	// ROWS0
    DF(1),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,
    DF(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,
    MO(1),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M
    ),
    [_FN1] = LAYOUT(
    KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_R,    KC_T,    KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN2] = LAYOUT(
    KC_TRNS, KC_7,    KC_8,    KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_U,    KC_I,    KC_O,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#include "quantum.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
        char oled_string[32];
        oled_set_cursor(0, 0);
        sprintf( oled_string, " L%d", (int)layer_state );
        oled_write_P(PSTR(oled_string), false);
        oled_set_cursor(0, 1);
        sprintf( oled_string, "DL%d", (int)default_layer_state );
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
