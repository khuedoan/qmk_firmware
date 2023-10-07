#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _SYM,
    _NAV,
    _FUNC,
    _GAME,
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_GAME,

    KC_SYMBSPC = LT(_SYM, KC_BSPC),
    KC_NAVSPC = LT(_NAV, KC_SPC),
    KC_SHIENT = MT(MOD_RSFT, KC_ENT),
    KC_XCAPE = MT(MOD_LCTL, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
        KC_XCAPE,   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,             XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SHIENT,
        /*    */    /*    */    KC_LCTL,    MO(_NAV),   KC_LALT,    KC_LGUI,    KC_SPC,              KC_SYMBSPC, KC_NAVSPC,  MO(_FUNC),  KC_RGUI,    KC_RCTL     /*    */    /*    */
    ),

    [_SYM] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                     KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,
        _______,    KC_GRV,     _______,    _______,    _______,    _______,                                     KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    _______,
        _______,    KC_TILD,    _______,    _______,    _______,    _______,    _______,             _______,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,    _______,
        /*    */    /*    */    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______     /*    */    /*    */
    ),

    [_NAV] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    KC_BTN3,    KC_MS_U,    KC_WH_U,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,                                     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
        _______,    _______,    _______,    _______,    KC_WH_D,    _______,    _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
        /*    */    /*    */    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______     /*    */    /*    */
    ),

    [_FUNC] = LAYOUT(
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                       KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    KC_PSCR,    KC_F12,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
        /*    */    /*    */    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    KC_BASE,    KC_GAME     /*    */    /*    */
    ),

    [_GAME] = LAYOUT(
        KC_ESC,     _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        KC_LCTL,    _______,    _______,    _______,    _______,    _______,                                     _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______,    _______,    _______,
        /*    */    /*    */    _______,    _______,    _______,    _______,    _______,             _______,    _______,    _______,    _______,    _______     /*    */    /*    */
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
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
