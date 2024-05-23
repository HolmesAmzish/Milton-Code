#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Send command:");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    switch (command) {
      case '1':
        animation1();
        break;
      case '2':
        animation2();
        break;
      case '3':
        animation3();
        break;
      default:
        lcd.print("Invalid cmd");
        break;
    }
  }
}

void animation1() {
  lcd.print("Scroll Left");
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
}

void animation2() {
  lcd.print("Scroll Right");
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
}

void animation3() {
  lcd.print("Blink Text");
  for (int i = 0; i < 10; i++) {
    lcd.noDisplay();
    delay(250);
    lcd.display();
    delay(250);
  }
}
