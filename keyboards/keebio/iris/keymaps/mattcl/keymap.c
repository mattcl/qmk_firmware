#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FN 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   MO(_FN),           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,                            KC_DQT,  KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼──────┼  ───────  ────────┼────────┼────────┤
     _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,                            KC_QUOT, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼──────┼  ───────  ────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_LPRN,          KC_RPRN, KC_GRV,  KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_0,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_LBRC, KC_RBRC, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_LCBR, KC_RCBR, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  _______,                            _______, _______, KC_LPRN, KC_RPRN, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_LPRN,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
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
