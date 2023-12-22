   ////////////////////////////////////////////////////////
  //                LinoBot v1.0                        //             
 //               By Aarav Garg                        //
////////////////////////////////////////////////////////

//I have added the possibilities of testing
//The values of analogRead could be changed for trouble shooting

//including the libraries


//defining pins and variables
#define lefts A4 
#define rights A5 
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
//defining motors

/*
AF_DCMotor motor1(3, MOTOR12_8KHZ); 
AF_DCMotor motor2(4, MOTOR12_8KHZ);
 */

void setup() {
  //setting the speed of motors

  //declaring pin types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(analogRead(lefts));
//  Serial.println(analogRead(rights));
  
  //line detected by left sensor
  if(analogRead(lefts) > 1000){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, LOW);
  }
  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN3, HIGH);
  }
}
