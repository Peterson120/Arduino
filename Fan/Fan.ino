int counter = 0;
void setup() {
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  counter+=20;
  digitalWrite(8,counter);
}
