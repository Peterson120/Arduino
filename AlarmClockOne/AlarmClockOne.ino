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

int del = 1000;
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
    for(int i = 0;i < outputValue*30;i++)
    {
      digitalWrite(10,HIGH);
      delay(1000);
      digitalWrite(10,LOW);
      delay(1000);
    }
    digitalWrite(10,HIGH);
    servo.write(180);
    delay(3000);
    servo.write(0);
    for(int i = 0; i < 5; i++){
      tone(13,500,500);
      delay(1000);
    }
    digitalWrite(10,LOW);
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
