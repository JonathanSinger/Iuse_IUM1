/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

#define BOARD_INFO_NAME   "FYSETC CLONE"

#define DISABLE_JTAG

//
// Flash EEPROM Emulation
//
#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  #define EEPROM_PAGE_SIZE     (0x800U)           // 2KB
  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
  #define MARLIN_EEPROM_SIZE    EEPROM_PAGE_SIZE  // 2KB
#endif

//
// Limit Switches
//
#define X_STOP_PIN                          PA2
#define Y_STOP_PIN                          PA3
#define Z_STOP_PIN                          PB10

//
// Steppers
//
#define X_STEP_PIN                          PC10
#define X_DIR_PIN                           PD2
#define X_ENABLE_PIN                        PA14

#define Y_STEP_PIN                          PA8
#define Y_DIR_PIN                           PC8
#define Y_ENABLE_PIN                        PA13

#define Z_STEP_PIN                          PB15
#define Z_DIR_PIN                           PC6
#define Z_ENABLE_PIN                        PC7

#define E0_STEP_PIN                         PC0
#define E0_DIR_PIN                          PB8
#define E0_ENABLE_PIN                       PA15

//
// Stepper current PWM
//
#ifndef MOTOR_CURRENT_PWM_RANGE
  #define MOTOR_CURRENT_PWM_RANGE           1500  // origin:2000
#endif
#define DEFAULT_PWM_MOTOR_CURRENT { 500, 500, 400 } // origin: {1300,1300,1250}

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC3
#define HEATER_BED_PIN                      PC1
#ifndef FAN_PIN
  #define FAN_PIN                           PC2
#endif

//
// Temperature Sensors
//
#define TEMP_BED_PIN                        PA1   // Analog Input
#define TEMP_0_PIN                          PA0   // Analog Input

//
// Misc. Functions
//
#define SDSS                                PA4

//
// LCD Pins
//
#if HAS_SPI_LCD

  #define BEEPER_PIN                        PC12

  #if HAS_GRAPHICAL_LCD

    #define DOGLCD_A0                       PB12
    #define DOGLCD_CS                       PB14


    #define DEFAULT_LCD_CONTRAST            210
    //#define LCD_SCREEN_ROT_90
    //#define LCD_SCREEN_ROT_180
    //#define LCD_SCREEN_ROT_270

  #endif

  // not connected to a pin
  #define SD_DETECT_PIN                     PC4

  #if ENABLED(NEWPANEL)
    // The encoder and click button
    #define BTN_EN1                         PC15
    #define BTN_EN2                         PC14
    #define BTN_ENC                         PC13
  #endif

  #define LCD_RESET_PIN                     PB13

#endif
