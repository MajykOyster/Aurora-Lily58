/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define MASTER_RIGHT

#define COMBO_COUNT 4

// Tapping term

#define TAPPING_TERM 200

// `SPLIT_HAND_PIN` can currently be defined in `info.json`,
// but can't yet be given a value
#define SPLIT_HAND_PIN F5

// Not yet available in `info.json`
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#endif

// Not yet available in `info.json`
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
#    define RGB_MATRIX_SPLIT RGBLED_SPLIT
#    define SPLIT_TRANSPORT_MIRROR
#endif

// Not yet available in `info.json`
#ifdef BOOTMAGIC_ENABLE
     // Top left key on left half
#    define BOOTMAGIC_LITE_ROW 0
#    define BOOTMAGIC_LITE_COLUMN 0
     // Top right key on right half
#    define BOOTMAGIC_LITE_ROW_RIGHT    5
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#define MOUSEKEY_DELAY 				10 	// Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 			20 	// Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 		6 	// Step size
#define MOUSEKEY_MAX_SPEED 			8	// Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 		50 	// Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 		10 	// Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 	80 	// Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED 	8 	// Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 	40 	// Time until maximum scroll speed is reached

// Unicode

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// RGB

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
// #define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
// #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16							// limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT		// Sets the default mode, if none has been set
// #define RGB_MATRIX_DEFAULT_HUE 0								// Sets the default hue value, if none has been set
// #define RGB_MATRIX_DEFAULT_SAT 255								// Sets the default saturation value, if none has been set
// #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS	// Sets the default brightness value, if none has been set
// #define RGB_MATRIX_DEFAULT_SPD 127								// Sets the default animation speed, if none has been set
// #define RGB_MATRIX_DISABLE_KEYCODES								// disables control of rgb matrix by keycodes (must use code functions to control the feature)
// #define RGB_MATRIX_SPLIT { X, Y } 								// (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
// #define SPLIT_TRANSPORT_MIRROR									// If RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
// #define RGB_TRIGGER_ON_KEYDOWN									// Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards

// Fix
#undef RGB_MATRIX_LED_COUNT
#define RGB_MATRIX_LED_COUNT 68
#undef RGB_MATRIX_SPLIT
#define RGB_MATRIX_SPLIT {34, 34}

// Enable animations
#define ENABLE_RGB_MATRIX_ALPHAS_MODS						// Static dual hue, speed is hue for secondary hue
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN					// Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT				// Static gradient left to right, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING						// Single hue brightness cycling animation
#define ENABLE_RGB_MATRIX_BAND_SAT							// Single hue band fading saturation scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_VAL							// Single hue band fading brightness scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT				// Single hue 3 blade spinning pinwheel fades saturation
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL				// Single hue 3 blade spinning pinwheel fades brightness
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT					// Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL					// Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL						// Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT					// Full gradient scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN					// Full gradient scrolling top to bottom
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN						// Full gradient scrolling out to in
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL				// Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON			// Full gradient Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL					// Full gradient spinning pinwheel around center of keyboard
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL						// Full gradient spinning spiral around center of keyboard
#define ENABLE_RGB_MATRIX_DUAL_BEACON						// Full gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON					// Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS				// Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS						// Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS				// Randomly changes a single key's hue and saturation
#define ENABLE_RGB_MATRIX_HUE_BREATHING					// Hue shifts up a slight ammount at the same time, then shifts back
#define ENABLE_RGB_MATRIX_HUE_PENDULUM						// Hue shifts up a slight ammount in a wave to the right, then back to the left
#define ENABLE_RGB_MATRIX_HUE_WAVE							// Hue shifts up a slight ammount and then back down in a wave to the right
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL					// Single hue fractal filled keys pulsing horizontally out to edges
#define ENABLE_RGB_MATRIX_PIXEL_FLOW						// Pulsing RGB flow along LED wiring with random hues
#define ENABLE_RGB_MATRIX_PIXEL_RAIN						// Randomly light keys with random hues
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP					// How hot is your WPM!
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN						// That famous computer simulation

// needs RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP					// How hot is your WPM!
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN						// That famous computer simulation

// needs RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE			// Pulses keys hit to hue & value then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE					// Static single hue, pulses keys hit to shifted hue then fades to current hue
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE				// Hue & value pulse near a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE			// Hue & value pulse near multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS				// Hue & value pulse the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS		// Hue & value pulse the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS				// Hue & value pulse away on the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS		// Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SPLASH							// Full gradient & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_MULTISPLASH						// Full gradient & value pulse away from multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_SPLASH						// Hue & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH				// Hue & value pulse away from multiple key hits then fades value out

// default
#define RGBLIGHT_DEFAULT_MODE ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON