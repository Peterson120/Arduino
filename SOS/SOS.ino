#define NOTE_C1  33

int buzzer = 3;
int short_delay = 100;
int long_delay = 500;

void setup() {
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  S();
  O();
  S();
  delay(long_delay);
}

void S()
{
  for(int i = 0; i < 3; i++)
  {
    tone(buzzer,NOTE_C1);    
    delay(short_delay);
    noTone(buzzer);
    delay(short_delay);
  }
}

void O()
{
  for(int i = 0; i < 3; i++)
  {
    tone(buzzer,NOTE_C1);    
    delay(long_delay);
    noTone(buzzer);
    delay(short_delay);
  }
}
