const int refresh=3;//3 seconds
// DHT settings starts
#include "DHT.h"
#define DHTPIN 2    // PINO

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
float tValue; // temperatura
float hValue; // umidade



#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "Trevas" // nome do wifi
#define STAPSK  "outrasenha" // senha
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(8080);


void sendTemp() {

  String page = "<!DOCTYPE html>";
  page +="    <meta http-equiv='refresh' content='";
  page += String(refresh);  // renova a view
  page +="'/>";  
  page +="<html>";
  page +="<body>"; 
  page +="<h1>Sensor de umidade e temperatura</h1>";    
  page +="<p id="temp" style=\"font-size:50px;\">Temperatura:<br/>";  
  page +="<p style=\"color:red; font-size:50px;\">";
  page += String(tValue, 2);
  
  page +="<p id="umi" style=\"font-size:50px;\">Umidade:<br/>";  
  page +="<p style=\"color:red; font-size:50px;\">";
  page += String(hValue, 2);
  
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
  
   dht.begin();
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // espera a conexao
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    uint8_t macAddr[6];
    WiFi.macAddress(macAddr);
    Serial.printf("Connected, mac address: %02x:%02x:%02x:%02x:%02x:%02x", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]); // printa o mac
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
  
  server.handleClient();
  MDNS.update();
  float c = dht.readTemperature();// le em celsius
  float h = dht.readHumidity();// le umidade 
  float f = dht.readTemperature(true);// le em fahrenheit
    Serial.println(c);
    Serial.println(h);
 tValue =c;
 hValue =h;
  delay(300); // refresh
  
}
