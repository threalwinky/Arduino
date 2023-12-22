#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#define b D0
// Set your access point network credentials
const char* ssid = "ESP8266";
const char* password = "123456789";

AsyncWebServer server(80);
int c = 0;
String readTemp() {
  int bs = digitalRead(b);
  return String(bs);
}

String readHumi() {
  return String(2);
}

String readPres() {
  return String(3);
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);
  pinMode(b, INPUT);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readTemp().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readHumi().c_str());
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readPres().c_str());
  });
  

  // Start server
  server.begin();
}
 
void loop(){

}
