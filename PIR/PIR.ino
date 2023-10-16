#define inputPin 12
#define ledPin 13

int pirState = LOW;
int val = 0;
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input
  Serial.begin(9600);
}
// -------------------------------------
void loop(){
  val = digitalRead(inputPin); // read input value
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
     if (pirState == LOW) {
        Serial.println("Motion detected!");
        pirState = HIGH;
     }
   } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
