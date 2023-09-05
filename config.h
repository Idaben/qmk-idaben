// Copyright 2023 niqueg (@idabenini)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 20

#define MATRIX_COL_PINS_LEFT  { B1, B3, B2, B6, B5, C6, B4, E6, D7, D0 }
#define MATRIX_ROW_PINS_LEFT { D4,  F5,  F6,  F7 }

#define MATRIX_COL_PINS_RIGHT { B1, B3, B2, B6, E6, B4, B5, F6, F5, D1 }
#define MATRIX_ROW_PINS_RIGHT { C6,  D7,  D4,  F7 }


//#define MATRIX_COL_PINS_LEFT { "B1", "B3", "B2", "B6", "B5", "C6", "B4", "E6", "D7", "D2" } 
// no pin is replaced with unused pin, D2
//#define MATRIX_ROW_PINS_LEFT { "D4", "F5", "F6", "F7" }


// THIS SHOULD BE REVERSED?????
//#define MATRIX_COL_PINS_RIGHT { "B5", "B4", "E6", "B6", "B2", "B3", "B1", "F6", "F5", "D1" }
//#define MATRIX_ROW_PINS_RIGHT { "C6", "D7", "D4", "F7" } 

#define DIODE_DIRECTION COL2ROW

#define SOFT_SERIAL_PIN D3  // or D1, D2, D3, E6

#define MASTER_LEFT

// SOME BASIC OLED CONFIGS
#define OLED_BRIGHTNESS 20
#define OLED_TIMEOUT 60000
#define OLED_SCROLL_TIMEOUT 30000

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
