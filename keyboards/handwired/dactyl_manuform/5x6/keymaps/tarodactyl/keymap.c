/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAKDH 1
#define _LOWER 2
#define _RAISE 3
#define _NAVIG 4
#define _ADJUST 5

// Layer Toggles
#define COLMKDH TG(_COLEMAKDH)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAVIG MO(_NAVIG)
#define ADJUST MO(_ADJUST)

// Key-Layer Toggles
#define BSPCLWR LT(_LOWER, KC_BSPC)
#define BSPCRSE LT(_RAISE, KC_BSPC)
#define BSPCNAV LT(_NAVIG, KC_BSPC)
#define ENTLWR LT(_LOWER, KC_ENT)
#define ENTRSE LT(_RAISE, KC_ENT)
#define ENTNAV LT(_NAVIG, KC_ENT)
#define SPCLWR LT(_LOWER, KC_SPC)
#define SPCRSE LT(_RAISE, KC_SPC)
#define SPCNAV LT(_NAVIG, KC_SPC)
#define TABRSE LT(_RAISE, KC_TAB)

// Mod-Key Toggles
#define BSPCALT MT(MOD_LALT, KC_BSPC)
#define CTRLESC MT(MOD_LCTL, KC_ESC)
#define DELLALT MT(MOD_LALT, KC_DEL)
#define DELRALT MT(MOD_RALT, KC_DEL)
#define ENTLALT MT(MOD_LALT, KC_ENT)
#define ENTRALT MT(MOD_RALT, KC_ENT)
#define SPCLALT MT(MOD_LALT, KC_SPC)
#define TABRALT MT(MOD_RALT, KC_TAB)

uint16_t copy_paste_timer;

enum custom_keycodes {
    KC_CVZY = SAFE_RANGE // hold-copy/paste; shifted hold-redo/undo
};


// Single Key Shortcuts
#define RUNPRMT RGUI(KC_R)
#define SCRNSHT RGUI(S(KC_S))
#define UNDO RCTL(KC_Z)
#define REDO RCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_GESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
     CTRLESC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                     KC_CVZY, KC_EQL,                                                        KC_MINS,SCRNSHT,
                                     LOWER,  KC_BSPC,                        KC_SPC, RAISE,
                                     KC_DEL, ENTNAV,                         BSPCNAV,KC_DEL,
                                     KC_LGUI,ADJUST,                         KC_DEL, RUNPRMT
  ),

  [_COLEMAKDH] = LAYOUT_5x6(
     KC_GESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , _______,
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
     CTRLESC, KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                         KC_M  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                         KC_K  , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                     KC_CVZY, KC_EQL,                                                        KC_MINS,SCRNSHT,
                                     LOWER,  KC_BSPC,                        KC_SPC, TABRSE,
                                     NAVIG,  ENTLALT,                        DELRALT,NAVIG,
                                     KC_LGUI,ADJUST,                         KC_DEL, RUNPRMT
  ),
//------------------------------------------------------------------------------------------------------------------------------ 
  // LOWER: Numpad, Function Keys
  [_LOWER] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     KC_NLCK,KC_SLSH,KC_7,   KC_8,   KC_9,   KC_MINS,                        _______,KC_F9,  KC_F10, KC_F11, KC_F12, KC_PAUS,
     _______,KC_ASTR,KC_4,   KC_5,   KC_6,   KC_PLUS,                        _______,KC_F5,  KC_F6,  KC_F7,  KC_F8,  _______,
     _______,KC_0,   KC_1,   KC_2,   KC_3,   KC_EQL,                         _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,
                     KC_DOT, KC_0,                                                           _______,_______,
                                     LOWER,  KC_SPC,                         _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,RESET  ,                        KC_PSCR,KC_INS
  ),

  // RAISE Layer: Symbols
  [_RAISE] = LAYOUT_5x6(

     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,KC_TILD, KC_AT,   KC_LCBR, KC_RCBR, _______,                    _______,_______,_______,_______,_______,_______,
     _______,KC_GRV,  KC_DLR,  KC_LPRN, KC_RPRN, KC_EXLM,                    KC_AMPR, KC_MINS, KC_PLUS, KC_EQL,  _______,_______,
     _______,_______, KC_CIRC, KC_LBRC, KC_RBRC, KC_HASH,                    KC_PIPE, KC_UNDS, KC_SLSH, KC_ASTR, KC_PERC,_______,
                     _______,_______,                                                        _______,_______,
                                     _______,_______,                        _______,RAISE,
                                     _______,_______,                        _______,_______,
                                     _______,KC_PAUS,                        RESET,  _______

  ),
  
  // NAVIG Layer: Mouse, Arrows, Home/End, Page Up/Down, SLCK
  [_NAVIG] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,KC_ACL2,KC_WH_L,KC_MS_U,KC_WH_R,KC_WH_U,                        KC_PGUP,KC_HOME, KC_UP ,KC_END ,_______,KC_SLCK,
     _______,KC_ACL1,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,_______,KC_CAPS,
     _______,KC_ACL0,KC_BTN1,KC_BTN3,KC_BTN2,_______,                        _______,_______,_______,_______,_______,KC_INS,
                     _______,_______,                                                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     KC_BTN5,KC_BTN4,                        _______,_______
  ),

// ADJUST Layer: RGB, Media
  [_ADJUST] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,COLMKDH,
     _______,_______,RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_G,                        _______,_______,_______,_______,_______,KC_VOLU,
     _______,_______,RGB_SAI,RGB_HUI,RGB_VAI,RGB_M_SW,                       _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLD,
     _______,_______,RGB_SAD,RGB_HUD,RGB_VAD,RGB_M_K,                        _______,_______,_______,_______,_______,KC_MUTE,
                     _______,RGB_TOG,                                                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t cvzy_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
