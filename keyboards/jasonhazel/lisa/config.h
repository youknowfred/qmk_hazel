#pragma once

#include "config_common.h"

#define DEVICE_VER              0x0001
#define VENDOR_ID               0x4A48
#define PRODUCT_ID              0x4C50

#define MANUFACTURER            jasonhazel
#define PRODUCT                 Lisa

#define MATRIX_ROWS             5
#define MATRIX_COLS             4

#define MATRIX_ROW_PINS         { D3, D2, D1, D0, B4 }
#define MATRIX_COL_PINS         { E6, D7, C6, D4 }

#define DIODE_DIRECTION         COL2ROW

#define DEBOUNCE                5

#define BOOTMAGIC_LITE_ROW      0
#define BOOTMAGIC_LITE_COLUMN   0