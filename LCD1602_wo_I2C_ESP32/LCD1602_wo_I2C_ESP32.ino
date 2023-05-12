// ESP32 Dev Module 

#include <LiquidCrystal.h>
 
// init with used interface pins
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
 
void setup() {
  // Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Test :-)");
}
 
void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  // give wifi time to operate
  delay(200);
}