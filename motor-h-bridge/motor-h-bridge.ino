const int EN=9;
const int MC1=3;
const int MC2=2;
const int POT=0;

int val = 0;
int velocity = 0;

void setup(){
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  brake();
}

void loop(){
  val = analogRead(POT);
  
  // go forward
  if(val > 562)
  {
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity);
  }
  
  // go backward
  else if(val < 462)
  {
    velocity = map(val, 461, 0, 0, 255);
    reverse(velocity);
  }
  
  // brake
  else
  {
    brake();
  }
}

// motor goes forward at given rate (from 0-255)
void forward (int rate)
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
}

// motor goes backward at given rate (from 0-255)
void reverse (int rate)
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);
}

// stops motor
void brake()
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  analogWrite(EN, HIGH);
}
