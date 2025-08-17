/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
    MAC_VIM,
    WIN_VIM,
    COMPAT,
};

// https://docs.qmk.fm/features/rgblight
#define C_NONEX {0, 0, 0}
#define C_LETTR {13, 128, 255} //13,248,255
#define C_LETT2 {13, 128, 255}
#define C_LAYER {127, 255, 255}
#define C_MODIF {43, 255, 255}
#define C_SPCHL {148, 128, 235}
#define C_CTCHL {43, 255, 255}
#define C_CURSR {21, 255, 255}
#define C_ENTER {169, 255, 255}
#define C_TENKY {43, 127, 255}
#define C_OPERA {0, 255, 255}
#define C_BRAKT {218, 255, 255}
#define C_BLUTH {169, 255, 255}
#define C_LANGE {201, 255, 255}
#define C_FNKEY {85, 255, 255}
#define C_BRIGT { 30, 255, 255}
#define C_MCTRL {148, 255, 255}
#define C_LNPAD {127, 255, 255}
#define C_MEDIA {127, 255, 255}
#define C_BLUTH {169, 255, 255}
#define C_WIRLS { 64, 255, 255}
#define C_QMKSP {0, 255, 255}
#define C_MOUSE {0, 255, 255}
#define C_MOUBT {201, 255, 255}
#define C_WWWNV {180, 255, 255}
#define C_WCTRL {127, 200, 255}
// clang-format off

// Mac

#define KS_MAC_BASE_1   KC_GRV,  KC_1,	  KC_2,    KC_3,    KC_4,    KC_5,	  KC_6,	   KC_7,    KC_8,	 KC_9,	  KC_0,	   KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE
#define CS_MAC_BASE_1   C_SPCHL, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_SPCHL, C_SPCHL, C_CTCHL  /*****/

#define KS_MAC_BASE_2   KC_TAB,  KC_Q,	  KC_W,	   KC_E,    KC_R,    KC_T,    KC_Y,	   KC_U,    KC_I,	 KC_O,	  KC_P,	   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL
#define CS_MAC_BASE_2   C_CTCHL, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL

#define KS_MAC_BASE_3   KC_LCTL, KC_A,    KC_S,	   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(MAC_VIM,KC_SCLN), KC_QUOT, KC_ENT,  KC_HOME
#define CS_MAC_BASE_3   C_MODIF, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LAYER,             C_SPCHL, C_ENTER, C_CTCHL

#define KS_MAC_BASE_4   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,	 KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP
#define CS_MAC_BASE_4   C_MODIF, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_LETT2, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR

#define KS_MAC_BASE_5   KC_ESC, KC_LOPTN, MT(MOD_LGUI,KC_LANGUAGE_2), MT(MOD_LGUI,KC_SPC), KC_SPC,  MO(FN2), KC_LANGUAGE_1,LT(MAC_FN1, KC_LANGUAGE_1), KC_LEFT, KC_DOWN, KC_RGHT
#define CS_MAC_BASE_5   C_CTCHL, C_MODIF, C_LANGE,                    C_MODIF,             C_SPCHL, C_LAYER, C_LANGE, C_LANGE,                    C_CURSR, C_CURSR, C_CURSR

// Windows

#define KS_WIN_BASE_1   KC_GRV,  KC_1,	  KC_2,	   KC_3,	KC_4,    KC_5,    KC_6,	   KC_7,    KC_8,	 KC_9,	  KC_0,	   KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE
#define CS_WIN_BASE_1   C_SPCHL, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_TENKY, C_SPCHL, C_SPCHL, C_CTCHL  /*****/

#define KS_WIN_BASE_2   KC_TAB,  KC_Q,	   KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,	   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL
#define CS_WIN_BASE_2   C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL

#define KS_WIN_BASE_3   MO(COMPAT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,	   KC_K,    KC_L,    LT(WIN_VIM,KC_SCLN), KC_QUOT, KC_ENT,  KC_HOME
#define CS_WIN_BASE_3   C_LAYER,    C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER,             C_SPCHL, C_ENTER, C_CTCHL

#define KS_WIN_BASE_4   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP
#define CS_WIN_BASE_4   C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR

#define KS_WIN_BASE_5   KC_ESC , KC_LALT, MT(MOD_LGUI,KC_LANGUAGE_2), MT(MOD_LCTL,KC_SPC),KC_SPC,  MO(FN2), KC_LANGUAGE_1, LT(WIN_FN1, KC_LANGUAGE_1), KC_LEFT, KC_DOWN, KC_RGHT
#define CS_WIN_BASE_5   C_CTCHL, C_MODIF, C_LANGE,               C_MODIF,            C_SPCHL, C_LAYER, C_LANGE,  C_LANGE,               C_CURSR, C_CURSR, C_CURSR

