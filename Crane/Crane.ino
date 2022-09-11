/*
 * Connect Wires
 * VRx to A0
 * VRy to A1
 * SW to 6
 * BUZZER to 5
 * LED to 4
 * 
 * Crane Simulation
 * Move the joystick around to control the crane and click once to remember the current coordinates of the crane arm, Click again to move back to position after moving away
 * Give the program a few seconds to calibrate before running to ensure calibration finishes
*/
#include <Servo.h>
#define led 4
#define buzz 5
#define button 6

double last[] = {0,0}; // last coordinates of crane
int counter = 0,lastButtonState; //button state
double xOut = 90,yOut = 0,xInitial, yInitial; //declare x,y values to output and set initial button state for calibration
long previous = millis(), current = 0; //start timer for reference

Servo xServo; 
Servo yServo;
void setup() {
  Serial.begin(9600);
  //setup pins
  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  xServo.attach(2);
  yServo.attach(3);
  xInitial = map(analogRead(A0),0,1023,0,5)-2.5; // map initial values to calibrate servo to not move while no joystick push 
  yInitial = map(analogRead(A1),0,1023,0,4)-2;
  xServo.write(xOut);
  yServo.write(yOut);
}

void loop() {
  //map x,y values of joystick position
  double x = map(analogRead(A0),0,1023,0,5)-2.5 - xInitial;
  double y = map(analogRead(A1),0,1023,0,4)-2 - yInitial;
  
  //check if joystick is not in original position and move servo accordingly
  xOut += x;
  yOut += y;
    
  if(xOut > 180){xOut = 180;}
  else if(xOut < 0){xOut = 0;}

  if(yOut > 90){yOut = 90;}
  else if(yOut < 0){yOut = 0;}
    
  if(x != 0 && xOut < 180 && xOut > 0){
    xServo.write(xOut);
    inMotion();
  }
            
  if(y != 0 && yOut < 90 && yOut > 0){
    yServo.write(yOut);
    inMotion();
  }
    
  int newState = digitalRead(button);
  if(newState == 0 && newState != lastButtonState){ //check if button state is not equal to previous button state(determine new button press)
   if(counter % 2 == 0){ //check if the counter is even or odd
      //store values
      last[0] = xOut;
      last[1] = yOut;
    }
    else if(counter % 2 == 1){
      //move servo according to previously stored locations
      if(xOut < last[0]){for(int i = xOut; i < last[0]; i++){xServo.write(i);inMotion();}}
      else if(xOut > last[0]){for(int i = xOut; i > last[0]; i--){xServo.write(i);inMotion();}}
      if(yOut < last[1]){for(int i = yOut; i < last[1]; i++){yServo.write(i);inMotion();}}
      else if(yOut > last[1]){for(int i = yOut; i > last[1]; i--){yServo.write(i);inMotion();}}
        xOut = last[0];
        yOut = last[1];
      }
      counter++; //increment counter
    }
    
    digitalWrite(led,LOW);
  
    lastButtonState = digitalRead(button);
    delay(20);
}

//beep and led if moving
void inMotion(){
  current = millis();
  if(current - previous >= 400){
    digitalWrite(led,HIGH);
    tone(buzz,1000,200);
    previous = millis();
  }
  else
  {
    digitalWrite(led,LOW);
    noTone(buzz);
  }
}
