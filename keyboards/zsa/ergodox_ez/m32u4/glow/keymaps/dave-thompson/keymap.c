#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  NUM_WRD,
  LYR_TOG,
  SPANISH,
  // Select Word harness (if uninstalled for space)
  // SELWORD,
  // SELWBAK,
  // SELLINE,
  // Switcher harness (if uninstalled for space)
  // SWTCH,
  // SWTCH_E,
};

enum layers {
  BASE,
  NUM,
  NAV,
};

///////////////////////////////////////////////////////////////////////////////
//
// Keycode Aliases
//
///////////////////////////////////////////////////////////////////////////////

#define KEYCODE_ALIASES              \
                                     \
  /* Home-row Mods */                \
  X(CTL_N, LCTL_T(KC_N))             \
  X(ALT_R, LALT_T(KC_R))             \
  X(GUI_T, LGUI_T(KC_T))             \
  X(SFT_S, LSFT_T(KC_S))             \
  X(SFT_H, RSFT_T(KC_H))             \
  X(GUI_A, RGUI_T(KC_A))             \
  X(ALT_E, RALT_T(KC_E))             \
  X(CTL_I, RCTL_T(KC_I))             \
  X(CTL_1, LCTL_T(KC_1))             \
  X(ALT_2, LALT_T(KC_2))             \
  X(GUI_3, LGUI_T(KC_3))             \
  X(SFT_4, LSFT_T(KC_4))             \
  X(SFT_7, RSFT_T(KC_7))             \
  X(GUI_8, RGUI_T(KC_8))             \
  X(ALT_9, RALT_T(KC_9))             \
  X(CTL_0, RCTL_T(KC_0))             \
                                     \
  /* Layer Switches */               \
  X(NUM_SPC, LT(NUM, KC_SPC))        \
                                     \
  /* Symbols */                      \
  X(POUND, S(KC_3))                  \
  X(HASH, A(KC_3))                   \
                                     \
  /* Window Management */            \
  X(NEW, G(KC_N))                    \
  X(CLOSE, G(KC_W))                  \
  X(FILLSCR, HYPR(KC_F))             \
  X(MINIM, G(KC_M))                  \
                                     \
  /* Formatting */                   \
  X(ITALIC, G(KC_I))                 \
  X(BOLD, G(KC_B))                   \
  X(UNDER, G(KC_U))                  \
                                     \
  /* State */                        \
  X(UNDO, G(KC_Z))                   \
  X(REDO, G(S(KC_Z)))                \
  X(SAVE, G(KC_S))                   \
                                     \
  /* Miscellaneous */                \
  X(ALFRED, G(KC_SPC))               \
  X(LOCKCMP, G(C(KC_Q)))             \
  X(BUILD_K, HYPR(KC_K))             \
                                     \
  /* Lighting */                     \
  X(LIGHT_1, HYPR(KC_J))             \
  X(LIGHT_2, HYPR(KC_T))             \
  X(LIGHT_3, HYPR(KC_M))             \
                                     \
  /* Monitor */                      \
  X(BRGH_UP, G(KC_F2))               \
  X(BRGH_DN, G(KC_F1))               \
                                     \
                                     \
  /* Mod-Tap Dummies (Below)   */    \
  /* ———————————————————————   */    \
  /* trigger tap-hold logic in */    \
  /* process_record_user       */    \
                                     \
  /* Editing */                      \
  X(CTL_SPC, LCTL_T(KC_NO))          \
  X(ALT_CUT, LALT_T(KC_NO))          \
  X(GUI_CPY, LGUI_T(KC_NO))          \
  X(SFT_PST, LSFT_T(KC_NO))


// Aliases Enum
#define X(name, value) name = value,
enum keycode_enum {
  KEYCODE_ALIASES
};
#undef X


// Keycode String
#define X(name, value) KEYCODE_STRING_NAME(name),
KEYCODE_STRING_NAMES_USER(
  KEYCODE_ALIASES
);
#undef X


