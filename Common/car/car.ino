#include <Arduino.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include "DHT.h"
const char *ssid = "esp8266";
const char *pass = "123456789";
WebSocketsServer webSocket = WebSocketsServer(81);
unsigned long t_tick = 0;
StaticJsonDocument<500> TempDoc;
#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3


void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  TempDoc["rain"] = 1;
  TempDoc["tempC"] = 0;
  TempDoc["humi"] = 0;
  Serial.println("Connecting to wifi");
  IPAddress apIP(192, 168, 99, 100);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid, pass);
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("Websocket is started");
  randomSeed(analogRead(0));
}
bool mode = 0;
bool onOff = 0;
double humi;
double tempC;
int rain;
int c = 0;
// int pp = 100;
// int ps = -100;
//void motor_1_Dung() {
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//}
//
//void motor_2_Dung() {
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//}
//
//void motor_1_Tien(int speed) {                     //speed: từ 0 - MAX_SPEED
//  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  //đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
//  digitalWrite(IN1, HIGH);                         // chân này không có PWM
//  analogWrite(IN2, 255 - speed);
//}
//
//void motor_1_Lui(int speed) {
//  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  //đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
//  digitalWrite(IN1, LOW);                          // chân này không có PWM
//  analogWrite(IN2, speed);
//}
//
//void motor_2_Tien(int speed) {                     //speed: từ 0 - MAX_SPEED
//  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  //đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
//  digitalWrite(IN3, HIGH);                         // chân này không có PWM
//  analogWrite(IN4, 255 - speed);
//}
//
//void motor_2_Lui(int speed) {
//  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  //đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
//  digitalWrite(IN3, LOW);                          // chân này không có PWM
//  analogWrite(IN4, speed);
//}

void tien(int s){
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(s);
    digitalWrite(IN3, LOW);
}

void lui(int s){
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    delay(s);
    digitalWrite(IN4, LOW);
}

void loop()
{
  webSocket.loop();
  if (millis() - t_tick > 10)
  {
//    Serial.println(onOff);
    if (c == 0){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (c == 1){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (c == 2){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if (c == 3){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (c == 4){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    rainEvent();
    t_tick = millis();
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
//    Serial.print("Data from flutter:");
    Serial.println(cmd);
    if (cmd == "d")
    {
      c = 0;
    }
    else if (cmd == "l")
    {
      c = 1;
    }
    else if (cmd == "x")
    {
      c = 2;
    }
    else if (cmd == "t")
    {
      c = 3;
    }
    else if (cmd == "p"){
      c = 4;
    }
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
  TempDoc["humi"] = humi;
  TempDoc["tempC"] = tempC;
  char msg[256];
  serializeJson(TempDoc, msg);
  webSocket.broadcastTXT(msg);
}
