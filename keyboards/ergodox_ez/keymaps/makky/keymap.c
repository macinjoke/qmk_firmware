#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define WIN 1 //  for windows
#define SYMB 2 // symbols
#define WINA 3 // for windows advance
#define GAME 4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |S+G+A+C+L|     |S+G+A+C+R|   6  |   7  |   8  |   9  |   0  |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Back  |           | ALT+ |   Y  |   U  |   I  |   O  |   P  |BackSpace|
 * |--------+------+------+------+------+------|space |           | RIGHT|------+------+------+------+------+--------|
 * |Ctrl    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| LAlt+|           | ALT+ |------+------+------+------+------+--------|
 * |LShift |Z/gui+sift| X |   C  |   V  |   B  |BackSp|           | LEFT |   N  |   M  |   ,  | . |//gui+sift| RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LEFT  | DOWN |KC_UP | LAlt | LGUI |                                       |  RGUI|ALT/LFT| DOWN|  UP  | RIGHT  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-----------------.    ,---------------.
 *                                        |TG(SYMB|TG(GAME) |    | VOLUP|TG(WIN|
 *                                 ,------|-------|---------|    |------+--------+------.
 *                                 |      |       |S+G+A+C+1|    |VOLDWN|        |      |
 *                                 | Space|Enter  |---------|    |------|MO(SYMB)|Space |
 *                                 |      |       |S+G+A+C+2|    |MUTE  |        |      |
 *                                 `-----------------------'    `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,                  KC_2,   KC_3,   KC_4,   KC_5,   LSFT(LGUI(LALT(LCTL(KC_LEFT)))),
        KC_TAB,         KC_Q,                  KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        KC_LCTL,        KC_A,                  KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT, MT(MOD_LGUI | MOD_LSFT, KC_Z),KC_X,   KC_C,   KC_V,   KC_B,   LALT(KC_BSPC),
        KC_LEFT,        KC_DOWN,               KC_UP,  KC_LALT,KC_LGUI,
                                              TG(SYMB),      TG(GAME),
                                                             LSFT(LGUI(LALT(LCTL(KC_1)))),
                                              KC_SPC, KC_ENT,LSFT(LGUI(LALT(LCTL(KC_2)))),
        // right hand
        RSFT(RGUI(RALT(RCTL(KC_RIGHT)))),
                        KC_6,   KC_7,   KC_8,           KC_9,   KC_0,                             KC_DEL,
        RALT(KC_RIGHT), KC_Y,   KC_U,   KC_I,           KC_O,   KC_P,                             KC_BSPC,
                        KC_H,   KC_J,   KC_K,           KC_L,   KC_SCLN,                          KC_ENT,
        RALT(KC_LEFT),  KC_N,   KC_M,   KC_COMM,        KC_DOT, MT(MOD_RGUI | MOD_RSFT, KC_SLSH), KC_RSFT,
                                KC_RGUI,RALT_T(KC_LEFT),KC_DOWN,KC_UP,                            KC_RIGHT,
        KC__VOLUP,   TG(WIN),
        KC__VOLDOWN,
        KC__MUTE,    MO(SYMB), KC_SPC
    ),
/* Keymap 1: for windows pc
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |S+G+A+C+L|     |S+G+A+C+R|   6  |   7  |   8  |   9  |   0  |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Back  |           | ALT+ |   Y  |   U  |   I  |   O  |   P  |BackSpace|
 * |--------+------+------+------+------+------|space |           | RIGHT|------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| LAlt+|           | ALT+ |------+------+------+------+------+--------|
 * |LShift |Z/gui+sift| X |   C  |   V  |   B  |BackSp|           | LEFT |   N  |   M  |   ,  | . |//gui+sift| RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LEFT  | DOWN |KC_UP | LAlt |Muhenkan|                                     |Henkan|ALT/LFT| DOWN|  UP  | RIGHT  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-----------------.    ,---------------.
 *                                        |TG(SYMB|  LGUI   |    | VOLUP|TG(WIN|
 *                                 ,------|-------|---------|    |------+--------+------.
 *                                 |      |       |S+G+A+C+2|    |VOLDWN|        |      |
 *                                 | Space|Enter  |---------|    |------|        |Space |
 *                                 |      |       |S+G+A+C+3|    |MUTE  |        |      |
 *                                 `-----------------------'    `----------------------'
 */
//
[WIN] = LAYOUT_ergodox(
        // left hand
        KC_GRV,         KC_1,                  KC_2,   KC_3,   KC_4,   KC_5,   LSFT(LGUI(LALT(LCTL(KC_LEFT)))),
        KC_TAB,         KC_Q,                  KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        LT(WINA, KC_ESC),  KC_A,                  KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT, MT(MOD_LGUI | MOD_LSFT, KC_Z),KC_X,   KC_C,   KC_V,   KC_B,   LALT(KC_BSPC),
        KC_LEFT,        KC_DOWN,      KC_UP,  KC_LALT, CTL_T(KC_MHEN),
                                              TG(SYMB),      KC_LGUI,
                                                             LSFT(LGUI(LALT(LCTL(KC_2)))),
                                              KC_SPC, KC_ENT,LSFT(LGUI(LALT(LCTL(KC_3)))),
        // right hand
        RSFT(RGUI(RALT(RCTL(KC_RIGHT)))),
                        KC_6,   KC_7,   KC_8,           KC_9,   KC_0,                             KC_DEL,
        RALT(KC_RIGHT), KC_Y,   KC_U,   KC_I,           KC_O,   KC_P,                             KC_BSPC,
                        KC_H,   KC_J,   KC_K,           KC_L,   KC_SCLN,                   KC_ENT,
        RALT(KC_LEFT),  KC_N,   KC_M,   KC_COMM,        KC_DOT, MT(MOD_RGUI | MOD_RSFT, KC_SLSH), KC_RSFT,
                                CTL_T(KC_HENK),RALT_T(KC_LEFT),KC_DOWN,KC_UP,                           KC_RIGHT,
        KC__VOLUP,   TG(WIN),
        KC__VOLDOWN,
        KC__MUTE,    KC_TRNS, KC_SPC
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |      |      |      |      | RESET|           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |   -  |   =  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|      |   [  |   ]  |   '  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |  F11 |  F12 |      |      |                                       |      | HOME | PgDn | PgUp |  End |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Caps  |      |      |       |      |      |      |
 *                                 |Lock  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
          EPRM,KC_F11, KC_F12, KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_CAPS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_LBRC,KC_RBRC, KC_QUOT, KC_BSLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_HOME, KC_PGDN, KC_PGUP, KC_END,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: for Windows Advance Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |  End |      |      |      |           |      |      |      |      |      |  Up  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Home |      |      | Right|      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      | Left |      |           |      | Down |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Windows Advance
[WINA] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_END, KC_TRNS ,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_HOME,KC_TRNS,KC_TRNS,KC_RIGHT,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,KC_LEFT,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
                KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_DOWN, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 4: Game layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  Y   |        |S+G+A+C+R|   6  |   7  |   8  |   9  |   0  |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  H   |           | ALT+ |   Y  |   U  |   I  |   O  |   P  |BackSpace|
 * |--------+------+------+------+------+------|      |           | RIGHT|------+------+------+------+------+--------|
 * |Ctrl    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|  N   |           | ALT+ |------+------+------+------+------+--------|
 * |LShift  |   Z  | X    |   C  |   V  |   B  |      |           | LEFT |   N  |   M  |   ,  | . |//gui+sift| RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LEFT  | DOWN |KC_UP | LAlt | LGUI |                                       |  RGUI|ALT/LFT| DOWN|  UP  | RIGHT  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-----------------.    ,---------------.
 *                                        |TG(SYMB|         |    | VOLUP|TG(WIN|
 *                                 ,------|-------|---------|    |------+--------+------.
 *                                 |      |       |S+G+A+C+2|    |VOLDWN|        |      |
 *                                 | Space|O(オー)|---------|    |------|MO(SYMB)|Space |
 *                                 |      |       |S+G+A+C+3|    |MUTE  |        |      |
 *                                 `-----------------------'    `----------------------'
 */
[GAME] = LAYOUT_ergodox(
        // left hand
        KC_ESC,         KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_Y,
        KC_TAB,         KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_H,
        KC_LCTL,        KC_A,       KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_N,
        KC_LEFT,        KC_DOWN,    KC_UP,  KC_LALT,KC_LGUI,
                                              TG(SYMB),      KC_TRNS,
                                                             LSFT(LGUI(LALT(LCTL(KC_2)))),
                                              KC_SPC, KC_O ,LSFT(LGUI(LALT(LCTL(KC_3)))),
        // right hand
        RSFT(RGUI(RALT(RCTL(KC_RIGHT)))),
                        KC_6,   KC_7,   KC_8,           KC_9,   KC_0,                             KC_DEL,
        RALT(KC_RIGHT), KC_Y,   KC_U,   KC_I,           KC_O,   KC_P,                             KC_BSPC,
                        KC_H,   KC_J,   KC_K,           KC_L,   KC_SCLN,                          KC_ENT,
        RALT(KC_LEFT),  KC_N,   KC_M,   KC_COMM,        KC_DOT, MT(MOD_RGUI | MOD_RSFT, KC_SLSH), KC_RSFT,
                                KC_RGUI,RALT_T(KC_LEFT),KC_DOWN,KC_UP,                            KC_RIGHT,
        KC__VOLUP,   TG(WIN),
        KC__VOLDOWN,
        KC__MUTE,    MO(SYMB), KC_SPC
    ),

/* Keymap X: all KC_TRNS Layer for copy and paste
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// [MOCK] = LAYOUT_mock(
//        // left hand
//        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
//        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
//        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
//        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
//        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
//                                        KC_TRNS,KC_TRNS,
//                                                KC_TRNS,
//                                KC_TRNS,KC_TRNS,KC_TRNS,
//        // right hand
//        KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                 KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                          KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS,
//        KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS
// ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