///////////////////////////////////////////////////////////////////////////////
//
// Keymap
//
///////////////////////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(

    // BASE - Left
    _______, _______, _______, _______, _______, _______, _______,    
    _______, KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    _______,    
    _______, CTL_N,   ALT_R,   GUI_T,   SFT_S,   KC_G,                
    _______, KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,    _______,    
    _______, _______, _______, _______, _______,                      

                                                 BRGH_DN, BRGH_UP,
                                                          _______,
                                        MO(NAV), _______, BUILD_K,

    // BASE - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    _______,
             KC_Y,    SFT_H,   GUI_A,   ALT_E,   CTL_I,   _______,
    _______, KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_COLN, _______,
                      _______, _______, _______, _______, _______,

    LIGHT_1, LIGHT_3,
    LIGHT_2,
    QK_BOOT, _______, NUM_SPC

  ),
  [NUM] = LAYOUT_ergodox(

    // NUM - Left
    _______, _______, _______, _______, _______, _______, _______,      
    _______, KC_BSLS, KC_MINS, KC_PERC, KC_SLSH, KC_LCBR, _______,
    _______, CTL_1,   ALT_2,   GUI_3,   SFT_4,   KC_LABK,
    _______, HASH,    KC_DLR,  POUND,   KC_5,    KC_LBRC, _______,      
    _______, _______, _______, _______, _______,                        

                                                 _______, _______,  
                                                          _______,  
                                        _______, _______, _______,

    // NUM - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_RCBR, KC_ASTR, KC_EQL,  KC_PLUS, KC_PIPE, _______,
             KC_RABK, SFT_7,   GUI_8,   ALT_9,   CTL_0,   _______,
    _______, KC_RBRC, KC_6,    KC_COMM, KC_DOT,  KC_CIRC, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, KC_SPC

  ),

  [NAV] = LAYOUT_ergodox(
    
    // NAV - Left
    _______, _______, _______, _______, _______, _______, _______,          
    _______, KC_ESC,  KC_BSPC, CLOSE,   NEW,    ITALIC,  _______,
    _______, CTL_SPC, ALT_CUT, GUI_CPY, SFT_PST, BOLD,                      
    _______, UNDO,    REDO,    SAVE,    KC_ENT,  UNDER,   _______,          
    _______, _______, _______, _______, _______,                            

                                                 _______, _______,      
                                                          _______,      
                                        _______, _______, _______,
    
    // NAV - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, SWTCH_E, SELWBAK, KC_UP,   SELWORD, LOCKCMP, _______,
             KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
    _______, _______, ALFRED,  SELLINE, SWTCH,   _______, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______

  ),


};


///////////////////////////////////////////////////////////////////////////////
//
// Caps Word
//
///////////////////////////////////////////////////////////////////////////////

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_MINS:
      return true;
    default:
      return false;
  }
}


///////////////////////////////////////////////////////////////////////////////
//
// Switcher
//
///////////////////////////////////////////////////////////////////////////////

SWITCHER_SECONDARY_KEYS(
    {KC_LEFT, KC_LEFT},     // 'left' functions as usual
    {KC_RIGHT, KC_RIGHT},   // 'right' functions as usual  
    {KC_UP, KC_UP},         // 'up' functions as usual
    {KC_DOWN, KC_DOWN},     // 'down' functions as usual
    {CTL_SPC, KC_Q},        // left pinky sends 'Q' to quit app
    {SFT_PST, KC_H},        // left index sends 'H' to hide app
    {NUM_SPC, KC_GRAVE},    // space sends 'backtick' to cycle apps in exposé
);


///////////////////////////////////////////////////////////////////////////////
//
// Sentence Case
//
///////////////////////////////////////////////////////////////////////////////

char sentence_case_press_user(uint16_t keycode,
                              keyrecord_t* record,
                              uint8_t mods) {

  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      
      // Letters
      case KC_A ... KC_Z:
      case KC_2 ... KC_0:  // treat numbers as letters
        return 'a';
      
      // Punctuation
      case KC_DOT: // KC_DOT is punctuation both when shifted (= !) and not
      case KC_EXLM:
      case KC_QUES:
        return '.';
      
      // Symnbols
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_SCLN:  // - = [ ] backslash ;
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
        return '#';

      // Spaces
      case KC_SPC:
      case KC_ENTER: // treat enter as a space to capitalise paragraph starts
        return ' ';
      
      // Quotes
      case KC_QUOT:
        return '\'';
      
      // Mixed
      case KC_COMM:
        return shifted ? '.' : '#'; // custom shifted , is ?
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}


