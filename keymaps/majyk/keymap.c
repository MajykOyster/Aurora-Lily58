#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"

// Turn off Liatris LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

// Unicode

enum unicode_names {
	AGrL,
	AGrU,
	AE_L,
	AE_U,
	OE_L,
	OE_U,
	CCedL,
	CCedU,
	E_AigL,
	E_AigU,
	E_GrL,
	U_Gr,
	Micro,
	Inf,
	Sup,
	Slash,
	BkSla,
	Pipe,
	Excl,
	At,
	
	InvQuest,
	InvExcl,
	
	Dollar,
	Percent,
	Copyright,
	Registrd,
	ArrowR
};

const uint32_t unicode_map[] PROGMEM = {
	[AGrL]		= 0x00E0, // à
	[AGrU]		= 0x00C0, // À
	[AE_L]		= 0x00E6, // æ
	[AE_U]		= 0x00C6, // Æ
	[OE_L]		= 0x0153, // œ
	[OE_U]		= 0x0152, // Œ
	[CCedL]		= 0x00E7, // ç
	[CCedU]		= 0x00C7, // Ç
	[E_AigL]	= 0x00E9, // é
	[E_AigU]	= 0x00C9, // É
	[E_GrL]		= 0x00E8, // è
	[U_Gr]		= 0x00F9, // ù
	[Micro]		= 0x00B5, // µ
	[Inf]		= 0x003C, // <
	[Sup]		= 0x003E, // >
	[Slash]		= 0x002F, // /
	[BkSla]		= 0x005C, // 
	[Pipe]		= 0x007C, // |
	[Excl]		= 0x0021, // !
	[At]		= 0x0040, // @

	[InvQuest]	= 0x00BF, // ¡
	[InvExcl]	= 0x00A1, // ¿


	[Dollar]	= 0x0024, // $
	[Percent]	= 0x0025, // %
	[Copyright]	= 0x00A9, // ®
	[Registrd]	= 0x00AE, // 
	[ArrowR]	= 0x2192, // →
};


// Layer Declarations

enum {
	Default = 0,
	NumArr,
	Unic,
	Fun,
	Media,
	Mouse,
	Gaming
};

// Combos
const uint16_t PROGMEM combo1[] = {FR_Q, FR_W, COMBO_END};
const uint16_t PROGMEM combo2[] = {FR_M, XP(Excl,BkSla), COMBO_END};
const uint16_t PROGMEM combo3[] = {FR_A, FR_E, COMBO_END};
const uint16_t PROGMEM combo4[] = {FR_O, FR_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(combo1, FR_A),
	COMBO(combo2, FR_P),
	COMBO(combo3, XP(AE_L,AE_U)),
	COMBO(combo4, XP(OE_L,OE_U)),
};


// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[Default] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_NO,				FR_A,				FR_Z,				FR_E,				FR_R,				FR_T,											FR_Y,				FR_U,				FR_I,				FR_O,				FR_P,				KC_NO,
		LT(Mouse,KC_ESC),	FR_Q,				FR_S,				FR_D,				FR_F,				FR_G,											FR_H,				FR_J,				FR_K,				FR_L,				FR_M,				LT(Media,FR_CIRC),
		KC_LCTL,			FR_W,				FR_X,				FR_C,				FR_V,				FR_B,			KC_MUTE,		KC_MPLY,		FR_N,				FR_COMM,			FR_SCLN,			FR_COLN,			XP(Excl,BkSla),		KC_DEL,
														KC_LALT,			KC_LGUI,			LT(Unic,KC_TAB),	LT(Fun,KC_ENT),					LT(NumArr,KC_SPC),	LSFT_T(KC_BSPC),	KC_APP,				KC_RALT),

	[NumArr] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_NO,				FR_6,				FR_7,				FR_8,				FR_9,				FR_0,											KC_PGUP,			FR_QUOT,			KC_UP,				FR_DQUO,			KC_HOME,			KC_NO,
		FR_EQL,				FR_1,				FR_2,				FR_3,				FR_4,				FR_5,											KC_PGDN,			KC_LEFT,			KC_DOWN,			KC_RGHT,			KC_END,				KC_NO,
		KC_TRNS,			X(Percent),			KC_PSLS,			KC_PAST,			KC_PMNS,			KC_PPLS,		KC_TRNS,		KC_TRNS,		FR_LPRN,			FR_RPRN,			FR_LBRC,			FR_RBRC,			X(Inf),				X(Sup),
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

	[Unic] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_TRNS,			XP(AGrL,AGrU),		X(E_GrL),			XP(E_AigL,E_AigU),	X(Registrd),		FR_AMPR,										KC_TRNS,			X(U_Gr),			KC_TRNS,			XP(OE_L,OE_U),		KC_TRNS,			KC_TRNS,
		KC_TRNS,			KC_TRNS,			X(Dollar),			FR_HASH,			KC_TRNS,			KC_TRNS,										KC_TRNS,			KC_TRNS,			KC_TRNS,			X(ArrowR),			X(Micro),			KC_TRNS,
		KC_TRNS,			KC_TRNS,			KC_TRNS,			XP(CCedL,CCedU),	FR_UNDS,			FR_MINS,		KC_TRNS,		KC_TRNS,		X(At),				X(InvQuest),		FR_LCBR,			FR_RCBR,			X(InvExcl),			KC_TRNS,
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

	[Fun] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,				KC_F6,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_F7,				KC_F8,				KC_F9,				KC_F10,				KC_F11,				KC_F12,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_TRNS,			KC_TRNS,			KC_TRNS,			C(A(KC_DEL)),		A(KC_F4),			C(S(KC_ESC)),	KC_TRNS,		KC_TRNS,		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS, 			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

	[Media] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_MSTP,			KC_VOLU,			KC_MPLY,			KC_NO,				KC_NO,
		TO(Gaming),			KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_MPRV,			KC_VOLD,			KC_MNXT,			KC_NO,				KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,			KC_TRNS,		KC_TRNS,		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

	[Mouse] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_BTN1,			KC_MS_U,			KC_BTN2,			KC_WH_U,			KC_NO,
		KC_NO,				KC_NO,				KC_ACL0,			KC_ACL1,			KC_ACL2,			KC_NO,											KC_NO,				KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_D,			KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,			KC_TRNS,		KC_TRNS,		KC_NO,				KC_WH_L,			KC_NO,				KC_WH_R,			KC_NO,				KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

	[Gaming] = LAYOUT(
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_NO,				KC_TAB,				FR_A,				FR_Z,				FR_E,				FR_R,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_LSFT,			FR_3,				FR_Q,				FR_S,				FR_D,				FR_F,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_LCTL,			FR_4,				FR_W,				FR_X,				FR_C,				FR_V,			FR_5,			KC_TRNS,		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_ESC,				FR_2,				FR_1,				KC_SPC,							KC_ENT,				TO(Default),		KC_TRNS,			KC_NO),
};



/* Gave up on this one.

// Declaring arrays for each key group, storing the key index :
	int arrayNum[] = {1, 2, 3};
	int arrayArrows[] = {10, 11, 12};
	int arrayUnicode[] = {15, 27, 40};
	int arrayZqsd[] = {15, 16, 17};
	int arrayUnused[] = {0};


// For each function
#define foreach(a,b) for(int a=0;a<(sizeof(b)/sizeof(b[0]));a++)

int colour[] = {255, 0, 0}; // White only :(

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case NumArr:
			// Applying a colour to a key group in the current layer
			foreach(keyIndex, arrayNum) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
			}
			// Same colour, additional key group
			foreach(keyIndex, arrayArrows) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
			}
			break;
		case Unic:
			foreach(keyIndex, arrayUnicode) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
				break;
			}
		case Unused:
			foreach(keyIndex, arrayUnused) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
				break;
			}
		case Gaming:
			foreach(keyIndex, arrayZqsd) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
			}
			foreach(keyIndex, arrayNum) {
				bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
					RGB_MATRIX_INDICATOR_SET_COLOR(keyIndex, colour[0], colour[1], colour[2]);
					    return false;
				}
				break;
			}
			break;
	}
	return state;
}
*/