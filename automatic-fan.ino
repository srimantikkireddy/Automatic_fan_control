#include <DHT.h> 
#include <LiquidCrystal_I2C.h> 

#define DHTPIN 2 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int potPin = A0; 
const int fanPin =3; 

void setup(){
  dht.begin(); 
  pinMode(fanPin, OUTPUT); 
  lcd.init(); 
  lcd.backlight(); 
  lcd.print("Temp Fan Ctrl"); 
  delay(2000); 
  lcd.clear(); 
}

void loop(){
  int potValue = analogRead(potPin); 
  int threshold = map(potValue, 0,1023, 20, 40); 
  float temperature = dht.readTemperature(); 

  
  if (temperature > threshold) {
    digitalWrite(fanPin, HIGH); 
  } else {
    digitalWrite(fanPin, LOW); 
  }

  
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(temperature); 
  lcd.print("C");

  lcd.setCursor(0,1); 
  lcd.print("Threshold: ");
  lcd.print(threshold); 
  lcd.print("C");

  delay(1000); 
}