///////////////////////////////////////////////////////////////////////////////
//
// Tap or Hold?
//
///////////////////////////////////////////////////////////////////////////////

////////////////
// Lightshift //
////////////////

// Doesn't change behaviour, but saves 178 bytes
char chordal_hold_handedness(keypos_t key) {
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}


////////////////////////////////////
// Tap-Hold for Compound Keycodes //
////////////////////////////////////

// Tap-hold for compound keycodes (QMK's MT/LT only allow basic keycodes)
static bool process_tap_hold(keyrecord_t* record,
                             uint16_t tap_keycode,
                             uint16_t hold_keycode) {
    // tap or hold?
    uint16_t keycode;
    if (record->tap.count > 0) keycode = tap_keycode;
    else keycode = hold_keycode;
    
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }

    // do not process further
    return false;
}


//////////////////////////////////////
// Shorter tapping term for NUM_SPC //
//////////////////////////////////////

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

  // hook for lightshift compatibility
  if (is_lightshift(keycode)) return get_lightshift_term(keycode, record);

  // shorter tapping term for NUM_SPC
  if (keycode == NUM_SPC) return 150;
  else return TAPPING_TERM;
}


///////////////////////////////////////////////////////////////////////////////
//
// Combos
//
///////////////////////////////////////////////////////////////////////////////

// -- BASE Row 1 --
const uint16_t PROGMEM backtick[]     = {KC_W,    KC_Z,             COMBO_END};
const uint16_t PROGMEM tilde[]        = {KC_QUOT, KC_F,             COMBO_END};
const uint16_t PROGMEM hyphen[]       = {KC_D,    KC_W,             COMBO_END};
const uint16_t PROGMEM spanish[]      = {KC_L,    KC_D,             COMBO_END};
const uint16_t PROGMEM num_word[]     = {KC_L,    KC_D,    KC_W,    COMBO_END};
const uint16_t PROGMEM caps_word[]    = {KC_F,    KC_O,    KC_U,    COMBO_END};

// -- BASE Row 2 --
const uint16_t PROGMEM underscore[]   = {SFT_S,   KC_G,             COMBO_END};
const uint16_t PROGMEM at_sign[]      = {KC_Y,    SFT_H,            COMBO_END};
const uint16_t PROGMEM del_word[]     = {ALT_R,   GUI_T,   SFT_S,   COMBO_END};
const uint16_t PROGMEM enter[]        = {SFT_H,   GUI_A,   ALT_E,   COMBO_END};

// -- BASE Row 3 --
const uint16_t PROGMEM open_paren[]   = {KC_X,    KC_M,             COMBO_END};
const uint16_t PROGMEM em_dash[]      = {KC_M,    KC_C,             COMBO_END};
const uint16_t PROGMEM ampersand[]    = {KC_P,    KC_COMM,          COMBO_END};
const uint16_t PROGMEM close_paren[]  = {KC_COMM, KC_DOT,           COMBO_END};

// -- NUM Row 2 --
const uint16_t PROGMEM del_word_num[] = {ALT_2,   GUI_3,   SFT_4,   COMBO_END};
const uint16_t PROGMEM enter_num[]    = {SFT_7,   GUI_8,   ALT_9,   COMBO_END};

// -- NAV Row 1 --
const uint16_t PROGMEM quit[]         = {KC_BSPC, CLOSE,            COMBO_END};
const uint16_t PROGMEM minimize[]     = {CLOSE,   NEW,              COMBO_END};
const uint16_t PROGMEM screenshot[]   = {NEW,     ITALIC,           COMBO_END};
const uint16_t PROGMEM prev_tab[]     = {SELWBAK, KC_UP,            COMBO_END};
const uint16_t PROGMEM next_tab[]     = {KC_UP,   SELWORD,          COMBO_END};
const uint16_t PROGMEM left_screen[]  = {KC_BSPC, CLOSE,   NEW,     COMBO_END};

