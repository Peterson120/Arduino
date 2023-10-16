int counter = 0;
int buttonState,lastButtonState;
void setup() {
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println(counter);
  buttonState = digitalRead(3);
  lastButtonState = buttonState;
}

void loop() {
  buttonState = digitalRead(3);
  if(buttonState!=lastButtonState && buttonState == 0)
  {
    counter++;
    Serial.println(counter);
  }
  lastButtonState = buttonState;
}
