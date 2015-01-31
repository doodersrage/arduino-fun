// servo potentiometer control
#include <Servo.h>

const int SERVO=9;
const int IR=0;
const int LED1=3;
const int LED2=5;
const int LED3=6;
const int LED4=11;

Servo myServo;
int dist1 = 0;
int dist2 = 0;
int dist3 = 0;
int dist4 = 0;

void setup(){
  Serial.begin(9600);
  myServo.attach(SERVO);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop(){
  
  dist1 = readDistance(15);
  Serial.println(dist1);
  analogWrite(LED1, dist1);
  delay(300);
  
  dist2 = readDistance(65);
  Serial.println(dist2);
  analogWrite(LED2, dist2);
  delay(300);
  
  dist3 = readDistance(115);
  Serial.println(dist3);
  analogWrite(LED3, dist3);
  delay(300);
  
  dist4 = readDistance(165);
  Serial.println(dist4);
  analogWrite(LED4, dist4);
  delay(300);
  
}

int readDistance(int pos){
  myServo.write(pos);
  delay(600);
  int dist = analogRead(IR);
  dist = map(dist, 50, 500, 0, 255);
  dist = constrain(dist, 0, 255);
  return dist;
}
