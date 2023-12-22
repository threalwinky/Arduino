int ledG1 =10 ;
int ledY1 =9 ;
int ledR1 =8;

int ledG2 =13 ;
int ledY2 =12 ;
int ledR2 =11;

int ledG3 =4 ;
int ledY3 =3 ;
int ledR3 =2 ;
void setup() {
  pinMode(ledG1, OUTPUT);
  pinMode(ledY1, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledR3, OUTPUT);
  pinMode(ledY3, OUTPUT);
  pinMode(ledG3, OUTPUT);
}
int c = 0;
void loop() {
    if (c == 0){
        digitalWrite(ledG1, HIGH);
        digitalWrite(ledG2, HIGH);
        digitalWrite(ledG3, HIGH);

        digitalWrite(ledR1, LOW);
        digitalWrite(ledR2, LOW);
        digitalWrite(ledR3, LOW);

        digitalWrite(ledY1, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledY3, LOW);
        delay(9000);
    }
    else if (c == 1){
        digitalWrite(ledG1, LOW);
        digitalWrite(ledG2, LOW);
        digitalWrite(ledG3, LOW);

        digitalWrite(ledR1, LOW);
        digitalWrite(ledR2, LOW);
        digitalWrite(ledR3, LOW);

        digitalWrite(ledY1, HIGH);
        digitalWrite(ledY2, HIGH);
        digitalWrite(ledY3, HIGH);
        delay(3000);
    }
    else{
        digitalWrite(ledG1, LOW);
        digitalWrite(ledG2, LOW);
        digitalWrite(ledG3, LOW);

        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, HIGH);
        digitalWrite(ledR3, HIGH);

        digitalWrite(ledY1, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledY3, LOW);
        delay(6000);
    }
    c++;
    if (c == 3){
        c = 0;
    }
}