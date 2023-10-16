#
nclude <Servo.h>
#define x A0
#define y A1
#define SW 2
#define serv1 5
#define serv2 9

Servo servo1;
Servo servo2;

int lastState = 1;
int counter = 0;

void setup() {
  pinMode(SW,INPUT);
  servo1.attach(serv1);
  servo1.write(90);
  
  servo2.attach(serv2);
  servo2.write(90);
}

void loop() {
  long xOut = analogRead(x);
  long yOut = analogRead(y);

  xOut = map(xOut,0,1023,0,180);
  yOut = map(yOut,0,1023,0,180);

  servo1.write(xOut);
  servo2.write(yOut);

  int currentState = digitalRead(SW);
  if(currentState != lastState) {
    counter++;
    delay(500);
  }
  else if(currentState == 0){counter = 0;}
}
