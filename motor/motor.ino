const int MOTOR=9;
const int POT=0;

int val = 0;

void setup(){
  pinMode(MOTOR, OUTPUT);
}

void loop(){
  val = analogRead(POT);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(MOTOR, val);
}
