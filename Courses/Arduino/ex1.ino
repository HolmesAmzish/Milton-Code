const int buttonPin = 2;
const int buzzerPin = 9;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long lastButtonPressTime = 0;
unsigned long doubleClickThreshold = 400;

// Initial
int buttonState = HIGH;
int lastButtonState = HIGH;
int buzzerState = LOW;

enum ButtonPress { NONE, SINGLE_CLICK, DOUBLE_CLICK };
ButtonPress buttonPress = NONE;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, buzzerState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        unsigned long currentTime = millis();
        if (currentTime - lastButtonPressTime < doubleClickThreshold) {
          buttonPress = DOUBLE_CLICK;
        } else {
          buttonPress = SINGLE_CLICK;
        }
        lastButtonPressTime = currentTime;
      }
    }
  }

  if (buttonPress == SINGLE_CLICK) {
    buzzerState = LOW;
    digitalWrite(buzzerPin, buzzerState);
    buttonPress = NONE;
  } else if (buttonPress == DOUBLE_CLICK) {
    buzzerState = HIGH;
    digitalWrite(buzzerPin, buzzerState);
    buttonPress = NONE;
  }

  lastButtonState = reading;
}