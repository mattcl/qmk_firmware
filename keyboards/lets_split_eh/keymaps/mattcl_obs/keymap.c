#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _OBS1,
  _OBS2,
  _MOD,
};

#define MOD     MO(_MOD)
#define OBS1     MO(_LOWER)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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

#define OBS_U1 MEH(KC_F19)
#define OBS_U2 MEH(KC_F20)
#define OBS_U3 MEH(KC_F21)
#define OBS_U4 MEH(KC_F22)
#define OBS_U5 MEH(KC_F23)
#define OBS_U6 MEH(KC_F24)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* OBS 1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  REC |  S7  |  S8  |  S9  |Studio|Stream|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  PSE |  S4  |  S5  |  S6  |QuFade|ScrSht|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  CAM |  S1  |  S2  |  S3  |QuCut |  U4  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | React|  U1  |  U2  |  U3  |  RGB |Lower |
 * `-----------------------------------------------------------------------------------'
 */
[_OBS1] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, OBS_REC, OBS_S7, OBS_S8, OBS_S9, OBS_SM,  OBS_STR,  \
  _______, _______, _______, _______, _______, _______, OBS_PSE, OBS_S4, OBS_S5, OBS_S6, OBS_QF,  OBS_SHT,  \
  _______, _______, _______, _______, _______, _______, OBS_CAM, OBS_S1, OBS_S2, OBS_S3, OBS_QT,  OBS_U4,   \
  _______, _______, _______, _______, _______, _______, M(0),    OBS_U1, OBS_U2, OBS_U3, RGB_TOG, MOD   \
),

/* OBS 2
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  REC |  S7  |  S8  |  S9  |Studio|Stream|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  PSE |  S4  |  S5  |  S6  |QuFade|ScrSht|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  CAM |  S1  |  S2  |  S3  |QuCut |  U4  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | React|  U1  |  U2  |  U3  |  RGB |  MOD |
 * `-----------------------------------------------------------------------------------'
 */
[_OBS2] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, OBS_REC, OBS_S7, OBS_S8, OBS_S9, OBS_SM,  OBS_STR,  \
  _______, _______, _______, _______, _______, _______, OBS_PSE, OBS_S4, OBS_S5, OBS_S6, OBS_QF,  OBS_SHT,  \
  _______, _______, _______, _______, _______, _______, OBS_CAM, OBS_S1, OBS_S2, OBS_S3, OBS_QT,  OBS_U4,   \
  _______, _______, _______, _______, _______, _______, M(0),    OBS_U1, OBS_U2, OBS_U3, RGB_TOG, MOD   \
),

[_MOD] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0: {
      if (record->event.pressed) {
        return MACRO(D(LCTL), D(LSFT), D(LALT), D(F11), W(100), U(F11), U(LALT), U(LSFT), U(LCTL), END);
      } else {
        return MACRO(D(LCTL), D(LSFT), D(LALT), D(F11), W(100), U(F11), U(LALT), U(LSFT), U(LCTL), END);
      }
      break;
    }
  }
  return MACRO_NONE;
};
