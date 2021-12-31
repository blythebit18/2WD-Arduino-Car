
#define in1 11
#define in2 10
#define in3 7
#define in4 6

const int enA = 3;
const int enB = 5;

void setup() {

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);

}

void loop() {
analogWrite(enA, 90);
analogWrite(enB, 90);

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

}
