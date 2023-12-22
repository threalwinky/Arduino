#define rds 2
#define ssp A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rds, INPUT);
}

void loop() {
  Serial.print("Mưa: ");
  Serial.println(digitalRead(rds));
  delay(100);
}
