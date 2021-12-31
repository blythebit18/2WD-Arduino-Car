#include <NewPing.h>

#define Trig_Pin 12
#define Echo_Pin 4
#define Max_Distance 400

float distance;

NewPing sonar(Trig_Pin, Echo_Pin, Max_Distance);

#define in1 11
#define in2 10
#define in3 7
#define in4 6

const int enA = 3;
const int enB = 5;

void setup(){
Serial.begin(9600);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);


}

void loop(){
Serial.print("Distance: ");
Serial.println(Distance());

if(Distance() < 25){
  Stop();
}else
  moveForward();
}

int Distance(){
distance = sonar.ping_cm();
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
Serial.println("Car moving Forward");
}

void Stop(){  
analogWrite(enA, 0);
analogWrite(enB, 0);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
Serial.println("Car Stop");
}

void moveLeft(){
analogWrite(enA, 90);
analogWrite(enB, 90);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}

void moveRight(){
analogWrite(enA, 90);
analogWrite(enB, 90);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
