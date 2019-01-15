

int radioID = 20;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial1.print(radioID);
  Serial.print(radioID);
  Serial1.print(",");
  Serial.print(",");
  Serial1.println(sensorValue);
  Serial.println(sensorValue);
  delay(200);        // delay in between reads for stability
}
