#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _FUNC,
    _MOUSE,
    _GAME,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,

    KC_XFUNC = LT(_FUNC, KC_ESC),
    KC_XNAV = LT(_NAV, KC_SPC),
    KC_XMOUSE = LT(_MOUSE, KC_TAB),
    KC_XSYM = LT(_SYM, KC_BSPC),
    KC_XNUM = LT(_NUM, KC_SPC),

    KC_HRM_A = MT(MOD_LSFT, KC_A),
    KC_HRM_S = MT(MOD_LGUI, KC_S),
    KC_HRM_D = MT(MOD_LALT, KC_D),
    KC_HRM_F = MT(MOD_LCTL, KC_F),
    KC_HRM_J = MT(MOD_RCTL, KC_J),
    KC_HRM_K = MT(MOD_RALT, KC_K),
    KC_HRM_L = MT(MOD_RGUI, KC_L),
    KC_HRM_BS = MT(MOD_RSFT, KC_BSPC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,
        XXXXXXX,    KC_HRM_A,   KC_HRM_S,   KC_HRM_D,   KC_HRM_F,   KC_G,                                        KC_H,       KC_HRM_J,   KC_HRM_K,   KC_HRM_L,   KC_HRM_BS,  XXXXXXX,
        XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,             XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                XXXXXXX,    XXXXXXX,    KC_XFUNC,   KC_XNAV,    KC_XMOUSE,           KC_XSYM,    KC_XNUM,    KC_ENT,     XXXXXXX,    XXXXXXX
    ),

    [_NUM] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_BSLS,    KC_1,       KC_2,       KC_3,       KC_EQL,                                      _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_LBRC,    KC_4,       KC_5,       KC_6,       KC_MINS,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_RBRC,    KC_7,       KC_8,       KC_9,       KC_0,       _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    KC_GRV,     KC_SCLN,    KC_QUOT,             _______,    _______,    _______,    _______,    _______
    ),

    [_SYM] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_PIPE,    KC_EXLM,    KC_AT,      KC_HASH,    KC_PLUS,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_LCBR,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_UNDS,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_RCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    KC_TILD,    KC_COLN,    KC_DQUO,             _______,    _______,    _______,    _______,    _______
    ),

    [_NAV] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    _______,
                                _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______
    ),

    [_FUNC] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F12,                                      _______,    _______,    _______,    _______,    KC_PSCR,    _______,
        _______,    _______,    KC_F4,      KC_F5,      KC_F6,      KC_F11,                                      _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,             _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______
    ),

    [_MOUSE] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,             KC_BTN3,    KC_BTN1,    KC_BTN2,    _______,    _______
    ),

    [_GAME] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _FUNC);
}

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
