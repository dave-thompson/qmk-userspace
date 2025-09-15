// Tap-Hold //
//----------//
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY     // Only three keys need shorter tapping terms:  HRM_S, HRM_H, NAV_SPC

#define FLOW_TAP_TERM 125        // Disable HRMs during fast typing (HRM_S and HRM_H are excepted after whitespace in keymap.c)

#define PERMISSIVE_HOLD          // Mod-tap keys held for LESS than TAPPING_TERM but fully encasing another key tap  =>  Treat as held modifier...
#define CHORDAL_HOLD             //                                                                                      ...unless the two keys are on the same hand
#define BILATERAL_COMBINATIONS   // Mod-tap keys held for MORE than TAPPING_TERM, then same-hand tap  =>  Treat modifier hold as a tap


// Key Repeating//
//--------------//
#define QUICK_TAP_TERM 0 // Fully disable key repeating so that tap <space> -> hold <num> still activates the num layer


// Oneshots //
//----------//
#define ONESHOT_TAP_TOGGLE 2
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 5000


// Lumberjack //
//------------//
#define LUMBERJACK_COLOR


// Switcher //
//----------//
#define SWITCHER_MACOS_APP_SWITCHER
#define SWITCHER_ENABLE_SECONDARY_KEYS


// Sentence Case //
//---------------//
#define SENTENCE_CASE_TIMEOUT 0  // disable timeout


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
