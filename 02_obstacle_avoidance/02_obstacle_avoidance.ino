#define IRpin 2 
#define ledPin 13 
void setup() { 
	// put your setup code here, to run once: 
  Serial.begin(9600);
  Serial.println(__FILE__ __DATE__ __TIME__);
  pinMode(IRpin,INPUT); 
  pinMode(ledPin,OUTPUT); 
} 

void loop() { 
	// put your main code here, to run repeatedly: 
	int IRread = digitalRead(IRpin); 
  digitalWrite(ledPin,LOW); 
  if(IRread == 0){ 
    Serial.println("Detekce!\n");
	  digitalWrite(ledPin,HIGH); 
  } 
  delay(1000);
} 
