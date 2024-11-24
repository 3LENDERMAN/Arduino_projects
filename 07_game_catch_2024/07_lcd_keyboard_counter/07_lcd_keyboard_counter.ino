#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int amount = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(">< CATCH 2024 ><");
  lcd.setCursor(0, 1);
  lcd.print("-> ");
}

void loop() {
  lcd.setCursor(2, 1);
  lcd.print(amount);

  int command = analogRead(0);

  isWinner(amount, command);
  int temp = amount;
  int nDigits = 1;

  while (temp != 0) {
    nDigits++;
    temp /= 10;
  }

  int shift = 1 + nDigits;

  if (amount < 0) {
    shift++;
  }

  lcd.setCursor(shift, 1);
  lcd.print("             ");

  if (command < 60) {
    lcd.print(" ERROR!");
  }
  else if (command < 200) {
    amount++;
  }
  else if (command < 400) {
    amount--;
  }
  else {
    lcd.print(" ERROR!");
  }
}

void isWinner(int amount, int command) {
  if (amount == 2024) {
    if (command > 600 && command < 800) {
      lcd.setCursor(0,0);
      lcd.print("We have a WINNER");
      lcd.setCursor(0,1);
      lcd.print("><><><><><><><><");
      while(1);
    }   
  }
}