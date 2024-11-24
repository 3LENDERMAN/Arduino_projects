#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

byte personRight[8] = {
  0b00110,
  0b00110,
  0b00101,
  0b01110,
  0b10100,
  0b00100,
  0b01010,
  0b10100
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

byte barrier[8] = {
  0b00000,
  0b00000,
  0b10001,
  0b11111,
  0b11111,
  0b10001,
  0b10001,
  0b10001
};

byte finish[8] = {
  0b10101,
  0b01010,
  0b10101,
  0b01010,
  0b10101,
  0b01010,
  0b10101,
  0b01010
};

byte star[8] = {
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b01110,
  0b00100,
  0b01010,
  0b00000
};

byte secondRight[8] = {
  0b00110,
  0b00110,
  0b10100,
  0b01110,
  0b00101,
  0b00100,
  0b11010,
  0b00001
};

int horizontal = 2;
int vertical = 1;
int obstacle = 16;
int score = 0;

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0, personRight);
  lcd.createChar(1, personLeft);
  lcd.createChar(2, personJump);
  lcd.createChar(3, secondRight);
  lcd.createChar(4, person);
  lcd.createChar(5, barrier);
  lcd.createChar(6, finish);
  lcd.createChar(7, star);
  menu();
}

void loop() {
  int command = analogRead(0);
  if (obstacle < 0) {
    if (score < 125) {
      obstacle = 15;
    }
  }
  if (score >= 125) {
    lcd.setCursor(14, 0);
    lcd.write(byte(6));
    lcd.setCursor(14, 1);
    lcd.write(byte(6));
    if (horizontal == 14) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" ! Vyhral jsi !");
      lcd.setCursor(0, 1);
      for (int i = 0 ; i < 16 ; i++) {
        lcd.setCursor(i,1);
        lcd.write(byte(7));
      }
      while(true);
    }
    delay(150);
  }
  obstacle--;
  lcd.clear();
  //lcd.setCursor(horizontal, vertical);
  //lcd.write(byte(4));

  lcd.setCursor(obstacle, 1);
  lcd.write(byte(5));
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
  if (score > 125) {
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(4));
  }
  else if (score % 2 == 0) {
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(3));
  } else {
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(0));
  }
  // check for pressed button:
  if (command < 60 && horizontal < 14) {
    horizontal++;
    lcd.clear();
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(0));
    delay(200);
  } 
  else if (command < 200) {
    vertical--;
    lcd.clear();
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(2));
    delay(200);
  }
  else if (command < 400) {
    vertical++;
    lcd.clear();
    lcd.setCursor(horizontal, vertical);
    lcd.write(byte(3));
    delay(200);
    vertical--;
  }
  else if (command < 600 && horizontal >= 0) {
    horizontal--;
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

// start menu:
void menu() {
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
