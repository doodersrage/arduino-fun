// servo potentiometer control
#include <Servo.h>

const int SERVO=9;
const int POT=0;

Servo myServo;
int val = 0;

void setup(){
  Serial.begin(9600);
  myServo.attach(SERVO);
}

void loop(){
  val = analogRead(POT);
  val = map(val, 0, 1023, 0, 179);
  myServo.write(val);
  Serial.println(val);
  delay(15);
}
