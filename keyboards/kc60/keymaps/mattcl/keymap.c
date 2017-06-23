// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "kc60.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define _______ KC_TRNS

// just make it nicer to read this/format this
#define CPASTE LSFT(KC_INS)
#define TM_SYNC M(0) // tmux synchronize panes
#define TM_PIPE M(1) // tmux pipe pane to log

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _F2 2
#define _F3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-------------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp   |
   * |-------------------------------------------------------------|
   * |Tab/FN|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|\/FN  |
   * |-------------------------------------------------------------|
   * |CTL     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
   * |-------------------------------------------------------------|
   * |Shift     |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-------------------------------------------------------------|
   * |Ctrl|Gui |Alt |        Space            |Alt |Gui |FN  |Ctrl |
   * `-------------------------------------------------------------'
   */
[_BL] = KEYMAP(
  F(0),             KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS, KC_EQL,  KC_BSPC, \
  LT(_FL, KC_TAB),  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,     KC_LBRC, KC_RBRC, LT(_FL, KC_BSLS), \
  KC_RCTL,          KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,  KC_QUOT, KC_NO,   KC_ENT,  \
  KC_LSFT, KC_NO,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,           KC_NO,   KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                             KC_NO,  OSL(_F2), KC_RGUI, MO(_FL), MO(_F3)),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |~ |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|   DEL  |
   * |-----------------------------------------------------------|
   * |     |PLY|PRV|NXT|   |   |   |PUP|HOM|PDN|END|   |   |     |
   * |-----------------------------------------------------------|
   * |       |MUT|VDN|VUP|   |   |LFT|DN |UP |RGT|   |`  |S-INS  |
   * |-----------------------------------------------------------|
   * |        |   |   |   |SIN|   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 ,  KC_F11,  KC_F12, KC_DEL ,  \
  _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, KC_PGUP, KC_HOME, KC_PGDN, KC_END , _______, _______, _______, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_GRV , _______, CPASTE, \
  _______, _______, _______, _______, _______, CPASTE,  _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                   KC_DEL ,                            _______, _______, _______, _______, _______ ),

  /* Keymap _F2: Function Layer 2
   * ,-----------------------------------------------------------.
   * |  |   |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |TP |   |   |     |
   * |-----------------------------------------------------------|
   * |       |   |TS |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

[_F2] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TM_PIPE, _______, _______, _______, \
  _______, _______, TM_SYNC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                   _______ ,                           _______, _______, _______, _______, _______ ),


[_F3] = KEYMAP(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______ ),
};

enum function_id {
    SHIFT_ESC,
    CTRLSPECIAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
  [1]  = ACTION_FUNCTION(CTRLSPECIAL),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
    case CTRLSPECIAL:
      break;
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case 0:
        return MACRO(D(RCTL), T(A), U(RCTL), D(RCTL), T(S), U(RCTL), END);
      case 1:
        return MACRO(D(RCTL), T(A), U(RCTL), D(LSFT), T(P), U(LSFT), END);
    }
  }
  return MACRO_NONE;
};
