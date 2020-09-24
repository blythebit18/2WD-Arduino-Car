#include "NewPing.h"
#include <Servo.h>

#define Trig_Pin 10
#define Echo_Pin 13
#define Max_Distance 400

NewPing sonar(Trig_Pin, Echo_Pin, Max_Distance);

int distance;

Servo SG90;
const int servoCenter = 100;
const int angle = 45;
const int servoPin = 9;

const int in1 = 1;
const int in2 = 2;

const int in3 = 3;
const int in4 = 4;

const int enA = 5;
const int enB = 6;

int maxSpeed = 200;

void setup() {
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
SG90.attach(servoPin);
SG90.write(servoCenter);

}

void loop() {
if(Distance()<10){
  Stop();
  delay(500);
    if(lookRight()<10 and lookLeft()<10){
      Reverse();
      delay(700);
      }else if(lookRight() > lookLeft()){
        Right();
        delay(300);
        }else{
          Left();
          delay(300);
          }
}else{
  Straight();
  }

}

int Distance(){
distance = sonar.ping_cm();
return distance;
}

int lookRight(){
SG90.write(servoCenter - angle);
delay(500);
distance = Distance();
SG90.write(servoCenter);
delay(600);
return distance;
}

int lookLeft(){
SG90.write(servoCenter + angle);
delay(500);
distance = Distance();
SG90.write(servoCenter);
delay(600);
return distance;  
}


void Straight(){
analogWrite(enA, maxSpeed);
analogWrite(enB, maxSpeed);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH); 
}

void Reverse(){
analogWrite(enA, 100);
analogWrite(enB, 100);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW); 
}

void Stop(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);  
}

void Left(){
analogWrite(enA, 100);
analogWrite(enB, 100);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);  
}

void Right(){
analogWrite(enA, 100);
analogWrite(enB, 100);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);  
}
