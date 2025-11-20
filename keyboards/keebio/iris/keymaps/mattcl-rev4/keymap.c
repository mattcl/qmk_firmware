#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _COLEMAK_DH 0
#define _QWERTY 1
#define _QWERTY_SPACE_SWAP 2
#define _LOWER 3
#define _NUM 4
#define _RAISE 5
#define _ADJUST 6
#define _FN 7

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
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
  TRIGT,  // tmux right
  TLEFT,  // tmux left
  TUP,    // tmux up
  TDOWN,  // tmux down
  TZOOM,  // tmux zoom toggle
  QLCC,   // qwerty layer color cycle
  LLCC,   // lower layer color cycle
  RLCC,   // raise layer color cycle
  FN_RET, // ->
  YOU,    // you
  IM,     // I'm
  QU,     // QU
  JO,     // JO
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

// Synthwave
enum synthwave {
  MAGENTA,
  TEAL,
  GREEN,
};

const int WHITE = 3;
const int YELLOW = 4;

const int SYNTHWAVE_NUM_COLORS = 3;

static int qwerty_color = 0;
static int lower_color = 1;
static int raise_color = 2;

enum combos {
    C_NUM,
    C_YOU,
    C_IM,
    C_QU,
    C_JO,
    C_LGUI,
    C_RGUI,
};

const uint16_t PROGMEM num_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM you_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM im_combo[] = {KC_I, KC_M, COMBO_END};
const uint16_t PROGMEM qu_combo[] = {KC_N, KC_U, COMBO_END};
const uint16_t PROGMEM jo_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [C_NUM] = COMBO(num_combo, MO(_NUM)),
    [C_YOU] = COMBO(you_combo, YOU),
    [C_IM] = COMBO(im_combo, IM),
    [C_QU] = COMBO(qu_combo, QU),
    [C_JO] = COMBO(jo_combo, JO),
    [C_LGUI] = COMBO(lgui_combo, KC_LGUI),
    [C_RGUI] = COMBO(rgui_combo, KC_RGUI),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     // QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
CTL_T(KC_ESC),KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE,          KC_DEL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_NUM), LOWER,  KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     // QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY_SPACE_SWAP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     // QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS,  KC_BSPC,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_SPC,                    KC_ENT,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     // KC_GRV,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               _______, _______, KC_SLSH, KC_ASTR, KC_MINS, KC_EQL,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_LABK, KC_LCBR, KC_RCBR, KC_RABK, KC_DLR,                             KC_CIRC, KC_ASTR, KC_AMPR, KC_PIPE, _______, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_EXLM, KC_LPRN, KC_RPRN, KC_EQL,  PASTE,                              KC_HASH, KC_MINS, KC_LBRC, KC_RBRC, KC_UNDS, KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,          _______, KC_PERC, KC_AT,   _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_BSPC, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     // KC_GRV,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               _______, _______, KC_SLSH, KC_ASTR, KC_MINS, KC_EQL,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_GRV,  KC_7,    KC_8,    KC_9,    _______, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LGUI, _______, _______, KC_DOT,  _______,                            KC_MINS, KC_4,    KC_5,    KC_6,    KC_UNDS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_DOT,  KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LSFT, KC_LGUI,                   KC_0,    _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_LBRC, KC_RBRC, KC_MINS, KC_PERC,                            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, KC_DEL,                   _______, RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    // _______, _______, KC_F12,  KC_F11,  KC_F10,  OBS_REC,                            _______, _______, _______, _______, _______, TOGOSX,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TPIPE,   TSYNC,   KC_F9,   KC_F8,   KC_F7,   OBS_PSE,                            _______, _______, _______, _______, _______, CALTDEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QWERTY,  KC_F6,   KC_F5,   KC_F4,  OBS_STR,                             NOG_LT,  COLEMAK, _______,  NOG_RT, _______, TOGOSX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, QSP,     KC_F3,   KC_F2,   KC_F1, MEH(KC_F1),LCA(KC_DEL),      QK_BOOT,  BL_BRTG, BL_DOWN, BL_UP,BL_TOGG, _______, UG_TOGG,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_F18,  KC_F17,  KC_F16,  _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_F15,  KC_F14,  KC_F13,  _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_F12,  KC_F11,  KC_F10,  _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
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
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_LCTL("s"));
      }
      return false;
    case TPIPE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_LSFT("p"));
      }
      return false;
    case TPRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_LSFT("9"));
      }
      return false;
    case TNXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_LSFT("0"));
      }
      return false;
    case TRIGT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "l");
      }
      return false;
    case TLEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "h");
      }
      return false;
    case TUP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "k");
      }
      return false;
    case TDOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "j");
      }
      return false;
    case TZOOM:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "z");
      }
      return false;
    case QLCC:
      if (record->event.pressed) {
        qwerty_color = (qwerty_color + 1) % SYNTHWAVE_NUM_COLORS;
      }
      return false;
    case LLCC:
      if (record->event.pressed) {
        lower_color = (lower_color + 1) % SYNTHWAVE_NUM_COLORS;
      }
      return false;
    case RLCC:
      if (record->event.pressed) {
        raise_color = (raise_color + 1) % SYNTHWAVE_NUM_COLORS;
      }
      return false;
    case FN_RET:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
    case YOU:
      if (record->event.pressed) {
        SEND_STRING("you");
      }
      return false;
    case IM:
      if (record->event.pressed) {
        SEND_STRING("I'm");
      }
      return false;
    case QU:
      if (record->event.pressed) {
        SEND_STRING("qu");
      }
      return false;
    case JO:
      if (record->event.pressed) {
        SEND_STRING("jo");
      }
      return false;
  }
  return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  // rgb_matrix_sethsv(HSV_MAGENTA);
  // rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
  return state;
}

// void set_layer_color(int index) {
//   switch(index) {
//   case TEAL:
//     rgb_matrix_sethsv_noeeprom(HSV_TEAL);
//     break;
//   case MAGENTA:
//     rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
//     break;
//   case GREEN:
//     rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//     break;
//   case WHITE:
//     rgb_matrix_sethsv_noeeprom(HSV_WHITE);
//     break;
//   case YELLOW:
//     rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
//     break;
//   }
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     uint8_t layer = biton32(state);
//     switch(layer) {
//     case _QWERTY:
//         set_layer_color(qwerty_color);
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
//         break;
//     case _LOWER:
//         set_layer_color(lower_color);
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
//         break;
//     case _LOWER_MOD:
//         set_layer_color(WHITE);
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
//         break;
//     case _RAISE:
//         set_layer_color(raise_color);
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
//         break;
//     case _RAISE_MOD:
//         set_layer_color(YELLOW);
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
//         break;
//     case _ADJUST:
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN);
//         break;
//     }
//     return state;
// }

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
