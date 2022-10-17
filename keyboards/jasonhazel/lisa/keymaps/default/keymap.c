#include QMK_KEYBOARD_H

enum lisa_layers {
  _NUMPAD,
  LAYER_LENGTH
};

enum lisa_combos {
  COMBO_LENGTH
};

enum lisa_tapdances {
  TAPDANCE_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
combo_t key_combos[] = {
  NULL
};

qk_tap_dance_action_t tap_dance_actions[] = {
  NULL
};

const key_override_t **key_overrides = (const key_override_t *[]) {
  NULL
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