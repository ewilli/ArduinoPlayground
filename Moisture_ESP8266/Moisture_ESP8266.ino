/*
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
  5 V Values
  3.3:
    0 200 dry
    200 - 450 humid
    450 - 1000 water
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0

int sensorValue = 0;  // value read from the pot

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
    lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Value:");
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogInPin);
 
  // print the readings in the Serial Monitor
  Serial.print("sensor = ");
  Serial.println(sensorValue);

    if(sensorValue<10)
  {
  lcd.setCursor(6,0);
  lcd.print(sensorValue);
  lcd.setCursor(7,0);
  lcd.print("    ");
  }
  if(sensorValue<100)
  {
  lcd.setCursor(6,0);
  lcd.print(sensorValue);
  lcd.setCursor(8,0);
  lcd.print("    ");
  }
  if(sensorValue>99)
  {
  lcd.setCursor(6,0);
  lcd.print(sensorValue);
  }
   if(sensorValue<301)
  {
  lcd.setCursor(0,1);
  lcd.print("dry soil       ");
  }
  if((sensorValue>300)&&(sensorValue<501))
  {
  lcd.setCursor(0,1);
  lcd.print("humid soil   ");
  }
     if(sensorValue>500)
  {
  lcd.setCursor(0,1);
  lcd.print("in water       ");
  }
  
  delay(1000);
}