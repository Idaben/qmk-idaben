#include QMK_KEYBOARD_H

# define _LAYER0 0
# define _LAYER1 1
# define _LAYER2 2
# define _LAYER3 3
# define _LAYER4 4



#include "key_layout.c"


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// MOUSEKEY STUFFS
#ifdef MOUSEKEY_ENABLE
#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 50

#define MK_C_OFFSET_0	1		//Cursor offset per movement (KC_ACL0)
#define MK_C_INTERVAL_0	32		//Time between cursor movements (KC_ACL0)
#define MK_C_OFFSET_1	4		//Cursor offset per movement (KC_ACL1)
#define MK_C_INTERVAL_1	16		//Time between cursor movements (KC_ACL1)
#define MK_C_OFFSET_2	32		//Cursor offset per movement (KC_ACL2)
#define MK_C_INTERVAL_2	16		//Time between cursor movements (KC_ACL2)
#endif
// END OF MOUSEKEY STUFFS


#define IDLE_TIMEOUT_MS 30000  // Idle timeout in milliseconds.
static uint16_t idle_timer = 0;
bool oled_enabled = true;
bool initial_clear = false;

#ifdef OLED_ENABLE
// WPM related animations variables
int current_wpm = 0;
int current_wpm2 = 0;
char    wpm_str[4];



// ROTATE OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

// DRAW TO OLED
// max is 5 characters horizontal, and 15 lines vertical

#include "render_anim.c"

// Draw to OLED
bool oled_task_user() {
	
	current_wpm = get_current_wpm();
	current_wpm2 = get_current_wpm();
	// Host Keyboard LED Status 
	led_t led_state = host_keyboard_led_state();
	
	if (oled_enabled == false) {
		//oled_off();
		oled_set_cursor(0, 1);
		oled_write("x4([9", false);
		oled_write("k!s+)", false);
		oled_write("8@ =/", false);
		oled_write(" 5fL ", false);
		oled_write("p-2](", false);
		oled_write("S $2 ", false);
		oled_write(" t 48", false);
		oled_write("i&uLq", false);
		oled_write("7 8%r", false);
		oled_write("4;0* ", false);
		oled_write(" s !#", false);
		oled_write("9q!x ", false);
		oled_write(" >` 8", false);
		oled_write(" @~K ", false);
		oled_write("u?pL ", false);
		oled_write("frlp^", false);
		oled_scroll_right();
	} 
	else {
		// LAYERS
		//clear screen on first entry only
		if (initial_clear == false) {
			oled_clear();
			initial_clear = true;
		}

		oled_set_cursor(0, 1);
		oled_write("LAYER", false);
		switch (get_highest_layer(layer_state)) {
			case _LAYER0:
				oled_write(" base", false);
				break;
			case _LAYER1:
				oled_write("fx(N)", false);
				break;
			case _LAYER2:
				oled_write("symbl", false);
				break;
			case _LAYER3:
				oled_write("!qntm", false);
				break;
			case _LAYER4:
				oled_write("gameq", false);
				break;
			default:
				oled_write("ERROR", false);
		}
		
		// CAPS
		oled_set_cursor(0, 5);
		oled_write("CAPSL", false);  //LINE 5
		//oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
		oled_write(led_state.caps_lock ? "> ON " : "> OFF", false);
		//oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
		
		// WPM
		oled_set_cursor(0, 8);
		//oled_write("WPM\n", false);  //LINE 8
		wpm_str[3] = '\0';
		wpm_str[2] = '0' + current_wpm % 10;
		wpm_str[1] = '0' + (current_wpm /= 10) % 10;
		wpm_str[0] = '0' + current_wpm / 10;
		//oled_write(wpm_str, false);  //LINE 9

		
		
		// ANIMATION
		oled_set_cursor(0, 13);
		if (led_state.caps_lock == 1) {
			render_animation(2);
		} else {
			
			if (current_wpm2 > 60) {
				render_animation(0);
			} 
			else if (current_wpm2 > 0 && current_wpm2 < 60) {
				render_animation(1);
			}
			else if (current_wpm2 ==0 ) {
				render_animation(4);
			}
			else {
				render_animation(3);
			}	
		}
	}
	
    return false;
}
#endif


void matrix_scan_user(void) {
  if (idle_timer && timer_expired(timer_read(), idle_timer)) {
    // If execution reaches here, the keyboard has gone idle.
    idle_timer = 0;
	//oled_clear();
	oled_enabled = false;
	initial_clear = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  // On every key event, set idle_timer to expire after IDLE_TIMEOUT_MS.
  // We use idle_timer == 0 to indicate that the timer is inactive, so
  // the value is bitwise or'd with 1 to ensure it is nonzero.
  idle_timer = (record->event.time + IDLE_TIMEOUT_MS) | 1;
  oled_enabled = true;
  // Macros...

  return true;
}