// -- NAV Row 2 --
const uint16_t PROGMEM select_all[]   = {ALT_CUT, GUI_CPY,          COMBO_END};
const uint16_t PROGMEM paste_plain[]  = {GUI_CPY, SFT_PST,          COMBO_END};
const uint16_t PROGMEM del_file[]     = {SFT_PST, BOLD,             COMBO_END};
const uint16_t PROGMEM fill_screen[]  = {ALT_CUT, GUI_CPY, SFT_PST, COMBO_END};

// -- NAV Row 3 --
const uint16_t PROGMEM zoom_out[]     = {REDO,    SAVE,             COMBO_END};
const uint16_t PROGMEM zoom_in[]      = {SAVE,    KC_ENT,           COMBO_END};
const uint16_t PROGMEM prev_win[]     = {KC_LEFT, KC_DOWN,          COMBO_END};
const uint16_t PROGMEM next_win[]     = {KC_DOWN, KC_RGHT,          COMBO_END};
const uint16_t PROGMEM right_screen[] = {REDO,    SAVE,    KC_ENT,  COMBO_END};
const uint16_t PROGMEM swap_screen[]  = {KC_LEFT, KC_DOWN, KC_RGHT, COMBO_END};

// -- Layer Lock (RTAE across all layers) --
const uint16_t PROGMEM lyr_lock_base[] = {ALT_R,   GUI_T,   GUI_A,   ALT_E,   COMBO_END};
const uint16_t PROGMEM lyr_lock_num[]  = {ALT_2,   GUI_3,   GUI_8,   ALT_9,   COMBO_END};
const uint16_t PROGMEM lyr_lock_nav[]  = {ALT_CUT, GUI_CPY, KC_DOWN, KC_RGHT, COMBO_END};


combo_t key_combos[] = {

    // BASE Row 1
    COMBO(backtick,    KC_GRV),            // W + Z             => `
    COMBO(tilde,       KC_TILD),           // ' + F             => ~
    COMBO(hyphen,      KC_MINS),           // D + W             => -
    COMBO(spanish,     SPANISH),           // L + D             => Spanish
    COMBO(num_word,    NUM_WRD),           // L + D + W         => Num Word
    COMBO(caps_word,   CW_TOGG),           // F + O + U         => Caps Word

    // BASE Row 2
    COMBO(underscore,  KC_UNDS),           // S + G             => _
    COMBO(at_sign,     KC_AT),             // Y + H             => @
    COMBO(del_word,    A(KC_BSPC)),        // R + T + S         => Delete Word
    COMBO(enter,       KC_ENTER),          // H + A + E         => Enter

    // BASE Row 3
    COMBO(open_paren,  KC_LPRN),           // X + M             => (
    COMBO(em_dash,     S(A(KC_MINS))),     // M + C             => —
    COMBO(ampersand,   KC_AMPR),           // P + ,             => &
    COMBO(close_paren, KC_RPRN),           // , + .             => )

    // NUM Row 2
    COMBO(del_word_num, A(KC_BSPC)),       // 2 + 3 + 4         => Delete Word
    COMBO(enter_num,    KC_ENTER),         // 7 + 8 + 9         => Enter

    // NAV Row 1
    COMBO(quit,        G(KC_Q)),           // ⌫ + close         => Quit
    COMBO(minimize,    MINIM),             // close + new       => Minimize
    COMBO(screenshot,  G(S(KC_4))),        // min + italic      => Screenshot
    COMBO(prev_tab,    C(S(KC_TAB))),      // ◀sel + ▲          => Previous Tab
    COMBO(next_tab,    C(KC_TAB)),         // ▲ + sel▶          => Next Tab
    COMBO(left_screen, HYPR(KC_L)),        // ⌫ + close + min   => Tile Left

    // NAV Row 2
    COMBO(select_all,  G(KC_A)),           // cut + copy        => Select All
    COMBO(paste_plain, C(KC_V)),           // copy + paste      => Plain Paste
    COMBO(del_file,    G(KC_BSPC)),        // paste + bold      => Delete File
    COMBO(fill_screen, HYPR(KC_F)),        // cut + copy + paste => Fill Screen

    // NAV Row 3
    COMBO(zoom_out,    G(KC_MINS)),        // redo + save       => Zoom Out
    COMBO(zoom_in,     G(KC_EQL)),         // save + ↩          => Zoom In
    COMBO(prev_win,    HYPR(KC_P)),        // alfred + ▼sel     => Previous Win
    COMBO(next_win,    HYPR(KC_N)),        // ▼sel + switch     => Next Window
    COMBO(right_screen, HYPR(KC_R)),       // redo + save + ↩   => Tile Right
    COMBO(swap_screen,  HYPR(KC_D)),       // ◀ + ▼ + ▶         => Swap Screen

    // ALL layers — Layer Toggle/Lock (RTAE)
    COMBO(lyr_lock_base, LYR_TOG),        // R + T + A + E      => Toggle BASE/NUM
    COMBO(lyr_lock_num,  LYR_TOG),        // 2 + 3 + 8 + 9      => Toggle BASE/NUM
    COMBO(lyr_lock_nav,  LYR_TOG),        // cut + copy + ▼ + ▶ => Toggle NAV Lock

};


