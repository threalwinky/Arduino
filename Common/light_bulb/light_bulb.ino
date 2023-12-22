void setup() {
  // put your setup code here, to run once:
  pinMode(D5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D5, HIGH);
  delay(2000);
  digitalWrite(D5, LOW);
  delay(2000);
}
