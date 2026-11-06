#pragma once

// Tap-Hold //
//----------//

#define TAPPING_TERM 250        // High tapping term for (non-lightshift) HRMs
#define FLOW_TAP_TERM 125       // Disable (non-lightshift) HRMs on typing
#define TAPPING_TERM_PER_KEY           // For NUM_SPC only
#define LIGHTSHIFT_USER_TAPPING_TERM   // For NUM_SPC only
#define SPECULATIVE_HOLD


// Key Repeating//
//--------------//
#define QUICK_TAP_TERM 0        // Fully disable key repeating, so
							    // tap <space> -> hold <num> activates NUM


// Combos //
//--------//
#define COMBO_ONLY_FROM_LAYER 0  // match all combos against BASE keycodes
#define COMBO_SHOULD_TRIGGER     // per-layer filtering in combo_should_trigger							    


// Lumberjack //
//------------//
#define LUMBERJACK_COLOR


// Switcher //
//----------//
#define SWITCHER_MACOS_APP_SWITCHER
#define SWITCHER_ENABLE_SECONDARY_KEYS


// Lightshift //
//------------//
#define LIGHTSHIFT_TAPPING_TERM 120


// Sentence Case //
//---------------//
#define SENTENCE_CASE_TIMEOUT 0  // disable timeout


// Caps Word //
//-----------//
// #define CAPS_WORD_INVERT_ON_SHIFT // breaks custom shift


// Select Word //
//-------------//
#define SELECT_WORD_OS_MAC


// Layers //
//--------//
#define LAYER_STATE_8BIT


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
