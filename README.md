## ESP_AT_Lib Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_AT_Lib.svg?)](https://www.ardu-badge.com/ESP_AT_Lib)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/ESP_AT_Lib.svg)](https://github.com/khoih-prog/ESP_AT_Lib/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/ESP_AT_Lib/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/ESP_AT_Lib.svg)](http://github.com/khoih-prog/ESP_AT_Lib/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this ESP_AT_Lib library](#why-do-we-need-this-esp_at_lib-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
  * [Currently Supported AT-command shields](#currently-supported-at-command-shields)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Important Notes about AT Firmwares](#important-notes-about-at-firmwares)
  * [1. Firmwares tested OK with ESP8266 AT shields](#1-firmwares-tested-ok-with-esp8266-at-shields)
  * [2. Firmwares tested OK with ESP32 AT shields](#2-firmwares-tested-ok-with-esp32-at-shields)
  * [3. Firmwares tested OK with WizFi360 AT shields](#3-firmwares-tested-ok-with-WizFi360-at-shields)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
  * [10. For RTL8720DN boards using AmebaD core](#10-for-rtl8720dn-boards-using-amebad-core)
  * [11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core](#11-For-SAMD21-and-SAMD51-boards-using-ArduinoCore-fab-sam-core)
  * [12. For Seeeduino RP2040 boards](#12-For-Seeeduino-RP2040-boards)
  * [13. For Seeeduino nRF52840 boards](#13-For-Seeeduino-nRF52840-boards)
* [HOWTO Get started](#howto-get-started)
  * [API List](#api-list)
* [Hardware Connection](#hardware-connection)
  * [MEGA, SAM DUE](#mega-sam-due)
* [Attention](#attention)
* [Examples](#examples)
  * [ 1. ConnectWiFi](examples/ConnectWiFi)
  * [ 2. HTTPGET](examples/HTTPGET) 
  * [ 3. TCPClientSingle](examples/TCPClientSingle)
  * [ 4. TCPClientMultiple](examples/TCPClientMultiple)
  * [ 5. TCPServer](examples/TCPServer) 
  * [ 6. UDPClientSingle](examples/UDPClientSingle)
  * [ 7. UDPClientMultiple](examples/UDPClientMultiple)
* [Example TCPServer](#example-tcpserver)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. HTTPGET on RASPBERRY_PI_PICO with ESP8266-AT shield](#1-httpget-on-raspberry_pi_pico-with-esp8266-at-shield)
  * [2. HTTPGET on MBED RASPBERRY_PI_PICO with ESP8266-AT shield](#2-httpget-on-mbed-raspberry_pi_pico-with-esp8266-at-shield)
  * [3. TCPServer on WIZNET_WIZFI360_EVB_PICO](#3-TCPServer-on-WIZNET_WIZFI360_EVB_PICO)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [ESP_AT_Lib library](https://github.com/khoih-prog/ESP_AT_Lib)

#### Features

This is an WizFi360/ESP8266/ESP32 wrapper library for Arduino providing an easy-to-use way to manipulate WizFi360/ESP8266/ESP32-AT shields.

This library is based on, modified and improved from [ITEADLIB_Arduino_WeeESP8266](https://github.com/itead/ITEADLIB_Arduino_WeeESP8266)

---

#### Currently Supported Boards

This [**ESP_AT_Lib** library](https://github.com/khoih-prog/ESP_AT_Lib) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 
 2. **SAM DUE**
 
 3. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 4. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0, LC)**
 
 6. **STM32F/L/H/G/WB/MP1 boards (with 64+K Flash)**

- Nucleo-144
- Nucleo-64
- Discovery
- Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
- STM32L0, STM32L1, STM32L4, **STM32L5**
- STM32G0, STM32G4
- STM32H7
- STM32WB
- STM32MP1
- LoRa boards
- 3-D printer boards
- Generic Flight Controllers
- Midatronics boards

 7. **SIPEED_MAIX_DUINO** boards

 8. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040** using [**Earle Philhower's arduino-pico** core v1.4.0+](https://github.com/earlephilhower/arduino-pico) or [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).

 9. RP2040-based boards, such as **Nano_RP2040_Connect** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).

10. **WIZNET_WIZFI360_EVB_PICO** using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)


#### WIZNET_WIZFI360_EVB_PICO

<p align="center">
    <img src="https://github.com/khoih-prog/ESP_AT_Lib/raw/master/pics/WIZNET_WIZFI360_EVB_PICO.png">
</p>


---

#### Currently Supported AT-command shields

 1. `ESP8266-AT-command` shield
 2. `ESP32-AT-command` shield
 3. `W600` and `WIS600-01S` AT-command shield
 4. `WizFi360` AT-command shield
 
#### WIZFI360
 
<p align="center">
    <img src="https://github.com/khoih-prog/ESP_AT_Lib/raw/master/pics/wizfi360-pa.png">
</p>


---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.6+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Arduino Core for STM32 v2.4.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.). [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
 4. [`Teensy core v1.57+`](https://github.com/PaulStoffregen/cores) for Teensy 4.1.  [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/cores.svg)](https://github.com/PaulStoffregen/cores/releases/latest)
 5. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 6. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 7. [`Adafruit SAMD core 1.7.11+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 8. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 9. [`Adafruit nRF52 v1.3.0`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
10. [`Arduino mbed_rp2040 core 3.5.4+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
11. [`Earle Philhower's arduino-pico core v2.7.1+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
12. [`Ai-Thinker AT Firmware v1.5.4`](AT_Firmwares/At_firmware_bin1.54.zip) or [`AT Firmware v1.7.4.0`](AT_Firmwares/AT_Firmware_bin_1.7.4.0.zip) for ESP8266-AT shields.
13. [`AT version_2.1.0.0_dev`](AT_Firmwares/AT_version_2.1.0.0_dev.zip) for ESP32-AT shields.
14. `AT version_1.1.4` for `WIS600-01S` and `W600-AT` WiFi shields
15. `AT version:1.1.1.7` for `WizFi360` WiFi shields


---
---

### Important Notes about AT Firmwares

#### 1. Firmwares tested OK with ESP8266 AT shields

  - [`Ai-Thinker AT Firmware v1.5.4`](https://github.com/khoih-prog/ESP8266_AT_WebServer/blob/master/AT_Firmwares/At_firmware_bin1.54.zip)
  
    ```cpp
    AT version:1.1.0.0(May 11 2016 18:09:56)
    SDK version:1.5.4(baaeaebb)
    Ai-Thinker Technology Co. Ltd.
    Jun 13 2016 11:29:20
    ```
  - [`AT Firmware v1.7.4.0`](https://github.com/khoih-prog/ESP8266_AT_WebServer/blob/master/AT_Firmwares/AT_Firmware_bin_1.7.4.0.zip)
  
    ```cpp
    AT version:1.7.4.0(May 11 2020 19:13:04)
    SDK version:3.0.4(9532ceb)
    compile time:May 27 2020 10:12:17
    Bin version(Wroom 02):1.7.4
    ```
    
  - [`WIS600-01S`](https://www.aliexpress.com/item/32956707239.html) and [`W600`](https://www.seeedstudio.com/w600.html) using either ESP8266 or ESP32-AT commands and stock firmware
  
    ```cpp
    AT version:1.1.4(Dec 05 2018 11:06:45)
    SDK version:3.0.0
    Dec 05 2018 11:06:45
    ```
  
  
#### 2. Firmwares tested OK with ESP32 AT shields

  - [`AT version_2.1.0.0_dev`](https://github.com/khoih-prog/ESP8266_AT_WebServer/blob/master/AT_Firmwares/AT_version_2.1.0.0_dev.zip)
    
    ```cpp
    AT version:2.1.0.0-dev(4f6b92c - Jun 10 2020 10:36:54)
    SDK version:v4.0.1-193-ge7ac221b4
    compile time(b85a8df):Jun 18 2020 14:00:59
    Bin version:2.0.0(WROOM-32)
    ```
    
    See instructions at [AT Command Core](https://github.com/espressif/esp-at) and [ESP_AT_Get_Started](https://github.com/espressif/esp-at/blob/master/docs/en/get-started/ESP_AT_Get_Started.md)
  

#### 3. Firmwares tested OK with WizFi360 AT shields

    
    ```cpp
    FW Version:AT version:1.1.1.7(May  4 2021 15:14:59)
    SDK version:3.2.0(a0ffff9f)
    compile time:May  4 2021 15:14:59
    ``` 

---

4. Upload [`AT Firmware v1.7.4.0`](https://github.com/khoih-prog/ESP8266_AT_WebServer/blob/master/AT_Firmwares/AT_Firmware_bin_1.7.4.0.zip) bin files to correct locations as follows:

```
# BOOT MODE

### Flash size 8Mbit: 512KB+512KB
    boot_v1.2+.bin              0x00000
    user1.1024.new.2.bin        0x01000
    esp_init_data_default.bin   0xfc000
    blank.bin                   0x7e000 & 0xfe000


### Flash size 16Mbit-C1: 1024KB+1024KB
    boot_v1.2+.bin              0x00000
    user1.2048.new.5.bin        0x01000
    esp_init_data_default.bin   0x1fc000
    blank.bin                   0xfe000 & 0x1fe000
```


5. Test before using different AT-Firmware Version at your own risks. Just use any simple example to verify if the AT-firmware is OK.
6. Compatible AT-Firmare version will be updated. Check for all supported AT Firmwares and download them from [AT_Firmwares](https://github.com/khoih-prog/ESP8266_AT_WebServer/tree/master/AT_Firmwares).
7. Support to ESP32-AT-command shields will be added by using new library [ESP_AT_Lib](https://github.com/khoih-prog/ESP_AT_Lib) to replace [Blynk's BlynkESP8266_Lib](https://github.com/blynkkk/blynk-library/releases/Blynk_Release_v0.6.1.zip).

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `ESP_AT_Lib`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_AT_Lib.svg?)](https://www.ardu-badge.com/ESP_AT_Lib) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [ESP_AT_Lib](https://github.com/khoih-prog/ESP_AT_Lib) page.
2. Download the latest release `ESP_AT_Lib-master.zip`.
3. Extract the zip file to `ESP_AT_Lib-master` directory 
4. Copy whole `ESP_AT_Lib-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**ESP_AT_Lib** library](https://registry.platformio.org/libraries/khoih-prog/ESP_AT_Lib) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/ESP_AT_Lib/installation). Search for **ESP_AT_Lib** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.11) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.11). 

Supposing the Adafruit SAMD core version is 1.7.11. These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.3) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3). 

Supposing the Seeeduino SAMD core version is 1.8.3. These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

For `Generic STM32F4 series` boards, such as `STM32F407VE`, using `LAN8720`, please use STM32 core `v2.2.0` as breaking core `v2.3.0` creates the compile error.

---

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h`


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.3.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


#### 10. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.4. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/ambd/avr/pgmspace.h`


#### 11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core
 
 To avoid compile error relating to SAMD21/SAMD51, you have to copy the file [ArduinoCore-fab-sam core pgmspace.h](Packages_Patches/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt) into `ArduinoCore-fab-sam` samd directory (~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt). 

Supposing the `ArduinoCore-fab-sam` samd core version is 1.9.0. This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/x.yy.zz/boards.txt`


#### 12. For Seeeduino RP2040 boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino RP2040 (XIAO RP2040, Wio RP2040 Mini) boards***, you have to copy the whole [Seeeduino RP2040 Packages_Patches](Packages_Patches/Seeeduino/hardware/rp2040/2.7.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2). 

Supposing the Seeeduino RP2040 core version is 2.7.2. These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/variants/Seeed_XIAO_RP2040/pins_arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/variants/Seeed_XIAO_RP2040/pins_arduino.h`


---

#### 13. For Seeeduino nRF52840 boards

**To be able to compile and run on Xiao nRF52840 boards**, you have to copy the whole [nRF52 1.0.0](Packages_Patches/Seeeduino/hardware/nrf52/1.0.0) directory into Seeeduino nRF52 directory (~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0). 

Supposing the Seeeduino nRF52 version is 1.0.0. These files must be copied into the directory:

- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/platform.txt`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Print.h`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Print.cpp`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/platform.txt`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

---
---

### HOWTO Get started

On the home page of API documentation, the tabs of Examples, Classes and Modules 
will be useful for Arduino lovers. 

### API List

```cpp

bool 	kick (void) : Verify ESP8266 whether live or not.
 
bool 	restart (void) : Restart ESP8266 by "AT+RST".
 
String 	getVersion (void) : Get the version of AT Command Set.
 
bool 	setOprToStation (void) : Set operation mode to station.
 
bool 	setOprToSoftAP (void) : Set operation mode to softap.
 
bool 	setOprToStationSoftAP (void) : Set operation mode to station + softap.

uint8_t  getOprMode(void) : Get the operation mode.
 
String 	getAPList (void) : Search available AP list and return it.
 
bool 	joinAP (String ssid, String pwd) : Join in AP. 
 
bool 	leaveAP (void) : Leave AP joined before. 
 
bool 	setSoftAPParam (String ssid, String pwd, uint8_t chl=7, uint8_t ecn=4) : Set SoftAP parameters. 
 
String 	getJoinedDeviceIP (void) : Get the IP list of devices connected to SoftAP. 
 
String 	getIPStatus (void) : Get the current status of connection(UDP and TCP). 
 
String 	getLocalIP (void) : Get the IP address of ESP8266. 
 
bool 	enableMUX (void) : Enable IP MUX(multiple connection mode). 
 
bool 	disableMUX (void) : Disable IP MUX(single connection mode). 
 
bool 	createTCP (String addr, uint32_t port) : Create TCP connection in single mode. 
 
bool 	releaseTCP (void) : Release TCP connection in single mode. 
 
bool 	registerUDP (String addr, uint32_t port) : Register UDP port number in single mode. 
 
bool 	unregisterUDP (void) : Unregister UDP port number in single mode. 
 
bool 	createTCP (uint8_t mux_id, String addr, uint32_t port) : Create TCP connection in multiple mode. 
 
bool 	releaseTCP (uint8_t mux_id) : Release TCP connection in multiple mode. 
 
bool 	registerUDP (uint8_t mux_id, String addr, uint32_t port) : Register UDP port number in multiple mode. 
 
bool 	unregisterUDP (uint8_t mux_id) : Unregister UDP port number in multiple mode. 
 
bool 	setTCPServerTimeout (uint32_t timeout=180) : Set the timeout of TCP Server. 

bool 	startServer (uint32_t port=333) ： Start Server(Only in multiple mode).

bool 	stopServer (void) : Stop Server(Only in multiple mode).

bool 	startTCPServer (uint32_t port=333) : Start TCP Server(Only in multiple mode). 
 
bool 	stopTCPServer (void) : Stop TCP Server(Only in multiple mode). 
 
bool 	send (const uint8_t *buffer, uint32_t len) : Send data based on TCP or UDP built already in single mode. 
 
bool 	send (uint8_t mux_id, const uint8_t *buffer, uint32_t len) : Send data based on one of TCP or UDP built already in multiple mode. 

bool 	sendFromFlash (const uint8_t *buffer, uint32_t len) : Send data based on TCP or UDP built already in single mode. 
 
bool 	sendFromFlash (uint8_t mux_id, const uint8_t *buffer, uint32_t len) : Send data based on one of TCP or UDP built already in multiple mode. 
 
uint32_t 	recv (uint8_t *buffer, uint32_t buffer_size, uint32_t timeout=1000) : Receive data from TCP or UDP built already in single mode. 
 
uint32_t 	recv (uint8_t mux_id, uint8_t *buffer, uint32_t buffer_size, uint32_t timeout=1000) : Receive data from one of TCP or UDP built already in multiple mode. 
 
uint32_t 	recv (uint8_t *coming_mux_id, uint8_t *buffer, uint32_t buffer_size, uint32_t timeout=1000) : Receive data from all of TCP or UDP built already in multiple mode. 
```
---
---

### Hardware Connection

ESP_AT_Lib library only needs an UART for hardware connection. All communications are done via UART. In each example, you must specify the UART used by mainboard to communicate with ESP8266/ESP32-AT firmware.

#### MEGA, SAM DUE

For MEGA and SAM DUE, `Serial1` or `Serial3` will be used if you create an object (named wifi)  of class ESP8266 in your code like this:

```cpp
#include "ESP_AT_Lib.h"
ESP8266 wifi(&Serial1);
```

The connection should be like these:


|ESP8266|<--->|MEGA, SAM DUE|
|:-:|:-:|:-:|
|TX|<--->|RX1(D19)|
|RX|<--->|TX1(D18)|
|CH_PD|<--->|3.3V|
|VCC|<--->|3.3V|
|GND|<--->|GND|

---

### Attention

The size of data from ESP8266/ESP32-AT is sometimes too big for Arduino boards, so the library can't receive the whole buffer because the size of the hardware serial buffer, defined in HardwareSerial.h, is too small.

The `SERIAL_TX_BUFFER_SIZE` and `SERIAL_RX_BUFFER_SIZE` are already redefined to 256 for Mega, and 2048 for other boards

```cpp
#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
  #if defined(SERIAL_TX_BUFFER_SIZE)
    #undef SERIAL_TX_BUFFER_SIZE
    #define SERIAL_TX_BUFFER_SIZE     256
  #endif
  
  #if defined(SERIAL_RX_BUFFER_SIZE)
    #undef SERIAL_RX_BUFFER_SIZE
    #define SERIAL_RX_BUFFER_SIZE     256
  #endif
#else
  #if defined(SERIAL_TX_BUFFER_SIZE)
    #undef SERIAL_TX_BUFFER_SIZE
    #define SERIAL_TX_BUFFER_SIZE     2048
  #endif
  
  #if defined(SERIAL_RX_BUFFER_SIZE)
    #undef SERIAL_RX_BUFFER_SIZE
    #define SERIAL_RX_BUFFER_SIZE     2048
  #endif
#endif
```

---
---

### Examples 

1. [ConnectWiFi](examples/ConnectWiFi)
2. [HTTPGET](examples/HTTPGET)
3. [TCPClientSingle](examples/TCPClientSingle)
4. [TCPClientMultiple](examples/TCPClientMultiple)
5. [TCPServer](examples/TCPServer)
6. [UDPClientSingle](examples/UDPClientSingle)
7. [UDPClientMultiple](examples/UDPClientMultiple)

---

#### Example [TCPServer](examples/TCPServer)

#### File [TCPServer.ino](examples/TCPServer/TCPServer.ino)

https://github.com/khoih-prog/ESP_AT_Lib/blob/94bbe56f0524a17d61d6c688f63a1ad81c1c34b3/examples/TCPServer/TCPServer.ino#L31-L160

#### File [defines.h](examples/TCPServer/defines.h)

https://github.com/khoih-prog/ESP_AT_Lib/blob/94bbe56f0524a17d61d6c688f63a1ad81c1c34b3/examples/TCPServer/defines.h#L12-L420

---
---

### Debug Terminal Output Samples

#### 1. HTTPGET on RASPBERRY_PI_PICO with ESP8266-AT shield

This is the terminal output when running [HTTPGET](examples/HTTPGET) example on **RASPBERRY_PI_PICO with ESP8266-AT shield**, using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)


```cpp
Start HTTPGET on RASPBERRY_PI_PICO
ESP_AT_Lib v1.5.1
FW Version:AT+GMR
AT version:1.7.4.0(May 11 2020 19:13:04)
SDK version:3.0.4(9532ceb)
compile time:May 27 2020 10:12:17
Bin version(Wroom 02):1.7.4
OK
Set AP/STA Mode OK
Connect to WiFi OK
IP: AT+CIFSR
+CIFSR:APIP,"192.168.4.1"
+CIFSR:APMAC,"6a:c6:3a:a6:f0:f1"
+CIFSR:STAIP,"192.168.2.185"
+CIFSR:STAMAC,"68:c6:3a:a6:f0:f1"
disableMUX OK
Done
Create TCP OK
=========================Received============================
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Tue, 11 May 2021 04:02:24 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;
============================================================
```

---

#### 2. HTTPGET on MBED RASPBERRY_PI_PICO with ESP8266-AT shield

This is the terminal output when running [HTTPGET](examples/HTTPGET) example on **RASPBERRY_PI_PICO with ESP8266-AT shield**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).


```cpp
Start HTTPGET on MBED RASPBERRY_PI_PICO
ESP_AT_Lib v1.5.1
FW Version:AT version:1.7.4.0(May 11 2020 19:13:04)
SDK version:3.0.4(9532ceb)
compile time:May 27 2020 10:12:17
Bin version(Wroom 02):1.7.4
OK
Set AP/STA Mode OK
Connect to WiFi OK
IP: +CIFSR:APIP,"192.168.4.1"
+CIFSR:APMAC,"6a:c6:3a:a6:f0:f1"
+CIFSR:STAIP,"192.168.2.76"
+CIFSR:STAMAC,"68:c6:3a:a6:f0:f1"
disableMUX OK
Done
Create TCP OK
=========================Received============================
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Tue, 18 May 2021 00:00:44 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                  
============================================================
```


---

#### 3. TCPServer on WIZNET_WIZFI360_EVB_PICO

This is the terminal output when running [TCPServer](examples/TCPServer) example on **WIZNET_WIZFI360_EVB_PICO**, using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)


```cpp
Start TCPServer on WIZNET_WIZFI360_EVB_PICO
FW Version:AT+GMR
AT version:1.1.1.7(May  4 2021 15:14:59)
SDK version:3.2.0(a0ffff9f)
compile time:May  4 2021 15:14:59
AT+CWMODE?
Set AP/STA Mode OK
AT+CWJAP_DEF="
Connect to WiFi OK
IP: AT+CIFSR
+CIFSR:APIP,"192.168.100.1"
+CIFSR:APMAC,"02:08:dc:6d:9c:f0"
+CIFSR:STAIP,"192.168.2.125"
+CIFSR:STAMAC,"00:08:dc:6d:9c:f0"
AT+CIPMUX=
enableMUX OK
AT+CIPSERVER=1,
Start TCP server OK
AT+CIPSTO=
Set TCP server timeout 10 seconds
Done
Status:[AT+CIPSTATUS
STATUS:3
+CIPSTATUS:0,"TCP","192.168.2.30",34422,80,1
+CIPSTATUS:1,"UDP","192.168.2.30",5416,56469,0]
Received from :0
[GET / HTTP/1.1
Host: 192.168.2.125
Connection: keep-alive
Cache-Control: max-age=0
DNT: 1
Upgrade-Insecure-Requests: 1
Use]
AT+CIPSEND=
Send back OK
AT+CIPCLOSE=
Release TCP 0 OK
Status:[AT+CIPSTATUS
STATUS:3
+CIPSTATUS:1,"UDP","192.168.2.30",5416,56469,0]
Status:[AT+CIPSTATUS
STATUS:3
+CIPSTATUS:0,"TCP","192.168.2.30",34578,80,1
+CIPSTATUS:1,"UDP","192.168.2.30",5416,56469,0]
Received from :0
[GET / HTTP/1.1
Host: 192.168.2.125
Connection: keep-alive
Cache-Control: max-age=0
DNT: 1
Upgrade-Insecure-Requests: 1
Use]
AT+CIPSEND=
Send back OK
AT+CIPCLOSE=
Release TCP 0 OK
Status:[AT+CIPSTATUS
STATUS:3
+CIPSTATUS:1,"UDP","192.168.2.30",5416,56469,0]
```

---
---


### Debug

Debug is disabled by default on Serial. To enable, add at the beginning of sketch

```cpp
#define ESP_AT_LIB_DEBUG_OUTPUT       Serial

/* Comment this out to disable prints and save space */
#define _ESP_AT_LIB_LOGLEVEL_         4
```


---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, `WizFi360/ESP8266/ESP32-AT shield` AT-command or this library version.

Sometimes, the library will only work if you update the `WizFi360/ESP8266/ESP32-AT shield` core to the newer or older version because some function compatibility.

---
---


### Issues

Submit issues to: [ESP_AT_Lib issues](https://github.com/khoih-prog/ESP_AT_Lib/issues)

---
---

### TO DO

1. Fix bugs

---

### DONE

 1. Add `ESP32-AT` support
 2. Replace deprecated AT commands
 3. Add debug output with debug levels
 4. Increase TX/RX Hardware Serial Buffer size
 5. Test OK with supported boards, running Blynk, Config Portal
 6. Add support to `RP2040-based` boards such as `RASPBERRY_PI_PICO`, using [arduino-pico core](https://github.com/earlephilhower/arduino-pico) 
 7. Add support to `SIPEED_MAIX_DUINO`
 8. Add Table-of-Contents
 9. Add Version String
10. Add support to `RP2040-based` boards, such as **RASPBERRY_PI_PICO boards** using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
11. Add support to `RP2040-based` boards, such as **RASPBERRY_PI_PICO boards** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
12. Add support to `RP2040-based` boards, such as **Nano_RP2040_Connect** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).
13. Add support to `Adafruit nRF52` core v0.22.0+
14. Add astyle using `allman` style. Restyle the library
15. Add support to WizNet `WizFi360`, such as `WIZNET_WIZFI360_EVB_PICO` using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)


---
---

### Contributions and Thanks

Please help contribute to this project and add your name here.

1. All the credits go to the original authors of the [ITEADLIB_Arduino_WeeESP8266 Library](https://github.com/itead/ITEADLIB_Arduino_WeeESP8266).

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/ESP_AT_Lib/blob/master/LICENSE)

---

### Copyright

Copyright (c) 2020- Khoi Hoang

