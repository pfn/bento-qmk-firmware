// Copyright 2022 Perry Nguyen (@pfn)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RGB_H,
    _RGB_S,
    _RGB_V,
    _RGB_M,
    _RGB_E,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        LT(_RGB_H, KC_MPLY),  LT(_RGB_M, KC_MFFD),   LT(_FN, KC_MUTE),
        LT(_RGB_S, KC_MPRV),  LT(_RGB_V, KC_MNXT),   LT(_RGB_E, KC_MSTP)
    ),
    [_RGB_H] = LAYOUT(
        _______, _______,  _______,
        _______, _______,  _______
    ),
    [_RGB_S] = LAYOUT(
        _______, _______,  _______,
        _______, _______,  _______
    ),
    [_RGB_V] = LAYOUT(
        _______, _______,  _______,
        _______, _______,  _______
    ),
    [_RGB_M] = LAYOUT(
        _______, _______,  _______,
        _______, _______,  _______
    ),
    [_RGB_E] = LAYOUT(
        _______, _______,  _______,
        _______, _______,  _______
    ),
    [_FN] = LAYOUT(
        _______, _______,  _______,
        RESET,   _______,  _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state | default_layer_state)) {
      case _RGB_H:
        if (clockwise) rgblight_increase_hue(); else rgblight_decrease_hue();
        break;
      case _RGB_S:
        if (clockwise) rgblight_increase_sat(); else rgblight_decrease_sat();
        break;
      case _RGB_V:
        if (clockwise) rgblight_increase_val(); else rgblight_decrease_val();
        break;
      case _RGB_M:
        if (clockwise) rgblight_step(); else rgblight_step_reverse();
        break;
      case _RGB_E:
        if (clockwise) rgblight_increase_speed(); else rgblight_decrease_speed();
        break;
      default:     tap_code(clockwise ? KC_VOLU : KC_VOLD);
  }

  return false;
}
