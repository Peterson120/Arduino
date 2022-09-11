#define r 3                 // Wheel Radius

const int dir[] = {12, 13}; // Motor DIR pins (digital)
const int pwm[] = {3, 11};  // Motor PWM pins (analog)
const int brake[] = {8, 9}; // Motor Brake pins (digital)

#define FORWARD 1
#define BACKWARD 0
void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
}

void loop() {
  moveRobot(50, FORWARD, 50);
  //analogWrite(11, 40);
  //analogWrite(3, 40);
  delay(1500);
}

void moveRobot(int speed, int direction, int CM) {  // Move robot based on distance
  const int maxSpeed1 = 50;
  if (speed > maxSpeed1) // Make sure speed stays under predefined max speed (lowered so CM is more accurate)
    speed = maxSpeed1;
  if (direction == FORWARD) { // if DIR == FORWARD
    digitalWrite(dir[0], HIGH);
    digitalWrite(dir[1], LOW);
  }
  else if (direction == BACKWARD) {  // if DIR == BACKWARD
    digitalWrite(dir[0], LOW);
    digitalWrite(dir[1], HIGH);
  }
  for (int i : brake) // Release Motor Brakes
    digitalWrite(i, LOW);
  analogWrite(3, speed - 4);
  analogWrite(11, speed);
  delay(CM / ((speed / 255.0 * 4.5) * (2.0 * PI * r)) * 1000);  // Calculate delay by using radius, speed, rotations/s at max speed, and CM
  stopRobot(true, true);
}

void stopRobot(bool left, bool right) { // Stop Motors
  if (left && right) {  // Stop left and right motors
    for (int i : brake) // Engage brakes
      digitalWrite(i, HIGH);

    for (int j : pwm)
      analogWrite(j, 0); // Set speed to 0
  }
  else if (left) { // Stop left motor
    digitalWrite(8, HIGH);
    analogWrite(11, 0);
  }
  else if (right) { // Stop right motor
    digitalWrite(9, HIGH);
    analogWrite(11, 0);
  }
}
