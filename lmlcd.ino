#include <LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int val;
int tempPin =A0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature:");
Serial.begin(9600);}

void loop() {
  val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);

//uncomment this to get temperature in farenhite 
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
lcd.print(cel);
lcd.print("C/");
 lcd.setCursor(7, 1);
 lcd.print(farh);
lcd.print("F");}
 