///////////////////////////////////////////////////////////////////////////////
//
// RGB Matrix Lighting
//
///////////////////////////////////////////////////////////////////////////////

extern rgb_config_t rgb_matrix_config;

typedef struct {
    uint8_t h, s, v;
} hsv_color_t;

// Only light up 3x5 keys on each side
const uint8_t active_leds[] =
    // left side
    { 5,  6,  7,  8,  9,
     10, 11, 12, 13, 14,
     15, 16, 17, 18, 19,
     // right side
     29, 30, 31, 32, 33,
     34, 35, 36, 37, 38,
     39, 40, 41, 42, 43};

const hsv_color_t PROGMEM layer_colors[] = {
    [BASE] = {0, 0, 255},    // White (hue=0, sat=0, bright=255)
    [NUM] = {74, 255, 255},  // Green
    [NAV] = {219, 255, 255}, // Pink
};


void set_layer_color(uint8_t layer) {

    // Get HSV colour
    uint8_t h = pgm_read_byte(&layer_colors[layer].h);
    uint8_t s = pgm_read_byte(&layer_colors[layer].s);
    uint8_t v = pgm_read_byte(&layer_colors[layer].v);
    HSV hsv = {.h = h, .s = s, .v = v};

    // Convert HSV to RGB
    RGB rgb = hsv_to_rgb(hsv); 

    // Apply global brightness scaling
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    
    // Update the LEDs
    rgb_matrix_set_color_all(0, 0, 0);
    for (int i = 0; i < ARRAY_SIZE(active_leds); i++) {
        rgb_matrix_set_color(active_leds[i], f * rgb.r, f * rgb.g, f * rgb.b);
    }
}


bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) return false;
    set_layer_color(get_highest_layer(layer_state));
    return true;
}


///////////////////////////////////////////////////////////////////////////////
//
// Custom Shifts:  {, —> ?}  {. —> !}  {: —> ;}
//
///////////////////////////////////////////////////////////////////////////////

// returns true if this event is a pressed custom shift
bool custom_shift(uint16_t keycode, keyrecord_t *record) {
  static uint16_t cs_registered = KC_NO;
  // if the last key event was a pressed custom shift, unregister it
  if (cs_registered != KC_NO) {
    unregister_code16(cs_registered);
    cs_registered = KC_NO;
  }
  // if this key event is a pressed custom shift, register it
  if ((record->event.pressed) // if this is a shifted keypress
      && ((get_mods() | get_weak_mods()) & MOD_MASK_SHIFT)) {
    // should this key be CUSTOM shifted?
    uint16_t shifted_code = KC_NO;
    if (keycode == KC_COMM) shifted_code = KC_QUES;
    else if (keycode == KC_DOT) shifted_code = KC_EXLM;
    else if (keycode == KC_COLN) shifted_code = KC_SCLN;
    // if so, clear shift, send the custom keypress, and reinstate shift
    if (shifted_code != KC_NO) {
      uint8_t saved_mods = get_mods();
      del_weak_mods(MOD_MASK_SHIFT);
      unregister_mods(MOD_MASK_SHIFT);
      cs_registered = shifted_code;
      register_code16(cs_registered);
      set_mods(saved_mods);
      return true;
    }
  }
  return false;
}


