/* Wind Speed Sensor 0~5V Voltage Type (JL-FSX2) [S163] : http://rdiot.tistory.com/64 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S163:WindSpeed");

  int sensorValue = analogRead(A0);
  float outvoltage = sensorValue * (5.0 / 1023.0);

  lcd.setCursor(0,1);
  lcd.print("outvoltage=" + (String)outvoltage + "V  ");

  int Level = 6*outvoltage;//The level of wind speed is proportional to the output voltage.

  lcd.setCursor(0,2);
  lcd.print("wind speed " + (String)Level + " Level");

  delay(500);

}
