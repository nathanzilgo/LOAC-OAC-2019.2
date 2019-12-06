/*
 * Display temperature using DHT11, DHT22 with NodeMCU ESP8266 with Arduino IDE
 * 
 * Written by Ahmad Shamshiri on Sep 27, 2019
 * in Ajax, Ontario, Canada
 * Watch video instruciton for this video: https://youtu.be/1A4-6hDARQc
 * 
 * I have combined DHT library of Adafruit with ESP8266 WebServer both links 
 * Adafruit DHT library on GitHub: https://github.com/adafruit/DHT-sensor-library
 * and 
 * ESP8266 on GitHub : https://github.com/esp8266/Arduino
 * 
 * 
Get this code and other Arduono codes from Robojax.com
You can get the wiring diagram from my Arduino Course at Udemy.com
Learn Arduino step by step with all library, codes, wiring diagram all in one place
visit my course now http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63
or make donation using PayPal http://robojax.com/L/?id=64

 * Code is available at http://robojax.com/learn/arduino
 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 

*/

const int refresh=3;//3 seconds
// DHT settings starts
#include "DHT.h"
#define DHTPIN 0    // what digital pin we're connected to
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);
float tValue;// 
// ****** DHT settings end (Robojax.com )


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "Guardians" // Your WiFi SSID
#define STAPSK  "guardiansdsc" //Your WiFi password
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(8080);


void sendTemp() {

  String page = "<!DOCTYPE html>";
  page +="    <meta http-equiv='refresh' content='";
  page += String(refresh);// how often temperature is read
  page +="'/>";  
  page +="<html>";
  page +="<body>"; 
  page +="<h1>Robojax.com DHT Code</h1>";    
  page +="<p style=\"font-size:50px;\">Temperature<br/>";  
  page +="<p style=\"color:red; font-size:50px;\">";
  page += String(tValue, 2);
  page +="</p>";  
  page +="</body>";  
  page +="</html>";  
 server.send(200,  "text/html",page);

}

void handleNotFound() {
 
  String message = "File Not Found";
  
  message += "URI: ";
  message += server.uri();
  message += "Method: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "Arguments: ";
  message += server.args();
  message += "";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "";
  }
  server.send(404, "text/plain", message);

}

void setup(void) {
  // Robojax.com code for ESP8266 and DHT11 DHT22
   dht.begin();
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    uint8_t macAddr[6];
    WiFi.macAddress(macAddr);
    Serial.printf("Connected, mac address: %02x:%02x:%02x:%02x:%02x:%02x", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  }  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("robojaxDHT")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", sendTemp);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  // Robojax.com code for ESP8266 and DHT11 DHT22
  server.handleClient();
  MDNS.update();
  float c = dht.readTemperature();// Read temperature as Celsius (the default)
  float h = dht.readHumidity();// Reading humidity 
  float f = dht.readTemperature(true);// Read temperature as Fahrenheit (isFahrenheit = true)
    Serial.println(c);
 tValue =c;
  delay(300);// change this to larger value (1000 or more) if you don't need very often reading
  // Robojax.com code for ESP8266 and DHT11 DHT22
}
