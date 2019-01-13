/*
   Metronome Receiver
   DIGF 6003 Ubiquitous Computing - Kate Hartman & Nick Puckett

   Based on the Physical Pixel example:
   http://www.arduino.cc/en/Tutorial/PhysicalPixel

   Changes:
   - "Serial1" is used to allow the data to be sent via the Arduino Micro hardware serial pins
    to the XBee radio.
   - "makeSomethingHappen" function has been added as a spot to put the response to the metronome.
*/

const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial1.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial1.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial1.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
      makeSomethingHappen();
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}

void makeSomethingHappen() {
  // This is where you could add a special event or behaviour.
  // Keep the duration under 200ms which the fastest pacing the metronome will provide.
}
