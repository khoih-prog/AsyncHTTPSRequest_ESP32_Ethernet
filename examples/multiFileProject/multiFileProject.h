/****************************************************************************************************************************
  multiFileProject.h
  For ESP32 using LwIP W5500 / ENC28J60 / LAN8720 Ethernet

  AsyncHTTPSRequest_ESP32_Ethernet is a library for ESP32 using LwIP W5500 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from asyncHTTPrequest Library (https://github.com/boblemaire/asyncHTTPrequest)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet
  Licensed under GPLv3 license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

/////////////////////////////////////////////////////////

// Use larger queue size if necessary for large data transfer. Default is 512 bytes if not defined here
//#define ASYNC_QUEUE_LENGTH     512

// Use larger priority if necessary. Default is 10 if not defined here. Must be > 4 or adjusted to 4
//#define CONFIG_ASYNC_TCP_PRIORITY   (12)

/////////////////////////////////////////////////////////

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncHTTPSRequest_ESP32_Ethernet.hpp"
