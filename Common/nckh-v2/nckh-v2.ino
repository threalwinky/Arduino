//Including libraries
#include <Arduino.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
const char *name = "Winky's wifi";
const char *pass = "123456789";
WebSocketsServer webSocket = WebSocketsServer(81);
StaticJsonDocument<500> TempDoc;

//Defining ports and variables
#define rds D0
#define ssp A0
unsigned long tick = 0;

int rain = 0;
//Setting up websocket and ports
void setup() {
  Serial.begin(9600);
  TempDoc["rain"] = 0;
  pinMode(rds, INPUT);
  Serial.println("Connecting to wifi");
  IPAddress apIP(192, 168, 99, 100);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(name, pass);
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("Websocket is started");
}
int pp = -50;
int ps = 100;
void loop() {
  webSocket.loop();
  if (millis() - tick > 2000)
  {
    rain = digitalRead(rds);
    humi = pp--;
    tempC = ps++;
    Serial.println(rain);
    rainEvent();
    tick = millis();
  }
}
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
  String cmd = "";
  switch (type)
  {
  case WStype_DISCONNECTED:
    Serial.println("Websocket is disconnected");
    break;
  case WStype_CONNECTED:
  {
    Serial.println("Websocket is connected");
    Serial.println(webSocket.remoteIP(num).toString());
    webSocket.sendTXT(num, "connected");
  }
  break;
  case WStype_TEXT:
    cmd = "";
    for (int i = 0; i < length; i++)
    {
      cmd = cmd + (char)payload[i];
    }
    Serial.print("Data from flutter:");
    Serial.println(cmd);
    break;
  case WStype_FRAGMENT_TEXT_START:
    break;
  case WStype_FRAGMENT_BIN_START:
    break;
  case WStype_BIN:
    hexdump(payload, length);
    break;
  default:
    break;
  }
}
void rainEvent()
{
  TempDoc["rain"] = rain;
  char msg[256];
  serializeJson(TempDoc, msg);
  webSocket.broadcastTXT(msg);
}