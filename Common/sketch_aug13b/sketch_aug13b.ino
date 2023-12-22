#include "DHT.h"
#define DHTPIN D0
const int DHTTYPE = DHT11;
const int ledPin = 13;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (h > 45){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  Serial.print("Nhiet do: ");
  Serial.println(t);
  Serial.print("Do am: ");
  Serial.println(h);
              
  Serial.println();
  delay(1000);
}