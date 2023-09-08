#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,

    KC_LOBSPC = LT(_LOWER, KC_BSPC),
    KC_RASPC = LT(_RAISE, KC_SPC),
    KC_SHIENT = MT(MOD_RSFT, KC_ENT),
    KC_XCAPE = MT(MOD_LCTL, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
      KC_XCAPE,   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
      KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,             XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SHIENT,
                              KC_LGUI,    KC_LALT,    KC_LALT,    KC_LGUI,    KC_SPC,              KC_LOBSPC,  KC_RASPC,   KC_RCTL,    KC_RALT,    KC_RGUI
    ),

    [_GAME] = LAYOUT(
      KC_ESC,     _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
      _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
      KC_LCTL,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
                              _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______
    ),

    [_LOWER] = LAYOUT(
      _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
      KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                     KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
      _______,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_UNDS,    KC_PLUS,    _______,             _______,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    _______,
                              _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______
    ),

    [_RAISE] = LAYOUT(
      _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                       KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
      _______,    _______,    KC_BTN3,    KC_MS_U,    KC_WH_U,    _______,                                     _______,    _______,    _______,    _______,    KC_PSCR,    KC_F12,
      _______,    KC_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,                                     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
      _______,    _______,    _______,    _______,    KC_WH_D,    _______,    _______,             _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
                              _______,    _______,    _______,    _______,    _______,             _______,    _______,    KC_QWERTY,  KC_GAME,    _______
    ),
};

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("qwert"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("game"), false);
            break;
        default:
            oled_write_P(PSTR("undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _GAME:
        case _QWERTY:
            oled_write_P(PSTR("base"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
    }
    return true;
}
