#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    while (Serial.available() > 0) {
      char c = Serial.read();
      lcd.print(c);
      delay(100);
    }
  }
}