// Mac FN1

#define KS_MAC_FN1_1    _______, KC_BRID, KC_BRIU, KC_MCTRL, KC_LNPAD, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, RGB_TOG
#define CS_MAC_FN1_1    C_NONEX, C_BRIGT, C_BRIGT, C_MCTRL,  C_LNPAD,  C_NONEX, C_NONEX, C_MEDIA, C_MEDIA, C_MEDIA, C_NONEX, C_NONEX, C_NONEX, C_NONEX  /******/

#define KS_MAC_FN1_2    _______, BT_HST1, BT_HST2, BT_HST3, P2P4G,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS
#define CS_MAC_FN1_2    C_NONEX, C_BLUTH, C_BLUTH, C_BLUTH, C_WIRLS, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_MAC_FN1_3    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END
#define CS_MAC_FN1_3    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_MAC_FN1_4    _______, _______, _______, _______, _______, _______, S(C(G(KC_4))), NK_TOGG, _______, _______, _______, _______, _______, KC_PGUP
#define CS_MAC_FN1_4    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL,       C_LETTR, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_MAC_FN1_5    _______, _______, G(KC_SPC), _______, _______, _______, _______, _______, _______, KC_PGDN, _______
#define CS_MAC_FN1_5    C_NONEX, C_NONEX, C_CTCHL, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL, C_NONEX

// Windows FN1

#define KS_WIN_FN1_1    _______, KC_BRID, KC_BRIU, KC_TASK, KC_FILE, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, RGB_TOG
#define CS_WIN_FN1_1    C_SPCHL, C_BRIGT, C_BRIGT, C_MCTRL, C_LNPAD, C_NONEX, C_NONEX, C_MEDIA, C_MEDIA, C_MEDIA, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_WIN_FN1_2    _______, BT_HST1, BT_HST2, BT_HST3, P2P4G,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS
#define CS_WIN_FN1_2    C_CTCHL, C_BLUTH, C_BLUTH, C_BLUTH, C_WIRLS, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_WIN_FN1_3    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END
#define CS_WIN_FN1_3    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_WIN_FN1_4    _______, _______, _______, _______, _______, _______, KC_PSCR, NK_TOGG, _______, _______, _______, _______, _______, KC_PGUP
#define CS_WIN_FN1_4    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL, C_LETTR, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL

#define KS_WIN_FN1_5    _______, _______, KC_LEFT_GUI, _______, _______, _______, _______, _______, _______, KC_PGDN, _______
#define CS_WIN_FN1_5    C_NONEX, C_NONEX, C_MODIF,     C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_CTCHL, C_NONEX

// FN2

#define KS_FN2_1        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______, _______
#define CS_FN2_1        C_SPCHL, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_FNKEY, C_NONEX  /*****/

#define KS_FN2_2        _______, _______, _______, _______, _______, KC_DQUO, KC_EQUAL, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______
#define CS_FN2_2        C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_SPCHL,  C_TENKY, C_TENKY, C_TENKY, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_FN2_3        KC_LCTL, KC_LABK, KC_LPRN, KC_RPRN, KC_RABK, KC_PIPE, KC_MINUS, KC_4,    KC_5,    KC_6,    KC_MINS, _______, _______, _______
#define CS_FN2_3        C_LAYER, C_SPCHL, C_BRAKT, C_BRAKT, C_SPCHL, C_SPCHL, C_OPERA,  C_TENKY, C_TENKY, C_TENKY, C_OPERA, C_NONEX, C_NONEX, C_NONEX

#define KS_FN2_4        _______, KC_MINUS, KC_LCBR, KC_RCBR, KC_PLUS, KC_QUOT, _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_COMM, _______
#define CS_FN2_4        C_NONEX, C_OPERA,  C_BRAKT, C_BRAKT, C_OPERA, C_NONEX, C_NONEX, C_OPERA, C_TENKY, C_TENKY, C_TENKY, C_OPERA, C_SPCHL, C_NONEX

#define KS_FN2_5        _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_0,    KC_DOT,  _______, _______, _______
#define CS_FN2_5        C_NONEX, C_NONEX, C_BRAKT, C_BRAKT, C_NONEX, C_NONEX, C_TENKY, C_TENKY, C_NONEX, C_NONEX, C_NONEX


// Mac Vim cursor and mouse movement

#define KS_MAC_VIM_1    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______
#define CS_MAC_VIM_1    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_QMKSP  /*****/

