#include QMK_KEYBOARD_H

# define _LAYER0 0
# define _LAYER1 1
# define _LAYER2 2
# define _LAYER3 3


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



#ifdef OLED_ENABLE


// ROTATE OLED 
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

// DRAW TO OLED 
// max is 5 characters horizontal, and 15 lines vertical
bool oled_task_user() {
	oled_set_cursor(0, 1);
	
	oled_write("LAYER", false);  //LINE 1
	
	//LINE 2 is this switch statement
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
		default:
			oled_write("ERROR", false);
	}
	
	oled_write("     ", false);	 //LINE 3
	oled_write("     ", false);  //LINE 4
	
	oled_write("CAPSL", false);  //LINE 5
	
	// THIS is LINE 6
	// Host Keyboard LED Status 
    led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write(led_state.caps_lock ? "> ON " : "> OFF", false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	
	
	
	//oled_write("> OFF", false);  //LINE 6
	
	
	oled_write("     ", false);  //LINE 7
	oled_write("STAT1", false);  //LINE 8
	oled_write("> 151", false);  //LINE 9
	oled_write("     ", false);  //LINE 10
	oled_write("STAT2", false);  //LINE 11
	oled_write("> 42 ", false);  //LINE 12
	oled_write("     ", false);  //LINE 13
	oled_write("STAT3", false);  //LINE 14
	oled_write("> 012", false);  //LINE 15
	return false;
}



#endif



