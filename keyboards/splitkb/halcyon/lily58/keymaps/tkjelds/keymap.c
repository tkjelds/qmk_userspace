#include <stdbool.h>
#include <stdint.h>
#include "action_layer.h"
#include "config.h"
#include "keyboard.h"
#include "keycodes.h"
#include "keymap_danish.h"
#include "keymap_us.h"
#include "os_detection.h"
#include "process_combo.h"
#include "progmem.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "rgb_matrix.h"
#include "keymap.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_WIN] = LAYOUT(
        KC_ESC	, DK_1	, DK_2	, DK_3	, DK_4	, DK_5	,                   DK_6	, DK_7	, DK_8	, DK_9	, DK_0	, DK_PLUS	,
        KC_TAB	, DK_Q	, DK_W	, DK_E	, DK_R	, DK_T	,                   DK_Y	, DK_U	, DK_I	, DK_O	, DK_P	, DK_ARNG 	,
        KC_BSPC , HR_A	, HR_S  , HR_D  , HR_F	, DK_G	,                   DK_H	, HR_J  , HR_K  , HR_L  , HR_AE , DK_OSTR 	,
        DK_DQUO , DK_Z	, DK_X	, DK_C	, DK_V	, DK_B	, KC_F13 , KC_F14 , DK_N	, DK_M	, DK_COMM, DK_DOT, DK_MINS, DK_UNDS,
                        MS_BTN1 ,KC_ESC,NUM_ROW, KC_SPC ,                   KC_ENT, SYMBOL_WIN,CW_TOGG ,  KC_F15),
// keyencoder
    [_BASE_MAC] = LAYOUT(
        KC_ESC	, DK_1	, DK_2	, DK_3	, DK_4	, DK_5	,                   DK_6	, DK_7	, DK_8	, DK_9	, DK_0	, DK_PLUS	,
        KC_TAB	, DK_Q	, DK_W	, DK_E	, DK_R	, DK_T	,                   DK_Y	, DK_U	, DK_I	, DK_O	, DK_P	, DK_ARNG 	,
        KC_BSPC , HR_A	, HR_S  , HR_D  , HR_F	, DK_G	,                   DK_H	, HR_J  , HR_K  , HR_L  , HR_AE , DK_OSTR 	,
        DK_DQUO, DK_Z	, DK_X	, DK_C	, DK_V	, DK_B	, KC_F13 , KC_F14   , DK_N	, DK_M	, DK_COMM, DK_DOT, DK_MINS, DK_UNDS,
// keyencoder
                           MS_BTN1 ,KC_ESC,NUM_ROW , KC_SPC,                     KC_ENT, SYMBOL_MAC,CW_TOGG ,  KC_F15),

    [_NUM_ROW] = LAYOUT(
        KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS	, KC_TRNS	, KC_TRNS	,
        KC_TRNS	, DK_1	, DK_2	, DK_3	, DK_4	, DK_5	,                   DK_6	, DK_7	, DK_8	, DK_9	, DK_0	, KC_TRNS	 	,
        KC_F1   , KC_F2 , KC_F3	, KC_F4	, KC_F5	, KC_F6 ,                   KC_LEFT , KC_DOWN, KC_UP, KC_RIGHT, KC_APP, KC_NO,
        KC_F7   , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12	, KC_F16   , KC_F17   ,KC_HOME   , KC_PGDN   , KC_PGUP   , KC_END    , BACK     , FRNT  ,
                          KC_TRNS	 , KC_TRNS	,MEDIA, KC_TRNS	,              ACPT , MEDIA , KC_TRNS, KC_NO),

