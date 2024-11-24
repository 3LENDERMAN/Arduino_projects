#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

unsigned long timeElapsed = 0 ;  
unsigned long timeStart = 0 ;
int seconds = 0 ;
int minutes = 0 ;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Timer");
  timeStart = millis();
}

void loop() {
  timeElapsed = millis() - timeStart;
  seconds = (timeElapsed / 1000) % 60;
  minutes = (timeElapsed / 60000);

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
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
