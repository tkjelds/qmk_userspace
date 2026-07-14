#pragma once
#include "quantum_keycodes.h"
// Layers
typedef enum { _BASE_WIN = 0, _BASE_MAC = 1, _NUM_ROW = 4, _SYMBOL_WIN = 2, _SYMBOL_MAC = 3,  _MEDIA = 5 } layers_id;

// Aliases for readability
#define NUM_ROW MO(_NUM_ROW)
#define SYMBOL_WIN MO(_SYMBOL_WIN)
#define SYMBOL_MAC MO(_SYMBOL_MAC)
#define MEDIA MO(_MEDIA)

#define FRNT LALT(KC_RIGHT)
#define BACK LALT(KC_LEFT)
#define ACPT LCTL(DK_Y)
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
#define WT_ENT LT(_SYMBOL_WIN, KC_ENT)
#define MT_ENT LT(_SYMBOL_MAC, KC_ENT)
#define T_BSPC LT(_NUM_ROW, KC_BSPC)
#define L_TAB LSFT(KC_TAB)

// Volume/Media control
#define VOLU KC_AUDIO_VOL_UP
#define VOLD KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define NEXT KC_MEDIA_NEXT_TRACK
#define PREV KC_MEDIA_PREV_TRACK

//  Custom keycodes
enum custom_keycodes {
    LMNT = SAFE_RANGE,
};

// Default layer switch
#define DF_MAC DF(_BASE_MAC)
#define DF_WIN DF(_BASE_WIN)
// Mac aliases
#define M_PIPE RALT(DK_I)// |
#define M_LCBR RALT(LSFT(KC_8)) //{
#define M_RCBR RALT(LSFT(KC_9)) //{
#define M_DLLR LSFT(KC_4) // $ 
#define M_BSLH RALT(LSFT(KC_7)) // 
#define M_AT RALT(DK_QUOT) // @ 
