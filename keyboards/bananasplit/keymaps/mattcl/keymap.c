#include "bananasplit.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define BASE_LAYER 0
#define LFN_LAYER 1
#define RFN_LAYER 2
#define FN_SFT_LAYER 3
#define OSHOT_LAYER 4

#define MC_TAB GUI_T(KC_TAB)
#define MC_BSLS GUI_T(KC_BSLS)
#define MC_SINS LSFT(KC_INS)

#define TSYNC 0 // tmux synchronize panes
#define TPIPE 1 // tmux pipe pane to log
#define MSIL 2  // konsole monitor for silence
#define MACT 3  // konsole monitor for activity
#define UBIS 4  // ubisoft shift-f2 (meh)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = KEYMAP(
    F(0),    KC_1,    KC_2,    KC_3,                  KC_4,             KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    MC_TAB,  KC_Q,    KC_W,    KC_E,                  KC_R,             KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, MC_BSLS, \
    KC_RCTL, KC_A,    KC_S,    KC_D,                  KC_F,             KC_G,                  KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,                  KC_V,             KC_B,                  KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,   \
    KC_LCTL, KC_LGUI, KC_LALT, LT(LFN_LAYER, KC_ENT), OSL(OSHOT_LAYER), LT(RFN_LAYER, KC_SPC), KC_RALT, KC_RCTL, KC_LEFT, KC_RIGHT, KC_DOWN
  ),

  [LFN_LAYER] = KEYMAP( \
    KC_GRV,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,  \
    _______,          KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______,          KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  KC_GRV,  MC_SINS, \
    MO(FN_SFT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PGUP, \
    _______,          _______, _______, _______, _______, KC_BSPC, _______, _______, KC_HOME, KC_END, KC_PGDN \
  ),
  [RFN_LAYER] = KEYMAP( \
    KC_GRV,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,  \
    _______,          KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______,          KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  KC_GRV,  MC_SINS, \
    MO(FN_SFT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, RESET,   \
    _______,          _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______ \
  ),
  [FN_SFT_LAYER] = KEYMAP( \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,          _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,          _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),
  [OSHOT_LAYER] = KEYMAP( \
    _______, _______,  M(UBIS),  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______, M(MSIL),  M(MACT),  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______, M(TPIPE), M(TSYNC), _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
    _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
    _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
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
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case TSYNC:
        return MACRO(D(RCTL), T(A), U(RCTL), D(RCTL), T(S), U(RCTL), END);
      case TPIPE:
        return MACRO(D(RCTL), T(A), U(RCTL), D(LSFT), T(P), U(LSFT), END);
      case MSIL:
        return MACRO(D(RCTL), D(LSFT), T(I), U(LSFT), U(RCTL), END);
      case MACT:
        return MACRO(D(RCTL), D(LSFT), T(A), U(LSFT), U(RCTL), END);
      case UBIS:
        return MACRO(D(LSFT), T(F2), U(LSFT), END);
    }
  }
  return MACRO_NONE;
};
