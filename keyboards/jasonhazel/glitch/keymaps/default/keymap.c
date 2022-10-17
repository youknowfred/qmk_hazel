#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _SYMBOL,
  _NUMBER,
  _NAVIGATION,
  LAYER_LENGTH
};


enum tapdances {
  TD_QESC,
  TD_SBKT,
  TD_CBKT,
  TD_PARN,
  TD_LTGT,
  TD_ATAB,
  TAPDANCE_LENGTH
};

enum combos {
  COMBO_NAVIGATION,
  COMBO_LENGTH
};


// begin tapdances
#define KC_QESC     TD(TD_QESC)
#define KC_SBKT     TD(TD_SBKT)
#define KC_CBKT     TD(TD_CBKT)
#define KC_PARN     TD(TD_PARN)
#define KC_LTGT     TD(TD_LTGT)
#define KC_ATAB     TD(TD_ATAB)

#define KC_GUIX     LGUI_T(KC_X)
#define KC_ALTC     LALT_T(KC_C)

// oneshots
#define KC_OSFT   OSM(MOD_LSFT)
#define KC_OALT   OSM(MOD_LALT)

// layer changing
#define KC_OSYM   OSL(_SYMBOL)
#define KC_ONUM   LT(_NUMBER, KC_BSPC)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GUIX:
        case KC_ALTC:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}

// tapdances
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_SBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_CBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PARN]   = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_LTGT]   = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_ATAB]   = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB)
};
// end tapdances

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_navigation[] = { KC_OSYM, KC_ONUM, COMBO_END };
combo_t key_combos[] = {
  [COMBO_NAVIGATION]        = COMBO(combo_navigation, OSL(_NAVIGATION)),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch(index) {
    case COMBO_NAVIGATION: // extending the combo term here helps reduce sticky layers some more.
      return 250;
    default:
      return COMBO_TERM;
  }
}
// end combos


// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT(
    KC_QESC,    KC_W,       KC_E,       KC_R,       KC_T,             KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       \
    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,             KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,    \
    KC_Z,       KC_GUIX,    KC_ALTC,    KC_V,       KC_B,             KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    \
                KC_LALT,    KC_LCTL,    KC_OSYM,    KC_OSFT,          KC_SPC,     KC_ONUM,    KC_ENT,     KC_ENT
  ),
  [_SYMBOL] = LAYOUT(
    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,          KC_CIRC,     KC_AMPR,   KC_ASTR,    KC_NO,      KC_PIPE,    \
    KC_GRV,     KC_NO,      KC_UNDS,    KC_EQL,     KC_NO,            KC_SBKT,     KC_CBKT,   KC_PARN,    KC_LTGT,    KC_BSLASH,  \
    KC_NO,      KC_NO,      KC_PLUS,    KC_MINS,    KC_NO,            KC_NO,       KC_NO,     KC_COLN,    KC_DOT,     KC_SCLN,    \
                KC_LALT,     KC_LCTL,    KC_OSYM,    KC_OSFT,          KC_SPC,     KC_ONUM,    KC_ENT,     KC_ENT
  ),
  [_NUMBER] = LAYOUT(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,             KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,            KC_NO,      KC_NO,      KC_NO,      KC_DOT,     KC_NO,      \
                KC_LALT,    KC_LCTL,    KC_OSYM,    KC_OSFT,          KC_SPC,     KC_ONUM,    KC_ENT,     KC_ENT
  ),
  [_NAVIGATION] = LAYOUT(
    KC_NO,      KC_F2,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_HOME,    KC_UP,      KC_END,     KC_BSPC,    \
    KC_TAB,     KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_ENT,     \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_DEL,     \
                KC_LALT,    KC_LCTL,    KC_OSYM,    KC_OSFT,          KC_SPC,     KC_ONUM,    KC_ENT,   KC_ENT
  )
};

