#define IN1 D4
#define IN2 D3
#define IN3 D2
#define IN4 D1
#define MAX_SPEED 255
#define MIN_SPEED 0
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void motor_1_Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}

void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

void motor_2_Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN3, HIGH);
  analogWrite(IN4, 255 - speed);
}

void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, speed);
}
bool r = 0;
void loop() {

  if (r == 0){
    motor_1_Tien(MAX_SPEED);
    delay(5000);
    motor_1_Dung();
    r = 1;
    delay(1000);
  }
  else{
    motor_1_Lui(MAX_SPEED);
    delay(3400);
    motor_1_Dung();
    r = 0;
    delay(1000);
  }
}