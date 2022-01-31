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
  QSP,    // swap space and enter
  TOGOSX,
  PASTE,
  TSYNC,  // tmux synchronize panes
  TPIPE,  // tmux pipe pane to log
  TPRV,   // tmux previous session
  TNXT,   // tmux next session
};

#define MC_TAB GUI_T(KC_TAB)
#define MC_BSLS GUI_T(KC_BSLS)
#define MC_SINS LSFT(KC_INS)
#define MC_MPST LGUI(KC_V)
#define MC_LSPC LT(LFN_LAYER, KC_SPC)
#define MC_RSPC LT(RFN_LAYER, KC_SPC)
#define MC_NOG RALT(KC_LCTL)

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
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
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
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
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
     _______, _______, KC_LPRN, KC_RPRN, KC_EQL,  PASTE,                              KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS,  KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼──────┼  ───────  ────────┼────────┼────────┤
     _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,          _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
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
     _______, _______, KC_F12,  KC_F11,  KC_F10,  OBS_REC,                            RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, TOGOSX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TPIPE,   TSYNC,   KC_F9,   KC_F8,   KC_F7,   OBS_PSE,                            OBS_SM,  OBS_SHT, OBS_CAM,  OBS_QF,  OBS_QT, CALTDEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QWERTY,  KC_F6,   KC_F5,   KC_F4,  OBS_STR,                             NOG_LT,  _______, _______,  NOG_RT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QSP,     KC_F3,   KC_F2,   KC_F1, MEH(KC_F1),LCA(KC_DEL),      RESET,   BL_BRTG, BL_DEC,  BL_INC,  BL_TOGG, _______, _______,
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
    case QSP:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_SPACE_SWAP);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case PASTE:
      if (record->event.pressed) {
        if (osx_mode) {
          SEND_STRING(SS_LGUI("v"));
        } else {
          SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_INS)SS_UP(X_LSFT));
        }
      }
      return false;
    case TOGOSX:
      if (record->event.pressed) {
        osx_mode = !osx_mode;
      }
      return false;
    case TSYNC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a") SS_DELAY(50) SS_LCTRL("s"));
      }
      return false;
    case TPIPE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a") SS_DELAY(50) SS_LSFT("p"));
      }
      return false;
    case TPRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a") SS_DELAY(50) SS_LSFT("9"));
      }
      return false;
    case TNXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a") SS_DELAY(50) SS_LSFT("0"));
      }
      return false;
  }
  return true;
}

uint32_t default_layer_state_set_user(uint32_t state) {
  // rev 4
  // rgblight_sethsv(HSV_MAGENTA);
  rgb_matrix_sethsv(HSV_PURPLE);
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch(layer) {
    case _QWERTY:
        rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
        // rgblight_mode_noeeprom(7);
        break;
    case _LOWER:
        rgb_matrix_sethsv_noeeprom(HSV_BLUE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
        // rgblight_mode_noeeprom(RGBLIGHT_EFFECT_RAINBOW_SWIRL + 5);
        break;
    case _RAISE:
        rgb_matrix_sethsv_noeeprom(HSV_GREEN);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
        // rgblight_mode_noeeprom(RGBLIGHT_EFFECT_SNAKE + 3);
        break;
    case _ADJUST:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN);
        // rgblight_mode_noeeprom(22);
        break;
    }
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return false;
}
