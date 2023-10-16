int red = 9;
int yellow = 8;
int green = 7;
int blue = 6;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  for(int i = 5; i < 10; i++)
  {
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
  }
}
