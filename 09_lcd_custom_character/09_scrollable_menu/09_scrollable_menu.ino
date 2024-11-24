#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte personRight[8] = {
  0b00110,
  0b00110,
  0b00101,
  0b01110,
  0b10100,
  0b00100,
  0b01010,
  0b10010
};

byte personLeft[8] = {
  0b01100,
  0b01100,
  0b10100,
  0b01110,
  0b00101,
  0b00100,
  0b01010,
  0b01001
};

byte personJump[8] = {
  0b00110,
  0b00110,
  0b10101,
  0b01110,
  0b00100,
  0b01110,
  0b10001,
  0b00000
};

byte person[8] = {
  0b00110,
  0b00110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b01010
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  lcd.createChar(1, personRight);
  lcd.createChar(2, personLeft);
  lcd.createChar(3, personJump);
  lcd.createChar(4, person);
  lcd.setCursor(0, 0);
  lcd.print("Custom characters:");
  lcd.setCursor(0, 1);
  lcd.write(byte(1));
  lcd.setCursor(2,1);
  lcd.write(byte(2));
  lcd.setCursor(4,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));
}

void loop() {

}
