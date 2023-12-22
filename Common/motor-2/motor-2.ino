#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
void setup() {
  // put your setup code here, to run once:
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void tien(){
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void lui(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  tien();
  delay(400);
  lui();
  delay(400);
}
