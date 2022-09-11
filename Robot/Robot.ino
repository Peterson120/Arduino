/*
 * Motor Shield Pins
Function        Channel A   Channel B
Direction       Digital 12  Digital 13
Speed (PWM)     Digital 3   Digital 11
Brake           Digital 9   Digital 8
Current Sensing Analog 0    Analog 1
*/

#include <Vector.h>
#include <LiquidCrystal.h>

//#define TrigPin 13
//#define EchoPin 12

#define MAX 255
#define mA 12
#define mB 13
#define bA 9
#define bB 8

#define IR 5
#define LED 7

//#define rs 12
//#define en 11
//#define d4 5
//#define d5 4
//#define d6 3
//#define d7 2

#define inputPin 12
#define ledPin 13
int pirState = LOW;

long duration = 0;

// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {  
//  pinMode (TrigPin, OUTPUT);
//  pinMode (EchoPin, INPUT);
  pinMode(IR,INPUT);
  pinMode(LED,OUTPUT);
//  pinMode(ledPin, OUTPUT);
//  pinMode(inputPin, INPUT);
//
//  lcd.begin(16, 2);
//  
//  //Set initial speed of the motor & stop
//  AF_DCMotor motorL(2);
//  AF_DCMotor motorR(1);
//  motorL.setSpeed(200);
//  motorL.run(RELEASE);
//  motorR.setSpeed(200);
//  motorR.run(RELEASE);
//  
//  v.push_back(motorL);
//  v.push_back(motorR);
  
  Serial.begin(9600);
}

void loop() {
//  // Set Robot Motor
//  digitalWrite (TrigPin, LOW);
//  delay (2);
//  digitalWrite (TrigPin, HIGH);
//  delay (10);
//  digitalWrite (TrigPin, LOW);
//  duration = pulseIn(EchoPin, HIGH);

  // IR sensor
  int sensStatus = digitalRead(IR);
  Serial.println(sensStatus);
//  if(sensStatus == 1)
//    digitalWrite(LED,LOW);
//   else 
//    digitalWrite(LED,HIGH);

//  // Ultrasonic
//  float CM = duration/58;
//  if(CM < 15) 
//    two(BACKWARD,200);
//  else if(CM > 50)
//    two(FORWARD,MAX);
//  else
//    two(FORWARD,MAX/2);
//
//  // PIR Motion
//  int val = digitalRead(inputPin);
//  if (val == HIGH) 
//  {
//    digitalWrite(ledPin, HIGH);
//     if (pirState == LOW) 
//     {
//        Serial.println("Motion detected!");
//        pirState = HIGH;
//     }
//   } 
//   else 
//   {
//    digitalWrite(ledPin, LOW);
//    if (pirState == HIGH)
//    {
//      Serial.println("Motion ended!");
//      pirState = LOW;
//    }
//  }
}
//
//void two(int dir,int m_speed) // Set two motors
//{
//  for(AF_DCMotor i:v) 
//  {
//    i.run(dir);
//    i.setSpeed(m_speed);
//  }
//}
//
//void one(int motor, int dir, int m_speed) // Set One Motor
//{
//  v[motor].run(dir);
//  v[motor].setSpeed(m_speed);
//}
