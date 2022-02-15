#include QMK_KEYBOARD_H

enum encoder_names {
    _LEFT,
    _RIGHT,
    _MIDDLE,
};

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

#define OBS_SM MEH(KC_F12)
#define OBS_QT MEH(KC_F13)
#define OBS_QF MEH(KC_F14)

#define OBS_STR MEH(KC_F17)

const int NUM_LAYERS = 4;
static int cur_desired_layer = 0;

enum layers {
    _OBS_ONE,
    _OBS_TWO,
    _HANGOUTS,
    _ADJUST
};

enum custom_keycodes {
    RST_BASE_LR = SAFE_RANGE,
    REACT_CAM
};

// a bitmask would probably be more efficient, but there are only 11 LEDs and
// this lines up well with the loop that determines the status for these
static bool light_enabled[11] = {
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    true,
    true
};

static uint8_t light_color[11][3] = {
    {RGB_PURPLE},
    {RGB_RED},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
    {RGB_PURPLE},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Next/prev layer |                  | Knob 2: Vol up/down  |
        | Press: reset to L0      | OBS Start stream | Press: Mute          |
        | OBS Scene 3             | OBS Scene 4      | OBS Quick transition |
        | OBS Scene 1             | OBS Scene 2      | OBS Reaction cam     |
     */
    [_OBS_ONE] = LAYOUT(
        RST_BASE_LR, OBS_STR, KC_MUTE,
        OBS_S3,      OBS_S4,  OBS_QF,
        OBS_S1,      OBS_S2,  REACT_CAM
    ),
    /*
        | Knob 1: Next/prev layer |                  | Knob 2: Vol up/down  |
        | Press: reset to L0      | OBS Start stream | Press: Mute          |
        | OBS Scene 7             | OBS Scene 8      | OBS Quick transition |
        | OBS Scene 5             | OBS Scene 6      | OBS Reaction cam     |
     */
    [_OBS_TWO] = LAYOUT(
        RST_BASE_LR, BL_STEP, KC_MUTE,
        OBS_S7,      OBS_S8,  OBS_QF,
        OBS_S5,      OBS_S6,  REACT_CAM
    ),

    /*
        | Knob 1: Next/prev layer |                       | Knob 2: Vol up/down       |
        | Press: reset to L0      | Hangouts toggle video | Press: Mute               |
        | N/A                     | N/A                   | N/A                       |
        | Hangouts mute           | N/A                   | Hangouts raise/lower hand |
     */
    [_HANGOUTS] = LAYOUT(
        RST_BASE_LR, LCTL(KC_E), KC_MUTE,
        KC_NO,       KC_NO,      KC_NO,
        LCTL(KC_D), KC_NO,      LCA(KC_H)
    ),

    /*
        | Knob 1: Next/prev layer |             | Knob 2: Vol up/down |
        | Press: reset to L0      | LEDs Toggle | RESET               |
        | N/A                     | N/A         | N/A                 |
        | N/A                     | N/A         | N/A                 |
     */
    [_ADJUST] = LAYOUT(
        RST_BASE_LR, RGB_TOG, RESET,
        KC_NO,       KC_NO,   KC_NO,
        KC_NO,       KC_NO,   KC_NO
    ),
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

int get_led_for_keyrecord(keyrecord_t *record) {
    return record->event.key.col + (record->event.key.row * 3);
}

void reset_light_map(bool include_underglow) {
    int max = include_underglow ? 11 : 9;
    for (int i = 0; i < max; i++) {
        light_enabled[i] = false;
    }
}

void process_lighting_changes(uint8_t led, bool pressed) {
    switch (cur_desired_layer) {
        // layers one and two are special in that some keys are
        // exclusive toggles in terms of lighting (not actually
        // enforced by the host, obviously).
        case _OBS_ONE:
        case _OBS_TWO:
            // the scene selection keys are exclusive toggles that only react
            // to keypresses
            if (led == 3 || led == 4 || led == 6 || led == 7) {
                if (pressed) {
                    light_enabled[3] = false;
                    light_enabled[4] = false;
                    light_enabled[6] = false;
                    light_enabled[7] = false;
                    // you cannot "deactivate" a scene key by pressing multiple
                    // times (unlike the default light behavior)
                    light_enabled[led] = true;
                }
                break;
            }

            // 5 and 8 are the scene transition and reaction cam keys
            // respectively. So they light when pressed and turn off when
            // released
            if (led == 5 || led == 8) {
                if (pressed) {
                    light_enabled[led] = true;
                } else {
                    light_enabled[led] = false;
                }
                break;
            }

            // otherwise, "default" behavior (there's only one key for this)
            if (pressed) {
                light_enabled[led] = !light_enabled[led];
            }
            break;

        // the hangouts layer only has 3 active keys that we need to worry
        // about, and they're all toggles
        case _HANGOUTS:
            if (pressed && (led == 1 || led == 6 || led == 8)) {
                light_enabled[led] = !light_enabled[led];
            }
            break;
        // adjust has no active keys
        case _ADJUST:
            break;
        default:
            // only alter on press by default
            if (pressed) {
                light_enabled[led] = !light_enabled[led];
            }
            break;
    }
}

void apply_light_color(uint8_t idx) {
    // always ignore the encoder LEDs for now
    if (idx == 0 || idx == 2) {
        rgb_matrix_set_color(idx, RGB_OFF);
        return;
    }

    if (light_enabled[idx]) {
        rgb_matrix_set_color(
            idx,
            light_color[idx][0],
            light_color[idx][1],
            light_color[idx][2]
        );
    } else {
        rgb_matrix_set_color(idx, RGB_OFF);
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (i >= 0 && i <= 11) {
            apply_light_color(i);
        }
    }
}

void set_light_map_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b) {
    light_color[idx][0] = r;
    light_color[idx][1] = g;
    light_color[idx][2] = b;
}

