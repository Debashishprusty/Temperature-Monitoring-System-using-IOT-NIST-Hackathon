#include <SoftwareSerial.h>
SoftwareSerial bt(0, 1);

#include <LiquidCrystal.h> 
#include "dht.h"
#define dataPin A0
#define led 8
#define m1 9    
#define m2 10
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
 Serial.println("Ready");
  
  lcd.begin(16,2);  
  lcd.setCursor(0,0);
  lcd.print(" Debashish Prusty ");
  lcd.setCursor(0,1);
  lcd.print(" NIST ");
  delay(2000);
  lcd.clear(); 
  pinMode(m1, OUTPUT);  
  pinMode(m2, OUTPUT);
  digitalWrite(m1, LOW);    
  digitalWrite(m2, LOW);
  pinMode(led, OUTPUT);
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
  
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("% ");

  lcd.setCursor(0,1); 
  lcd.print("Temp: "); 
  lcd.print(temp); 
  lcd.print((char)223);
  lcd.print("C ");

 bt.print(temp);
 bt.print(";");
 bt.print(hum);
 bt.println(";");
  
  delay(1000);

 if(temp>=29)
{
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(led, HIGH);
 }
else if(temp<29)
{
 digitalWrite(m1, LOW);
 digitalWrite(m2, LOW);
 digitalWrite(led, LOW);
}
}