#include "keycodes.h"
#include "keymap_danish.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H //NOLINT

// Layers
enum layers{
    _BASE = 0,
    _NUM_ROW = 1,
    _SYMBOL = 2,
    _MEDIA = 3
};
// Aliases for readability
#define NUM_ROW DF(1)
#define SYMBOL DF(2)
#define MEDIA DF(3)

#define FRNT LALT(KC_RIGHT)
#define BACK LALT(KC_LEFT)
// Homerow Aliases
#define HR_A LGUI_T(DK_A)
#define HR_S LALT_T(DK_S)
#define HR_D LSFT_T(DK_D)
#define HR_F LCTL_T(DK_F)

#define HR_J LCTL_T(DK_J)
#define HR_K LSFT_T(DK_K)
#define HR_L LALT_T(DK_L)
#define HR_AE LGUI_T(DK_AE)

// Layer tap aliases
#define T_ESC LT(_NUM_ROW, KC_ESC)
#define T_ENT LT(_SYMBOL, KC_ENT)
#define T_BSPC LT(_NUM_ROW, KC_BSPC)
#define L_TAB LSFT(KC_TAB)





// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB	   , DK_Q	   , DK_W	   , DK_E	   , DK_R	   , DK_T	           , DK_Y	   , DK_U	   , DK_I	   , DK_O	   , DK_P	   , DK_ARNG ,
        DK_DQUO	   , HR_A      , HR_S	   , HR_D	   , HR_F	   , DK_G	           , DK_H	   , HR_J	   , HR_K	   , HR_L	   , HR_AE     , DK_OSTR ,
        DK_QUOT	   , DK_Z	   , DK_X	   , DK_C	   , DK_V	   , DK_B	           , DK_N	   , DK_M	   , DK_COMM   , DK_DOT	   , DK_MINS   , DK_UNDS ,
                                             KC_LGUI   , T_ESC	   , KC_SPC	           , T_ENT	   , T_BSPC	   , KC_DEL)  ,


    [_NUM_ROW] = LAYOUT_split_3x6_3(
        KC_TAB	   , DK_1	   , DK_2	   , DK_3	   , DK_4	   , DK_5	           , DK_6	   , DK_7	   , DK_8	   , DK_9	   , DK_0	   , KC_NO ,
        KC_F1	   , KC_F2     , KC_F3	   , KC_F4	   , KC_F5	   , KC_F6	           , KC_LEFT   , KC_DOWN   , KC_UP	   , KC_RIGHT  , KC_APP    , KC_NO ,
        KC_F7	   , KC_F8	   , KC_F9	   , KC_F10	   , KC_F11	   , KC_F12	           , KC_END	   , KC_PGDN   , KC_PGUP   , KC_HOME   , BACK     , FRNT  ,
                                             KC_TRNS   , MEDIA	   , KC_SPC	           , KC_ENT	   , MEDIA	   , KC_RALT),

    [_SYMBOL] = LAYOUT_split_3x6_3(
        L_TAB	   , DK_GRV	   , DK_LABK   , DK_RABK   , DK_MINS   , DK_SLSH	       , DK_CIRC   , DK_LBRC   , DK_RBRC   , DK_DLR	   , KC_NO	   , KC_NO ,
        KC_CAPS	   , DK_EXLM   , DK_ASTR   , DK_QUES   , DK_EQL	   , DK_AMPR	       , DK_PIPE   , DK_LPRN   , DK_RPRN   , DK_SCLN   , DK_BSLS   , KC_NO ,
        KC_NO	   , DK_TILD   , DK_PLUS   , DK_LBRC   , KC_RBRC   , DK_PERC	       , DK_AT	   , DK_COLN   , DK_HASH   , KC_TRNS   , KC_TRNS   , KC_TRNS  ,
                                             KC_TRNS   , MEDIA	   , KC_SPC	           , KC_ENT	   , MEDIA	   , KC_RALT),

    [_MEDIA] = LAYOUT_split_3x6_3(KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, KC_LGUI, MO(3), KC_SPC, KC_ENT, _______, KC_RALT),
};
// clang-format on
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [2] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [3] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}
