/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 * Copyright 2020 MK
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

/* USB Device descriptor parameter (moved to .json)*/
//#define VENDOR_ID    0x16c0
//#define PRODUCT_ID   0x0487
//#define DEVICE_VER   0x0001
//#define MANUFACTURER MK
//#define PRODUCT      TRACKzeron

/* ke22y matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 7

 // Pinout Map - Teensy 2.0++
     //               Index      Middle      Ring      Pinky
     // ,-----------------------------------------------------------------.
     // |          |  C0/13 | |  D3/6   | | F5/38  | | E6/30  |           |       Profile    LED
     // |------------------ ----------------------------------------------|     ,-------------------.
     // |          |  E1/12 | |  D2/5   | | F4/37  | | E7/29  |           |     |  F6/39  | C5/C18  |  
     // |-----------------------------------------------------------------|     |-------------------|
     // |  F0/33   |  E0/11 | |  D1/4   | | F3/36  | | B4/24  |           |     |  F7/40  | C6/C19  |
     // |-----------------------------------------------------------------|     `-------------------'
     // |  C1/14 | |  D5/8  | |  D0/3   | | F2/35  | | B5/23  |           |  
     // |-----------------------------------------------------------------|
     // |  C2/15 | |  D4/7  | |  B7/2   | | F1/34  | | B6/22  |           |
     // `-----------------------------------------------------------------'
     //   ^ Pinky, Index, Thumb

#define DIRECT_PINS { \
  { NO_PIN, C0, D3, F5, E6, C5, C6  }, \
  { NO_PIN, E1, D2, F4, E7, F6, F7  }, \
  {   F0,   E0, D1, F3, B4, NO_PIN, NO_PIN }, \
  {   C1,   D5, D0, F2, B5, NO_PIN, NO_PIN }, \
  {   C2,   D4, B7, F1, B6, NO_PIN, NO_PIN } \
}



/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* Much more so than a keyboard, speed matters for a mouse. So we'll go for as high
   a polling rate as possible. */
#define USB_POLLING_INTERVAL_MS 1
#define USB_MAX_POWER_CONSUMPTION 100

