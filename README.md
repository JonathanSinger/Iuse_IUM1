
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

**The configurations that are shared have no guarantee or warranty. The configurations may not work on your device, or may even cause damage or harm. The configurations are to be considered AS-IS and should be used at your own risk.**

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
___________________
| -  | X | X | TX |
| RX | X | X | +  |
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
```