#define KS_MAC_VIM_2    _______, _______, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, _______, _______, KC_PGDN, KC_PAGE_UP, _______, _______, _______, _______, _______, _______
#define CS_MAC_VIM_2    C_NONEX, C_NONEX, C_MOUBT,       C_MOUSE,  C_MOUBT,        C_NONEX, C_NONEX, C_CTCHL, C_CTCHL,    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_MAC_VIM_3    _______, KC_MS_WH_UP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, _______, _______
#define CS_MAC_VIM_3    C_NONEX, C_MOUBT,     C_MOUSE,    C_MOUSE,    C_MOUSE,     C_NONEX, C_CURSR, C_CURSR, C_CURSR, C_CURSR,  C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_MAC_VIM_4    _______, KC_MS_WH_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define CS_MAC_VIM_4    C_NONEX, C_MOUBT,       C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_MAC_VIM_5    _______, _______, KC_MS_BTN2, KC_MS_BTN1, _______, RCMD(KC_LEFT), RCMD(KC_RIGHT), _______, _______, _______, KC_SYSTEM_SLEEP
#define CS_MAC_VIM_5    C_NONEX, C_NONEX, C_MOUBT,    C_MOUBT,    C_NONEX, C_WWWNV,       C_WWWNV,        C_NONEX, C_NONEX, C_NONEX, C_QMKSP

// Windows Vim cursor and mouse movement

#define KS_WIN_VIM_1    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______
#define CS_WIN_VIM_1    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_QMKSP

#define KS_WIN_VIM_2    _______, _______, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, _______, _______, KC_PGDN, KC_PAGE_UP, _______, _______, _______, _______, _______, _______
#define CS_WIN_VIM_2    C_NONEX, C_NONEX, C_MOUBT,       C_MOUSE,  C_MOUBT,        C_NONEX, C_NONEX, C_CTCHL, C_CTCHL,    C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_WIN_VIM_3    _______, KC_MS_WH_UP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, _______, _______
#define CS_WIN_VIM_3    C_NONEX, C_MOUBT,     C_MOUSE,    C_MOUSE,    C_MOUSE,     C_NONEX, C_CURSR, C_CURSR, C_CURSR, C_CURSR,  C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_WIN_VIM_4    _______, KC_MS_WH_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define CS_WIN_VIM_4    C_NONEX, C_MOUBT,       C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX

#define KS_WIN_VIM_5    _______, _______, KC_MS_BTN2, KC_MS_BTN1, _______, RALT(KC_LEFT), RALT(KC_RIGHT), _______, _______, _______, KC_SYSTEM_SLEEP
#define CS_WIN_VIM_5    C_NONEX, C_NONEX, C_MOUBT,    C_MOUBT,    C_NONEX, C_WWWNV,       C_WWWNV,        C_NONEX, C_NONEX, C_NONEX, C_QMKSP

// Emacs cursor move compatibility

#define KS_COMPAT_1    LCTL(KC_GRAVE), LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0),  LCTL(KC_MINS), LCTL(KC_EQL),  LCTL(KC_BSPC), _______
#define CS_COMPAT_1    C_WCTRL,        C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,     C_WCTRL,       C_WCTRL,       C_WCTRL       /******/

#define KS_COMPAT_2    LCTL(KC_TAB), LCTL(KC_Q), LCTL(KC_W), KC_END,  LCTL(KC_R), LCTL(KC_T), LCTL(KC_Y), LCTL(KC_U), LCTL(KC_I), LCTL(KC_O), KC_UP,   LCTL(KC_LBRC), LCTL(KC_RBRC), LCTL(KC_BSLS), LCTL(KC_DEL)
#define CS_COMPAT_2    C_WCTRL,      C_WCTRL,    C_WCTRL,    C_CTCHL, C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_CURSR, C_WCTRL,       C_WCTRL,       C_WCTRL,       C_WCTRL

#define KS_COMPAT_3    _______, KC_HOME, LCTL(KC_S), KC_DELETE, KC_RIGHT, LCTL(KC_G), KC_BSPC, KC_ENTER, LCTL(KC_K), LCTL(KC_L), LCTL(KC_SCLN), LCTL(KC_QUOT), LCTL(KC_ENT), LCTL(KC_HOME)
#define CS_COMPAT_3    C_LAYER, C_CTCHL, C_WCTRL,    C_CTCHL,   C_CURSR,  C_WCTRL,    C_CTCHL, C_ENTER,  C_WCTRL,    C_WCTRL,    C_WCTRL,       C_WCTRL,       C_WCTRL,      C_WCTRL

#define KS_COMPAT_4    LCTL(KC_LSFT), LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_LEFT, KC_LEFT, KC_DOWN, KC_ENTER, LCTL(KC_COMM), LCTL(KC_DOT),  LCTL(KC_SLSH), LCTL(KC_RSFT), LCTL(KC_UP)
#define CS_COMPAT_4    C_WCTRL,       C_WCTRL,    C_WCTRL,    C_WCTRL,    C_WCTRL,    C_CURSR, C_CURSR, C_CURSR, C_ENTER,  C_WCTRL,       C_WCTRL,       C_WCTRL,       C_WCTRL,       C_WCTRL

