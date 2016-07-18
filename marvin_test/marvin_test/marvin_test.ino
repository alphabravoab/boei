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

}

