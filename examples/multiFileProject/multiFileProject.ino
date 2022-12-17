/****************************************************************************************************************************
  multiFileProject.ino
  For ESP32 using LwIP W5500 / ENC28J60 / LAN8720 Ethernet

  AsyncHTTPSRequest_ESP32_Ethernet is a library for ESP32 using LwIP W5500 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from asyncHTTPrequest Library (https://github.com/boblemaire/asyncHTTPrequest)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet
  Licensed under GPLv3 license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#if !( defined(ESP32) )
  #error This code is intended to run on the ESP32 platform! Please check your Tools->Board setting.
#endif

#define ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_MIN_TARGET      "AsyncHTTPSRequest_ESP32_Ethernet v2.4.0"
#define ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_MIN             2004000

/////////////////////////////////////////////////////////

// Uncomment for certain HTTP site to optimize
//#define NOT_SEND_HEADER_AFTER_CONNECTED        true

#include "multiFileProject.h"

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncHTTPSRequest_ESP32_Ethernet.h"

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(500);

  Serial.println(F("\nStart multiFileProject"));
  Serial.println(ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION);

#if defined(ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_MIN)

  if (ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_INT < ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_MIN)
  {
    Serial.print(F("Warning. Must use this example on Version equal or later than : "));
    Serial.println(ASYNC_HTTPS_REQUEST_ESP32_ETHERNET_VERSION_MIN_TARGET);
  }

#endif
}

void loop()
{
  // put your main code here, to run repeatedly:
}
