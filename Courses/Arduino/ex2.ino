const int buttonPin = 2;
const int buzzerPin = 9;

volatile bool buttonPressed = false;
volatile unsigned long lastPressTime = 0;
unsigned long doubleClickThreshold = 400;

enum ButtonPress { NONE, SINGLE_CLICK, DOUBLE_CLICK };
ButtonPress buttonPress = NONE;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
}

void loop() {
  if (buttonPressed) {
    buttonPressed = false;

    unsigned long currentTime = millis();
    if (currentTime - lastPressTime < doubleClickThreshold) {
      buttonPress = DOUBLE_CLICK;
    } else {
      buttonPress = SINGLE_CLICK;
    }
    lastPressTime = currentTime;

    if (buttonPress == SINGLE_CLICK) {
      digitalWrite(buzzerPin, LOW);
    } else if (buttonPress == DOUBLE_CLICK) {
      digitalWrite(buzzerPin, HIGH);
    }
  }
}

void handleButtonPress() {
  buttonPressed = true;
}
