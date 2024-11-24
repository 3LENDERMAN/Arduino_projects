#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

bool begin = true;
const char startText = "Welcome to QUIZ GAME! You will be given questions to answer, either right -> or left <-. Good Luck!     ";
int scroll_position = 0;


void setup() {
  lcd.begin(16,2);
}

void loop() {
  int position = 0;
  int command = digitalRead(0);
  // first question
  for(scroll_position; scroll_position<100; scroll_position++){
    lcd.setCursor(1,0);
    lcd.print("Welcome to QUIZ žžžžžžžžžžžžžžžžžGAME! You will be given");
    lcd.scrollDisplayLeft();
    delay(300);
  }
  scroll_position = 0;
}
