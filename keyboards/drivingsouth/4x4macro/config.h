/*
Copyright 2021 Kyle McCreery

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6D77 // mw = "MechWild"
#define PRODUCT_ID      0x1709
#define DEVICE_VER      0x0101
#define MANUFACTURER    DrvSth
#define PRODUCT         4x4macro

/* key matrix size */
#define MATRIX_ROWS 8	// X
#define MATRIX_COLS 4	// Y

  //#define OLED_ENABLE
#ifdef OLED_ENABLE
#define OLED_DRIVER_ENABLE  // need this to display on OLED
//#define OLED_DRIVER
  //OLED_DISPLAY_128X64 = yes
#define OLED_DISPLAY_128X64
#endif

//#define EEPROM_I2C_24LC64

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { A7, A6, A5, A4 }
#define MATRIX_COL_PINS { A3, A2, A1, A0 }
#define UNUSED_PINS

/* encoder pins */
//#define ENCODERS_PAD_A { A3 }
//#define ENCODERS_PAD_B { A2 }

/* encoder resolution */
//#define ENCODER_RESOLUTION 4
//#define TAP_CODE_DELAY 10

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGB settings, uncomment this define to enable RGB */
//#define RGB_DI_PIN A1
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 3
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
*/
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

#define SPLIT_USB_DETECT
//#define MASTER_LEFT
//#define MASTER_RIGHT

#define SEL_F103
//#define SEL_F411

#undef SERIAL_USART_RX_PIN
#ifdef SEL_F103
  #define SOFT_SERIAL_PIN B10  // USART TX ピン for F103
  #define SERIAL_USART_RX_PIN B11	 // for F103
  #define SERIAL_USART_DRIVER SD3  // for F103
#endif

#ifdef SEL_F411
  #define SOFT_SERIAL_PIN B6  // USART TX ピン for F411
  #define SERIAL_USART_RX_PIN B7     // for F411
  #define SERIAL_USART_DRIVER SD1		// for F411
#endif
#define SELECT_SOFT_SERIAL_SPEED 1 // または 0, 2, 3, 4, 5
                                   //  0: 約 460800 ボー
                                   //  1: 約 230400 ボー (デフォルト)
                                   //  2: 約 115200 ボー
                                   //  3: 約 57600 ボー
                                   //  4: 約 38400 ボー
                                   //  5: 約 19200 ボー
//#define SERIAL_USART_DRIVER SD1 // TX ピンの USART ドライバ。デフォルトは SD1
#define SERIAL_USART_TX_PAL_MODE 7 // 「代替機能」 ピン。MCU の適切な値については、それぞれのデータシートを見てください。デフォルトは 7
#define SERIAL_USART_RX_PAL_MODE 7 // 「代替機能」 ピン。MCU の適切な値については、それぞれのデータシートを見てください。デフォルトは 7
//#define USART1_REMAP

/* SERIAL SPLIT DRIVER */
//#undef SERIAL_USART_TX_PIN
//#define SERIAL_USART_TX_PIN B6
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TIMEOUT 5
#define SERIAL_USART_CR2 0x0  // 1 stop bit is enough


