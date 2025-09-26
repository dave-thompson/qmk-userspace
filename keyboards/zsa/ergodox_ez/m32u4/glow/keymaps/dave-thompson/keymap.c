#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  EPISTORY_NAV,
};


///////////////////////////////////////////////////////////////////////////////
//
// Keyboard Layout
//
///////////////////////////////////////////////////////////////////////////////

enum layers {
  BASE,
  NUM,
  SYM,
  NAV,
  EPI,
};

enum keycode_aliases {

  // Home-row Mods
  HRM_N = LALT_T(KC_N),
  HRM_R = LCTL_T(KC_R),
  HRM_T = LGUI_T(KC_T),
  HRM_S = LSFT_T(KC_S),
  HRM_H = RSFT_T(KC_H),
  HRM_A = RGUI_T(KC_A),
  HRM_E = RCTL_T(KC_E),
  HRM_I = RALT_T(KC_I),
  HRM_1 = LALT_T(KC_1),
  HRM_2 = LCTL_T(KC_2),
  HRM_3 = LGUI_T(KC_3),
  HRM_4 = LSFT_T(KC_4),
  HRM_7 = RSFT_T(KC_7),
  HRM_8 = RGUI_T(KC_8),
  HRM_9 = RCTL_T(KC_9),
  HRM_0 = RALT_T(KC_0),

  // Layer Switches
  NUM_SPC = LT(NUM, KC_SPC),

  // Symbols
  POUND = S(KC_3),
  M_DSH = A(S(KC_MINS)),
  HASH = A(KC_3),

  // Window Management
  NEW = G(KC_N),
  CLOSE = G(KC_W),
  FULLSCR = G(C(KC_F)),
  MINIM = G(KC_M),

  // Formatting
  ITALIC = G(KC_I),
  BOLD = G(KC_B),
  UNDER = G(KC_U),

  // Editing
  ALL = G(KC_A),
  CUT = G(KC_X),
  COPY = G(KC_C),
  PASTE = G(KC_V),

  // State
  UNDO = G(KC_Z),
  REDO = G(S(KC_Z)),
  SAVE = G(KC_S),

  // Miscellaneous
  ALFRED = G(KC_SPC),
  LOCKCMP = G(C(KC_Q)),
  BUILD_K = HYPR(KC_K),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(

    // BASE - Left
    _______, _______, _______, _______, _______, _______, _______,    
    _______, KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    _______,    
    _______, HRM_N,   HRM_R,   HRM_T,   HRM_S,   KC_G,                
    _______, KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,    _______,    
    _______, _______, _______, _______, _______,                      

                                                 _______, _______,
                                                          _______,
                                        MO(NAV), _______, BUILD_K,

    // BASE - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    _______,
             KC_Y,    HRM_H,   HRM_A,   HRM_E,   HRM_I,   _______,
    _______, KC_K,    KC_P,    KC_COMM, KC_DOT,  OSL(SYM),_______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    QK_BOOT, _______, NUM_SPC

  ),
  [NUM] = LAYOUT_ergodox(

    // NUM - Left
    _______, _______, _______, _______, _______, _______, _______,      
    _______, KC_LABK, KC_MINS, KC_PERC, KC_SLSH, KC_LBRC, _______,      
    _______, HRM_1,   HRM_2,   HRM_3,   HRM_4,   KC_LPRN,               
    _______, KC_CIRC, KC_DLR,  POUND,   KC_5,    KC_LCBR, _______,      
    _______, _______, _______, _______, _______,                        

                                                 _______, _______,  
                                                          _______,  
                                        _______, _______, _______,

    // NUM - Right
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_RBRC, KC_ASTR, KC_EQL,  KC_PLUS, KC_RABK, _______,
             KC_RPRN, HRM_7,   HRM_8,   HRM_9,   HRM_0,   _______,
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
    _______, KC_AMPR, KC_UNDS, KC_AT,   M_DSH,   _______,                   
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
    _______, ALL,     CUT,     COPY,    PASTE,   BOLD,                      
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
    _______, _______, _______, _______, _______, _______,  _______,                  
    _______, _______, _______, KC_E,    _______, _______,  _______,                  
    _______, _______, _______, _______, KC_F,    _______,                            
    _______, _______, _______, _______, _______, _______,  _______,                  
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
    {ALL, KC_Q},            // left pinky sends 'Q' to quit app
    {PASTE, KC_H},          // left index sends 'H' to hide app
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

char chordal_hold_handedness(keypos_t key) {
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        // Disable flow tap when home-row shifting after space/enter/backspace
        uint16_t prev_tap = get_tap_keycode(prev_keycode);
        if (prev_tap == KC_SPC
            || prev_tap == KC_ENTER
            || prev_tap == KC_BSPC) {
            switch (keycode) {
                case HRM_S:
                case HRM_H:
                    return 0;
                default:
                    return FLOW_TAP_TERM;
            }
        }  
    }
    return 0;
}   

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Lower TT for home-row shifts for capital letters while fast typing
        case HRM_S:
        case HRM_H:
            //return 160;
        case NUM_SPC:
        default:
            return TAPPING_TERM;
    }
}


