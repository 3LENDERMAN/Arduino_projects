#include "dht.h"
 
dht DHT;
 
int redc = 3;
int greenc = 4;
int bluec = 5;

void setup(){
 
  Serial.begin(9600);
  delay(5000); // time for proper boot up
  pinMode(redc, OUTPUT);
  pinMode(greenc, OUTPUT);
  pinMode(bluec, OUTPUT);
  
  Serial.println("DHT11 Senzor Vlhkosti a Teploty\n\n");
  Serial.println("Modrá LED - zima ; Bílá LED - akorát ; Červená LED - teplo\n");
  delay(3000); //Wait before accessing Sensor
 
}
 
void loop(){
  DHT.read11(7);
  float temp = DHT.temperature;
  float humid = DHT.humidity;

  // Print the humidity and temperature: 
  Serial.print("Aktuální vlhkost = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("teplota = ");
  Serial.print(DHT.temperature); 
  Serial.println("°C  ");

  // Set color of diode:
  if (temp < 21.0) { setColor(0,0,255); Serial.print(" - teplota je nízká"); }
  else if (temp < 23.0) { setColor(255,200,200); Serial.print(" - teplota je akorát"); }
  else { setColor(255,0,0); Serial.print(" - teplota je vysoká"); }

  if (humid < 40) { Serial.println(" - vlhkost je nízká"); }
  else if (humid < 60) { Serial.println(" - vlhkost je akorát"); }
  else { Serial.println(" - vlkost je vysoká"); }

  delay(120000); // measure once every 2 minutes..
}

void setColor(int r, int g, int b) {
  analogWrite(redc, r);
  analogWrite(greenc, g);
  analogWrite(bluec, b);
}