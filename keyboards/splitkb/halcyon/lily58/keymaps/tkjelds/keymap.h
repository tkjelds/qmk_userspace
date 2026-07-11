#pragma once
#include "quantum_keycodes.h"
typedef enum { _BASE = 0, _NUM_ROW = 1, _SYMBOL = 2, _MEDIA = 3 } layers_id;
// Aliases for readability
#define NUM_ROW MO(1)
#define SYMBOL MO(2)
#define MEDIA MO(3)

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
#define T_ENT LT(_SYMBOL, KC_ENT)
#define T_BSPC LT(_NUM_ROW, KC_BSPC)
#define L_TAB LSFT(KC_TAB)

// Volume/Media control
#define VOLU KC_AUDIO_VOL_UP
#define VOLD KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define NEXT KC_MEDIA_NEXT_TRACK
#define PREV KC_MEDIA_PREV_TRACK

// Custom keycodes
typedef enum {
    LMNT = SAFE_RANGE,
}custom_keycodes;
