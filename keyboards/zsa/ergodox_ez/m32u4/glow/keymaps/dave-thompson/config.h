// Tap-Hold //
//----------//

#define TAPPING_TERM 250        // High tapping term for (non-lightshift) HRMs
#define FLOW_TAP_TERM 125       // Disable (non-lightshift) HRMs on typing


// Key Repeating//
//--------------//
#define QUICK_TAP_TERM 0        // Fully disable key repeating, so
							    // tap <space> -> hold <num> activates NUM


// Lumberjack //
//------------//
#define LUMBERJACK_COLOR


// Switcher //
//----------//
#define SWITCHER_MACOS_APP_SWITCHER
#define SWITCHER_ENABLE_SECONDARY_KEYS


// Lightshift //
//------------//
#define LIGHTSHIFT_TAPPING_TERM 140


// Sentence Case //
//---------------//
#define SENTENCE_CASE_TIMEOUT 0  // disable timeout


// Caps Word //
//-----------//
#define CAPS_WORD_INVERT_ON_SHIFT


// Select Word //
//-------------//
#define SELECT_WORD_OS_MAC


// ZSA //
//-----//
#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "aW7eb/B49raD"
#define LAYER_STATE_8BIT
// RGB:
#define RGB_MATRIX_STARTUP_SPD 60
#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 30000


// Space Saving //
//--------------//

#define DISABLE_LEADER

#ifndef NO_DEBUG
	#define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
	#define NO_PRINT
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
