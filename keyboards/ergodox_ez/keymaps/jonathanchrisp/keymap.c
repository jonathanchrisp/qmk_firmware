#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define QWTY 0 // qwerty layer
#define SYMB 1 // symbols layer
#define NAVI 2 // navigation layer
#define MUSI 3 // media layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWTY] = LAYOUT_ergodox(
        // left hand
        TG(MUSI),KC_1,KC_2,KC_3,KC_4,KC_5,KC_F14,

        KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,LCMD(KC_V),
        KC_ESC,LT(SYMB,KC_A),CTL_T(KC_S),ALT_T(KC_D),GUI_T(KC_F),KC_G,
        LSFT(KC_MINUS),CTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,LCMD(KC_C),

        KC_NO,KC_NO,KC_NO,KC_LABK,KC_1,

        KC_SLEP,KC_WAKE,
        KC_PGDN,
        LT(NAVI,KC_SPC),KC_LSFT,RCTL(KC_A),

        // right hand
        KC_F15,KC_6,KC_7,KC_8,KC_9,KC_0,TG(MUSI),

        RCMD(RSFT(KC_Z)),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_DEL,
        KC_H,MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RCTL, KC_L),LT(SYMB, KC_SCLN),KC_BSPC,
        RCMD(KC_Z),KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,

        RSFT(KC_DLR),KC_RABK,KC_NO,KC_NO,KC_NO,

        KC_MSTP,KC_MPLY,
        KC_PGUP,
        LCTL(KC_F),KC_RSFT,KC_ENT
    ),

[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,

       KC_LABK,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_COLN,
       KC_ESC,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRV,
       LSFT(KC_MINUS),KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_SCLN,

       KC_NO,KC_NO,KC_NO,KC_COLN,KC_HASH,

       KC_NO,KC_NO,
       KC_NO,
       KC_NO,KC_LSFT,KC_NO,

       // right hand
       KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_NO,

       KC_DQUO,RSFT(KC_EQL),KC_7,KC_8,KC_9,KC_ASTR,KC_LABK,
       KC_MINUS,KC_4,KC_5,KC_6,KC_PLUS,KC_BSPC,
       KC_QUOT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLS,KC_EQL,

       KC_0,KC_COLN,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,
       KC_NO,
       KC_NO,KC_RSFT,KC_NO
),

[NAVI] = LAYOUT_ergodox(
       // left hand
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,LSFT(KC_LCTL),LSFT(KC_LALT),LSFT(KC_LCMD),KC_NO,KC_NO,
       KC_ESC,KC_NO,KC_LCTL,KC_LALT,KC_LCMD,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO, KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,
       KC_NO,
       KC_NO,KC_LSFT,KC_NO,

       // right hand
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,KC_NO,KC_BSPC,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,
       KC_NO,
       KC_NO,KC_RSFT,KC_ENT
  ),

[MUSI] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,
       KC_NO,
       KC_VOLD,KC_VOLU,KC_MUTE,

       // right hand
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,

       KC_NO,KC_NO,
       KC_MSTP,
       KC_MPLY,KC_MRWD,KC_MFFD
  ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
