#include "NewPing.h"
#include <Servo.h>

#define Trig_Pin 12
#define Echo_Pin 4
#define Max_Distance 400

float distance;
float rightDistance;
float leftDistance;


NewPing sonar(Trig_Pin, Echo_Pin, Max_Distance);

Servo SG90;

#define right 20
#define left 120
#define center 65

#define in1 11
#define in2 10
#define in3 7
#define in4 6

const int enA = 3;
const int enB = 5;



void setup() {
SG90.attach(9);
SG90.write(center);
Serial.begin(9600);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);

}



void loop() {

if(Distance() < 30){
  stop();
  delay(1000);
   if(lookRight()<25 && lookLeft()<25){
     delay(500);
     moveBackward();
    delay(500);
    stop();
  }else if(leftDistance > rightDistance) {
    delay(300);
    turnLeft();
    delay(500);
    stop();    
  }else{
    delay(300);
    turnRight();
    delay(500);
    stop();    
    
  }       
  
}else{
  moveForward();
  }
}
void moveForward(){
Serial.println("Move Forward");
analogWrite(enA, 110);
analogWrite(enB, 110);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void moveBackward(){
Serial.println("Move Backward");
analogWrite(enA, 120);
analogWrite(enB, 120);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}


float Distance(){
float distance = sonar.ping_cm();
delay(300);
return distance;
}

float lookRight(){
Serial.println("Look Right");
SG90.write(right);
delay(500);
float distance = Distance();
SG90.write(center);
delay(300);
rightDistance = distance;
Serial.print("Right Distance: ");
Serial.println(rightDistance);
return distance;
}

float lookLeft(){
Serial.println("Look Left");
SG90.write(left);
delay(500);
float distance = Distance();
SG90.write(center);
delay(300);
leftDistance = distance;
Serial.print("Left Distance: ");
Serial.println(leftDistance);
return distance;
}

void turnLeft(){
Serial.println("Turn Left");
analogWrite(enA, 120);
analogWrite(enB, 120);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}

void turnRight(){
Serial.println("Turn Right");
analogWrite(enA, 120);
analogWrite(enB, 120);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}


void stop(){
Serial.println("Stop");
analogWrite(enA, 0);
analogWrite(enB, 0);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}