#include <Servo.h>
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define buzz 9
#define led 10
#define button 11

Servo xServo;
Servo yServo;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  xServo.attach(12);
  yServo.attach(13);
  xServo.write(0);
  yServo.write(0);
}

void loop() {
  int value = analogRead(A0);
  int outputValue = map(value,0,1023,1,5);

  if(outputValue == 1){one();}
  else if(outputValue == 2){two();}
  else if(outputValue == 3){three();}
  else if(outputValue == 4){four();}
  else if(outputValue == 5){five();}

  int buttonValue = digitalRead(button);
  if(buttonValue == 1) {
    for(int i = 0; i < 180; i++) {
      xServo.write(i);
      delay(20);
    }
    delay(500);
    for(int i = 0; i < 90; i++) {
      yServo.write(i);
      delay(20);
    }
    int time = map(outputValue,1,5,60,300);
    for(int i = time/2; i > 0; i--)
    {
      if(i/60 == 5){five();}
      else if(i/60 == 4){four();}
      else if(i/60 == 3){three();}
      else if(i/60 == 2){two();}
      else if(i/60 == 1){one();}
      else if(i/60 == 0){zero();}
      digitalWrite(led,HIGH);
      delay(1000);
        digitalWrite(led,LOW);
      delay(1000);
    }
    digitalWrite(led,HIGH);
    for(int i = 90; i > 0; i-=2) {yServo.write(i);}
    delay(20);
    for(int i = 180; i > 0; i-=2) {xServo.write(i);}
    tone(buzz,500,500);
    delay(500);
    digitalWrite(led,LOW);
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
