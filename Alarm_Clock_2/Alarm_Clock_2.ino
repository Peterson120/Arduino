#include <Servo.h>

Servo servo;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  servo.attach(12);
  pinMode(13,OUTPUT);
  servo.write(0);
}

void loop() {
  int value = analogRead(A0);
  int outputValue = map(value,0,1023,0,5);

  if(outputValue == 0){zero();}
  else if(outputValue == 1){one();}
  else if(outputValue == 2){two();}
  else if(outputValue == 3){three();}
  else if(outputValue == 4){four();}
  else if(outputValue == 5){five();}

  int buttonValue = digitalRead(11);
  if(buttonValue == 1) {
    double firstHalf = map(outputValue,0,5,0,300)/8;
    double secondQuarter = map(outputValue,0,5,0,300)/8;
    double thirdQuarter = map(outputValue,0,5,0,300)/4;
    int amountDelay = 2000;
    double values[] = {firstHalf,secondQuarter,thirdQuarter};
    if(outputValue != 0){
      for(int i = 0; i < 3; i++)
      {
          led(values[i],amountDelay,i);
          amountDelay/=2;
      }
    }
    zero();
    digitalWrite(10,HIGH);
    servo.write(180);
    delay(3000);
    servo.write(0);
    buzz();
    digitalWrite(10,LOW);
  }
}

void buzz()
{
  for(int i = 0; i < 5; i++) {
    tone(13,500,500);
    delay(1000);
  }
}

void led(double loop,int numDelay,int numTimes)
{
  for(double i = 0; i < loop+0.5; i++)
  {
    int check = loop-0.5-i;
    digitalWrite(10,HIGH);
    delay(numDelay);
    digitalWrite(10,LOW);
    delay(numDelay);
    if(check <= 0 && numTimes == 2){zero();}
    else if(check <= 1 && numTimes == 2){one();}
    else if(check <= 2 && numTimes == 2){two();}
    else if(check <= 3 && numTimes == 2){three();}
    else if(check <= 4 && numTimes == 2){four();}
    else if(check <= 5 && numTimes == 2){five();}
  }
}

void clearAll()
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void zero()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}

void one()
{
  clearAll();
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}

void two()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
}

void three()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
}

void four()
{
  clearAll();
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void five()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
