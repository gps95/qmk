#include QMK_KEYBOARD_H

//todo: investigate: leader key, combos, mouse key delays,

//declare layers
enum layers{_BASE,_PSYM,_FUN,_NAV,_NUM,_MOUSE,_SYM,_TRI};

/*key overrides*/
//const key_override_t ko_ = ko_make_basic();
const key_override_t ko_semicolon = ko_make_basic(MOD_MASK_SHIFT,KC_COMM,KC_SCLN);//S+, -> ;
const key_override_t ko_colon = ko_make_basic(MOD_MASK_SHIFT,RALT_T(KC_DOT),KC_COLN);//S+. -> :

//This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&ko_semicolon,
  &ko_colon,
};

/*tri layer*/
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _PSYM, _FUN, _TRI);
}

//keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]=
{
//base layer
[_BASE] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,                                        KC_MUTE, KC_Z, KC_U, KC_I, KC_O, KC_P,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_ESC,         KC_BSLS, KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT),
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_Y, KC_X, KC_C, KC_V, KC_B,                                                 KC_N, KC_M, KC_COMM, KC_DOT, KC_MINUS,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  LT(_PSYM,KC_TAB), LT(_NAV,KC_SPC), LT(_MOUSE,KC_ENT),                        LT(_SYM,KC_SLASH), LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL)
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//programming symbols
[_PSYM] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_ESC,                          KC_BSLS, XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  RALT(KC_N), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_TRNS, XXXXXXX, XXXXXXX,                                                    KC_SLASH, KC_BSPC, KC_TRNS
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//F keys
[_FUN] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXXXXX,                                   KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_ESC,                                   XXXXXXX, KC_PSCR, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_TRNS, KC_SPC, KC_ENT,                                                      XXXXXXX, XXXXXXX, KC_TRNS
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//Document navigation
[_NAV] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                          KC_MUTE, KC_HOME, KC_END, KC_UP, KC_PGUP, KC_PGDN,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_ESC,                          XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX,                                                    KC_SPC, KC_BSPC, KC_DEL
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//Numbers and operations
[_NUM] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_1, KC_2, KC_3, KC_4, KC_5, XXXXXXX,                                        KC_MUTE, XXXXXXX, LSA(KC_DOT), LSA(KC_SCLN), LSA(KC_COMM), XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_6, KC_7, KC_8, KC_9, KC_0, KC_ESC,                                         XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_MINUS, KC_EQUAL, KC_ASTR, KC_COLN, KC_PLUS,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_TAB, KC_SPC, KC_ENT,                                                       XXXXXXX, XXXXXXX, XXXXXXX
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//mouse movement
[_MOUSE] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MUTE, KC_APP, XXXXXXX, MS_UP, MS_WHLU, MS_WHLD,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_ESC,                          XXXXXXX, MS_WHLL, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLR,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX,                                                    MS_BTN1, MS_BTN2, MS_BTN3 
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//symbols
[_SYM] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERC, XXXXXXX,                         KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_EQUAL, KC_AMPR, KC_PLUS, KC_QUES, KC_TILDE, KC_ESC,                        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_LT, KC_GT, KC_CIRC, KC_ASTR, RALT(KC_S),                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  KC_TRNS, KC_SPC, KC_ENT,                                                      XXXXXXX, XXXXXXX, XXXXXXX
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
),

//tri layer
[_TRI] = LAYOUT_split_3x5_3_ex2(
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLU, XXXXXXX, QK_BOOT,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,                          XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLD, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
  XXXXXXX, XXXXXXX, XXXXXXX,                                                    XXXXXXX, XXXXXXX, XXXXXXX
//----------------------------------------------------------------------|     |---------------------------------------------------------------------------
)};

//encoder map
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[_BASE]  = { ENCODER_CCW_CW(MS_WHLU,MS_WHLD),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(KC_VOLD,KC_VOLU), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_NAV]   = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_MOUSE] = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_PSYM]  = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_NUM]   = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_SYM]   = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_FUN]   = { ENCODER_CCW_CW(RM_NEXT, RM_PREV),  ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(RM_HUEU,RM_HUED), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
[_TRI]   = { ENCODER_CCW_CW(XXXXXXX,XXXXXXX),   ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX), ENCODER_CCW_CW(XXXXXXX,XXXXXXX),},
};
#endif