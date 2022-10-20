#pragma once

#include "config_common.h"

#define DEVICE_VER  0x0001
#define VENDOR_ID   0x4A48 // JH
#define PRODUCT_ID  0x4257 // BW

#define MANUFACTURER    jasonhazel
#define PRODUCT         Bad Wings

#define MATRIX_COLS 8
#define MATRIX_ROWS  5

#define SPI_SCK_PIN     GP2
#define SPI_MOSI_PIN    GP3
#define SPI_MISO_PIN    GP4

#define SHIFTREG_MATRIX_COL_CS  GP0
#define SHIFTREG_DIVISOR        8
#define SHIFTREG_ROWS           5
#define SHIFTREG_COLS           8

#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS_SR { GP26, GP27, GP28, GP29, GP6 }

#define POINTING_DEVICE_CS_PIN GP1

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

