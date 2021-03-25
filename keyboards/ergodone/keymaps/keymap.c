#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUM 2 // numpad + mouse controls

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  EXPLR,
  CUT,
  COPY,
  PASTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | GrvEsc | 1  ! | 2  @ | 3  # | 4  $ | 5  % | CUT  |           | Calc | 6  ^ | 7  & | 8  * | 9  ( | 0  ) |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | COPY |           | NULL |   Y  |   U  |   I  |   O  |   P  |  Bkspc |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NUM   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : |  '  "  |
 * |--------+------+------+------+------+------|PASTE |           | NULL |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  / ? | SftEnt |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LWin | LAlt | Caps | SYMB |                                       | SYMB | Left | Down |  Up  | Right  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | -  _ | =  + |       | [  { | ]  } |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |EXPLR |       | NULL |        |      |
 *                                 |Space | MEH  |------|       |------|  NULL  |Space |
 *                                 |      |      |  F2  |       | NULL |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       CUT,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       COPY,
        MO(NUM),    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       PASTE,
        KC_LCTRL,   KC_LWIN,     KC_LALT,    KC_CAPS,    MO(SYMB),
                                                                    KC_MINUS,   KC_EQUAL,
                                                                                EXPLR,
                                                        KC_SPACE,   KC_MEH,     KC_F2,
        // right hand
        KC_CALC,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_NO,      KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE,
                    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE,
        KC_NO,      KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_SFTENT,
                                MO(SYMB),   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
        KC_LBRACKET,KC_RBRACKET,
        KC_NO,
        KC_NO,      KC_NO,      KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   TRNS  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  TRNS  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   TRNS  |   !  |   @  |   {  |   }  | | \  | F11  |           | F12  |      |      |   =  |      |      |  TRNS  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TRNS  |   #  |   $  |   (  |   )  |      |------|           |------|      |   -  |   _  |   +  |      |  TRNS  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TRNS  |   %  |   ^  |   [  |   ]  |      |      |           |      |      |      |      |      |      |  TRNS  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS  | TRNS | TRNS |      | TRNS |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | TRNS | TRNS |------|       |------|      | TRNS |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_NO,
        KC_TRNS,    KC_EXCLAIM, KC_AT,      KC_LCBR,    KC_RCBR,    KC_BSLASH,  KC_F11,
        KC_TRNS,    KC_HASH,    KC_DOLLAR,  KC_LPRN,    KC_RPRN,    KC_NO,
        KC_TRNS,    KC_PERCENT, KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_NO,      KC_NO,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,
                                                                    KC_NO,      KC_NO,
                                                                                KC_NO,
                                                        KC_TRNS,    KC_TRNS,    KC_NO,
        // right hand
        KC_NO,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_TRNS,
        KC_F12,     KC_NO,      KC_NO,      KC_EQUAL,   KC_NO,      KC_NO,      KC_TRNS,
                    KC_NO,      KC_MINUS,   KC_UNDS,    KC_PLUS,    KC_NO,      KC_TRNS,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,
        KC_NO,
        KC_NO,      KC_NO,      KC_TRNS
),
/* Keymap 2: Numpad + mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS  |      |      |      |      |      |      |           |      |      |      |   /  |   *  |   -  |  TRNS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TRNS  |      |LClick| MsUp |RClick|      |      |           |      |      |   7  |   8  |   9  |   +  |  TRNS  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  TRNS  |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |   +  |  TRNS  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  TRNS  |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |Enter |  TRNS  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS |      | TRNS |                                       |   0  |   0  |   .  |Enter |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | TRNS | TRNS |------|       |------|      | TRNS |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,    KC_NO,      KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2, KC_NO,      KC_NO,
        KC_TRNS,    KC_NO,      KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_NO,
        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,
                                                                    KC_NO,      KC_NO,
                                                                                KC_NO,
                                                        KC_TRNS,    KC_TRNS,    KC_NO,
        // right hand
        KC_NO,      KC_NO,      KC_NO,      KC_SLASH,   KC_ASTERISK,KC_MINUS,   KC_TRNS,
        KC_NO,      KC_NO,      KC_7,       KC_8,       KC_9,       KC_PLUS,    KC_TRNS,
                    KC_NO,      KC_4,       KC_5,       KC_6,       KC_PLUS,    KC_TRNS,
        KC_NO,      KC_NO,      KC_1,       KC_2,       KC_3,       KC_KP_ENTER,KC_TRNS,
                                KC_0,       KC_0,       KC_KP_DOT,  KC_KP_ENTER,KC_NO,
        KC_NO,      KC_NO,
        KC_NO,
        KC_NO,      KC_NO,      KC_TRNS
),
};

// MACROS

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EXPLR: // Open Windows Explorer
        if (record->event.pressed) {
            // when keycode EXPLR is pressed
            SEND_STRING(SS_LWIN("e")); // Win+E
        } else {
            // when keycode EXPLR is released
        }
        break;
   
    case CUT: // Cut shortcut
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x")); // Ctrl+X
        } else {
        }
        break;
   
    case COPY: // Copy shortcut
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")); // Ctrl+C
        } else {
        }
        break;
      
      case PASTE: // Paste shortcut
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v")); // Ctrl+V
        } else {
        }
        break;
    }
    return true;
};