/*
 * Metronome Coordinator
 * DIGF 6003 Ubiquitous Computing - Kate Hartman & Nick Puckett
 * 
 */

const int potPin = 0;
int potVal;
int mappedPotVal;

void setup() {
  // This is what allows us to debug locally via the serial monitor.
  Serial.begin(9600);
  // This is what is sent via the serial pins that are connected to the XBee.
  Serial1.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  mappedPotVal = map(potVal, 0, 1023, 200, 5000);
  Serial.print("H");
  Serial1.print("H");
  delay(mappedPotVal);
  Serial.print("L");
  Serial1.print("L");
  delay(mappedPotVal);
  
}
