#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  EPISTORY_NAV,
  SHIFT_COMBO,
};

/** Custom Shift **/
const custom_shift_key_t custom_shift_keys[] = {
  {KC_COMM, KC_QUES}, // Shift , is ?
  {KC_DOT , KC_EXLM}, // Shift . is !
  {KC_QUOTE, KC_DOUBLE_QUOTE}, // Shift ' is "
};

/** Switcher **/
SWITCHER_SECONDARY_KEYS(
    {KC_LEFT, KC_LEFT},     // 'left' functions as usual
    {KC_RIGHT, KC_RIGHT},   // 'right' functions as usual  
    {KC_UP, KC_UP},         // 'up' functions as usual
    {KC_DOWN, KC_DOWN},     // 'down' functions as usual
    {LGUI(KC_A), KC_Q},     // left pinky sends 'Q' to quit app
    {LGUI(KC_V), KC_H},     // left index sends 'H' to hide app
);

/** One-shot shift via Thumb Keys **/
static uint16_t shift_tap_timer = 0;
#define SHIFT_TAP_TIMEOUT 1000 // Maximum time in ms between shift combo presses to count as a double tap and thus CAPS_WORD; double tapping both thumb keys simultaneously takes longer than a typical TAPPING_TERM


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(LGUI(LCTL(LSFT(KC_K)))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_B,           KC_L,           KC_D,           KC_W,           KC_Z,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_QUOTE,       KC_F,           KC_O,           KC_U,           KC_J,           KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LALT, KC_N),MT(MOD_LCTL, KC_R),MT(MOD_LGUI, KC_T),MT(MOD_LSFT, KC_S),KC_G,                                                               KC_Y,           MT(MOD_RSFT, KC_H),MT(MOD_RGUI, KC_A),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_P,           KC_COMMA,       KC_DOT,         OSL(2),         TG(4),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    MO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(1, KC_SPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_MINUS,       KC_PERC,        KC_SLASH,       KC_LBRC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RBRC,        KC_ASTR,        KC_EQUAL,       KC_PLUS,        KC_RABK,        KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LALT, KC_1),MT(MOD_LCTL, KC_2),MT(MOD_LGUI, KC_3),MT(MOD_LSFT, KC_4), KC_LPRN,                                                           KC_RPRN,        MT(MOD_RSFT, KC_7),MT(MOD_RGUI, KC_8),MT(MOD_RCTL, KC_9),MT(MOD_RALT, KC_0), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC,        KC_DLR,         UK_PND,         KC_5,           KC_LCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RCBR,        KC_6,           KC_TRANSPARENT, KC_TRANSPARENT, OSL(2),         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,       KC_BSLS,        KC_PIPE,        KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR,        KC_UNDS,        KC_AT,          LALT(LSFT(KC_MINUS)),KC_TRANSPARENT,                                                            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        LALT(KC_3),     KC_SCLN,        KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_N),     LGUI(KC_W),       LGUI(LCTL(KC_F)),              LGUI(KC_M),     LGUI(KC_I),     KC_TRANSPARENT,                KC_TRANSPARENT, SWITCHER_EXPOSE,SELWBAK,        KC_UP,          SELWORD,        QK_LLCK,          KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_A),     LGUI(KC_X),       LGUI(KC_C),                    LGUI(KC_V),     LGUI(KC_B),                                                    KC_TAB,         KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_BSPC,          KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(LSFT(KC_Z)), KC_DOT,                        LGUI(KC_S),     LGUI(KC_U),     KC_TRANSPARENT,                KC_TRANSPARENT, KC_NO,          LGUI(KC_SPACE), SELLINE,        SWITCHER,       LGUI(LCTL(KC_Q)), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,                KC_TRANSPARENT,                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty( // temp NANOTALE layer (delete when no longer playing): has non-modtap homekeys, for navigating in NANOTALE
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_N,           KC_R,           KC_T,           KC_S,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_A,           KC_E,           KC_I,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(  // temp EPISTORY Nav Layer (delete layer when no longer playing): Same as Nav layer 3 above, but with EFJI mapped in for Epistory's navigation.
    KC_NO,          KC_NO,          KC_NO,            KC_NO,        KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         
    KC_NO,          KC_NO,          KC_NO,            KC_E,         KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_I,           KC_NO,          KC_NO,          KC_NO,         
    KC_NO,          KC_NO,          KC_NO,            KC_NO,        KC_F,           KC_NO,                                                          KC_NO,          KC_J,           KC_NO,          KC_NO,          KC_NO,          KC_NO,         
    KC_NO,          KC_NO,          KC_NO,            KC_NO,        KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         
    KC_NO,          KC_NO,          KC_NO,            KC_NO,        KC_NO,                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,        
                                                                                                                    KC_NO,          KC_NO,         
                                                                                     KC_NO,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO        
  ),
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_ergodox(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L',
  'L', 'L',
  'L', 'L', 'L', 'L',
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 
  'R', 'R', 'R', 'R'
);

const uint16_t PROGMEM combo0[] = { LGUI(KC_N), LGUI(KC_W), COMBO_END};
const uint16_t PROGMEM combo1[] = { LGUI(KC_V), LGUI(KC_B), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_UP, SELWORD, COMBO_END};
const uint16_t PROGMEM combo3[] = { SELWBAK, KC_UP, COMBO_END};
const uint16_t PROGMEM combo4[] = { SELLINE, SWITCHER, COMBO_END};
const uint16_t PROGMEM combo5[] = { LGUI(KC_SPACE), SELLINE, COMBO_END};
const uint16_t PROGMEM combo6[] = { LGUI(KC_S), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_DOT, LGUI(LSFT(KC_Z)), COMBO_END};
const uint16_t PROGMEM combo8[] = { LGUI(KC_X), LGUI(KC_C), COMBO_END};
const uint16_t PROGMEM combo9[] = { LGUI(KC_C), LGUI(KC_V), COMBO_END};
const uint16_t PROGMEM combo10[] = { LGUI(KC_W), LGUI(LCTL(KC_F)), COMBO_END};
const uint16_t PROGMEM combo11[] = { MT(MOD_LCTL, KC_R), MT(MOD_LGUI, KC_T), MT(MOD_LSFT, KC_S), COMBO_END};
const uint16_t PROGMEM combo12[] = { MT(MOD_RSFT, KC_H), MT(MOD_RGUI, KC_A), MT(MOD_RCTL, KC_E), COMBO_END};
const uint16_t PROGMEM epistory_enter_nav[] = { KC_D, MT(MOD_LSFT, KC_S), MT(MOD_RSFT, KC_H), KC_O, COMBO_END}; // EPISTORY combo - delete when no longer playing
const uint16_t PROGMEM epistory_exit_nav[] = { KC_E, KC_F, KC_J, KC_I, COMBO_END}; // EPISTORY combo - delete when no longer playing
const uint16_t PROGMEM one_shot_shift[] = { MO(3), LT(1, KC_SPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, LALT(LGUI(LSFT(KC_V)))),
    COMBO(combo2, LCTL(KC_TAB)),
    COMBO(combo3, LCTL(LSFT(KC_TAB))),
    COMBO(combo4, LGUI(KC_GRAVE)),
    COMBO(combo5, LGUI(LSFT(KC_GRAVE))),
    COMBO(combo6, LGUI(KC_EQUAL)),
    COMBO(combo7, LGUI(KC_MINUS)),
    COMBO(combo8, LALT(LGUI(LCTL(LSFT(KC_L))))),
    COMBO(combo9, LALT(LGUI(LCTL(LSFT(KC_R))))),
    COMBO(combo10, LGUI(KC_Q)),
    COMBO(combo11, LALT(KC_BSPC)),
    COMBO(combo12, KC_ENTER),
    COMBO(epistory_enter_nav, EPISTORY_NAV), // EPISTORY combo - delete when no longer playing
    COMBO(epistory_exit_nav, EPISTORY_NAV), // EPISTORY combo - delete when no longer playing
    COMBO(one_shot_shift, SHIFT_COMBO),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // NANOTALE
    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // EPISTORY
    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4: // NANOTALE
      set_layer_color(4);
      break;
    case 5: // EPISTORY
      set_layer_color(5);
      break;  
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // One-shot Shifting via Thumb keys: Special early handling for Custom Shifted keys only
    // (This is too early for the general case, but process_record_user will be too late for __Custom_Shifted__ keys.)

    // Is it a custom shift key?
    bool is_custom_shift_key = false;
    for (int i = 0; i < (int)ARRAY_SIZE(custom_shift_keys); ++i) {
        const custom_shift_key_t* custom_shift_key = &custom_shift_keys[i];
        if (keycode == custom_shift_key->keycode) {
            is_custom_shift_key = true;
            break;
        }
    }

    // If shift combo recently tapped, not been tapped a second time, and now a custom shift key tapped
    if (shift_tap_timer && is_custom_shift_key) { 
            // SINGLE_TAP followed by Custom Shift key => (JIT) ONE SHOT SHIFT
            set_oneshot_mods(MOD_LSFT);
            shift_tap_timer = 0;
        }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
    // TODO: Refactor one-shot shift / caps word so that one-shot shift is applied instantly, and then just removed and replaced with caps word on double tap
    // One-shot Shifting via Thumb keys
    if (keycode == SHIFT_COMBO) { // It's the Shift combo
        if (record->event.pressed) {
                if (shift_tap_timer && !timer_expired(timer_read(), shift_tap_timer)) { // This is the second half of a double tap
                    // DOUBLE TAP => CAPS_WORD
                    caps_word_on();
                    shift_tap_timer = 0;
                } else {
                    // This is either a single tap, or the first half of a double tap; let's wait to find out which.
                    shift_tap_timer = (record->event.time + SHIFT_TAP_TIMEOUT) | 1;
                }
            } 
            return false;
    }
    else { // It's something else; check to see if we need to apply shift before it's processed
        if (shift_tap_timer) { // Shift combo was tapped recently, it's not been tapped a second time, and now something else has been tapped
                // SINGLE_TAP => (JIT) ONE SHOT SHIFT
                set_oneshot_mods(MOD_LSFT);
                shift_tap_timer = 0;
         }
    }

    switch (keycode) {

        // EPISTORY
        case EPISTORY_NAV:
            if (record->event.pressed) {
                tap_code(KC_SPC);
                layer_invert(5);
            }
            return false;

        // Oryx Stuff
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    } 

    return true;
}

void housekeeping_task_user(void) {
    if (shift_tap_timer && timer_expired(timer_read(), shift_tap_timer)) {// Shift combo was tapped recently, it's not been tapped a second time, and the tapping term's expired
    // SINGLE_TAP => ONE SHOT SHIFT
    set_oneshot_mods(MOD_LSFT);
    shift_tap_timer = 0;
  }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        // Disable flow tap when shifting after a space, enter or backspace
        uint16_t prev_tap = get_tap_keycode(prev_keycode);
        if (prev_tap == KC_SPC || prev_tap == KC_ENTER || prev_tap == KC_BSPC) {
            switch (keycode) {
                case MT(MOD_LSFT, KC_S):
                case MT(MOD_RSFT, KC_H):
                    return 0;
                default:
                    return FLOW_TAP_TERM;
            }
        }  
    }
    return 0;
}

char sentence_case_press_user(uint16_t keycode,
                              keyrecord_t* record,
                              uint8_t mods) {

  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      
      case KC_A ... KC_Z:
      case KC_2 ... KC_0:  // 2 3 4 5 6 7 8 9 0  (DT Customisation - treat numbers as letters rather than symbols)
        return 'a';  // Letter key.

      case KC_DOT:  // . is punctuation, Shift . is a symbol (>)
        return '.'; // DT Customisation - Shift-. is  ! rather than >
      
      case KC_COMM:
        return shifted ? '.' : '#'; // DT Cutomisation - Shift-, is  ? rather than <
      
      case KC_EXLM:
      case KC_QUES:
        return '.';
      
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_SCLN:  // - = [ ] backslash ;
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
        return '#';  // Symbol key.
      
      case KC_SPC:
      case KC_ENTER: // DT Customisation - Treat enter as a space, thus capitalising the start of paragraphs
        return ' ';  // Space key.
      
      case KC_QUOT:
        return '\'';  // Quote key.

      case SHIFT_COMBO: // DT Customisation - Ignore the Shift Combo
        return '\0';
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}

uint8_t layer_state_set_user(uint8_t state) {
  return state;
};
