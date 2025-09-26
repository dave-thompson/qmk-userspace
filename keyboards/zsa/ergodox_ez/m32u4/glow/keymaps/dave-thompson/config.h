// Tap-Hold //
//----------//

// This still isn't working for me.  Core issue:

// For Shift-I, LSFT(KC_S) is pressed for ~170ms, so TAPPING_TERM need to be
// less than that.  PERMISSIVE_HOLD doesn't solve the problem, because
// (right-little) I is slower to release than left-index LSFT(KC_S).  A
// typical pattern looks like this:
//
// S (down) - 
// I (down) - 90
// S ( up ) - 80  (Hold: 170)
// I ( up ) -  4  (Hold: 84)

// However, reducing TAPPING_TERM below 170 creates its own problem:
//
// In the left-handed roll 'str', S is depressed for ~170ms, so 'string'
// becomes TRing'.

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY     // Only three candidates for shorter tapping
								 // terms:  HRM_S, HRM_H, NAV_SPC

#define FLOW_TAP_TERM 125        // Disable HRMs on fast typing (HRM_S / HRM_H
								 // after whitespace excepted in keymap.c)

#define PERMISSIVE_HOLD          // Mod-taps held LESS than TAPPING_TERM but
								 // fully encasing another key tap  =>  Treat
								 // as held modifier...
#define CHORDAL_HOLD             //      ...unless both keys on the same hand

// Sadly, BILATERAL_COMBINATIONS was never merged, so this does nothing.
// Otherwise, it would fix the problem.
#define BILATERAL_COMBINATIONS   // Mod-taps held MORE than TAPPING_TERM, then
                                 // same-hand tap  =>  Treat as tap


// Key Repeating//
//--------------//
#define QUICK_TAP_TERM 0         // Fully disable key repeating, so
								 // tap <space> -> hold <num> activates NUM


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