void suspend_power_down_user(void) { oled_off(); }
void suspend_wakup_init_user(void) { oled_on();  }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

    // void render_logo(void) {
    //     static const unsigned char PROGMEM raw_logo[] = {
    //         0,  0, 64,  1,224,240,250,252,252,252,252,254,254,254,254,254,254,254,254,252,252,248,248,251,228,248, 48,252,254,252,252,252,252,252,253,240,240, 48,216,  1,130,  2,192,  3, 50,  0,254,255,254,254,254,254,254,254,245,240,253,252,252,252,252,252,252,252,252,252,252,252,253,254,252,254,252,252,252,254,254,240,240,247,240,248,252,252,252,254,254,254,254,254,254,254,252,252,252,248,248,232,226,255,252,252,252,252,254,252,252,240,242,  0, 64,  4,252,252,252,252,252,252,252,252,242,240,  0,  0,  0,  0,  0,  0,
    //         0,  0,125,127,255,255,255,255,255,255,255,255,255,255,247,247,243,243,243,247,247,255,255,255,255,255,195,255,255,255,255,255,255,255,255,255,255,192,196,192,  0, 28,  1,  0,  0,  8,127,127,255,255,255,255,255,255,255,255,193,231,207,  7,  7,  7,127,255,255,255,255,255,255,255,255,255,215,215,215, 23,127,127,255,255,255,255,255,255,255,255,255,207,199,243,  3, 11,  3,  7, 15, 15, 63, 63,127,255,127,255,255,255,255,255,255,255,255,252,252,252,255,255,255,255,255,255,255,255,255,255,192,192,200, 16,  0,  0, 
    //         0, 18, 32, 68,  3,  3,  3,103,127,255,255,255,255,255,255,255,255,231,255,223,255,255,255,255,255,255,255,255,255,255, 35, 67,255,255,255,255,255,255,255,255,254,224,224,227,228,232,224,224,243,211, 35,255,255,255,255,255,255,255,255,254,102,130,  3,  1,  3,  3,  3,255,255,255,255,255,255,255,255,254,  0,104, 67,131, 23, 19, 31,255,255,255,255,255,255,255,254,240,224,192,192,192,224,244,240,248,248,255,227,179,255,255,255,255,255,255,255,255,255,207, 15, 15, 79,255,255,255,255,255,255,255,255,254,  0,  0, 
    //         0,  1,  0, 32,  0,  0,  0,  1, 24, 19, 39,143, 15, 95,191, 63, 63,127,127,127,127,127,127,127, 63, 63, 63,159, 95, 63, 24, 24, 15, 63,191, 63, 63, 63, 63, 63, 63,191, 63, 63, 63, 63, 63,191, 63, 63,  0,143, 63, 63, 63,191,127,191,191, 63, 48,  0, 13,103,156,  0,  0, 47,127,191, 63, 63,127,127, 63,127, 67, 64,128, 33, 99,110,216,204, 79, 79,143, 31, 63, 63, 63, 63,127,127,127,127,127,127,191, 63, 63, 31, 31,128, 47,191, 63, 63, 63, 63, 63, 63, 63,  0,  0,  0,  0, 15,191, 63, 63, 63, 63, 63, 63, 63,  0,  0,
    //     };
    //     oled_write_raw_P(raw_logo, sizeof(raw_logo));
    // }

bool oled_task_user(void) {
  // if (!is_keyboard_master()) {
  //   render_logo();
  // }


  if (is_keyboard_master()) {
  uint8_t modifiers = get_mods() | get_oneshot_mods();

  // mods
  oled_set_cursor(0, 11); 
  oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT) || is_caps_word_on());
  oled_write_P(PSTR("CNTRL"), (modifiers & MOD_MASK_CTRL));

  // layer
  oled_set_cursor(0, 14);
  switch(get_highest_layer(layer_state)) {
      case _ALPHA:
          oled_write_P(PSTR("ALPHA"), false);
          break;
      case _SYMBOL:
          oled_write_P(PSTR(" SYM "), false);
          break;
      case _NUMBER:
          oled_write_P(PSTR(" NUM "), false);
          break;
      case _NAVIGATION:
          oled_write_P(PSTR(" NAV "), false);
          break;
  }
  }



  return true;
}
