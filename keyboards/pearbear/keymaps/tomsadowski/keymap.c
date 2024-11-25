// tomsadowski
// keymap for split_3x5_2 keyboards

#include QMK_KEYBOARD_H
#include "action.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "process_combo.h"

//                                 . 3 3 . .          . . 3 3 .
const uint16_t PROGMEM    tab_cmb_l[] = {KC_C,    KC_H,    COMBO_END};
const uint16_t PROGMEM    tab_cmb_r[] = {KC_W,    KC_P,    COMBO_END};
//                           . 2 2 . .          . . 2 2 .
const uint16_t PROGMEM  shift_cmb_l[] = {KC_S,    KC_R,    COMBO_END};
const uint16_t PROGMEM  shift_cmb_r[] = {KC_I,    KC_O,    COMBO_END};
//                           . 1 1 . .          . . 1 1 .
const uint16_t PROGMEM   caps_cmb_l[] = {KC_F,    KC_L,    COMBO_END};
const uint16_t PROGMEM   home_cmb_r[] = {KC_M,    KC_G,    COMBO_END};
//                           3 . . 3 .          . 3 . . 3
const uint16_t PROGMEM    alt_cmb_l[] = {KC_X,    KC_B,    COMBO_END};
const uint16_t PROGMEM    alt_cmb_r[] = {KC_Y,    KC_J,    COMBO_END};
//                           2 . . 2 .          . 2 . . 2
const uint16_t PROGMEM   ctrl_cmb_l[] = {KC_A,    KC_T,    COMBO_END};
const uint16_t PROGMEM   ctrl_cmb_r[] = {KC_E,    KC_N,    COMBO_END};
//                           1 . . 1 .          . 1 . . 1
const uint16_t PROGMEM  rgate_cmb_l[] = {KC_X,    KC_Q,    COMBO_END};
const uint16_t PROGMEM  rgate_cmb_r[] = {KC_Z,    KC_J,    COMBO_END};
//                           3 . . . 3          3 . . . 3
const uint16_t PROGMEM    gui_cmb_l[] = {KC_T,    KC_X,    COMBO_END};
const uint16_t PROGMEM    gui_cmb_r[] = {KC_E,    KC_J,    COMBO_END};
//                           2 . . . 2          2 . . . 2
const uint16_t PROGMEM  arrow_cmb_l[] = {KC_A,    KC_D,    COMBO_END};
const uint16_t PROGMEM   nmbr_cmb_r[] = {KC_U,    KC_N,    COMBO_END};
//                           3 . . 2 .          . 2 . . 3
const uint16_t PROGMEM  mouse_cmb_l[] = {KC_V,    KC_D,    COMBO_END};
const uint16_t PROGMEM  mouse_cmb_r[] = {KC_U,    KC_K,    COMBO_END};
//                           2 . . 1 .          . 1 . . 2
const uint16_t PROGMEM game3d_cmb_l[] = {KC_DOT,  KC_N,    COMBO_END};
const uint16_t PROGMEM game2d_cmb_r[] = {KC_A,    KC_COMM, COMBO_END};
//                           . . . 3 2          2 3 . . .
const uint16_t PROGMEM    esc_cmb_l[] = {KC_B,    KC_COMM, COMBO_END};
const uint16_t PROGMEM  enter_cmb_r[] = {KC_DOT,  KC_Y,    COMBO_END};

enum combos
{
    // . 3 3 . .     . . 3 3 .
    TAB_CMB_L,     TAB_CMB_R,
    // . 2 2 . .     . . 2 2 .
    SHIFT_CMB_L,   SHIFT_CMB_R,
    // . 1 1 . .     . . 1 1 .
    CAPS_CMB_L,    HOME_CMB_R,
    // 3 . . 3 .     . 3 . . 3
    ALT_CMB_L,     ALT_CMB_R,
    // 2 . . 2 .     . 2 . . 2
    CTRL_CMB_L,    CTRL_CMB_R,
    // 1 . . 1 .     . 1 . . 1
    MOUSE_CMB_L,   MOUSE_CMB_R,
    // 3 . . . 3     3 . . . 3
    RGATE_CMB_L,   RGATE_CMB_R,
    // 2 . . . 2     2 . . . 2
    GAME3D_CMB_L,  GAME2D_CMB_R,
    // 3 . . 2 .     . 2 . . 3
    GUI_CMB_L,     GUI_CMB_R,
    // 2 . . 1 .     . 1 . . 2
    ARROW_CMB_L,   NMBR_CMB_R,
    // . . . 3 2     2 3 . . .
    ESC_CMB_L,     ENTER_CMB_R,
};

