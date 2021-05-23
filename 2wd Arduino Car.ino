#include "NewPing.h"
#include <Servo.h>

#define Trig_Pin 10
#define Echo_Pin 13
#define Max_Distance 400

NewPing sonar(Trig_Pin, Echo_Pin, Max_Distance);

float distance;

Servo SG90;

#define in1 11
#define in2 2

#define in3 3
#define in4 4

const int enA = 5;
const int enB = 6;

#define right 20
#define left 110
#define center 65



void setup() {
Serial.begin(9600);
SG90.attach(9);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
SG90.write(center);
}

void loop() {

if(Distance()<25){
 stop();
 delay(1000);
  if(lookRight()<25 and lookLeft()<25){
    delay(800);
    moveBackward();
    delay(300);
    stop();
    }else if(lookLeft() > lookRight()){
     delay(500);
     moveLeft();
     delay(700);
     stop();
        
  }else{
    delay(500);
    moveRight();
    delay(700);
    stop();
  }
}else moveForward();

}

int Distance(){
distance = sonar.ping_cm();
Serial.println(distance);
delay(300);
return distance;


}

void moveForward(){
analogWrite(enA, 90);
analogWrite(enB, 90);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void moveBackward(){
analogWrite(enA, 100);
analogWrite(enB, 100);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
Serial.println("Move Backward");
}

void moveRight(){
analogWrite(enA, 0);
analogWrite(enB, 100);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
Serial.println("Turn Right");
}

void moveLeft(){
analogWrite(enA, 100);
analogWrite(enB, 0);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
Serial.println("Turn Left");
}

void stop(){
analogWrite(enA, 0);
analogWrite(enB, 0);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
Serial.println("Stop");
}

int lookRight(){
SG90.write(right);
Serial.println("look Right");
Serial.print("Right Distance: ");
delay(500);
int distance = Distance();
SG90.write(center);
delay(300);
return distance;


}

int lookLeft(){
SG90.write(left);
Serial.print("Left Distance: ");
delay(500);
int distance = Distance();
SG90.write(center);
delay(300);
return distance;
}
