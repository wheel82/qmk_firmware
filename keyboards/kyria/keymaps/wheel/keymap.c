/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// Key-Layer Toggles
// #define BSPCLWR LT(LOWER, KC_BSPC)
// #define BSPCRSE LT(RAISE, KC_BSPC)
#define BSPCNAV LT(NAV, KC_BSPC)
// #define ENTLWR LT(LOWER, KC_ENT)
// #define ENTRSE LT(RAISE, KC_ENT)
#define ENTNAV LT(NAV, KC_ENT)
// #define SPCLWR LT(LOWER, KC_SPC)
 #define SPCRSE LT(RAISE, KC_SPC)
// #define SPCNAV LT(NAV, KC_SPC)
// #define TABRSE LT(RAISE, KC_TAB)

// Mod-Key Toggles
// #define BSPCALT MT(MOD_LALT, KC_BSPC)
#define CTRLESC MT(MOD_LCTL, KC_ESC)
// #define DELLALT MT(MOD_LALT, KC_DEL)
// #define DELRALT MT(MOD_RALT, KC_DEL)
// #define ENTLALT MT(MOD_LALT, KC_ENT)
// #define ENTRALT MT(MOD_RALT, KC_ENT)
// #define LSFTESC MT(MOD_LSFT, KC_ESC)
#define RSFTEQL MT(MOD_RSFT, KC_EQL)
// #define RSFTMIN MT(MOD_RSFT, KC_MINS)
// #define SPCLALT MT(MOD_LALT, KC_SPC)
#define TABLALT MT(MOD_LALT, KC_TAB)
#define TABRALT MT(MOD_RALT, KC_TAB)

// Single Key Shortcuts
// #define RUNPRMT RGUI(KC_R)
// #define SCRNSHT RGUI(S(KC_S))
// #define UNDO RCTL(KC_Z)
// #define REDO RCTL(KC_Y)


enum layers {
    QWERTY = 0,
    LOWER,
    RAISE,
    NAV,
    ADJUST
};

enum custom_keycodes {
    KC_CVZY = SAFE_RANGE, // hold-copy/paste; shifted hold-redo/undo
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      | CCCV |  |Leader| RGUI |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------'
 *                        |  DEL | Tab  |      | Bspc | Enter|  | Bspc | Space|      | Tab  |  DEL |
 *                        |      | ALT  | LOWER|      | NAV  |  | NAV  |      | RAISE| ALT  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      CTRLESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_DEL, KC_CVZY,     KC_LEAD, KC_DEL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       KC_LGUI,TABLALT,MO(LOWER), KC_BSPC, ENTNAV,        BSPCNAV, KC_SPC, MO(RAISE), TABRALT, KC_RGUI
    ),