enum custom_keycodes
{
    RGATE = SAFE_RANGE,
    LAYOUT_HOME,
    CAPS_ON
};

enum layers
{
    ALPHA_LYR,
    NMBR_LYR,
    MOUSE_LYR_R,
    ARROW_LYR,
    MOUSE_LYR_L,
    GAME2D_LYR,
    GAME3D_LYR,
    ALPHA_FROM_NMBR_LYR,
    ALPHA_FROM_MOUSE_LYR,
    NMBR_FROM_OTHER_LYR,
    MOUSE_FROM_OTHER_LYR
};

combo_t key_combos[] =
{
    // . 3 3 . .     . . 3 3 .
    [TAB_CMB_L]    = COMBO(   tab_cmb_l, KC_TAB),
    [TAB_CMB_R]    = COMBO(   tab_cmb_r, KC_TAB),
    // . 2 2 . .     . . 2 2 .
    [SHIFT_CMB_L]  = COMBO( shift_cmb_l, KC_LEFT_SHIFT),
    [SHIFT_CMB_R]  = COMBO( shift_cmb_r, KC_RIGHT_SHIFT),
    // . 1 1 . .     . . 1 1 .
    [CAPS_CMB_L]   = COMBO(  caps_cmb_l, CAPS_ON),
    [HOME_CMB_R]   = COMBO(  home_cmb_r, LAYOUT_HOME),
    // 3 . . 3 .     . 3 . . 3
    [ALT_CMB_L]    = COMBO(   alt_cmb_l, KC_LEFT_ALT),
    [ALT_CMB_R]    = COMBO(   alt_cmb_r, KC_RIGHT_ALT),
    // 2 . . 2 .     . 2 . . 2
    [CTRL_CMB_L]   = COMBO(  ctrl_cmb_l, KC_LEFT_CTRL),
    [CTRL_CMB_R]   = COMBO(  ctrl_cmb_r, KC_RIGHT_CTRL),
    // 1 . . 1 .     . 1 . . 1
    [MOUSE_CMB_L]  = COMBO( mouse_cmb_l, TO(MOUSE_LYR_L)),
    [MOUSE_CMB_R]  = COMBO( mouse_cmb_r, TO(MOUSE_LYR_R)),
    // 3 . . . 3     3 . . . 3
    [RGATE_CMB_L]  = COMBO( rgate_cmb_l, RGATE),
    [RGATE_CMB_R]  = COMBO( rgate_cmb_r, RGATE),
    // 2 . . . 2     2 . . . 2
    [GAME3D_CMB_L] = COMBO(game3d_cmb_l, TO(GAME3D_LYR)),
    [GAME2D_CMB_R] = COMBO(game2d_cmb_r, TO(GAME2D_LYR)),
    // 3 . . 2 .     . 2 . . 3
    [GUI_CMB_L]    = COMBO(   gui_cmb_l, KC_LEFT_GUI),
    [GUI_CMB_R]    = COMBO(   gui_cmb_r, KC_RIGHT_GUI),
    // 2 . . 1 .     . 1 . . 2
    [ARROW_CMB_L]  = COMBO( arrow_cmb_l, TO(ARROW_LYR)),
    [NMBR_CMB_R]   = COMBO(  nmbr_cmb_r, TO(NMBR_LYR)),
    // . . . 3 2     2 3 . . .
    [ESC_CMB_L]    = COMBO(   esc_cmb_l, KC_ESCAPE),
    [ENTER_CMB_R]  = COMBO( enter_cmb_r, KC_ENTER),


};

// game layers disable some combos
bool combo_should_trigger(uint16_t combo_index,
                          combo_t* combo,
                          uint16_t keycode,
                          keyrecord_t* record)
{
    if (layer_state_is(GAME2D_LYR) ||
        layer_state_is(GAME3D_LYR))
    {
        switch (combo_index)
        {
            case HOME_CMB_R:
            case MOUSE_CMB_L:
            case MOUSE_CMB_R:
            case ARROW_CMB_L:
            case NMBR_CMB_R:
            case ESC_CMB_L:
            case ENTER_CMB_R:
                return true;
            default:
                return false;
        }
    }
    return true;
}

