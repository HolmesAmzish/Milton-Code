const int fanPin = 9;

void setup() {
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case '0':
        analogWrite(fanPin, 0);
        break;
      case '1':
        analogWrite(fanPin, 128);
        break;
      case '2':
        analogWrite(fanPin, 255);
        break;
    }
  }
}
