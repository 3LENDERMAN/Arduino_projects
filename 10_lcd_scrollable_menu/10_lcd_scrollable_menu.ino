#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte bullet[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01010,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
};

byte selected[8] = {
  0b11111,
  0b11111,
  0b11011,
  0b10101,
  0b10101,
  0b11011,
  0b11111,
  0b11111,
};

const char* menuItems[] = {
  "     MENU",
  "1. Stickman",
  "2. Catch 2024",
  "3. treti",
  "4. ctvrty",
  "5. paty",
  "6. sesty",
  "7. sedmy"
};

int menuIndex = 0;
const int numItems = sizeof(menuItems) / sizeof(menuItems[0]);

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, bullet);
  lcd.createChar(1, selected);

  lcd.setCursor(0, 0);
  lcd.print(" Herni konzole ");
  lcd.setCursor(0, 1);
  lcd.print("Zmackni *Up* ...");
  isReady();
}

void loop() {
  int cmd = analogRead(0);
  delay(150);
  // print bullet points:
  if (menuIndex < 0) {
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
  }
  lcd.setCursor(0, 1);
  lcd.write(byte(1));
  
  if (cmd < 200) {
    // up button:
    if (menuIndex > 0) {
      menuIndex--;
    }
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print(menuItems[menuIndex]);
    lcd.setCursor(1, 1);
    lcd.print(menuItems[menuIndex + 1]);

  } else if (cmd > 200 && cmd < 400) {
    // down button:
    if (menuIndex < numItems - 2) {
      menuIndex++;
    }
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print(menuItems[menuIndex]);
    lcd.setCursor(1, 1);
    lcd.print(menuItems[menuIndex + 1]);
  }
  else if (cmd < 800 && cmd > 600) {
    if (menuIndex == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Hra");
      delay(5000);
    }
    else if (menuIndex == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("dalsi hra");
      delay(5000);
    }
    else if (menuIndex == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("treti polozka");
      delay(5000);      
    }
    else if (menuIndex == 3) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ctvrta polozka");
      delay(5000);
    }
    else if (menuIndex == 4) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("pata polozka");
      delay(5000);      
    }
    else if (menuIndex == 5) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("sesta polozka");
      delay(5000);
    }
    else if (menuIndex == 6) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("sedma polozka");
      delay(5000);
    }
  }
}

void isReady() {
  while (true) {
    int command = analogRead(0);
    if (command > 60 && command < 200) {
      lcd.clear();
      break;
    }
  }
}