// shorten combo-term when in game layers for faster button-response
uint16_t get_combo_term(uint16_t index,
                        combo_t* combo)
{
    if (layer_state_is(GAME2D_LYR) ||
        layer_state_is(GAME3D_LYR))
    {
        return 6;
    }
    else
    {
        return COMBO_TERM;
    }
}

// switching to non-alpha layers breaks capsword
layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state))
    {
        case MOUSE_LYR_R ... GAME3D_LYR:
            caps_word_off();
            break;
        default:
            break;
    }
    return state;
}

// "escape" breaks capsword, "space" does not
bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode)
    {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LEFT_SHIFT));
            return true;
        case KC_ESCAPE:
            return false;
        default:
            return true;
    }
}

// rgate data and functions

typedef enum
{
    DECIDE,
    BLOCK,
    PASS,
    NONE
} rgate_state_t;

typedef struct
{
    rgate_state_t state;
    uint16_t last_pressed;
} rgate_t;

static rgate_t rgate =
{
    NONE,
    KC_NO
};

inline void reset_rgate(rgate_t rgate)
{
    rgate.state = NONE;
    rgate.last_pressed = KC_NO;
    clear_keyboard();
}

// process custom keys
bool process_record_user(uint16_t keycode,
                         keyrecord_t* record)
{
    switch (keycode)
    {
        case KC_A ... KC_RGUI:
            // rgate not used, stop evaluating ASAP
            if (rgate.state == NONE)
            {
                return true;
            }
            // rgate in use
            else if (record->event.pressed)
            {
                if (rgate.state == DECIDE)
                {
                    if (rgate.last_pressed == RGATE)
                    {
                        rgate.state = BLOCK;
                    }
                    else
                    {
                        rgate.state = PASS;
                    }
                    rgate.last_pressed = keycode;
                }
                else if (rgate.state == BLOCK)
                {
                    rgate.last_pressed = keycode;
                }
                return true;
            }
            else if (rgate.state == DECIDE)
            {
                if (rgate.last_pressed == RGATE)
                {
                    rgate.state = PASS;
                }
                else
                {
                    reset_rgate(rgate);
                }
                return false;
            }
            else if (rgate.state == BLOCK)
            {
                if (rgate.last_pressed == keycode)
                {
                    rgate.last_pressed = KC_NO;
                }
                else
                {
                    reset_rgate(rgate);
                }
                return false;
            }
            else if (rgate.state == PASS &&
                rgate.last_pressed == keycode)
            {
                reset_rgate(rgate);
            }
            return true;


        case RGATE:
            if (record->event.pressed)
            {
                rgate.state = DECIDE;
                rgate.last_pressed = RGATE;
            }
            else if (rgate.state != BLOCK)
            {
                reset_rgate(rgate);
            }
            else if (rgate.last_pressed == KC_NO)
            {
                rgate.state = DECIDE;
            }
            else
            {
                rgate.state = PASS;
            }
            return false;


        case LAYOUT_HOME:
            if (record->event.pressed)
            {
                caps_word_off();
                reset_rgate(rgate);
                layer_move(ALPHA_LYR);
            }
            return false;

        case CAPS_ON:
            if (record->event.pressed)
            {
                caps_word_on();
            }
            return false;

        default:
            return true;
    }
}


// layers

