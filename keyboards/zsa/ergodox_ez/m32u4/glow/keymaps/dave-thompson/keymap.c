#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  DASH,
  EPISTORY_NAV,
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
  SYM,
  NAV,
  EPI,
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
  X(GUI_R, LGUI_T(KC_R))             \
  X(ALT_T, LALT_T(KC_T))             \
  X(SFT_S, LSFT_T(KC_S))             \
  X(SFT_H, RSFT_T(KC_H))             \
  X(ALT_A, RALT_T(KC_A))             \
  X(GUI_E, RGUI_T(KC_E))             \
  X(CTL_I, RCTL_T(KC_I))             \
  X(CTL_1, LCTL_T(KC_1))             \
  X(GUI_2, LGUI_T(KC_2))             \
  X(ALT_3, LALT_T(KC_3))             \
  X(SFT_4, LSFT_T(KC_4))             \
  X(SFT_7, RSFT_T(KC_7))             \
  X(ALT_8, RALT_T(KC_8))             \
  X(GUI_9, RGUI_T(KC_9))             \
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
  X(FULLSCR, G(C(KC_F)))             \
  X(MINIM, G(KC_M))                  \
                                     \
  /* Formatting */                   \
  X(ITALIC, G(KC_I))                 \
  X(BOLD, G(KC_B))                   \
  X(UNDER, G(KC_U))                  \
                                     \
  /* Editing */                      \
  /* see process_record_user */      \
  X(CTL_ALL, LCTL_T(KC_NO))          \
  X(GUI_CUT, LGUI_T(KC_NO))          \
  X(ALT_CPY, LALT_T(KC_NO))          \
  X(SFT_PST, LSFT_T(KC_NO))          \
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
  X(LIGHT_2, HYPR(KC_L))             \
  X(LIGHT_3, HYPR(KC_M))             \
                                     \
  /* Monitor */                      \
  X(BRGH_UP, G(KC_F2))               \
  X(BRGH_DN, G(KC_F1))             


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
    _______, CTL_N,   GUI_R,   ALT_T,   SFT_S,   KC_G,                
    _______, KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,    _______,    
    _______, _______, _______, _______, _______,                      

                                                 BRGH_DN, BRGH_UP,
                                                          _______,
                                        MO(NAV), _______, BUILD_K,

    // BASE - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    _______,
             KC_Y,    SFT_H,   ALT_A,   GUI_E,   CTL_I,   _______,
    _______, KC_K,    KC_P,    KC_COMM, KC_DOT,  OSL(SYM),_______,
                      _______, _______, _______, _______, _______,

    LIGHT_1, LIGHT_3,
    LIGHT_2,
    QK_BOOT, _______, NUM_SPC

  ),
  [NUM] = LAYOUT_ergodox(

    // NUM - Left
    _______, _______, _______, _______, _______, _______, _______,      
    _______, KC_LABK, KC_MINS, KC_PERC, KC_SLSH, KC_LBRC, _______,      
    _______, CTL_1,   GUI_2,   ALT_3,   SFT_4,   KC_LPRN,               
    _______, KC_CIRC, KC_DLR,  POUND,   KC_5,    KC_LCBR, _______,      
    _______, _______, _______, _______, _______,                        

                                                 _______, _______,  
                                                          _______,  
                                        _______, _______, _______,

    // NUM - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_RBRC, KC_ASTR, KC_EQL,  KC_PLUS, KC_RABK, _______,
             KC_RPRN, SFT_7,   ALT_8,   GUI_9,   CTL_0,   _______,
    _______, KC_RCBR, KC_6,    _______, _______, OSL(SYM),_______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, KC_SPC

  ),
  [SYM] = LAYOUT_ergodox(
    
    // SYM - Left
    _______, _______, _______, _______, _______, _______, _______,          
    _______, KC_GRV,  KC_BSLS, KC_PIPE, KC_SLSH, _______, _______,          
    _______, KC_AMPR, KC_AT,   KC_UNDS, DASH,   _______,                   
    _______, KC_TILD, HASH,    KC_SCLN, KC_COLN, _______, _______,          
    _______, _______, _______, _______, _______,                            

                                                 _______, _______,      
                                                          _______,      
                                        _______, _______, _______,
    
    // SYM - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______      

  ),
  [NAV] = LAYOUT_ergodox(
    
    // NAV - Left
    _______, _______, _______, _______, _______, _______, _______,          
    _______, NEW,     CLOSE,   FULLSCR, MINIM,   ITALIC,  _______,          
    _______, CTL_ALL, GUI_CUT, ALT_CPY, SFT_PST, BOLD,                      
    _______, UNDO,    REDO,    KC_DOT,  SAVE,    UNDER,   _______,          
    _______, _______, _______, _______, _______,                            

                                                 _______, _______,      
                                                          _______,      
                                        _______, _______, _______,
    
    // NAV - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, SWTCH_E, SELWBAK, KC_UP,   SELWORD, QK_LLCK, _______,
             KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
    _______, _______, ALFRED,  SELLINE, SWTCH,   LOCKCMP, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______

  ),

  [EPI] = LAYOUT_ergodox(

    // EPI - Left
    _______, _______, _______, _______, _______, _______, _______,                  
    _______, _______, _______, KC_E,    _______, _______, _______,                  
    _______, _______, _______, _______, KC_F,    _______,                            
    _______, _______, _______, _______, _______, _______, _______,                  
    _______, _______, _______, _______, _______,                                     

                                                 _______, _______,      
                                                          _______,      
                                        _______, _______, _______,

    // EPI - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_I,    _______, _______, _______,
             _______, KC_J,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______

  ),
};


///////////////////////////////////////////////////////////////////////////////
//
// Custom Shift
//
///////////////////////////////////////////////////////////////////////////////

