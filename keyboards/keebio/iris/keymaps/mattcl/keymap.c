#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _QWERTY 0
#define _QWERTY_SPACE_SWAP 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _FN 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  QWERTY_SPACE_SWAP,
};

#define MC_TAB GUI_T(KC_TAB)
#define MC_BSLS GUI_T(KC_BSLS)
#define MC_SINS LSFT(KC_INS)
#define MC_MPST LGUI(KC_V)
#define MC_LSPC LT(LFN_LAYER, KC_SPC)
#define MC_RSPC LT(RFN_LAYER, KC_SPC)
#define MC_NOG RALT(KC_LCTL)

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

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

// Nog
#define NOG_TOG LALT(LCTL(KC_W)) // toggle nog
#define NOG_RT LALT(LCTL(KC_L))  // move right
#define NOG_LT LALT(LCTL(KC_H))  // move left

// OBS
#define OBS_S1 MEH(KC_F1)
#define OBS_S2 MEH(KC_F2)
#define OBS_S3 MEH(KC_F3)
#define OBS_S4 MEH(KC_F4)
#define OBS_S5 MEH(KC_F5)
#define OBS_S6 MEH(KC_F6)
#define OBS_S7 MEH(KC_F7)
#define OBS_S8 MEH(KC_F8)
#define OBS_S9 MEH(KC_F9)
#define OBS_CAM MEH(KC_F10)
#define OBS_WTF MEH(KC_F11)

#define OBS_SM MEH(KC_F12)
#define OBS_QT MEH(KC_F13)
#define OBS_QF MEH(KC_F14)

#define OBS_REC MEH(KC_F15)
#define OBS_PSE MEH(KC_F16)
#define OBS_STR MEH(KC_F17)
#define OBS_SHT MEH(KC_F18)


static bool osx_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY_SPACE_SWAP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_SPC,                    KC_ENT,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               _______, _______, KC_SLSH, KC_ASTR, KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, _______, KC_LCBR, KC_RCBR, KC_PGDN, KC_PGUP,                            KC_COMM, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼──────┼  ───────  ────────┼────────┼────────┤
     _______, _______, KC_LPRN, KC_RPRN, KC_EQL,  M(PASTE),                           KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS,  KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼──────┼  ───────  ────────┼────────┼────────┤
     _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_LPRN,          KC_RPRN, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______,  KC_SPC,                   KC_0,    _______, KC_DOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, OBS_S5,  OBS_S6,  OBS_S7,  OBS_S8,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, KC_DEL,                    _______, _______,KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     M(MSIL), M(MACT), KC_F12,  KC_F11,  KC_F10,  OBS_REC,                            RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______,M(TOGOSX),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     M(TPIPE),M(TSYNC), KC_F9,   KC_F8,   KC_F7,  OBS_PSE,                            OBS_SM,  OBS_SHT, OBS_CAM,  OBS_QF,  OBS_QT,  CALTDEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QWERTY,  KC_F6,   KC_F5,   KC_F4,  OBS_STR,                            NOG_LT,  _______, _______,  NOG_RT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QWERTY_SPACE_SWAP,  KC_F3,   KC_F2,   KC_F1, MEH(KC_F1),LCA(KC_DEL),      RESET,  BL_BRTG,  BL_DEC, BL_INC,  BL_TOGG, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______,  _______
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
    case QWERTY_SPACE_SWAP:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_SPACE_SWAP);
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

uint32_t default_layer_state_set_user(uint32_t state) {
  rgblight_sethsv(HSV_MAGENTA);
  rgblight_mode(7);
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch(layer) {
    case _QWERTY:
        rgblight_mode_noeeprom(7);
        break;
    case _LOWER:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
        break;
    case _RAISE:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 3);
        break;
    case _ADJUST:
        rgblight_mode_noeeprom(22);
        break;
    }
    return state;
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
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
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
