#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define BASE_LAYER 0
#define LSPC_LAYER 1
#define LFN_LAYER 2
#define RFN_LAYER 3
#define FN_SFT_LAYER 4
#define OSHOT_LAYER 5

#define MC_TAB GUI_T(KC_TAB)
#define MC_BSLS GUI_T(KC_BSLS)
#define MC_SINS LSFT(KC_INS)
#define MC_MPST LGUI(KC_V)
#define MC_LSPC LT(LFN_LAYER, KC_SPC)
#define MC_RSPC LT(RFN_LAYER, KC_SPC)

#define TSYNC 0          // tmux synchronize panes
#define TPIPE 1          // tmux pipe pane to log
#define TPRV 2           // tmux previous session
#define TNXT 3           // tmux next session
#define MSIL 4           // konsole monitor for silence
#define MACT 5           // konsole monitor for activity
#define UBIS 6           // ubisoft shift-f2 (meh)
#define LCB 7            // <leader><C-b>
#define LCX 8            // <leader><C-x>
#define GPMD_PREV 9      // google play music desktop prev
#define GPMD_NEXT 10     // google play music desktop next
#define GPMD_PAUSE 11    // google play music desktop play/pause
#define GPMD_UP 12       // google play music desktop thumb up
#define GPMD_DOWN 13     // google play music desktop thumb down
#define PASTE 14         // configurable paste
#define TOGOSX 15        // toggle paste keys

static bool osx_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // The left spacebar is tap for space, hold for fn
	[BASE_LAYER] = LAYOUT( \
		F(0),          KC_1,    KC_2,    KC_3,    KC_4,             KC_5,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
		MEH_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,             KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS,
		KC_RCTL,       KC_A,    KC_S,    KC_D,    KC_F,             KC_G,   KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KC_ENT,
		KC_LSFT,       KC_NO,   KC_Z,    KC_X,    KC_C,             KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,
		KC_LCTL,       KC_LGUI, KC_LALT, MC_LSPC, OSL(OSHOT_LAYER), KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_RIGHT, KC_DOWN \
  ),

  // The right spacebar is tap for space, hold for fn
	[LSPC_LAYER] = LAYOUT( \
		F(0),    KC_1,    KC_2,    KC_3,   KC_4,             KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,             KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC, KC_RBRC, MC_BSLS,
		KC_RCTL, KC_A,    KC_S,    KC_D,   KC_F,             KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   KC_Z,    KC_X,   KC_C,             KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, OSL(OSHOT_LAYER), MC_RSPC, KC_RALT, KC_RCTL, KC_LEFT, KC_RIGHT, KC_DOWN \
  ),

  [LFN_LAYER] = LAYOUT( \
    KC_GRV,                    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, KC_DEL,  \
    _______,                   KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______,                   KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  KC_GRV,  M(PASTE), \
    MO(FN_SFT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PGUP, \
    _______,                   _______, _______, _______, _______, KC_BSPC, _______, _______, KC_HOME, KC_END, KC_PGDN \
  ),
  [RFN_LAYER] = LAYOUT( \
    KC_GRV,                    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, KC_DEL,  \
    _______,                   KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______,                   KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  KC_GRV,  M(PASTE), \
    MO(FN_SFT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PGUP, \
    _______,                   _______, _______, KC_BSPC, _______, _______, _______, _______, KC_HOME, KC_END, KC_PGDN \
  ),
  [FN_SFT_LAYER] = LAYOUT( \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,          _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, MC_MPST, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
    _______,                   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),
  [OSHOT_LAYER] = LAYOUT( \
    _______, M(GPMD_PAUSE), M(GPMD_PREV), M(GPMD_NEXT), _______, _______, _______, _______, _______,        M(TPRV),        M(TNXT),    M(GPMD_DOWN), M(GPMD_UP), _______, M(UBIS), \
    _______, M(MSIL),       M(MACT),      _______,      _______, _______, _______, _______, _______,        _______,        _______,    _______,      _______,    _______, \
    _______, M(TPIPE),      M(TSYNC),     _______,      _______, _______, _______, M(LCB) , M(LCX) ,        _______,        _______,    _______,      _______,    \
    _______, _______,       _______,      _______,      _______, _______, RGB_TOG, _______, BL_BRTG,        BL_DEC,         BL_INC,     BL_TOGG,      _______,    _______, \
    _______, _______,       _______,      _______,      _______, _______, _______, _______, DF(BASE_LAYER), DF(LSPC_LAYER), M(TOGOSX) \
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
      case TPRV:
        return MACRO(D(RCTL), T(A), U(RCTL), D(LSFT), T(9), U(LSFT), END);
      case TNXT:
        return MACRO(D(RCTL), T(A), U(RCTL), D(LSFT), T(0), U(LSFT), END);
      case MSIL:
        return MACRO(D(RCTL), D(LSFT), T(I), U(LSFT), U(RCTL), END);
      case MACT:
        return MACRO(D(RCTL), D(LSFT), T(A), U(LSFT), U(RCTL), END);
      case UBIS:
        return MACRO(D(LSFT), T(F2), U(LSFT), END);
      case LCB:
        return MACRO(T(COMM), D(RCTL), T(B), U(RCTL), END);
      case LCX:
        return MACRO(T(COMM), D(RCTL), T(X), U(RCTL), END);
      case GPMD_PREV:
        return MACRO(D(RCTL), D(LALT), D(LSFT), T(1), U(LSFT), U(LALT), U(RCTL), END);
      case GPMD_NEXT:
        return MACRO(D(RCTL), D(LALT), D(LSFT), T(2), U(LSFT), U(LALT), U(RCTL), END);
      case GPMD_PAUSE:
        return MACRO(D(RCTL), D(LALT), D(LSFT), T(3), U(LSFT), U(LALT), U(RCTL), END);
      case GPMD_UP:
        return MACRO(D(RCTL), D(LALT), D(LSFT), T(4), U(LSFT), U(LALT), U(RCTL), END);
      case GPMD_DOWN:
        return MACRO(D(RCTL), D(LALT), D(LSFT), T(5), U(LSFT), U(LALT), U(RCTL), END);
      case PASTE:
        if (osx_mode) {
          return MACRO(D(LGUI), T(V), U(LGUI), END);
        } else {
          return MACRO(D(LSFT), T(INS), U(LSFT), END);
        }
      case TOGOSX:
        osx_mode = !osx_mode;
        return MACRO_NONE;
    }
  }
  return MACRO_NONE;
};