///////////////////////////////////////////////////////////////////////////////
//
// Spanish Letters: {á, é, í, ó, ú, ñ, Á, É, Í, Ó, Ú, ¿, ¡}
//
///////////////////////////////////////////////////////////////////////////////

// sends Spanish version of the current keycode (and returns true on success)
bool process_spanish_char(uint16_t keycode) {
    
  // get base keycode
  uint16_t base_kc = keycode;
  if (IS_QK_MOD_TAP(keycode))
    base_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  else if (IS_QK_LAYER_TAP(keycode))
    base_kc = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);

  // get shift state
  if (is_caps_word_on()) caps_word_press_user(keycode); // run caps word early
  uint8_t saved_mods = get_mods();
  uint8_t saved_weak = get_weak_mods();
  bool shifted = (saved_mods | saved_weak) & MOD_MASK_SHIFT;
  
  // if key can be made spanish, set dead_key and follow_key
  uint16_t dead_key = KC_NO;
  uint16_t follow_key = KC_NO;
  switch (base_kc) {
    case KC_A: case KC_E: case KC_I: case KC_O: case KC_U:
      // a —> á, A —> Á (also e,i,o,u)
      dead_key = A(KC_E);  follow_key = base_kc;  break;
    case KC_N: // n —> ñ, N —> Ñ
      dead_key = A(KC_N);  follow_key = base_kc;  break;
    case KC_DOT: // ! —> ¡
      if (shifted) {dead_key = A(KC_1);}          break;
    case KC_COMM: // ? —> ¿
      if (shifted) {dead_key = A(S(KC_SLSH));}    break;
  }

  // replace typed key with dead_key and follow_key
  if (dead_key != KC_NO) {
    // suspend mods while sending dead key
    clear_mods();
    clear_weak_mods();
    tap_code16(dead_key);
    // reinstate mods before sending follow key
    set_mods(saved_mods);
    set_weak_mods(saved_weak);
    if (follow_key != KC_NO) tap_code16(follow_key);
    return true;
  }
  return false;
}

// returns true if either:
// - this is a spanish leader key
// - this is a printable Spanish key, which has been successfully sent
bool process_spanish_keys(uint16_t keycode, keyrecord_t *record) {
  static bool spanish_pending = false;
  
  // Spanish leader key
  if (keycode == SPANISH) { // remember it was pressed
    if (record->event.pressed) spanish_pending = true;
    return true;
  }

  // Key after Spanish leader key: swap for Spanish version
  if (spanish_pending && record->event.pressed
      // ignore mod and layer holds
      && !(IS_QK_MOD_TAP(keycode) && record->tap.count == 0)
      && !(IS_QK_LAYER_TAP(keycode) && record->tap.count == 0)) {

    spanish_pending = false;
    return process_spanish_char(keycode);
  }
  return false;
}


///////////////////////////////////////////////////////////////////////////////
//
// User macro callbacks
//
///////////////////////////////////////////////////////////////////////////////

static bool num_word_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (process_spanish_keys(keycode, record)) return false;

  if (custom_shift(keycode, record)) return false;

    switch (keycode) {

        // Num Word
        case NUM_WRD:
            if (record->event.pressed) {
                num_word_active = true;
                layer_on(NUM);
            }
            return false;

        // Layer Toggle
        case LYR_TOG:
            if (record->event.pressed) {
                switch (get_highest_layer(layer_state)) {
                    case BASE:
                        layer_lock_on(NUM);
                        break;
                    case NUM:
                        if (is_layer_locked(NUM)) layer_lock_off(NUM);
                        break;
                    case NAV:
                        layer_lock_invert(NAV);
                        break;
                }
            }
            return false;

        // HRM Editing Keys
        case CTL_SPC:
            return process_tap_hold(record, KC_SPC, KC_LCTL);
        case ALT_CUT:
            return process_tap_hold(record, G(KC_X), KC_LALT);
        case GUI_CPY:
            return process_tap_hold(record, G(KC_C), KC_LGUI);
        case SFT_PST:
            return process_tap_hold(record, G(KC_V), KC_LSFT);
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ((keycode == KC_SPC || keycode == KC_ENTER)
      && num_word_active
      && record->event.pressed) {
        num_word_active = false;
        layer_off(NUM); // Call in PoPR: leave layer AFTER ending key processed
  }
}
