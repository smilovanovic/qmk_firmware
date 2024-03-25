
 /* Copyright 2024 Stefan Milovanovic
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
    {35+22, 3, hsv},\
    {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
    {20, 2, hsv}, \
    {30, 2, hsv}, \
    {35+ 10, 2, hsv}, \
    {35+ 20, 2, hsv}, \
    {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
    {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
    {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
    {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {35+1, 6, hsv}, \
    {7, 4, hsv}, \
    {35+ 7, 4, hsv}, \
    {25, 2, hsv}, \
    {35+ 25, 2, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _COLEMAK,
    _COLEMAKDH,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_COLEMAKDH,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, /* --- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, /* --- */ KC_Y, KC_U, KC_I, KC_O, KC_P, RALT_T(KC_BSLS),
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, /* --- */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOT),
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, /* --- */ KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RCTL_T(KC_EQL),
        // ----------------------------------------------------------------------------------- //
        KC_NO, KC_LALT, KC_LCMD, KC_SPC, LT(_LOWER, KC_ESC), /* --- */ LT(_RAISE, KC_ENT), KC_BSPC, KC_RCMD, KC_NO, KC_NO
    ),
    [_LOWER] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /* --- */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, /* --- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
        KC_LSFT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, /* --- */ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        MO(_NUMPAD), KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_NO, /* --- */ KC_NO, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_PSLS,
        // ----------------------------------------------------------------------------------- //
        KC_NO, KC_LALT, KC_LCMD, KC_SPC, MO(_ADJUST), /* --- */ MO(_ADJUST), LALT(KC_BSPC), LGUI(KC_BSPC), KC_RCTL, KC_NO
    ),
    [_RAISE] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* --- */ LGUI(KC_RGHT), KC_NO, KC_NO, KC_NO, LGUI(KC_LEFT), KC_NO,
        KC_TAB, KC_NO, LALT(KC_RGHT), KC_NO, KC_NO, KC_NO, /* --- */ LGUI(KC_C), KC_NO, LSFT(KC_I), KC_NO, LGUI(KC_V), KC_NO,
        KC_LSFT, LSFT(KC_A), KC_LCTL, LGUI(KC_X), KC_LALT, KC_LCMD, /* --- */ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_LCTL, KC_EQL, KC_NO, KC_NO, KC_NO, LALT(KC_LEFT), /* --- */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // ----------------------------------------------------------------------------------- //
        KC_NO, KC_LALT, KC_LCMD, KC_SPC, MO(_ADJUST), /* --- */ MO(_ADJUST), KC_BSPC, KC_RCMD, KC_RCTL, KC_NO
    ),
    [_ADJUST] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* --- */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, 0x7f, KC_NO, /* --- */ KC_NO, 0x7f, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, 0x81, 0x80, KC_NO, /* --- */ KC_NO, 0x81, 0x80, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, 0x47, 0x48, KC_NO, KC_NO, /* --- */ KC_NO, KC_NO, 0x47, 0x48, KC_NO, KC_NO, KC_NO,
        // ----------------------------------------------------------------------------------- //
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* --- */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    /* NUMPAD
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_NUMPAD] = LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),
    // /*
    //  * QWERTY
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    //  * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
    //  * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  `   |
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | N/A  | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    //   [_QWERTY] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   LT(_NUMPAD,KC_TAB),KC_Q,KC_W,KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_D_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  KC_BSPC, KC_LCMD, KC_LOWER, KC_SPC,  KC_ENT   ,     KC_SPC, KC_ENT ,  KC_RAISE, KC_RCTL, KC_RALT
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    //
    // /*
    //  * COLEMAK
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |LShift|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
    //  * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
    //  * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |LShift|
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    // [_COLEMAK] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      LT(_SWITCH,KC_6),    KC_7,   KC_8,    KC_9,    KC_0,    KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_TRNS,    KC_TRNS,KC_K,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    //
    // /*
    //  * COLEMAK-DH
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
    //  * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
    //  * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    // [_COLEMAKDH] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      LT(_SWITCH,KC_6),    KC_7,   KC_8,    KC_9,    KC_0,    KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_TRNS,    KC_TRNS,KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    //
    // /* LOWER
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
    //  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    //  * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    // [_LOWER] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   _______,  KC_NO,  KC_NO,   KC_NO,   KC_WH_U, KC_PGUP,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_NO,   KC_DEL,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   _______,  KC_NO,  KC_NO,   KC_NO,   KC_WH_D, KC_PGDN,_______,    _______,KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    _______,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    // /* RAISE
    //  * ,----------------------------------------.                    ,-----------------------------------------.
    //  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
    //  * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
    //  * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    // [_RAISE] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   _______, _______ , _______ , _______ , _______ , _______,               _______,  _______  , _______,  _______ ,  _______ ,_______,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,_______,    _______,KC_UNDS, KC_PLUS,KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    // /* ADJUST
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|desk <|      |      |desk >|      |      |
    //  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    //  * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    //   [_ADJUST] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   QK_BOOT, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, KC_COLEMAKDH,KC_COLEMAK,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, XXXXXXX,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX,KC_QWERTY,XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //     //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
    //
    // /* SWITCH
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
    //  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    //  * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    //   // layer switcher
    // [_SWITCH] = LAYOUT(
    //   //,------------------------------------------------.                    ,---------------------------------------------------.
    //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
    //   //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    //   KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //   KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //   //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    //   //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    //
    // 	),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
	layer_switcher_lights,  // Overrides other layers
	layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        // 'image', 128x44px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x60, 0x30, 0x30,
        0x30, 0x60, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0xc0, 0x60, 0x30, 0x70, 0xe0,
        0xc0, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x60, 0x30, 0x30, 0x30, 0x60, 0xe0, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xe0, 0x60, 0x30, 0x30, 0x30, 0x60, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x0c, 0x0c, 0x98, 0xf8, 0xf0, 0x60, 0x60, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc0, 0xfc, 0x7f, 0x07, 0x01, 0x3f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xe3, 0x60, 0x60, 0x60,
        0x60, 0x60, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03,
        0x03, 0x00, 0x00, 0x00, 0xc3, 0xe3, 0x60, 0x60, 0x60, 0x60, 0x60, 0xff, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x0f, 0x1c, 0x38, 0x70, 0xe0, 0xc0, 0x87, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x7c, 0x7f, 0x0f, 0x06, 0x06, 0x06, 0x06, 0x07, 0x3f, 0x7e, 0x60, 0x00, 0x00, 0x00,
        0x3f, 0x7f, 0x60, 0xc0, 0xe0, 0x7e, 0x7f, 0x00, 0x00, 0x00, 0x0e, 0x7f, 0x7f, 0xe0, 0xc0, 0xc0,
        0x60, 0x30, 0x3f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x60, 0xc0, 0xc0, 0x60, 0x70, 0x3f, 0x7f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3e, 0x7e, 0x60, 0xc0, 0xc0, 0xc0, 0x61, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
     static const char PROGMEM apple_logo[] = {
        149,150,10,
        181,182,0
    };
    static const char PROGMEM arrows[] = {
        27,25,24,26,0
    };
    static const char PROGMEM hearth[] = {
        3,0
    };

    oled_write_P(apple_logo, false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("ATRS"), false);
    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("hjkl"), false);
            oled_write_ln_P(PSTR(""), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        case _RAISE:
            oled_write_ln_P(arrows, false);
            oled_write_ln_P(PSTR(""), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("!@#$"), false);
            oled_write_ln_P(PSTR(""), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("MacOS"), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Nump"), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        case _SWITCH:
            oled_write_ln_P(PSTR("Swit"), false);
            oled_write_ln_P(PSTR(""), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            oled_write_ln_P(PSTR(""), false);
    }

    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_ln_P(PSTR("Tara"), false);
    oled_write_P(PSTR("Nadja"), false);
    oled_write_ln_P(PSTR("Ana"), false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
    oled_write_P(hearth, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
         print_status_narrow();
    } else {
         render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
         if (clockwise) {
             tap_code(0x47);
         } else {
             tap_code(0x48);
         }
    } else if (index == 1) {
         if (clockwise) {
             tap_code(KC_VOLD);
         } else {
             tap_code(KC_VOLU);
         }
    }
    return false;
}

#endif

