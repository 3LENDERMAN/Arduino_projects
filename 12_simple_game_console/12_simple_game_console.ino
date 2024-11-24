#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

byte personRight[8] = { 0b00110, 0b00110, 0b00101, 0b01110, 0b10100, 0b00100, 0b01010, 0b10010 };

byte personLeft[8] = { 0b01100, 0b01100, 0b10100, 0b01110, 0b00101, 0b00100, 0b01010, 0b01001 };

byte personDown[8] = { 0b00000, 0b00000, 0b00110, 0b00110, 0b01100, 0b10111, 0b01011, 0b01010 };

byte personJump[8] = { 0b00110, 0b00110, 0b10101, 0b01110, 0b00100, 0b01110, 0b10001, 0b00000 };

byte barrier[8] = { 0b00000, 0b00000, 0b10001, 0b11111, 0b11111, 0b10001, 0b10001, 0b10001 };

byte finish[8] = { 0b10101, 0b01010, 0b10101, 0b01010, 0b10101, 0b01010, 0b10101, 0b01010 };

byte star[8] = { 0b00000, 0b00100, 0b01110, 0b11111, 0b01110, 0b00100, 0b01010, 0b00000 };

//byte point[8] = { 0b00110, 0b00110, 0b00101, 0b01110, 0b10100, 0b00100, 0b01010, 0b10010 };

byte arrow[8] = { 0b00000, 0b00000, 0b00100, 0b00110, 0b11111, 0b00110, 0b00100, 0b00000 };

const char* menuItems[] = {
  "     MENU",
  "1. Stickman",
  "2. Catch 2024",
  "3. Casovac",
  "4. ctvrty",
  "5. paty",
  "6. sesty",
  "7. sedmy"
};

// menu
int menuIndex = 0;
const int numItems = sizeof(menuItems) / sizeof(menuItems[0]);

// stickman
int horizontal = 2;
int vertical = 1;
int obstacle = 16;
int score = 0;
// timer
unsigned long timeElapsed = 0 ;  
unsigned long timeStart = 0 ;
int seconds = 0 ;
int minutes = 0 ;

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0, personRight);
  lcd.createChar(1, personLeft);
  lcd.createChar(2, personDown);
  lcd.createChar(3, personJump);
  lcd.createChar(4, barrier);
  lcd.createChar(5, finish);
  lcd.createChar(6, arrow);

  lcd.blink();
  lcd.setCursor(0, 0);
  lcd.print(" Herni konzole ");
  lcd.setCursor(0, 1);
  isReady();
  lcd.noBlink();
}

void loop() {
  int cmd = analogRead(0);
  delay(150);
  lcd.setCursor(0, 1);
  lcd.write(byte(6));
  
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
      delay(200);
      menuStickman();
      while(true) {
      int command = analogRead(0);
      if (obstacle < 0) {
        if (score < 125) {
          obstacle = 15;
        }
      }
      if (score >= 125) {
        lcd.setCursor(14, 0);
        lcd.write(byte(5));
        lcd.setCursor(14, 1);
        lcd.write(byte(5));
        if (horizontal == 14) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(" ! Vyhral jsi !");
          lcd.setCursor(0, 1);
          lcd.print("****************");
          while(true);
        }
        delay(150);
      }
      obstacle--;
      lcd.clear();
      lcd.setCursor(obstacle, 1);
      lcd.write(byte(4));
      lcd.setCursor(obstacle + 1, 1);
      lcd.print(" ");
      // check if stickman jumped over barrier:
      if (horizontal == obstacle && vertical == 1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Konec hry!");
        lcd.setCursor(0, 1);
        lcd.print("Tve skore: ");
        lcd.setCursor(11, 1);
        lcd.print(score);
        while(true);
        // end of the game..
      }
      vertical = 1;
      lcd.setCursor(horizontal, vertical);
      lcd.write(byte(0));
      
      // check for pressed button:
      if (command < 60 && horizontal < 14) {
        horizontal++; // move stickman to right:
        lcd.clear();
        lcd.setCursor(horizontal, vertical);
        lcd.write(byte(0));
        delay(200);
      } 
      else if (command < 200) {
        vertical--; // jump
        lcd.clear();
        lcd.setCursor(horizontal, vertical);
        lcd.write(byte(3));
        delay(200);
      }
      else if (command < 400) {
        vertical++; // squat
        lcd.clear();
        lcd.setCursor(horizontal, vertical);
        lcd.write(byte(2));
        delay(200);
        vertical--;
      }
      else if (command < 600 && horizontal >= 0) {
        horizontal--; // move stickam to left
        lcd.clear();
        lcd.setCursor(horizontal, vertical);
        lcd.write(byte(1));
        delay(200);
      }
      // select button
      else if (command < 800) {
        lcd.clear();
      }
      score++;
      delay(150);
      }
    }
    else if (menuIndex == 1) {
      // game catch 2024:
      int amount = 0;
      lcd.setCursor(0, 0);
      lcd.print(">< CATCH 2024 ><");
      lcd.setCursor(0, 1);
      lcd.print("-> ");

      while(true) {
        lcd.setCursor(2, 1);
        lcd.print(amount);
        int command = analogRead(0);

        isWinner(amount, command);
        int temp = amount;
        int nDigits = 1;

        while (temp != 0) {
          nDigits++;
          temp /= 10; // count ciphers
        }
        int shift = 1 + nDigits;
        if (amount < 0) {
          shift++;
        }
        lcd.setCursor(shift, 1);
        lcd.print("             ");

        if (command < 60) {
          lcd.print(" ERROR!");
        } else if (command < 200) {
          amount++;
        } else if (command < 400) {
          amount--;
        } else {
          lcd.print(" ERROR!");
        }
      }
    }
    // end of the game catch 2024
    else if (menuIndex == 2) {
      lcd.begin(16,2);
      lcd.clear();
      timeStart = millis();

      while(true) {
        timeElapsed = millis() - timeStart;
        seconds = (timeElapsed / 1000) % 60;
        minutes = (timeElapsed / 60000);

        lcd.setCursor(0, 0);
        lcd.print("Cas: ");
        if (minutes < 10) {
          lcd.print("0"); 
        }
        lcd.print(minutes);
        lcd.print(":");
        if (seconds < 10) {
          lcd.print("0"); 
        }
        lcd.print(seconds);
        delay(500);

      }
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
// start menu of the game Stickman:
void menuStickman() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.print(" Stickman");
  lcd.setCursor(13, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.print("§------§");
  while(true) {
    int com = analogRead(0);
    if (com < 800) {
      lcd.clear();
      break;
    }
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
