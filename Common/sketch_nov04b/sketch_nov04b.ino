#define IN1 D3
#define IN2 D2
#define IN3 D1
#define IN4 D0
#define MAX 255
#define MIN 0
void setup() {
  // put your setup code here, to run once:
  pinMode(D3, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motor_1_Tien(int speed) {                     
  speed = constrain(speed, MIN, MAX);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}

void motor_2_Tien(int speed) {                     
  speed = constrain(speed, MIN, MAX); 
  digitalWrite(IN3, HIGH);                        
  analogWrite(IN4, 255 - speed);
}

void loop() {
  // put your main code here, to run repeatedly:
//  motor_2_Tien(MAX);
digitalWrite(IN3,LOW);
}
