///////////////////////////////////////////////////////////////////////////////
//
// ErgoDox EZ Glow: Board-specific code
//
///////////////////////////////////////////////////////////////////////////////

#include QMK_KEYBOARD_H

#include "layout.h"
#include "dave-thompson.c"


///////////////////////////////////////////////////////////////////////////////
//
// Chordal Hold Handedness
//
///////////////////////////////////////////////////////////////////////////////

// Doesn't change behaviour, but saves 178 bytes
char chordal_hold_handedness(keypos_t key) {
  return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}


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
