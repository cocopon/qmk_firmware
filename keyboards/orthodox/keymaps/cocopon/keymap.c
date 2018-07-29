/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

// Tap Dance
enum taps {
  _TD_LBR = 0,
  _TD_RBR
};

void on_left_bracket_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // KC_LPRN
    register_code(KC_LSFT);
    register_code(KC_9);
  } else if (state->count == 2) {
    // KC_LCBR
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  } else {
    register_code(KC_LBRC);
  }
}

void on_left_bracket_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // KC_LPRN
    unregister_code(KC_LSFT);
    unregister_code(KC_9);
  } else if (state->count == 2) {
    // KC_LCBR
    unregister_code(KC_LSFT);
    unregister_code(KC_LBRC);
  } else {
    unregister_code(KC_LBRC);
  }
}

void on_right_bracket_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // KC_RPRN
    register_code(KC_LSFT);
    register_code(KC_0);
  } else if (state->count == 2) {
    // KC_RCBR
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  } else {
    register_code(KC_RBRC);
  }
}

void on_right_bracket_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // KC_RPRN
    unregister_code(KC_LSFT);
    unregister_code(KC_0);
  } else if (state->count == 2) {
    // KC_RCBR
    unregister_code(KC_LSFT);
    unregister_code(KC_RBRC);
  } else {
    unregister_code(KC_RBRC);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [_TD_LBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_left_bracket_dance_finished, on_left_bracket_dance_reset),
  [_TD_RBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_right_bracket_dance_finished, on_right_bracket_dance_reset)
};

#define TD_LBR TD(_TD_LBR)
#define TD_RBR TD(_TD_RBR)


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define ODX_LCTL MT(MOD_LCTL, KC_TAB)
#define ODX_RSFT MT(MOD_RSFT, KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_GRV,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT, \
    ODX_LCTL, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_LALT,  KC_LALT,        KC_RALT,  KC_RALT,            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,  \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     LOWER,    KC_LGUI,  KC_SPACE,       KC_SPACE, KC_RGUI,  RAISE,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  ODX_RSFT \
  ),
  [_LOWER] = LAYOUT( \
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                                                                    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC, \
    KC_TAB,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_DOWN,  KC_UP,          KC_LEFT,  KC_RIGHT,           KC_F11,   KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE, \
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,  KC_ESC,   KC_ESC,         KC_ESC,   KC_ESC,   _______,  KC_F12,   KC_HOME,  KC_COMM,  KC_DOT,   _______,  KC_EQL   \
  ),
  [_RAISE] = LAYOUT( \
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
    KC_TAB,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_DOWN,  KC_UP,          KC_LEFT,  KC_RIGHT,           KC_F11,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS, \
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,  KC_ESC,   KC_ESC,         KC_ESC,   KC_ESC,   _______,  KC_F12,   KC_PGUP,  KC_COMM,  KC_DOT,   _______,  KC_EQL   \
  ),
  [_ADJUST] = LAYOUT( \
    RESET,    _______,  _______,  _______,  KC_WH_U,  _______,                                                                    _______,  _______,  _______,  _______,  _______,  RESET,   \
    _______,  _______,  _______,  _______,  KC_WH_D,  _______,            _______,  _______,        _______,  _______,            KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______, \
    _______,  _______,  _______,  _______,  _______,  KC_BTN1,  _______,  _______,  _______,        _______,  _______,  _______,  KC_BTN2,  _______,  _______,  _______,  _______,  _______  \
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  }
  return true;
}
