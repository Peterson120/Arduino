#define A A0

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

int del = 1000;
void loop() {
  int value = analogRead(A);
  int outputValue = map(value,0,1023,0,9);

  if(outputValue == 0){zero();}
  else if(outputValue == 1){one();}
  else if(outputValue == 2){two();}
  else if(outputValue == 3){three();}
  else if(outputValue == 4){four();}
  else if(outputValue == 5){five();}
  else if(outputValue == 6){six();}
  else if(outputValue == 7){seven();}
  else if(outputValue == 8){eight();}
  else if(outputValue == 9){nine();}
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

void six()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void seven()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}

void eight()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void nine()
{
  clearAll();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void decimal()
{
  digitalWrite(9,HIGH);
}
