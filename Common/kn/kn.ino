#include "DHT.h"            

#define DHTPIN D1
#define rds D0
#define ssp A0
#define IN1 D5
#define IN2 D6
#define IN3 D7
#define IN4 D8
#define li D2
const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(rds, INPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(li, OUTPUT);
}

int c = 0;

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

void loop() {
  Serial.print("Mưa: ");
  Serial.println(digitalRead(rds));
  float h = dht.readHumidity();    
  float t = dht.readTemperature(); 
  Serial.print("Nhiet do: ");
  Serial.println(t);               
  Serial.print("Do am: ");
  Serial.println(h);  
              
  Serial.println();               
  int r = digitalRead(rds);
  if (r == 0){
    if (c == 0){
      tien(1000);
      digitalWrite(li, HIGH);
      c = 1;
    }  
  }
  else{
    if (c == 1){
      lui(1000);
      c = 0;
      digitalWrite(li, LOW);
    }  
  }
  delay(500);
}
