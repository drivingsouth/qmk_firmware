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
#include "../../config.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
	_FN2,
	_FN3
};

/////////////////////////////////////////////////////////////////////
///////  KEYMAPS
/////////////////////////////////////////////////////////////////////
	// COL0   COL1      COL2   COL3  COL4   COL5   COL6   COL7     COL7     COL6   COL5   COL4   COL3    COL2     COL1    COL0
	// COL0   COL1      COL2   COL3     COL4     COL5     COL6     COL7     COL7     COL6      COL5    COL4      COL3     COL2     COL1     COL0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    KC_ESCAPE,     KC_1,        KC_2,         KC_3,        KC_4,        KC_5,   KC_6,    KC_COPY,  KC_PASTE, KC_7,    KC_8,    KC_9,         KC_0,         KC_MINUS,      KC_EQUAL,        KC_BACKSPACE,	// ROWS0
    MO(1),         KC_GRAVE,    KC_Q,         KC_W,        KC_E,        KC_R,   KC_T,    KC_NO,    KC_NO,    KC_Y,    KC_U,    KC_I,         KC_O,         KC_P,          KC_LEFT_BRACKET, KC_RIGHT_BRACKET,	// ROWS1
    MO(2),         KC_TAB,      KC_A,         KC_S,        KC_D,        KC_F,   KC_G,    KC_NO,    KC_NO,    KC_H,    KC_J,    KC_K,         KC_L,         KC_SEMICOLON,  KC_QUOTE,        KC_ENTER,	// ROWS2
	MO(1),         KC_LGUI,     KC_Z,         KC_X,        KC_C,        KC_V,   KC_B,    KC_NO,    KC_NO,    KC_N,    KC_M,    KC_COMMA,     KC_DOT,       KC_SLASH,      KC_BACKSLASH,    KC_DELETE, //ROWS3
    KC_LEFT_SHIFT, KC_SPACE,    KC_LEFT_CTRL, KC_LEFT_ALT, C(KC_SPACE), KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_BACKSPACE, KC_RIGHT_ALT, KC_RIGHT_CTRL, KC_ENTER,        KC_RIGHT_SHIFT	// ROWS4
    ),
    [_FN1] = LAYOUT(
    KC_TRNS,       KC_F1,       KC_F2,        KC_F3,       KC_F4,       KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,  KC_F7,   KC_F8,   KC_F9,        KC_F10,       KC_F11,      KC_F12,    KC_TRNS,	// ROWS0
    KC_TRNS,       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_TRNS,   KC_TRNS,	// ROWS1
    KC_TRNS,       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_BACKSPACE, KC_LEFT, KC_UP,   KC_RIGHT,     KC_TRNS,     KC_TRNS,   KC_TRNS,	// ROWS2
    KC_TRNS,       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_DOWN,      KC_TRNS,      KC_TRNS,     KC_TRNS,   KC_TRNS,	// ROWS3
    KC_TRNS,       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_TRNS,   KC_TRNS	// ROWS4
    ),
    [_FN2] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,	// ROWS0
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS1
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS2
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS3
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS	// ROWS4
    ),
    [_FN3] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,	// ROWS0
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS1
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS2
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	// ROWS3
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS	// ROWS4
    )
};

#ifdef OLED_DRIVER_ENABLE
/////////////////////////////////////////////////////////////////////
///////  OLED
/////////////////////////////////////////////////////////////////////
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

#ifdef ENABLE_ENOCDER
/////////////////////////////////////////////////////////////////////
///////  ROTARY ENCODERS
/////////////////////////////////////////////////////////////////////
static void encoder_update_user_index0_BASE( bool clockwise )
{
	// LEFT EC12 Rotary Encoder

//	if ( get_mods() & (MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RCTRL)) ) {
	if( clockwise ){
		tap_code( KC_PGUP );
	} else {
		tap_code( KC_PGDN );
	}
}

static void encoder_update_user_index0_FN1( bool clockwise )
{
	if( clockwise ){
		tap_code( KC_PGUP /*KC_VOLU*/ );
	} else {
		tap_code( KC_PGDN /*KC_VOLD*/ );
	}
}

static void encoder_update_user_index0( bool clockwise )
{
	if( IS_LAYER_ON( _FN1 ) ){
		encoder_update_user_index0_FN1( clockwise );
	} else {
		encoder_update_user_index0_BASE( clockwise );
	}
}
/*
static void encoder_update_user_index1_BASE( bool clockwise )
{
	if ( get_mods() & MOD_BIT(KC_LCTRL) ) {
		if( clockwise ){
			tap_code( KC_KB_VOLUME_UP );
		} else {
			tap_code( KC_KB_VOLUME_DOWN );
		}
	} else {
		if( clockwise ){
			tap_code( KC_PAGE_UP );
		} else {
			tap_code( KC_PAGE_DOWN );
		}
	}
}

static void encoder_update_user_index1_FN1( bool clockwise )
{
	if ( get_mods() & MOD_BIT(KC_LCTRL) ) {
		if( clockwise ){
			tap_code( KC_MS_WH_LEFT );
		} else {
			tap_code( KC_MS_WH_RIGHT );
		}
	} else {
		if( clockwise ){
			tap_code( KC_MS_WH_UP );
		} else {
			tap_code( KC_MS_WH_DOWN );
		}
	}
}
*/
static void encoder_update_user_index1( bool clockwise )
{
	// Dial Left
	if( clockwise ){
		tap_code( KC_LEFT );
	} else {
		tap_code( KC_RIGHT );
	}
}

static void encoder_update_user_index2( bool clockwise )
{
	// EC12 Right
	if( clockwise ){
		tap_code( KC_DEL );
	} else {
		tap_code( KC_BSPC );
	}
}

static void encoder_update_user_index3( bool clockwise )
{
	// Dial Right
	if( clockwise ){
		tap_code( KC_UP );
	} else {
		tap_code( KC_DOWN );
	}
}

bool encoder_update_user(uint8_t index, bool clockwise)
{
	switch( index ){
	case 0:	// EC12 Left
		encoder_update_user_index0( clockwise );
		break;
	case 1: // Dial Left
		encoder_update_user_index1( clockwise );
		break;
	case 2:	// EC12 Right
		encoder_update_user_index2( clockwise );
		break;
	case 3:	// Dial Right
		encoder_update_user_index3( clockwise );
		break;
	default:
		break;
	}

	return true;
}
#endif

/////////////////////////////////////////////////////////////////////
///////  DIP SWITCH
/////////////////////////////////////////////////////////////////////
bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
//            if(active) { audio_on(); } else { audio_off(); }
            break;
        case 1:
//            if(active) { clicky_on(); } else { clicky_off(); }
            break;
        case 2:
//            if(active) { music_on(); } else { music_off(); }
            break;
    }
    return true;
}
