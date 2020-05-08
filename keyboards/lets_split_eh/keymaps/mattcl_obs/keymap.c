#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _OBS 1
#define _LOWER 4

enum custom_keycodes {
  OBS = SAFE_RANGE,
  LOWER,
};
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
#define OBS_PSE MEH(KC_F17)
#define OBS_STR MEH(KC_F17)
#define OBS_SHT MEH(KC_F18)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* OBS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  REC |  S7  |  S8  |  S9  |Studio|Stream|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  PSE |  S4  |  S5  |  S6  |QuFade|ScrSht|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  CAM |  S1  |  S2  |  S3  |QuCut |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | React|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_OBS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, OBS_REC, OBS_S7,  OBS_S8,  OBS_S9,  OBS_SM,  OBS_STR, \
  _______, _______, _______, _______, _______, _______, OBS_PSE, OBS_S4,  OBS_S5,  OBS_S6,  OBS_QF,  OBS_SHT, \
  _______, _______, _______, _______, _______, _______, OBS_CAM, OBS_S1,  OBS_S2,  OBS_S3,  OBS_QT,  _______, \
  _______, _______, _______, _______, _______, _______, OBS_WTF, _______, _______, _______, RGB_TOG, LOWER,   \
)

[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OBS:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_OBS);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
  }
  return true;
}
