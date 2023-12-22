#define O1 2
#define O2 3
#define O3 4
#define O4 5
#define O5 6
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(O1, INPUT);
  pinMode(O2, INPUT);
  pinMode(O3, INPUT);
  pinMode(O4, INPUT);
  pinMode(O5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(O1);
  int b = digitalRead(O2);
  int c = digitalRead(O3);
  int d = digitalRead(O4);
  int e = digitalRead(O5);
  Serial.print(a);Serial.print(" ");
  Serial.print(b);Serial.print(" ");
  Serial.print(c);Serial.print(" ");
  Serial.print(d);Serial.print(" ");
  Serial.print(e);Serial.println(" ");
}
