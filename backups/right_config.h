// Copyright 2023 niqueg (@idabenini)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 10


#define MATRIX_ONBOARD_COL_PINS { B5, B4, E6, B6, B2, B3, B1, F6, F5, D1 }
#define MATRIX_ONBOARD_ROW_PINS { C6,  D7,  D4,  F7 }

#define DIODE_DIRECTION COL2ROW


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