/*
 * Lower Layer: Numpad, Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | NumLck |  / ? |  7 &  | 8 *  | 9 ( |      |                              |      | F9   | F10  | F11  | F12  | Pause  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   *  |  4 $  | 5 %  | 6 ^ |      |                              |      | F5   | F6   | F7   | F8   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  0 ) |  1 !  | 2 @  | 3 # |      |      |      |  |      |      |      | F1   | F2   | F3   | F4   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | . >  |  0 ) |      |      |      |  |      |      |      |      |      |
 *                        |      |      | LOWER|      |PrtScr|  |      |      | RAISE|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LOWER] = LAYOUT(
      KC_NLCK, KC_SLSH, KC_7,  KC_8,   KC_9,   KC_MINS,                                      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS,
      _______, KC_ASTR, KC_4,  KC_5,   KC_6,   KC_PLUS,                                      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
      _______, KC_0,    KC_1,  KC_2,   KC_3,   KC_EQL, _______, _______,   _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
                        KC_DOT,KC_0,MO(LOWER), KC_SPC, KC_PSCR,            _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  ~   |  @   |  {   |  }   |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  `   |  $   |  (   |  )   |  !   |                              |   &  |  -   |  +   |  =   |  %   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  ^   |  [   |  ]   |  #   |      |      |  |      |      |   |  |  _   |  /   |  *   |  %   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | LOWER|      |      |  |      |      | RAISE|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RAISE] = LAYOUT(
      _______, KC_TILD, KC_AT,   KC_LCBR, KC_RCBR, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_GRV,  KC_DLR,  KC_LPRN, KC_RPRN, KC_EXLM,                                     KC_AMPR, KC_MINS, KC_PLUS, KC_EQL,  _______, _______,
      _______, _______, KC_CIRC, KC_LBRC, KC_RBRC, KC_HASH, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_SLSH, KC_ASTR, KC_PERC, _______,
                                 _______, _______, _______, _______, _______, _______, _______, MO(RAISE), _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | ACL2 | WH_L | MS_U | WH_R | WH_U |                              | PgUp | Home | Up   | End  |      | ScrlLk |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | ACL1 | MS_L | MS_D | MS_R | WH_D |                              | PgDn | Left | Down | Right|      | CapsLk |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ACL0 | BTN1 | BTN3 | BTN2 |      |      |      |  |      |      |      |      |      |      |      | Insert |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | LOWER|      | NAV  |  | NAV  |      | RAISE|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NAV] = LAYOUT(
      _______, KC_ACL2, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_SLCK,
      _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_CAPS,
      _______, KC_ACL0, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |  VOL+  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | SAI  | HUI  | VAI  |      |                              |      | Prev | Play | Next |      |  VOL-  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  |      |      |      |  |      |      |      |      |      |      |      |  MUTE  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | LOWER|      |      |  |      |      | RAISE|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,  KC_VOLU,
      _______, _______, RGB_SAI, RGB_HUI, RGB_VAI, _______,                                     _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  KC_VOLD,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MUTE,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

uint16_t cvzy_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) 
    {
        case KC_CVZY: // hold-copy/paste; shifted hold-redo/undo
            if (record->event.pressed) 
            {
                cvzy_timer = timer_read();
            }
            else
            {
                // if shift key is pressed, do undo/redo
                if ((get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) != 0)
                {
                    bool is_shift_left = false;
                    bool is_shift_right = false;

                    // detect and unregister the shift key pressed for undo/redo to only be ctrl + key
                    if (get_mods() & MOD_BIT(KC_LSFT))
                    {
                        is_shift_left = true;
                        unregister_mods(MOD_BIT(KC_LSFT));
                    }
                    
                    if (get_mods() & MOD_BIT(KC_RSFT))
                    {
                        is_shift_right = true;
                        unregister_mods(MOD_BIT(KC_RSFT));
                    }

                    if (timer_elapsed(cvzy_timer) > TAPPING_TERM)
                    {
                        tap_code16(LCTL(KC_Y));
                    }
                    else 
                    {
                        tap_code16(LCTL(KC_Z));
                    }
                    
                    // register shift key again
                    if (is_shift_left)
                    {
                        register_mods(MOD_BIT(KC_LSFT));
                    }
                    
                    if (is_shift_right)
                    {
                        register_mods(MOD_BIT(KC_RSFT));
                    }
                }
                else
                {
                    if (timer_elapsed(cvzy_timer) > TAPPING_TERM) 
                    {  
                        // Hold, copy
                        tap_code16(LCTL(KC_C));
                    }
                    else 
                    { // Tap, paste
                        tap_code16(LCTL(KC_V));
                    }
                }
            }

            break;
    }

    return true;
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_R) { // Run
            SEND_STRING(SS_LGUI("r"));
        }  
        SEQ_TWO_KEYS(KC_S, KC_S) { // Windows screenshot  
            SEND_STRING(SS_RGUI("\nS"));
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
char wpm[10];
bool is_bowser_active = true;
uint16_t image_timer = 0;
uint16_t wpm_timer = 0;
uint32_t anim_sleep = 0;

#define IMAGE_TIMEOUT 20000 // 20 sec
#define WPM_TIMEOUT 2000 // 2 sec

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    image_timer = IMAGE_TIMEOUT;
    wpm_timer = WPM_TIMEOUT;

	return OLED_ROTATION_180;
}

static void render_bowser(void) {
    static const char PROGMEM bowser_logo[] = {
// 'bowser_sm', 128x64px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 
0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xfc, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x7f, 0x2f, 0x0f, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 
0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0x68, 0xf0, 0xf0, 0xf8, 0xf8, 
0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf8, 0xf8, 0xe0, 0xc0, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x37, 0x0f, 0x03, 0x00, 0x00, 0x01, 0x0d, 0x06, 0x07, 0x21, 0x3b, 0x7f, 0x7f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfb, 0xc7, 0x83, 0xc3, 0xc3, 0xc7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf3, 0xe3, 0xe3, 0xe3, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf2, 0xfa, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x17, 0x1f, 
0x5f, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 
0x1f, 0x1f, 0x1f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4f, 0x1f, 0x0f, 0x77, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x03, 0x07, 0x01, 0x0e, 0x36, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x08, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x0f, 0x03, 0x1f, 0x07, 0x0f, 
0xbf, 0xb9, 0xf8, 0xf0, 0xf0, 0xf8, 0xf0, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0x1f, 0x03, 0x00, 0x00, 0x12, 0x70, 0xf0, 0xc0, 0x88, 0x03, 0x07, 0x0f, 0x0b, 
0x17, 0x07, 0x1f, 0x27, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 
0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x70, 0x7e, 0x0f, 
0x07, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x80, 0xa0, 0xf8, 0x7c, 0xaf, 0xfb, 0x7b, 0x07, 0x3f, 0x3b, 
0x6d, 0x0b, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x67, 0x0f, 0x0e, 0xfc, 0xf8, 
0xc0, 0xc3, 0x84, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x1f, 0x11, 0x11, 0x1b, 0x0e, 0x00, 0x0f, 0x19, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x1f, 
0x1e, 0x07, 0x1e, 0x1f, 0x01, 0x00, 0x13, 0x12, 0x16, 0x1c, 0x00, 0x00, 0x0f, 0x1a, 0x12, 0x12, 
0x13, 0x00, 0x00, 0x10, 0x1f, 0x11, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x21, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe0, 0xe0, 0xfa, 0x1e, 0x3c, 0xcd, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
0x03, 0x1b, 0x1f, 0x3f, 0x73, 0x22, 0x1c, 0x28, 0x60, 0x40, 0x40, 0x00, 0x01, 0x03, 0x03, 0x07
    };
    oled_write_raw_P(bowser_logo, sizeof(bowser_logo));
}


static void render_mabel(void) {
    static const char PROGMEM mabel_logo[] = {
// 'mabel', 128x64px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xe0, 0xe0, 
0xc0, 0xe0, 0xf0, 0x60, 0xb0, 0x50, 0xd0, 0xf8, 0xd8, 0xf8, 0xfc, 0xbe, 0x56, 0xae, 0x5e, 0xae, 
0x52, 0x2c, 0x14, 0x2e, 0xbc, 0x7c, 0xbc, 0x78, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x00, 0x00, 
0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x40, 0x00, 0x20, 0x00, 0xc0, 0xe0, 0xf0, 0xb0, 0xb0, 0x30, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x50, 0xd7, 0xf7, 0x7e, 0xa8, 0x11, 
0xa2, 0xc1, 0xaa, 0xd4, 0xba, 0x5d, 0xfe, 0xfe, 0xfe, 0xbf, 0x5f, 0xbe, 0x5d, 0xfe, 0xff, 0xfe, 
0xfa, 0xf4, 0xfa, 0xf5, 0x7a, 0x7d, 0x7e, 0x7f, 0x2f, 0x3f, 0x27, 0x77, 0x7a, 0xc8, 0x8c, 0x04, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x08, 0x19, 0x13, 0x22, 0x44, 0xcc, 0x88, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x0f, 
0x0e, 0x0f, 0x16, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xfb, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xfb, 0x5f, 
0x3c, 0xbf, 0x6b, 0xcf, 0xc2, 0xc0, 0xe0, 0x60, 0x29, 0x31, 0x1f, 0x0c, 0x0c, 0x0c, 0x0f, 0x03, 
0x00, 0x00, 0xc0, 0xf8, 0x7e, 0x3f, 0x4f, 0xed, 0x3f, 0x1f, 0x0f, 0x06, 0x02, 0x02, 0x02, 0x03, 
0x03, 0x0f, 0x0d, 0x1b, 0x1e, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x88, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfa, 0xf7, 0xef, 0xf3, 0xf7, 0xff, 0xff, 
0xbf, 0x7f, 0xaf, 0x57, 0xab, 0xd5, 0xbf, 0xf8, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xf8, 0xff, 0xff, 0xf0, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
0x06, 0x0c, 0x30, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 
0x60, 0x70, 0xc0, 0x80, 0x80, 0x80, 0xe0, 0xff, 0xff, 0x7f, 0x71, 0x39, 0x7b, 0x7f, 0x77, 0x7f, 
0x3e, 0x3d, 0x3f, 0x1f, 0x9f, 0x8f, 0xc7, 0x43, 0xf1, 0x53, 0xfc, 0xb8, 0x70, 0xe0, 0xe0, 0xf0, 
0xf0, 0xff, 0xbe, 0x7f, 0xbf, 0x7b, 0xff, 0xfe, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06, 
0x0c, 0x0c, 0x06, 0x03, 0x03, 0xe3, 0xff, 0xff, 0x6f, 0xff, 0xfe, 0x5e, 0xb6, 0x4a, 0x0e, 0x16, 
0x8a, 0x43, 0x8b, 0xd7, 0xeb, 0xd1, 0xa2, 0x40, 0xc8, 0x31, 0xaa, 0x54, 0xab, 0x05, 0x0a, 0x10, 
0x0a, 0x94, 0x03, 0x05, 0x2a, 0x45, 0x2f, 0x57, 0xaf, 0x3f, 0xfb, 0xff, 0xfe, 0xfc, 0xf0, 0xe0, 
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf0, 
0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xf0, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x40, 
0xc0, 0xc0, 0x80, 0x00, 0x00, 0xfc, 0xfe, 0x9c, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x80, 0xc0, 
0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xf7, 0xaf, 0x97, 0xef, 0x16, 0x42, 0x85, 0x40, 0x25, 
0x8a, 0x7c, 0xff, 0xff, 0xfd, 0xff, 0xfe, 0xfd, 0xd7, 0x2b, 0xd4, 0xf9, 0xf2, 0xe4, 0xe8, 0x94, 
0xa0, 0x50, 0xa8, 0x50, 0xaa, 0xd5, 0xe2, 0xc5, 0xe2, 0xd7, 0xed, 0xda, 0x3d, 0xff, 0xfb, 0xdf, 
0xff, 0x36, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 
0x00, 0x03, 0x07, 0x06, 0x03, 0x01, 0x00, 0x01, 0x3f, 0x3f, 0x00, 0x0f, 0x1f, 0x18, 0x10, 0x18, 
0x0c, 0x07, 0x1f, 0x1c, 0x00, 0x1f, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, 
0x14, 0x14, 0x14, 0x17, 0x12, 0x00, 0x1f, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xfe, 0xf7, 0xfd, 0xf7, 0xff, 0x7f, 0xbf, 0x5f, 0xbf, 0x7f, 0xfd, 0xfe, 0x3c, 0xbf, 
0x5f, 0x2f, 0x17, 0x0b, 0x17, 0x29, 0x57, 0xaf, 0x7f, 0xff, 0xff, 0xdf, 0x3f, 0xce, 0x07, 0xff, 
0xff, 0xff, 0xfe, 0xef, 0x57, 0xad, 0x5a, 0x0f, 0x03, 0x03, 0x01, 0x03, 0x03, 0x0f, 0x1f, 0x3f, 
0x06, 0xd8, 0x10, 0x03, 0x46, 0x8c, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(mabel_logo, sizeof(mabel_logo));
}

static void render_anim(void)
{
    if (timer_elapsed(image_timer) >= IMAGE_TIMEOUT)
    {
        image_timer = timer_read();

        if (is_bowser_active)
        {
            render_bowser();
            is_bowser_active = !is_bowser_active;
        }
        else
        {
            render_mabel();
            is_bowser_active = !is_bowser_active;
        }
    }
}

static void render_wpm(void)
{
    if (timer_elapsed(wpm_timer) >= WPM_TIMEOUT)
    {
        sprintf(wpm, "WPM: %03d\n", get_current_wpm());
        
        wpm_timer = timer_read();
    }

    oled_write(wpm, false);
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.3\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    render_wpm();

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) 
{
    if (is_keyboard_master()) 
    {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } 
    else
    {
        if (get_current_wpm() != 000) 
        {
            oled_on();
            render_anim();

            anim_sleep = timer_read32();
        }
        else
        {
            if (timer_elapsed32(anim_sleep) >= OLED_TIMEOUT)
            {
                oled_off();
                image_timer = IMAGE_TIMEOUT;
            }
            else
            {
                render_anim();
            }
        }

        // render_bowser();
    }
}
#endif
