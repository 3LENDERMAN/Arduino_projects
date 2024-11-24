int greenLed = 6;
int redLed = 5;
int blueLed = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // blue color
  setColor(0, 0, 255);
}
 
void setColor(int first, int second, int third) {
  analogWrite(redLed, first);
  analogWrite(greenLed, second);
  analogWrite(blueLed, third);
}
