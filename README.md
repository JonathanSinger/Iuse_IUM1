# Iuse IUM1
Marlin Firmware 2.0.6.1 for the Iuse IUM1, specifically running an STM32.

This printer is also known by other names:

- Alladinbox Skycube
- Bonsai Labs BS Cube
- Icstation
- iNSTONE
- iSee 3D
- HopeWant

Other versions may not have an STM32 so be sure to check. Research has shown earlier models sport an ATMEL. They all appear to run Repetier firmware out of the box.

Some disassembly is required to access the pins and buttons for this process.

**The configurations that are shared have no guarantee or warranty. The configurations may not work on your device, or may even cause damage or harm. The configurations are to be considered AS-IS and should be used at your own risk.**

## Specifications

- 110mm X
- 110mm Y
- 110mm Z
- M6 Z lead screw
- No heated bed
- No parts cooling
- A4988 Stepper Drivers

## Files

### Configuration.h

### Configuration_adv.h

### pins_FYSETC_CLONE.h

## Setup

### pins.h

```
#elif  MB(FYSETC_CLONE)
  #include  "stm32f1/pins_FYSETC_CLONE.h"  // STM32F1 env:STM32F103RE
```

### boards.h

```
  #define  BOARD_FYSETC_CLONE  9997 // FYSETC CLONE
```

### platformio.ini

```
default_envs = STM32F103RE
```

### File Placement

pins_FYSETC_CLONE.h should be placed in the **src/pins/stm32f1/** directory.

## Flashing

This particular board is programmed via Serial with a simple USB converter such as FTDI.

### Pinout

Board Side "WIFI" J1 header

```
[POWER]
___________________ _____
| -  | X | X | TX | |FAN|
| RX | X | X | +  | | 1 | 
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯
```

### Toolchain

Software used is stm32loader (https://pypi.org/project/stm32loader/)

For the port path, this may change. I used OSX, which appears as cu.usbserial-XXXXXXXX, while on other operating systems this may be appear different.

For the file path, use the relative or exact path for your PlatformIO build output firmware file.

```
$ stm32loader -ew -p /dev/cu.usbserial-XXXXXXXX -f F1 -a 0x08000000 .pio/build/STM32F103RE/firmware.bin
Activating bootloader (select UART)
Bootloader version: 0x22
Chip id: 0x414 (STM32F10x High-density)
Device UID: FF36-05D9-37304842-XXXXXXXX
Flash size: 512 KiB
Write 800 chunks at address 0x8000000...
Writing ████████████████████████████████ 800/800
```

To flash the board:
1. Hold down the SW2 (BOOT0) button located near the endstop headers and JP1
2. Press the reset button while holding BOOT0
3. Release the BOOT0 button
4. Wait 2 seconds before running the stm32loader command
