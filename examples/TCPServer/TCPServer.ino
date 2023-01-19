/****************************************************************************************************************************
  TCPServer.ino
  For WizFi360/ESP8266/ESP32-AT-command running shields

  ESP_AT_Lib is a wrapper library for the WizFi360/ESP8266/ESP32 AT-command shields

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/ESP_AT_Lib
  Licensed under MIT license
  
  @example TCPServer.ino
  @brief The TCPServer demo of library WeeESP8266.
  @author Wu Pengfei<pengfei.wu@itead.cc>
  @date 2015.02

  @par Copyright:
  Copyright (c) 2015 ITEAD Intelligent Systems Co., Ltd. \n\n
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of
  the License, or (at your option) any later version. \n\n
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 *****************************************************************************************************************************/

#include "defines.h"

#include "ESP_AT_Lib.h"

ESP8266 wifi(&EspSerial);

// Your board <-> ESP_AT baud rate:
#define ESP_AT_BAUD       115200

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(1000);

#if defined(BOARD_NAME)
  Serial.println("\nStart TCPServer on " + String(BOARD_NAME));
#else
  Serial.println("\nStart TCPServer");
#endif

  // initialize serial for ESP module
  EspSerial.begin(ESP_AT_BAUD);

  Serial.print("FW Version:");
  Serial.println(wifi.getVersion().c_str());

  if (wifi.setOprToStationSoftAP())
  {
    Serial.println("Set AP/STA Mode OK");
  }
  else
  {
    Serial.println("Set AP/STA Mode failed");
  }

  if (wifi.joinAP(SSID, PASSWORD))
  {
    Serial.println("Connect to WiFi OK");
    Serial.print("IP: ");
    Serial.println(wifi.getLocalIP().c_str());
  }
  else
  {
    Serial.println("Connect to WiFi failed");
  }

  if (wifi.enableMUX())
  {
    Serial.println("enableMUX OK");
  }
  else
  {
    Serial.println("enableMUX failed");
  }

  if (wifi.startTCPServer(8090))
  {
    Serial.println("Start TCP server OK");
  }
  else
  {
    Serial.println("start TCP server failed");
  }

  if (wifi.setTCPServerTimeout(10))
  {
    Serial.println("Set TCP server timeout 10 seconds");
  }
  else
  {
    Serial.println("Set TCP server timeout failed");
  }

  Serial.println("Done");
}

void loop()
{
  uint8_t buffer[128] = {0};
  uint8_t mux_id;

  uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);

  if (len > 0)
  {
    Serial.print("Status:[");
    Serial.print(wifi.getIPStatus().c_str());
    Serial.println("]");

    Serial.print("Received from :");
    Serial.println(mux_id);
    Serial.print("[");

    for (uint32_t i = 0; i < len; i++)
    {
      Serial.print((char)buffer[i]);
    }

    Serial.println("]");

    if (wifi.send(mux_id, buffer, len))
    {
      Serial.println("Send back OK");
    }
    else
    {
      Serial.println("Send back failed");
    }

    if (wifi.releaseTCP(mux_id))
    {
      Serial.print("Release TCP ");
      Serial.print(mux_id);
      Serial.println(" OK");
    }
    else
    {
      Serial.print("Release TCP ");
      Serial.print(mux_id);
      Serial.println(" failed");
    }

    Serial.print("Status:[");
    Serial.print(wifi.getIPStatus().c_str());
    Serial.println("]");
  }
}
