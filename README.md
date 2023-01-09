# AsyncHTTPSRequest_ESP32_Ethernet Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncHTTPSRequest_ESP32_Ethernet.svg?)](https://www.ardu-badge.com/AsyncHTTPSRequest_ESP32_Ethernet)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet.svg)](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet.svg)](http://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this AsyncHTTPSRequest_ESP32_Ethernet library](#why-do-we-need-this-AsyncHTTPSRequest_ESP32_Ethernet-library)
  * [Important notes for WT32_ETH01](#Important-notes-for-WT32_ETH01)
  * [Features](#features)
  * [Supports](#supports)
  * [Principles of operation](#principles-of-operation)
  * [Currently supported Boards](#currently-supported-boards)
  * [To-be supported Boards](#To-be-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs) 
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [How to connect W5500, W6100 or ENC28J60 to ESP32_S2/S3/C3](#How-to-connect-W5500-W6100-or-ENC28J60-to-ESP32_S2S3C3)
* [Examples](#examples)
  * [For WT32_ETH01](#For-WT32_ETH01)
    * [1. AsyncHTTPSRequest_WT32_ETH01](examples/WT32_ETH01/AsyncHTTPSRequest_WT32_ETH01)
  * [For ESP32_ENC](#For-ESP32_ENC)
    * [1. AsyncHTTPSRequest_ESP32_ENC](examples/ESP32_ENC/AsyncHTTPSRequest_ESP32_ENC)
  * [For ESP32_W5500](#For-ESP32_W5500)
    * [1. AsyncHTTPSRequest_ESP32_W5500](examples/ESP32_W5500/AsyncHTTPSRequest_ESP32_W5500)
  * [For ESP32_W6100](#For-ESP32_W6100)
    * [1. AsyncHTTPSRequest_ESP32_W6100](examples/ESP32_W6100/AsyncHTTPSRequest_ESP32_W6100)
  * [For ESP32_SC_ENC](#For-ESP32_SC_ENC)
    * [1. AsyncHTTPSRequest_ESP32_SC_ENC](examples/ESP32_SC_ENC/AsyncHTTPSRequest_ESP32_SC_ENC)
  * [For ESP32_SC_W5500](#For-ESP32_SC_W5500)
    * [1. AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500)
  * [For ESP32_SC_W6100](#For-ESP32_SC_W6100)
    * [1. AsyncHTTPSRequest_ESP32_SC_W6100](examples/ESP32_SC_W6100/AsyncHTTPSRequest_ESP32_SC_W6100)
  * [For ESP32](#For-ESP32) 
    * [1. multiFileProject](examples/multiFileProject)
* [Example AsyncHTTPSRequest_ESP32_SC_W5500](#example-AsyncHTTPSRequest_ESP32_SC_W5500)
* [Debug Terminal Output Samples](#debug-terminal-output-samples) 
  * [ 1. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S3_DEV with ESP32_S3_W5500](#1-AsyncHTTPSRequest_ESP32_SC_W5500-using-ESP32S3_DEV-with-ESP32_S3_W5500)
  * [ 2. AsyncHTTPSRequest_ESP32_SC_ENC using ESP32S3_DEV with ESP32_S3_ENC28J60](#2-AsyncHTTPSRequest_ESP32_SC_ENC-using-ESP32S3_DEV-with-ESP32_S3_ENC28J60)
  * [ 3. AsyncHTTPSRequest_ESP32_W5500 using ESP32_DEV with ESP32_W5500](#3-AsyncHTTPSRequest_ESP32_W5500-using-ESP32_DEV-with-ESP32_W5500)
  * [ 4. AsyncHTTPSRequest_ESP32_ENC using ESP32_DEV with ESP32_ENC28J60](#4-AsyncHTTPSRequest_ESP32_ENC-using-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 5. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32C3_DEV with ESP32_C3_W5500](#5-AsyncHTTPSRequest_ESP32_SC_W5500-using-ESP32C3_DEV-with-ESP32_C3_W5500)
  * [ 6. AsyncHTTPSRequest_ESP32_SC_ENC using ESP32C3_DEV with ESP32_C3_ENC28J60](#6-AsyncHTTPSRequest_ESP32_SC_ENC-using-ESP32C3_DEV-with-ESP32_C3_ENC28J60)
  * [ 7. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S2_DEV with ESP32_S2_W5500](#7-AsyncHTTPSRequest_ESP32_SC_W5500-using-ESP32S2_DEV-with-ESP32_S2_W5500)
  * [ 8. AsyncHTTPSRequest_ESP32_SC_W6100 using ESP32S3_DEV with ESP32_S3_W6100](#8-AsyncHTTPSRequest_ESP32_SC_W6100-using-ESP32S3_DEV-with-ESP32_S3_W6100)
  * [ 9. AsyncHTTPSRequest_ESP32_W6100 using ESP32_DEV with ESP32_W6100](#9-AsyncHTTPSRequest_ESP32_W6100-using-ESP32_DEV-with-ESP32_W6100)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License and credits](#license-and-credits)
* [Copyright](#copyright)

---
---

## Why do we need this [AsyncHTTPSRequest_ESP32_Ethernet library](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet)

#### Important notes for WT32_ETH01

ESP32 Core v2.0.0+ introduces new enum breaking almost all `WT32_ETH01` codes written for core v1.0.6-.

It's really strange to define a breaking enum `arduino_event_id_t` in [**WiFiGeneric.h**#L36-L78](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFiGeneric.h#L36-L78), compared to the old `system_event_id_t`, now placed in [**esp_event_legacy.h**#L29-L63](https://github.com/espressif/arduino-esp32/blob/master/tools/sdk/esp32/include/esp_event/include/esp_event_legacy.h#L29-L63)

It's better to preserve the old enum order and just adding new items **to do no harm to pre-2.0.0 codes**

- [**WebServer_WT32_ETH01** Releases v1.2.0-**](https://github.com/khoih-prog/WebServer_WT32_ETH01) to be used for EP32 core v1.0.6- only
- [**WebServer_WT32_ETH01** Releases v1.3.0+**](https://github.com/khoih-prog/WebServer_WT32_ETH01) can be used for either EP32 core v2.0.0+ or v1.0.6-. **Default is using core v2.0.0+**

To use with core v1.0.6-, just define in your sketch

```cpp
#define USING_CORE_ESP32_CORE_V200_PLUS       false
```

- [**WebServer_WT32_ETH01** Releases v1.4.0+**](https://github.com/khoih-prog/WebServer_WT32_ETH01) can be used for either ESP32 core v2.0.0+ or v1.0.6-. **Autodetect core**

---

### Features

1. Asynchronous HTTPS Request library for **ESP32, ESP32_S2, ESP32_C3, ESP32_S3**, **WT32_ETH01** using `LwIP ENC28J60, W5500 or LAN8720`
2. Providing a subset of HTTPS.
3. Relying on [`AsyncTCP_SSL` library](https://github.com/khoih-prog/AsyncTCP_SSL) for ESP32
4. Methods similar in format and usage to `XmlHTTPrequest` in Javascript.
5. Coexist with `AsyncHTTPRequest` library to permit sending `HTTP / HTTPS` requests to multiple addresses and receive responses from them

### Supports

1. **GET, POST, PUT, PATCH, DELETE and HEAD**
2. Request and response headers
3. Chunked response
4. Single String response for short (<~5K) responses (heap permitting).
5. Optional onData callback.
6. Optional onReadyStatechange callback.

---

### Principles of operation

This library adds a simple HTTPS layer on top of the [**AsyncTCP_SSL** library](https://github.com/khoih-prog/AsyncTCP_SSL) to **facilitate REST communication from a Client to a Server**. The paradigm is similar to the XMLHttpRequest in Javascript, employing the notion of a ready-state progression through the transaction request.

**Synchronization can be accomplished using callbacks on ready-state change, a callback on data receipt, or simply polling for ready-state change**. Data retrieval can be incremental as received, or bulk retrieved when the transaction completes provided there is enough heap to buffer the entire response.

The underlying buffering uses a new xbuf class. It handles both character and binary data. Class xbuf uses a chain of small (64 byte) segments that are allocated and added to the tail as data is added and deallocated from the head as data is read, achieving the same result as a dynamic circular buffer limited only by the size of heap. The xbuf implements indexOf and readUntil functions.

For short transactions, buffer space should not be an issue. In fact, it can be more economical than other methods that use larger fixed length buffers. Data is acked when retrieved by the caller, so there is some limited flow control to limit heap usage for larger transfers.

Request and response headers are handled in the typical fashion.

Chunked responses are recognized and handled transparently.

This library is based on, modified from:

1. [Bob Lemaire's asyncHTTPrequest Library](https://github.com/boblemaire/asyncHTTPrequest)
2. [Khoi Hoang's AsyncHTTPSRequest_Generic Library](https://github.com/khoih-prog/AsyncHTTPSRequest_Generic)

---

### Currently Supported Boards

#### 1. ESP32 using LwIP ENC28J60, W5500, W6100 or LAN8720

1. **ESP32 (ESP32-DEV, etc.)**

#### 2. **WT32_ETH01** using ESP32-based boards and LAN8720 Ethernet

#### 3. ESP32S3 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-S3 (ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3, etc.)**

#### 4. ESP32S2 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-S2 (ESP32S2_DEV, etc.)**

#### 5. ESP32C3 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-C3 (ESP32C3_DEV, etc.)**

--- 

#### ESP32S3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32S3_DEV.png">
</p>

#### ESP32S2_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32S2_DEV.png">
</p> 


#### ESP32C3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32_C3_DevKitC_02.png">
</p> 

---

##### W6100

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W6100.png">
</p>


---

##### W5500

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W5500.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W5500_small.png">
</p> 

---

##### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ENC28J60.png">
</p>
 
 
 
---

### To-be Supported Boards

#### 1. New ESP32 using LwIP W5500, W6100 or ENC28J60


---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP32 Core 2.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [Latest stable release ![Release Version](https://img.shields.io/github/release/espressif/arduino-esp32.svg?style=plastic)
 3. [`AsyncTCP_SSL v1.3.1+`](https://github.com/khoih-prog/AsyncTCP_SSL) for ESP32. [![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncTCP_SSL.svg)](https://github.com/khoih-prog/AsyncTCP_SSL/releases)
 4. [`WebServer_WT32_ETH01 v1.5.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) for ESP32-based WT32_ETH01 using **either ESP32 core v2.0.0+ or v1.0.6-**. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WebServer_WT32_ETH01.svg)](https://github.com/khoih-prog/WebServer_WT32_ETH01/releases)
 5. [`WebServer_ESP32_ENC library v1.5.1+`](https://github.com/khoih-prog/WebServer_ESP32_ENC) if necessary to use ESP32 boards using `LwIP ENC28J60` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_ENC)
 6. [`WebServer_ESP32_W5500 library v1.5.2+`](https://github.com/khoih-prog/WebServer_ESP32_W5500) if necessary to use ESP32 boards using `LwIP W5500` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_W5500.svg?)](https://www.ardu-badge.com/WebServer_ESP32_W5500)
 7. [`WebServer_ESP32_SC_ENC library v1.2.0+`](https://github.com/khoih-prog/WebServer_ESP32_SC_ENC) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP ENC28J60` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_ENC)
 8. [`WebServer_ESP32_SC_W5500 library v1.2.1+`](https://github.com/khoih-prog/WebServer_ESP32_SC_W5500) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP W5500` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_W5500.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_W5500)
 9. [`WebServer_ESP32_W6100 library v1.5.2+`](https://github.com/khoih-prog/WebServer_ESP32_W6100) if necessary to use ESP32 boards using `LwIP W6100` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_W6100.svg?)](https://www.ardu-badge.com/WebServer_ESP32_W6100)
10. [`WebServer_ESP32_SC_W6100 library v1.2.1+`](https://github.com/khoih-prog/WebServer_ESP32_SC_W6100) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP W6100` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_W6100.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_W6100)



---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `AsyncHTTPSRequest_ESP32_Ethernet`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncHTTPSRequest_ESP32_Ethernet.svg?)](https://www.ardu-badge.com/AsyncHTTPSRequest_ESP32_Ethernet) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncHTTPSRequest_ESP32_Ethernet](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet) page.
2. Download the latest release `AsyncHTTPSRequest_ESP32_Ethernet-main.zip`.
3. Extract the zip file to `AsyncHTTPSRequest_ESP32_Ethernet-main` directory 
4. Copy the whole `AsyncHTTPSRequest_ESP32_Ethernet-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncHTTPSRequest_ESP32_Ethernet** library](https://registry.platformio.org/libraries/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/installation). Search for AsyncHTTPSRequest_ESP32_Ethernet in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Note for Platform IO using ESP32 LittleFS

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```cpp
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```cpp
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.5+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```cpp
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncHTTPSRequest_ESP32_Ethernet.hpp"     //https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```cpp
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncHTTPSRequest_ESP32_Ethernet.h"           //https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet
```

Check the new [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.

Have a look at the discussion in [Different behaviour using the src_cpp or src_h lib #80](https://github.com/khoih-prog/ESPAsync_WiFiManager/discussions/80)

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- `ADC1` controls ADC function for pins **GPIO32-GPIO39**
- `ADC2` controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use `ADC2` for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use `ADC2` with WiFi/BlueTooth (BT/BLE).
- Use `ADC1`, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by `ADC2` (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### How to connect W5500, W6100 or ENC28J60 to ESP32_S2/S3/C3


##### W6100

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W6100.png">
</p>

---


#### W5500

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W5500.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/W5500_small.png">
</p> 

---

#### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ENC28J60.png">
</p>
 

---

#### ESP32S3_DEV


<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32S3_DEV.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            4
```

|W5500, W6100 or ENC28J60|<--->|ESP32_S3|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO11|
|MISO|<--->|GPIO13|
|SCK|<--->|GPIO12|
|CS/SS|<--->|GPIO10|
|INT|<--->|GPIO4|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|

---

#### ESP32S2_DEV


<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32S2_DEV.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            4
```

|W5500, W6100 or ENC28J60|<--->|ESP32_S2|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO35|
|MISO|<--->|GPIO37|
|SCK|<--->|GPIO36|
|CS/SS|<--->|GPIO34|
|INT|<--->|GPIO4|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|


---

#### ESP32C3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/raw/main/Images/ESP32_C3_DevKitC_02.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            10
```

|W5500, W6100 or ENC28J60|<--->|ESP32_C3|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO6|
|MISO|<--->|GPIO5|
|SCK|<--->|GPIO4|
|CS/SS|<--->|GPIO7|
|INT|<--->|GPIO10|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|



---
---

### Examples

#### For WT32_ETH01

 1. [AsyncHTTPSRequest_WT32_ETH01](examples/WT32_ETH01/AsyncHTTPSRequest_WT32_ETH01)
 
#### For ESP32_ENC

 1. [AsyncHTTPSRequest_ESP32_ENC](examples/ESP32_ENC/AsyncHTTPSRequest_ESP32_ENC)
 
#### For ESP32_W5500

 1. [AsyncHTTPSRequest_ESP32_W5500](examples/ESP32_W5500/AsyncHTTPSRequest_ESP32_W5500)

#### For ESP32_W6100

 1. [AsyncHTTPSRequest_ESP32_W6100](examples/ESP32_W6100/AsyncHTTPSRequest_ESP32_W6100)
  
#### For ESP32_SC_ENC

 1. [AsyncHTTPSRequest_ESP32_SC_ENC](examples/ESP32_SC_ENC/AsyncHTTPSRequest_ESP32_SC_ENC)
 
#### For ESP32_SC_W5500

 1. [AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500)
 
#### For ESP32_SC_W6100

 1. [AsyncHTTPSRequest_ESP32_SC_W6100](examples/ESP32_SC_W6100/AsyncHTTPSRequest_ESP32_SC_W6100)
  
#### For ESP32

  1. [multiFileProject](examples/multiFileProject)
 
---

### Example [AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500)

https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/blob/ad9a1a9a23194eec5f7a6bba28aa3634e491d8fc/examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500.ino#L43-L302


---
---

### Debug Terminal Output Samples

#### 1. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S3_DEV with ESP32_S3_W5500

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500) on `ESP32S3_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL) with `LwIP W5500 Ethernet`

```cpp
Starting AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S3_DEV with ESP32_S3_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 2
[AHTTPS] MOSI: 11
[AHTTPS] MISO: 13
[AHTTPS] SCK: 12
[AHTTPS] CS: 10
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: DE:AD:BE:EF:FE:01, IPv4: 192.168.2.95
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.95

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:45:31.138055-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304331
utc_datetime: 2023-01-09T22:45:31.138055+00:00
utc_offset: -05:00
week_number: 2
**************************************
```
---

#### 2. AsyncHTTPSRequest_ESP32_SC_ENC using ESP32S3_DEV with ESP32_S3_ENC28J60

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_ENC](examples/ESP32_SC_ENC/AsyncHTTPSRequest_ESP32_SC_ENC) on `ESP32S3_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL) with `LwIP ENC28J60 Ethernet`

```cpp
Starting AsyncHTTPSRequest_ESP32_SC_ENC using ESP32S3_DEV with ESP32_S3_ENC28J60
WebServer_ESP32_SC_ENC v1.2.0 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 1
[AHTTPS] MOSI: 11
[AHTTPS] MISO: 13
[AHTTPS] SCK: 12
[AHTTPS] CS: 10
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 8
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: DE:AD:BE:EF:BE:04, IPv4: 192.168.2.105
FULL_DUPLEX, 10Mbps

HTTP WebClient is @ IP : 192.168.2.105

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:46:31.136551-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304391
utc_datetime: 2023-01-09T22:46:31.136551+00:00
utc_offset: -05:00
week_number: 2
**************************************
```

---

#### 3. AsyncHTTPSRequest_ESP32_W5500 using ESP32_DEV with ESP32_W5500

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_W5500](examples/ESP32_W5500/AsyncHTTPSRequest_ESP32_W5500) on `ESP32_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL) with `LwIP W5500 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_W5500 using ESP32_DEV with ESP32_W5500
WebServer_ESP32_W5500 v1.5.2 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 2
[AHTTPS] MOSI: 11
[AHTTPS] MISO: 13
[AHTTPS] SCK: 12
[AHTTPS] CS: 10
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: 0C:B8:15:D8:01:D7, IPv4: 192.168.2.158
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.158

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:47:31.135080-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304451
utc_datetime: 2023-01-09T22:47:31.135080+00:00
utc_offset: -05:00
week_number: 2
**************************************
```

---

#### 4. AsyncHTTPSRequest_ESP32_ENC using ESP32_DEV with ESP32_ENC28J60

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_ENC](examples/ESP32_ENC/AsyncHTTPSRequest_ESP32_ENC) on `ESP32_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP ENC28J60 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_ENC using ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.1 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 1
[AHTTPS] MOSI: 11
[AHTTPS] MISO: 13
[AHTTPS] SCK: 12
[AHTTPS] CS: 10
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 8
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: 0C:B8:15:D8:01:D7, IPv4: 192.168.2.158
FULL_DUPLEX, 10Mbps

HTTP WebClient is @ IP : 192.168.2.158

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:48:31.131151-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304511
utc_datetime: 2023-01-09T22:48:31.131151+00:00
utc_offset: -05:00
week_number: 2
**************************************
```


---

#### 5. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32C3_DEV with ESP32_C3_W5500

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500) on `ESP32C3_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP W5500 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32C3_DEV with ESP32_C3_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 1
[AHTTPS] MOSI: 6
[AHTTPS] MISO: 5
[AHTTPS] SCK: 4
[AHTTPS] CS: 7
[AHTTPS] INT: 10
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================
Using built-in mac_eth = 7C:DF:A1:BC:BC:53

ETH Started
ETH Connected
ETH MAC: 7C:DF:A1:BC:BC:53, IPv4: 192.168.2.135
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.135

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:49:31.129480-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304571
utc_datetime: 2023-01-09T22:49:31.129480+00:00
utc_offset: -05:00
week_number: 2
**************************************
HHHH HH
**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:50:31.127344-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304631
utc_datetime: 2023-01-09T22:50:31.127344+00:00
utc_offset: -05:00
week_number: 2
**************************************
```

---

#### 6. AsyncHTTPSRequest_ESP32_SC_ENC using ESP32C3_DEV with ESP32_C3_ENC28J60

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_ENC](examples/ESP32_SC_ENC/AsyncHTTPSRequest_ESP32_SC_ENC) on `ESP32C3_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP ENC28J60 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_SC_ENC using ESP32C3_DEV with ESP32_C3_ENC28J60
WebServer_ESP32_SC_ENC v1.2.0 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 1
[AHTTPS] MOSI: 6
[AHTTPS] MISO: 5
[AHTTPS] SCK: 4
[AHTTPS] CS: 7
[AHTTPS] INT: 10
[AHTTPS] SPI Clock (MHz): 8
[AHTTPS] =========================
Using built-in mac_eth = 7C:DF:A1:DA:66:87

ETH Started
ETH Connected
ETH MAC: 7C:DF:A1:DA:66:87, IPv4: 192.168.2.136
FULL_DUPLEX, 10Mbps

HTTP WebClient is @ IP : 192.168.2.136

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:51:31.125644-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304691
utc_datetime: 2023-01-09T22:51:31.125644+00:00
utc_offset: -05:00
week_number: 2
**************************************
```


---

#### 7. AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S2_DEV with ESP32_S2_W5500

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_W5500](examples/ESP32_SC_W5500/AsyncHTTPSRequest_ESP32_SC_W5500) on `ESP32S2_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP W5500 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_SC_W5500 using ESP32S2_DEV with ESP32_S2_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 2
[AHTTPS] MOSI: 35
[AHTTPS] MISO: 37
[AHTTPS] SCK: 36
[AHTTPS] CS: 34
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================
Using built-in mac_eth = 7E:DF:A1:08:32:C9

ETH Started
ETH Connected
ETH MAC: 7E:DF:A1:08:32:C9, IPv4: 192.168.2.133
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.133

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:54:31.118640-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304871
utc_datetime: 2023-01-09T22:54:31.118640+00:00
utc_offset: -05:00
week_number: 2
**************************************
```


---

#### 8. AsyncHTTPSRequest_ESP32_SC_W6100 using ESP32S3_DEV with ESP32_S3_W6100

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_SC_W6100](examples/ESP32_SC_W6100/AsyncHTTPSRequest_ESP32_SC_W6100) on `ESP32S3_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP W6100 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_SC_W6100 using ESP32S3_DEV with ESP32_S3_W6100
WebServer_ESP32_SC_W6100 v1.2.1 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 2
[AHTTPS] MOSI: 11
[AHTTPS] MISO: 13
[AHTTPS] SCK: 12
[AHTTPS] CS: 10
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: FE:ED:DE:AD:BE:EF, IPv4: 192.168.2.92
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.92

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:39:57.259659-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673303997
utc_datetime: 2023-01-09T22:39:57.259659+00:00
utc_offset: -05:00
week_number: 2
**************************************
HHHHHH
**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:40:52.235568-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304052
utc_datetime: 2023-01-09T22:40:52.235568+00:00
utc_offset: -05:00
week_number: 2
**************************************
```


---

#### 9. AsyncHTTPSRequest_ESP32_W6100 using ESP32_DEV with ESP32_W6100

Following is the debug terminal when running example [AsyncHTTPSRequest_ESP32_W6100](examples/ESP32_W6100/AsyncHTTPSRequest_ESP32_W6100) on `ESP32_DEV` to demonstrate the operation of SSL Async HTTPS request, using [AsyncTCP_SSL Library](https://github.com/khoih-prog/AsyncTCP_SSL),  with `LwIP W6100 Ethernet`


```cpp
Starting AsyncHTTPSRequest_ESP32_W6100 using ESP32_DEV with ESP32_W6100
WebServer_ESP32_W6100 v1.5.2 for core v2.0.0+
AsyncTCP_SSL v1.3.1
AsyncHTTPSRequest_ESP32_Ethernet v2.6.0
[AHTTPS] Default SPI pinout:
[AHTTPS] SPI_HOST: 2
[AHTTPS] MOSI: 23
[AHTTPS] MISO: 19
[AHTTPS] SCK: 18
[AHTTPS] CS: 5
[AHTTPS] INT: 4
[AHTTPS] SPI Clock (MHz): 25
[AHTTPS] =========================

ETH Started
ETH Connected
ETH MAC: 0C:B8:15:D8:01:D7, IPv4: 192.168.2.158
FULL_DUPLEX, 100Mbps

HTTP WebClient is @ IP : 192.168.2.158

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2023-01-09T17:43:37.156213-05:00
day_of_week: 1
day_of_year: 9
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1673304217
utc_datetime: 2023-01-09T22:43:37.156213+00:00
utc_offset: -05:00
week_number: 2
**************************************
```

---
---


### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
#define ASYNC_HTTPS_DEBUG_PORT          Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_TCP_SSL_LOGLEVEL_        1
#define _ASYNC_HTTPS_LOGLEVEL_          2
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the `ESP32` core for Arduino.

Sometimes, the library will only work if you update the `ESP32` core to the latest version because I am using newly added functions.

---

### Issues ###

Submit issues to: [AsyncHTTPSRequest_ESP32_Ethernet issues](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues)

---
---

## TO DO

 1. Fix bug. Add enhancement
 2. Add support to more `LwIP Ethernet` shields
 
 ---

## DONE

 1. Initially add support to `ESP32/S2/S3/C3` boards using `LwIP W5500 / ENC28J60 / LAN8720 Ethernet`
 2. Sync with [AsyncHTTPSRequest_Generic v2.4.0](https://github.com/khoih-prog/AsyncHTTPSRequest_Generic)
 3. Use `allman astyle` and add `utils`. Restyle the library
 4. Add support to `ESP32S2/C3` boards using `LwIP W5500 or ENC28J60 Ethernet`
 5. Add support to `ESP32` and `ESP32S2/S3/C3` boards using `LwIP W6100 Ethernet`

---
---


### Contributions and Thanks

This library is based on, modified, bug-fixed and improved from:

1. [Bob Lemaire's **asyncHTTPrequest Library**](https://github.com/boblemaire/asyncHTTPrequest) to use the better **asynchronous** features of the following Async SSL TCP Libraries : ( [`AsyncTCP_SSL`](https://github.com/khoih-prog/AsyncTCP_SSL) ).


<table>
  <tr>
    <td align="center"><a href="https://github.com/boblemaire"><img src="https://github.com/boblemaire.png" width="100px;" alt="boblemaire"/><br /><sub><b>⭐️ Bob Lemaire</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License and credits ###

- The library is licensed under [GPLv3](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/blob/main/LICENSE)

---

## Copyright

Copyright (C) <2018>  <Bob Lemaire, IoTaWatt, Inc.>

Copyright (C) 2022- Khoi Hoang



