#include <Servo.h>
#include "NewPing.h"

#define Trig_Pin 12
#define Echo_Pin 4
#define Max_Distance 400

float distance;

NewPing sonar(Trig_Pin, Echo_Pin, Max_Distance);

Servo SG90;

#define right 20
#define left 120
#define center 65

void setup() {
Serial.begin(9600);
SG90.attach(9);
SG90.write(center);

}
void loop() {
Serial.print("Center Distance: ");
Serial.println(Distance());

if(Distance()<25){
  Serial.print("Center Distance: ");
  Serial.println(Distance());
  lookRight();
  delay(500);
  lookLeft();
  delay(500);
}

}

int Distance(){
distance = sonar.ping_cm();
delay(300);
return distance;
  }

int lookRight(){
SG90.write(right);
Serial.println("Look Right");
delay(500);
float distance = Distance();
Serial.print("Right Distance : ");
Serial.println(distance);
delay(1000);
SG90.write(center);
delay(2000);
return distance;
}

int lookLeft(){
SG90.write(left);
Serial.println("Look Left");
delay(500);
float distance = Distance();
Serial.print("Left Distance: ");
Serial.println(distance);
delay(1000);
SG90.write(center);
delay(2000);
return distance;
}


