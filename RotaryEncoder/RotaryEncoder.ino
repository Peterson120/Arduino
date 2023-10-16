#include <Servo.h>
#define CLK 2
#define DT 3
#define SW 4
#define analog A0

int counter = 0;
int currentStateCLK;
int lastStateCLK;
int lastSensorValue;
String currentDir ="";
unsigned long lastButtonPress = 0;
Servo servo;

void setup() {
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  servo.attach(8, 1000, 2000);
  
  Serial.begin(9600);

  lastStateCLK = digitalRead(CLK);
}

void loop() {
  currentStateCLK = digitalRead(CLK);
  int sensorValue = analogRead(analog);

  if(lastSensorValue != sensorValue)
  {
    lastSensorValue = sensorValue;
    long outputValue = map(sensorValue,0,1023,0,255);
    servo.write(outputValue);
    Serial.println(sensorValue);
  }
  
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    if (digitalRead(DT) != currentStateCLK) {
      counter--;
      currentDir ="CCW";
    } else {
      counter++;
      currentDir ="CW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }
  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      counter = 0;
      servo.write(counter);
      Serial.print("Button pressed ");
      Serial.println(counter);
    }
    lastButtonPress = millis();
  }
  delay(1);
}