void set_layer_coloring(uint8_t layer) {
    switch (layer) {
        case _OBS_ONE:
            for (int i = 0; i < 11; i++) {
                set_light_map_color(i, RGB_PURPLE);
            }
            // recording key is red
            set_light_map_color(1, RGB_RED);
            break;
        case _OBS_TWO:
            for (int i = 0; i < 11; i++) {
                set_light_map_color(i, RGB_TEAL);
            }
            // recording key is red
            set_light_map_color(1, RGB_RED);
            break;
        case _HANGOUTS:
            for (int i = 0; i < 11; i++) {
                set_light_map_color(i, RGB_GREEN);
            }
            break;
        case _ADJUST:
            for (int i = 0; i < 11; i++) {
                set_light_map_color(i, RGB_YELLOW);
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int led = get_led_for_keyrecord(record);
    switch(keycode) {
        case RST_BASE_LR:
            if (record->event.pressed) {
                cur_desired_layer = 0;
                set_layer_coloring(cur_desired_layer);
                set_single_persistent_default_layer(cur_desired_layer);
            }
            return false;
        case REACT_CAM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_DOWN(X_F11) SS_DELAY(100) SS_UP(X_F11)))));
            } else {
                SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_DOWN(X_F11) SS_DELAY(100) SS_UP(X_F11)))));
            }

            if (led >= 0 && led <= 11) {
                process_lighting_changes(led, record->event.pressed);
            }
            return false;
        default:
            // LED MAP
            if (led >= 0 && led <= 11) {
                process_lighting_changes(led, record->event.pressed);
            }
            return true;
    }
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            cur_desired_layer = (cur_desired_layer + 1) % NUM_LAYERS;
            set_layer_coloring(cur_desired_layer);
            reset_light_map(false);
            set_single_persistent_default_layer(cur_desired_layer);
        } else {
            cur_desired_layer = (NUM_LAYERS + cur_desired_layer - 1) % NUM_LAYERS;
            set_layer_coloring(cur_desired_layer);
            reset_light_map(false);
            set_single_persistent_default_layer(cur_desired_layer);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
