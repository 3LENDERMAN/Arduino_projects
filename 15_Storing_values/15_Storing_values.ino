#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int num = 0;
int eepromAdress = 0;

void setup() {
  lcd.begin(16,2);
  num = EEPROM.read(eepromAdress);
  lcd.print("Hodnota: ");
  lcd.setCursor(0,1);
  lcd.print(num);
}

void loop() {
  int cmd = analogRead(0);
  // if up button (increment value)
  if (cmd > 50 && cmd < 195) {
    num++;
    lcd.setCursor(0, 1);
    lcd.print("                ");  // Vymazání spodního řádku
    lcd.setCursor(0, 1);
    lcd.print(num);
  }
  // if down button (decrement value)
  if (cmd > 195 && cmd < 380) {
    num--;
    lcd.setCursor(0, 1);
    lcd.print("                ");  // Vymazání spodního řádku
    lcd.setCursor(0, 1);
    lcd.print(num);
  }
  // if select button (save current value)
  if (cmd > 555 && cmd < 800) {
    EEPROM.write(eepromAdress, num);
    lcd.setCursor(0,0);
    lcd.print("Value Saved!");
    delay(1000);
  }
  delay(230);
}
