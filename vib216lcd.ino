#include <LiquidCrystal.h>
 const int buzzer = 7; //Buzzer connected to pin 8 of Arduino uno / mega
int sensor;           //Variable to store analog value (0-1023)
unsigned long int time;
int i;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Serial.begin(9600);      //Only for debugging
  pinMode(buzzer, OUTPUT);
lcd.begin(16, 2);
  // Print a message to the LCD.
  }

void loop()
{
  sensor = analogRead(A0);
  //While sensor is not moving, analog pin receive 1023~1024 value
  if (sensor<1022){
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  time=millis();
 while(time<=10000){
  tone(buzzer, 1000,1000);
   lcd.setCursor(0, 1);
  lcd.print("Area Breached");
  delay(100);
  lcd.clear();
  delay(300);
 }
 }
  
  else{ 
    noTone(buzzer);
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
  lcd.begin(16, 2); }
   
  
  delay(100); //Small delay
}