#define HOLD_MOUSE_TAP_SPACE            LT(MOUSE_FROM_OTHER_LYR, KC_SPC)
#define HOLD_NMBR_TAP_SPACE             LT(NMBR_FROM_OTHER_LYR,  KC_SPC)
#define HOLD_ALPHA_TAP_SPACE_FROM_NMBR  LT(ALPHA_FROM_NMBR_LYR,  KC_SPC)
#define HOLD_ALPHA_TAP_SPACE_FROM_MOUSE LT(ALPHA_FROM_MOUSE_LYR, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    // alpha layer (home layer)
    // - contains: alphabet, space, backspace, delete
    [ALPHA_LYR] = LAYOUT_split_3x5_2(
        KC_X,    KC_C,    KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,    KC_J,
        KC_A,    KC_S,    KC_R,    KC_T,    KC_COMMA,        KC_DOT,  KC_E,    KC_I,    KC_O,    KC_N,
        KC_V,    KC_F,    KC_L,    KC_D,    KC_QUOT,         KC_SCLN, KC_U,    KC_M,    KC_G,    KC_K,
                 KC_BSPC, HOLD_MOUSE_TAP_SPACE,              HOLD_NMBR_TAP_SPACE,       KC_DEL),
    // number layer
    // - contains: digits, arrow-keys, misc symbols, misc navigation
    [NMBR_LYR] = LAYOUT_split_3x5_2(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, _______,         HOLD_ALPHA_TAP_SPACE_FROM_NMBR,  _______),
    // mouse layer
    // - contains: function keys 1-14, printscreen, cursor direction/speed, scroll-wheel direction/speed,
    //             left and right click
    [MOUSE_LYR_R] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        _______, HOLD_ALPHA_TAP_SPACE_FROM_MOUSE,            KC_BTN1, KC_BTN2),
    // arrow layer
    // - contains the navigation keys found in the number layer, but under the left hand
    [ARROW_LYR] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,         _______, _______, _______, _______, _______,
        KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,         _______, _______, _______, _______, _______,
                                   _______, KC_SPC,          KC_SPC,  _______),
    // left mouse layer
    // - contains the mouse keys found in the mouse layer, but under the left hand
    [MOUSE_LYR_L] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,         _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR,
        KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,         _______, _______, _______, _______, _______,
                                   KC_BTN2, KC_BTN1,         KC_SPC,  _______),
    // 2D game layer
    // - same as alpha layer with the following exceptions:
    //  - HOLD_MOUSE_TAP_SPACE is now just "space" (hold for space, tap for space)
    //  - HOLD_NMBR_TAP_SPACE is now just "0" (hold for 0 tap for 0)
    //  - combo-window is shortened for quicker response times
    //  - only escape, enter, and layer-changing combos are enabled
    [GAME2D_LYR] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                   _______, KC_SPC,          KC_0,    _______),
    // 3D game layer
    // - like the 2D game layer but with mouse functionality under the right hand
    [GAME3D_LYR] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        _______, _______, _______, _______, _______,         _______, _______, KC_WH_D, KC_WH_U, _______,
                                   _______, KC_SPC,          KC_BTN1, KC_BTN2),
    // alpha-from-number layer
    // - alpha layer momentarily accessed from number layer
    [ALPHA_FROM_NMBR_LYR] = LAYOUT_split_3x5_2(
        KC_X,   KC_C,     KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,    KC_J,
        KC_A,   KC_S,     KC_R,    KC_T,    _______,         _______, KC_E,    KC_I,    KC_O,    KC_N,
        KC_V,   KC_F,     KC_L,    KC_D,    _______,         _______, KC_U,    KC_M,    KC_G,    KC_K,
                                   _______, KC_SPC,          _______, _______),
    // alpha-from-mouse layer
    // - alpha layer momentarily accessed from mouse layer
    [ALPHA_FROM_MOUSE_LYR] = LAYOUT_split_3x5_2(
        KC_X,   KC_C,     KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,     KC_J,
        KC_A,   KC_S,     KC_R,    KC_T,    _______,         _______, KC_E,    KC_I,    KC_O,     KC_N,
        KC_V,   KC_F,     KC_L,    KC_D,    _______,         _______, KC_U,    KC_M,    KC_G,     KC_K,
                                   _______, _______,         HOLD_NMBR_TAP_SPACE,       KC_DEL),
    // number-from-other layer
    // - number layer momentarily accessed from alpha layer or alpha-from-mouse layer
    [NMBR_FROM_OTHER_LYR] = LAYOUT_split_3x5_2(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, KC_SPC,          _______, _______),
    // mouse-from-other layer
    // - mouse layer momentarily accessed from alpha layer or number layer
    [MOUSE_FROM_OTHER_LYR] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                                   _______, _______,         KC_BTN1, KC_BTN2),
};

// HOLD_MOUSE_TAP_SPACE will go to mouse layer before TAPPING_TERM elapses if another key is pressed then released
bool get_permissive_hold(uint16_t keycode,
                         keyrecord_t* record)
{
    if (HOLD_MOUSE_TAP_SPACE)
    {
        return true;
    }
    return false;
}

// HOLD_NMBR_TAP_SPACE will go to number layer before TAPPING_TERM elapses if another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode,
                                 keyrecord_t* record)
{
    if (HOLD_NMBR_TAP_SPACE)
    {
        return true;
    }
    return false;
}