#define KS_COMPAT_5    _______, _______, KC_LWIN, _______, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT)
#define CS_COMPAT_5    C_NONEX, C_NONEX, C_MODIF, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_NONEX, C_WCTRL,       C_WCTRL,       C_WCTRL

// clang-format on

#define LAYOUT(...) LAYOUT_69_ansi(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(KS_MAC_BASE_1, KS_MAC_BASE_2, KS_MAC_BASE_3, KS_MAC_BASE_4, KS_MAC_BASE_5),

    [WIN_BASE] = LAYOUT(KS_WIN_BASE_1, KS_WIN_BASE_2, KS_WIN_BASE_3, KS_WIN_BASE_4, KS_WIN_BASE_5),

    [MAC_FN1] = LAYOUT(KS_MAC_FN1_1, KS_MAC_FN1_2, KS_MAC_FN1_3, KS_MAC_FN1_4, KS_MAC_FN1_5),

    [WIN_FN1] = LAYOUT(KS_WIN_FN1_1, KS_WIN_FN1_2, KS_WIN_FN1_3, KS_WIN_FN1_4, KS_WIN_FN1_5),

    [FN2] = LAYOUT(KS_FN2_1, KS_FN2_2, KS_FN2_3, KS_FN2_4, KS_FN2_5),

    [MAC_VIM] = LAYOUT(KS_MAC_VIM_1, KS_MAC_VIM_2, KS_MAC_VIM_3, KS_MAC_VIM_4, KS_MAC_VIM_5),

    [WIN_VIM] = LAYOUT(KS_WIN_VIM_1, KS_WIN_VIM_2, KS_WIN_VIM_3, KS_WIN_VIM_4, KS_WIN_VIM_5),

    [COMPAT] = LAYOUT(KS_COMPAT_1, KS_COMPAT_2, KS_COMPAT_3, KS_COMPAT_4, KS_COMPAT_5),

    // [WIN_VIM] = LAYOUT_69_ansi(
    //     _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, _______,  _______,  _______, _______, _______, /******/  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, /******/  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______, /******/
    //     _______, _______,  _______,  /******/ _______, /******/ _______,  _______, /******/ _______, /******/  _______,  /******/  _______, _______, _______,
    // )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},

    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},

    [MAC_FN1] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},

    [WIN_FN1] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},

    [FN2] = {ENCODER_CCW_CW(_______, _______)},

    [MAC_VIM] = {ENCODER_CCW_CW(_______, _______)},

    [WIN_VIM] = {ENCODER_CCW_CW(_______, _______)},

    [COMPAT] = {ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// RGB

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [MAC_BASE] = {CS_MAC_BASE_1, CS_MAC_BASE_2, CS_MAC_BASE_3, CS_MAC_BASE_4, CS_MAC_BASE_5},

    [WIN_BASE] = {CS_WIN_BASE_1, CS_WIN_BASE_2, CS_WIN_BASE_3, CS_WIN_BASE_4, CS_WIN_BASE_5},

    [MAC_FN1] = {CS_MAC_FN1_1, CS_MAC_FN1_2, CS_MAC_FN1_3, CS_MAC_FN1_4, CS_MAC_FN1_5},

    [WIN_FN1] = {CS_WIN_FN1_1, CS_WIN_FN1_2, CS_WIN_FN1_3, CS_WIN_FN1_4, CS_WIN_FN1_5},

    [FN2] = {CS_FN2_1, CS_FN2_2, CS_FN2_3, CS_FN2_4, CS_FN2_5},

    [MAC_VIM] = {CS_MAC_VIM_1, CS_MAC_VIM_2, CS_MAC_VIM_3, CS_MAC_VIM_4, CS_MAC_VIM_5},

    [WIN_VIM] = {CS_WIN_VIM_1, CS_WIN_VIM_2, CS_WIN_VIM_3, CS_WIN_VIM_4, CS_WIN_VIM_5},

    [COMPAT] = {CS_COMPAT_1, CS_COMPAT_2, CS_COMPAT_3, CS_COMPAT_4, CS_COMPAT_5},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case MAC_BASE:
            set_layer_color(MAC_BASE);
            break;
        case WIN_BASE:
            set_layer_color(WIN_BASE);
            break;
        case MAC_FN1:
            set_layer_color(MAC_FN1);
            break;
        case WIN_FN1:
            set_layer_color(WIN_FN1);
            break;
        case FN2:
            set_layer_color(FN2);
            break;
        case WIN_VIM:
            set_layer_color(WIN_VIM);
            break;
        case MAC_VIM:
            set_layer_color(MAC_VIM);
            break;
        case COMPAT:
            set_layer_color(COMPAT);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}