///////////////////////////////////////////////////////////////////////////////
//
// Combos
//
///////////////////////////////////////////////////////////////////////////////

// Typing
const uint16_t PROGMEM enter[]          = {HRM_H, HRM_A, HRM_E, COMBO_END};
const uint16_t PROGMEM del_word[]       = {HRM_R, HRM_T, HRM_S, COMBO_END};

// Editing
const uint16_t PROGMEM paste_plain[]    = {PASTE, BOLD, COMBO_END};

// Window Navigation
const uint16_t PROGMEM prev_tab[]       = {SELWBAK, KC_UP, COMBO_END};
const uint16_t PROGMEM next_tab[]       = {KC_UP, SELWORD, COMBO_END};
const uint16_t PROGMEM prev_win[]       = {ALFRED, SELLINE, COMBO_END};
const uint16_t PROGMEM next_win[]       = {SELLINE, SWTCH, COMBO_END};

// Window Layout
const uint16_t PROGMEM left_screen[]    = {CUT, COPY, COMBO_END};
const uint16_t PROGMEM right_screen[]   = {COPY, PASTE, COMBO_END};

// Window Management
const uint16_t PROGMEM escape[]         = {NEW, CLOSE, COMBO_END};
const uint16_t PROGMEM quit[]           = {CLOSE, FULLSCR, COMBO_END};

// Magnification
const uint16_t PROGMEM zoom_out[]       = {REDO, KC_DOT, COMBO_END};
const uint16_t PROGMEM zoom_in[]        = {KC_DOT, SAVE, COMBO_END};

// Epistory
const uint16_t PROGMEM epi_enter_nav[]  = {KC_D, HRM_S, HRM_H, KC_O, COMBO_END};
const uint16_t PROGMEM epi_exit_nav[]   = {KC_E, KC_F, KC_J, KC_I, COMBO_END};


combo_t key_combos[] = {

    // Typing
    COMBO(enter, KC_ENTER),              // H + A + E           => Enter
    COMBO(del_word, A(KC_BSPC)),         // R + T + S           => Delete Word

    // Editing
    COMBO(paste_plain, C(KC_V)),         // Paste + Bold        => Plain Paste

    // Window Navigation
    COMBO(prev_tab, C(S(KC_TAB))),       // Sel Left + Up       => Previous Tab
    COMBO(next_tab, C(KC_TAB)),          // Up + Sel Right      => Next Tab
    COMBO(prev_win, G(S(KC_GRAVE))),     // Alfred + Sel Down   => Previous Win
    COMBO(next_win, G(KC_GRAVE)),        // Sel Down + Switcher => Next Window

    // Window Layout
    COMBO(left_screen, HYPR(KC_L)),      // Cut + Copy          => Tile Left
    COMBO(right_screen, HYPR(KC_R)),     // Copy + Paste        => Tile Right

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
//   - One-Shot Shift / Caps Word
//   - Epistory
//
///////////////////////////////////////////////////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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
