const int TEMP=0;
const int LIGHT=1;
const int LED=3;
const int BUTTON=2;

boolean lastButton = LOW;
boolean currentButton = LOW;
boolean running = false;
int counter = 1;

void setup(){
  pinMode(LED, OUTPUT);
  Keyboard.begin();
}

void loop(){
  currentButton = debounce(lastButton);

  if(lastButton == LOW && currentButton == HIGH)
    running = !running;
  
  lastButton = currentButton;

  if(running)
  {
    digitalWrite(LED, HIGH);
    if(millis() % 1000 == 0)
    {
      int temperature = analogRead(TEMP);
      int brightness = analogRead(LIGHT);
      Keyboard.print(counter);
      Keyboard.print(",");
      Keyboard.print(temperature);
      Keyboard.print(",");
      Keyboard.print(brightness);
      counter++;
    }
  } else {
    digitalWrite(LED, LOW);
  }
}

boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON);
  if(last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}
