/*
  Multple Serial test

 Receives from the main serial port, sends to the others.
 Receives from serial port 1, sends to the main serial (Serial 0).

 This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc

 The circuit:
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:

 created 30 Dec. 2008
 modified 27 Nov 2015
 by Arturo Guadalupi
 modified 15 July 2016
 by Tom Igoe & Jed Roach
 modified 14 July 2016
 by Chris Peters

 This example code is in the public domain.

 */


void setup() {
  // power RN2483
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  
  // initialize both serial ports:
  Serial.begin(57600);
  Serial1.begin(57600);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);

}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }
  else {
    Serial.println("Unable to read from Serial1");
    delay(1000);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
  else {
    Serial.println("Unable to write to Serial1");
    delay(1000);
  }
}