// keyencoder

    [_SYMBOL_WIN] = LAYOUT(
        KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS	, KC_TRNS	, KC_TRNS	,
        L_TAB	   , DK_GRV	   , DK_LABK   , DK_RABK   , DK_MINS   , DK_SLSH	       , DK_CIRC   , DK_LCBR   , DK_RCBR   , DK_DLR	   , KC_NO	   , KC_NO ,
        DK_QUOT, DK_EXLM   , DK_ASTR   , DK_QUES   , DK_EQL	   , DK_AMPR	       , DK_PIPE   , DK_LPRN   , DK_RPRN   , DK_SCLN   , DK_BSLS   , KC_NO ,
        DK_DQUO, DK_TILD   , DK_PLUS   , DK_LBRC   , DK_RBRC   , DK_PERC	, KC_F18   , KC_F19  , DK_AT	   , DK_COLN   , DK_HASH   , KC_TRNS   , KC_TRNS   , KC_TRNS  ,
                          KC_NO , KC_TRNS	, MEDIA,     KC_TRNS	,               KC_TRNS	 , KC_TRNS	, KC_TRNS	 , KC_TRNS	 ),
// keyencoder
    [_SYMBOL_MAC] = LAYOUT(
        KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS	, KC_TRNS, KC_TRNS, KC_TRNS	, KC_TRNS	, KC_TRNS	,
        L_TAB	   , DK_GRV	   , DK_LABK   , DK_RABK   , DK_MINS   , DK_SLSH	       , DK_CIRC   , M_LCBR , M_RCBR , M_DLLR , KC_NO	   , KC_NO ,
        KC_QUOT , DK_EXLM   , DK_ASTR   , DK_QUES   , DK_EQL	   , DK_AMPR	       , M_PIPE , DK_LPRN   , DK_RPRN   , DK_SCLN   , KC_GRV , KC_NO ,
        KC_DQUO, DK_TILD   , DK_PLUS   , DK_LBRC   , DK_RBRC   , DK_PERC	, KC_F18   , KC_F19  , M_AT , DK_COLN   , DK_HASH   , KC_TRNS   , KC_TRNS   , KC_TRNS  ,
                          KC_NO , KC_TRNS	, MEDIA,     KC_TRNS	,               KC_TRNS	 , KC_TRNS	, KC_TRNS	 , KC_TRNS	 ),

    [_MEDIA] = LAYOUT(
        KC_NO , KC_NO	, KC_NO	  , KC_NO	, KC_NO	    , KC_NO	,                   KC_NO	, KC_NO	, KC_NO	, KC_NO	, KC_NO	, KC_NO	,
        KC_NO , KC_NO	, RM_SPDD , RM_SPDU , KC_NO     , LMNT,                   DF_WIN, DF_MAC, KC_NO	, KC_NO	, KC_NO	, KC_NO 	,
        KC_NO , KC_NO	 , RM_PREV  , RM_VALU , RM_VALD    , RM_NEXT   	,                  PREV, VOLD ,VOLU, NEXT, KC_NO , KC_NO 	,
        KC_NO , KC_NO  , RM_HUED  , RM_SATD , RM_SATU   , RM_HUEU, KC_F20   , KC_F21  ,  MUTE , KC_NO	, KC_NO	, KC_NO	, KC_NO	, KC_NO,
                     KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS   , KC_TRNS, KC_TRNS , KC_TRNS )
};
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM cv_combo[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[]   = {KC_V, KC_B, COMBO_END};
combo_t                key_combos[] = {
    COMBO(cv_combo, MS_BTN1),
    COMBO(vb_combo, MS_BTN2),
};

// bool is_flow_tap_key(uint16_t keycode) {
//     if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
//         return false; // Disable Flow Tap on hotkeys.
//     }
//     switch (get_tap_keycode(keycode)) {
//         case KC_SPC:
//         case KC_A ... KC_Z:
//         case KC_DOT:
//         case KC_COMM:
//         case KC_SCLN:
//         case KC_SLSH:
//             return true;
//     }
//     return false;

// uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
//
//     switch (keycode) {
//         case HR_A :
//         case HR_AE :
//             return 175;  // Disable Flow Tap for this key.
//         default:
//             return FLOW_TAP_TERM;
//     }
// }
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
    rgb_matrix_mode_noeeprom(RGB_MATRIX_COMMUNITY_MODULE_PALETTEFX_FLOW);
    // Set the palette and maximize saturation and brightness.
    uint8_t palette_index = PALETTEFX_BADWOLF;
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

