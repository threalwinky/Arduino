#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
String rec_data="off";


void setup() {
   pinMode(9, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);   // BlueTooth Data baud,set the data rate for the SoftwareSerial port
}

void loop() { // run over and over
  if (mySerial.available()) {
    
    rec_data=mySerial.readString();
    
    if(rec_data=="on"){digitalWrite(9, HIGH);}
    if(rec_data=="off"){digitalWrite(9, LOW);}

    
    
    Serial.println(rec_data);
    delay(100);
  }
  
}