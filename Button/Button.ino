const int upButton = 3,downButton = 2;
int upButtonState = 1,counter=0, downButtonState = 1;
bool changed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println(counter);
}

void loop() {
  // put your main code here, to run repeatedly:
  int upButtonInitial = upButtonState,downButtonInitial = downButtonState;
  upButtonState = digitalRead(upButton);
  delay(50);
  downButtonState = digitalRead(downButton);
  
  if(upButtonState == 0 && downButtonState == 0 && changed) {
    counter = 0;
    changed = false;
    Serial.println(counter);
  }
  else if(upButtonState == 0 && upButtonInitial != upButtonState)
  {
    counter++;
    changed = true;
    Serial.println(counter);
  }
  else if(downButtonState == 0 && downButtonInitial != downButtonState)
  {
    counter--;
    changed = true;
    Serial.println(counter);
  }
  delay(50);
}
