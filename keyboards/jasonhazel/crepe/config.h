#pragma once

#include "config_common.h"

#define DEVICE_VER		0x0001
#define VENDOR_ID		  0x4A48 // JH
#define PRODUCT_ID		0x4350 // cp

#define MANUFACTURER    jasonhazel
#define PRODUCT         CREPE

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { F4, F5, F6, F7, B1, B3, B2, B6}
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 0