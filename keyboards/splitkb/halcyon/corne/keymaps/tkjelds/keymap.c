#include "keymap.h"
#include <stdbool.h>
#include <stdint.h>
#include "keycodes.h"
#include "keymap_danish.h"
#include "os_detection.h"
#include "process_combo.h"
#include "progmem.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H //NOLINT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE_WIN] = LAYOUT_corne_hlc(
        KC_TAB	   , DK_Q	   , DK_W	   , DK_E	   , DK_R	   , DK_T	           , DK_Y	   , DK_U	   , DK_I	   , DK_O	   , DK_P	   , DK_ARNG ,
        DK_DQUO	   , HR_A      , HR_S	   , HR_D	   , HR_F	   , DK_G	           , DK_H	   , HR_J	   , HR_K	   , HR_L	   , HR_AE     , DK_OSTR ,
        DK_QUOT	   , DK_Z	   , DK_X	   , DK_C	   , DK_V	   , DK_B	           , DK_N	   , DK_M	   , DK_COMM   , DK_DOT	   , DK_MINS   , DK_UNDS ,
                                             MS_BTN1   , T_ESC     , KC_SPC	           , WT_ENT	   , T_BSPC	   , KC_DEL,
                     KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO             , KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,

    [_BASE_MAC] = LAYOUT_corne_hlc(
        KC_TAB	   , DK_Q	   , DK_W	   , DK_E	   , DK_R	   , DK_T	           , DK_Y	   , DK_U	   , DK_I	   , DK_O	   , DK_P	   , DK_ARNG ,
        DK_DQUO	   , HR_A      , HR_S	   , HR_D	   , HR_F	   , DK_G	           , DK_H	   , HR_J	   , HR_K	   , HR_L	   , HR_AE     , DK_OSTR ,
        DK_QUOT	   , DK_Z	   , DK_X	   , DK_C	   , DK_V	   , DK_B	           , DK_N	   , DK_M	   , DK_COMM   , DK_DOT	   , DK_MINS   , DK_UNDS ,
                                             KC_LGUI   , T_ESC     , KC_SPC	           , MT_ENT	   , T_BSPC	   , KC_DEL,
                     KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO             , KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,

    [_NUM_ROW] =   LAYOUT_corne_hlc(
        KC_TAB	   , DK_1	   , DK_2	   , DK_3	   , DK_4	   , DK_5	           , DK_6	   , DK_7	   , DK_8	   , DK_9	   , DK_0	   , KC_NO ,
        KC_F1	   , KC_F2     , KC_F3	   , KC_F4	   , KC_F5	   , KC_F6	           , KC_LEFT   , KC_DOWN   , KC_UP	   , KC_RIGHT  , KC_APP    , KC_NO ,
        KC_F7	   , KC_F8	   , KC_F9	   , KC_F10	   , KC_F11	   , KC_F12	           , KC_HOME   , KC_PGDN   , KC_PGUP   , KC_END    , BACK     , FRNT  ,
                                             KC_TRNS   , MEDIA	   , KC_SPC	           , ACPT      , MEDIA	   , KC_RALT,
                     KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO             , KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,

    [_SYMBOL_WIN] =  LAYOUT_corne_hlc(
        L_TAB	   , DK_GRV	   , DK_LABK   , DK_RABK   , DK_MINS   , DK_SLSH	       , DK_CIRC   , DK_LCBR   , DK_RCBR   , DK_DLR	   , KC_NO	   , KC_NO ,
        KC_CAPS	   , DK_EXLM   , DK_ASTR   , DK_QUES   , DK_EQL	   , DK_AMPR	       , DK_PIPE   , DK_LPRN   , DK_RPRN   , DK_SCLN   , DK_BSLS   , KC_NO ,
        KC_NO	   , DK_TILD   , DK_PLUS   , DK_LBRC   , DK_RBRC   , DK_PERC	       , DK_AT	   , DK_COLN   , DK_HASH   , KC_TRNS   , KC_TRNS   , KC_TRNS  ,
                                             KC_TRNS   , MEDIA	   , KC_SPC	           , KC_ENT	   , MEDIA	   , KC_RALT,
                     KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO             , KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,
    [_SYMBOL_MAC] =  LAYOUT_corne_hlc(
        L_TAB	   , DK_GRV	   , DK_LABK   , DK_RABK   , DK_MINS   , DK_SLSH	       , DK_CIRC   , DK_LCBR   , DK_RCBR   , DK_DLR	   , KC_NO	   , KC_NO ,
        KC_CAPS	   , DK_EXLM   , DK_ASTR   , DK_QUES   , DK_EQL	   , DK_AMPR	       , DK_PIPE   , DK_LPRN   , DK_RPRN   , DK_SCLN   , DK_BSLS   , KC_NO ,
        KC_NO	   , DK_TILD   , DK_PLUS   , DK_LBRC   , DK_RBRC   , DK_PERC	       , DK_AT	   , DK_COLN   , DK_HASH   , KC_TRNS   , KC_TRNS   , KC_TRNS  ,
                                             KC_TRNS   , MEDIA	   , KC_SPC	           , KC_ENT	   , MEDIA	   , KC_RALT,
                     KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO             , KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,

    [_MEDIA] =  LAYOUT_corne_hlc(
        KC_TAB	  , KC_EXLM	  , KC_AT	  , KC_HASH	  , KC_DLR	  , KC_PERC	         , DF_WIN, DF_MAC, KC_ASTR	  , KC_LPRN	  , KC_RPRN	  , KC_BSPC	  ,
        KC_LCTL	  , XXXXXXX	  , RM_SPDD   , RM_SPDU   , XXXXXXX	  , XXXXXXX	         , KC_MINS	  , KC_VOLD   , KC_VOLU   , KC_RBRC	  , KC_BSLS	  , KC_GRV	  ,
        KC_LSFT	  , XXXXXXX	  , RM_VALD   , RM_VALU   , LMNT      , XXXXXXX	         , KC_UNDS	  , KC_PLUS	  , KC_LCBR	  , KC_RCBR	  , KC_PIPE	  , KC_TILD	  ,
                                            KC_LGUI   , _______   , KC_SPC           , KC_ENT     , _______   , KC_RALT ,
                    KC_MUTE   , KC_NO     , KC_NO     , KC_NO     , KC_NO            , KC_MUTE    , KC_NO     , KC_NO     , KC_NO     , KC_NO)  ,
};
// clang-format on
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [2] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [3] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// combos
// const uint16_t PROGMEM ew_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM cv_combo[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[]   = {KC_V, KC_B, COMBO_END};
combo_t                key_combos[] = {
    COMBO(cv_combo, MS_BTN1),
    COMBO(vb_combo, MS_BTN2),
}; // clang-format off

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

os_variant_t current_os = OS_UNSURE;
void housekeeping_task_user(void) {
    os_variant_t detected = detected_host_os();

    if (detected != current_os) {
        current_os = detected;

        switch (current_os) {
            case OS_MACOS:
            case OS_IOS:
                default_layer_set(1UL << _BASE_MAC);
                break;

            case OS_WINDOWS:
            case OS_LINUX:
                default_layer_set(1UL << _BASE_WIN);
                break;

            default:
                break;
        }
    }
}

void keyboard_post_init_user(void) {
    // Set the effect.
    rgb_matrix_mode_noeeprom(RGB_MATRIX_COMMUNITY_MODULE_PALETTEFX_RIPPLE);
    // Set the palette and maximize saturation and brightness.
    uint8_t palette_index = PALETTEFX_POLARIZED; // Set Carnival palette.
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette_index, 255, 255);
    // Set speed to default.
    rgb_matrix_set_speed_noeeprom(64);
    // Make sure RGB Matrix is on.
    rgb_matrix_enable_noeeprom();
}
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case LMNT:
            lumino_cycle_3_state();
            return true;
            break;
        }
    return true;
}

