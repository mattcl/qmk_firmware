#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _UTIL 3
#define _LOWER 4
#define _RAISE 5
#define _FUNCTION 15
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  UTIL,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,       KC_Y,       KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,       KC_H,       KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,       KC_N,       KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, LT(KC_SPC), LT(KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Space Layer
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Pause | Prev | Next |      |      |      | Pg Dn| Pg Up|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ |      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  End | Home |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  Del |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] = LAYOUT( \
  KC_ESC,  KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, \
  KC_DEL,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  KC_END, KC_HOME, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  KC_DEL, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   @  |      |      |      |      |      |   &  |   {  |   }  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   =  |   (  |   )  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO | |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |      | Bksp |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, KC_AMPR, KC_LCBR, KC_RCBR, _______, _______, \
  KC_DEL,  _______, _______, _______, _______, _______, _______, KC_EQL,  KC_LPRN, KC_RPRN, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |  F1  |  F2  |  F3  |      |   %  |   *  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      |   #  |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |   ^  |Enter |   1  |   2  |   3  |   /  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  F10 |  F11 |  F12 |Enter |      |Raise |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, KC_F1,  KC_F2,  KC_F3,  _______, KC_PERC, KC_ASTR, KC_7, KC_8,   KC_9,    KC_MINS, \
  _______, _______, KC_F4,  KC_F5,  KC_F6,  _______, KC_HASH, KC_EQL,  KC_4, KC_5,   KC_6,    KC_PLUS, \
  _______, _______, KC_F7,  KC_F8,  KC_F9,  _______, KC_CIRC, KC_ENT,  KC_1, KC_2,   KC_3,    KC_SLSH, \
  _______, _______, KC_F10, KC_F11, KC_F12,  KC_ENT, _______, _______, KC_0, KC_DOT, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  TSKMGR,  _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL, \
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_STEP, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
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