const custom_shift_key_t custom_shift_keys[] = {
  {KC_COMM, KC_QUES},          // Shift , is ?
  {KC_DOT , KC_EXLM},          // Shift . is !
};


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
    {CTL_ALL, KC_Q},        // left pinky sends 'Q' to quit app
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


///////////////////////////////////////////////////////////////////////////////
//
// Combos
//
///////////////////////////////////////////////////////////////////////////////

// -- BASE --

// Typing
const uint16_t PROGMEM enter[]          = {SFT_H, ALT_A, GUI_E, COMBO_END};
const uint16_t PROGMEM del_word[]       = {GUI_R, ALT_T, SFT_S, COMBO_END};
const uint16_t PROGMEM caps_word[]      = {MO(NAV), NUM_SPC, COMBO_END};

// Epistory
const uint16_t PROGMEM epi_enter_nav[]  = {KC_D, SFT_S, SFT_H, KC_O, COMBO_END};
const uint16_t PROGMEM epi_exit_nav[]   = {KC_E, KC_F, KC_J, KC_I, COMBO_END};

// -- NAV --

// Editing
const uint16_t PROGMEM paste_plain[]    = {SFT_PST, BOLD, COMBO_END};

// Window Navigation
const uint16_t PROGMEM prev_tab[]       = {SELWBAK, KC_UP, COMBO_END};
const uint16_t PROGMEM next_tab[]       = {KC_UP, SELWORD, COMBO_END};
const uint16_t PROGMEM prev_win[]       = {ALFRED, SELLINE, COMBO_END};
const uint16_t PROGMEM next_win[]       = {SELLINE, SWTCH, COMBO_END};

// Window Layout
const uint16_t PROGMEM left_screen[]    = {BACKSPC, CLOSE, MINIM, COMBO_END};
const uint16_t PROGMEM full_screen[]    = {GUI_CUT, ALT_CPY, SFT_PST, COMBO_END};
const uint16_t PROGMEM right_screen[]   = {REDO, SAVE, KC_ENT, COMBO_END};

// Window Management
const uint16_t PROGMEM escape[]         = {NEW, BACKSPC, COMBO_END};
const uint16_t PROGMEM quit[]           = {BACKSPC, CLOSE, COMBO_END};

// Magnification
const uint16_t PROGMEM zoom_out[]       = {REDO, SAVE, COMBO_END};
const uint16_t PROGMEM zoom_in[]        = {SAVE, KC_ENT, COMBO_END};


combo_t key_combos[] = {

    // Typing
    COMBO(enter, KC_ENTER),              // H + A + E           => Enter
    COMBO(del_word, A(KC_BSPC)),         // R + T + S           => Delete Word

    // Caps Word
    COMBO(caps_word, CW_TOGG),           // Double Thumb        => Caps Word

    // Editing
    COMBO(paste_plain, C(KC_V)),         // Paste + Bold        => Plain Paste

    // Window Navigation
    COMBO(prev_tab, C(S(KC_TAB))),       // Sel Left + Up       => Previous Tab
    COMBO(next_tab, C(KC_TAB)),          // Up + Sel Right      => Next Tab
    COMBO(prev_win, G(S(KC_GRAVE))),     // Alfred + Sel Down   => Previous Win
    COMBO(next_win, G(KC_GRAVE)),        // Sel Down + Switcher => Next Window

    // Window Layout
    COMBO(left_screen, HYPR(KC_L)),      // Bkspc + Close + Min => Tile Left
    COMBO(full_screen, G(C(KC_F))),      // Cut + Copy + Paste  => Fullscreen
    COMBO(right_screen, HYPR(KC_R)),     // Redo + Save + Enter => Tile Right

    // Window Management
    COMBO(escape, KC_ESCAPE),            // New + Close         => Escape
    COMBO(quit, G(KC_Q)),                // Close + Fullscreen  => Quit App

    // Magnification
    COMBO(zoom_out, G(KC_MINS)),         // Redo + .            => Zoom out
    COMBO(zoom_in, G(KC_EQL)),           // . + Save            => Zoom In

    // Epistory
    COMBO(epi_enter_nav, EPISTORY_NAV),
    COMBO(epi_exit_nav, EPISTORY_NAV),

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
    [SYM] = {0, 255, 255},   // Red
    [NAV] = {219, 255, 255}, // Pink
    [EPI] = {188, 255, 255}, // Purple
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
// User macro callbacks
//   - Epistory
//
///////////////////////////////////////////////////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // DASH — send hyphen normally, or em-dash after SPACE
    static bool last_char_space = false;
    if (keycode == DASH && record->event.pressed) {
        if (last_char_space) {
            SEND_STRING(SS_LALT(SS_LSFT("-"))); // em-dash
         } else {
            SEND_STRING("-"); // hyphen
         }
    }
    // naive tracking of whether last char was SPACE (to minimise firmware space)
    if (!(keycode == OSL(SYM))) {
        if ((keycode == NUM_SPC) && (record->tap.count == 1)) {
            last_char_space = true;
        }
        else {
            last_char_space = false;
        }
    }

    switch (keycode) {
        // HRM Editing Keys
        case CTL_ALL:
            return process_tap_hold(record, G(KC_A), KC_LCTL);
        case GUI_CUT:
            return process_tap_hold(record, G(KC_X), KC_LGUI);
        case ALT_CPY:
            return process_tap_hold(record, G(KC_C), KC_LALT);
        case SFT_PST:
            return process_tap_hold(record, G(KC_V), KC_LSFT);
    }

    switch (keycode) {
        // Epistory
        case EPISTORY_NAV:
            if (record->event.pressed) {
                tap_code(KC_SPC);
                layer_invert(EPI);
            }
            return false;
    }

    return true;
}
