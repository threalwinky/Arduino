int a[15];
#define G A1
#define Y A2
#define R A3
void setup() {
  // put your setup code here, to run once:
  for (int i=2; i<=13; i++){
    a[i] = i;
  }
  for (int i=2; i<=13; i++){
    pinMode(a[i], OUTPUT);
  }
  Serial.begin(9600);
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
}
int f[15][15] = {
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},//1
  {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},//2
  {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},//3
  {1, 1, 1, 1, 1, 0, 1, 1, 0, 0},//4
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},//5
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},//6
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},//7
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//8
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},//9
};
int c = 5;
int m = 1;
int t = 0;
void loop() {
  if (Serial.available()) 
  {
    switch (Serial.read())
    {
      case 'x': t = 1; break;
      
    }
  }
  // put your main code here, to run repeatedly:
  for (int i=0; i<10; i++){
      
      if (f[c][i]){
        digitalWrite(a[i+2], HIGH);
      }
      else digitalWrite(a[i+2], LOW);
  }
  c--;
  if (t == 1 && c == -1){
    t = 0;
    Serial.println("Hello");
    digitalWrite(G, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(R, HIGH);
    delay(2000);
    Serial.println("Done");
  }
  else{
    if (m == 1){
        digitalWrite(G, HIGH);
        digitalWrite(Y, LOW);
        digitalWrite(R, LOW);
      }
      else if (m == 2 || t == 1){
        digitalWrite(G, LOW);
        digitalWrite(Y, HIGH);
        digitalWrite(R, LOW);
      }
      else{
        digitalWrite(G, LOW);
        digitalWrite(Y, LOW);
        digitalWrite(R, HIGH);
        m=0;
      }
    if (c == -1){
      if (m == 1){
        c = 2;
      }
      else if (m == 2 || t == 1){
        c = 8;
        t = 2;
      }
      else c = 5;
      m++;
    }
  }
  
  delay(200);
}
