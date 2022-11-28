#include QMK_KEYBOARD_H

enum lisa_layers {
  _NUMPAD,
  LAYER_LENGTH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NUMPAD] = LAYOUT(
    KC_ESC,   KC_BSPC,  KC_BSLS,  KC_ASTR,
    KC_7,     KC_8,     KC_9,     KC_MINS,
    KC_4,     KC_5,     KC_6,     KC_PLUS,
    KC_1,     KC_2,     KC_3,     KC_EQL ,
    KC_COMM,  KC_0,     KC_DOT,   KC_ENT
  ),
};