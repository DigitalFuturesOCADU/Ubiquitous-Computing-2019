/*
 * Metronome Coordinator (Processing Code)
 * DIGF 6003 Ubiquitous Computing - Kate Hartman & Nick Puckett
 * 
 */

import processing.serial.*; // import the Processing serial library
Serial myPort;              // The serial port
int radioID;
int sensorValue;


void setup() {
  size(800, 300);
  // List all the available serial ports in the console
  printArray(Serial.list());

  // Change the 0 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  // read incoming bytes to a buffer
  // until you get a linefeed (ASCII 10):
  myPort.bufferUntil('\n');
}


void draw() {
  background(255);
  // Make use of the sensor data here!
}


void serialEvent(Serial myPort) {
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    // println(myString);
    myString = trim(myString);

    // split the string at the commas
    // and convert the sections into integers:
    int sensors[] = int(split(myString, ','));
    println();
    radioID= sensors[0];  
    sensorValue = sensors[1]; 
    println("Radio ID: " + radioID + "Sensor Value: " + sensorValue);
  }
}
