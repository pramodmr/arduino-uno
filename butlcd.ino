#include<LiquidCrystal.h>

int state1 = 0; //initialize push button state
int state2 = 0;
int pb1 = 8; //initialize push button state
int pb2 = 7;
unsigned long int flag = 0;
unsigned long int flag1 = 0;
unsigned long int flag2 = 0;
// initialize the library with the numbers of the interface pins
unsigned long int value1 = 0;
unsigned long int value2 = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int interval = 20000;
unsigned long previousMillis = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pb1, INPUT); //set pb as input
  pinMode(pb2, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  //clear LCD
  lcd.print("USER1-RED");
  delay(1000);
  lcd.clear();
  lcd.print("USER2-YELLOW");
  delay(1000);
  lcd.clear();
}


void loop()
{
  unsigned long currentMillis = millis();
  state1 = digitalRead(pb1);
  state2 = digitalRead(pb2);
  if ((unsigned long)(currentMillis - previousMillis) <= interval)
  {
    lcd.noBlink();
    lcd.setCursor(0, 0);
    if (state1 == LOW)
    {
      if ( flag1 == 0)
      {
        flag1 = 1;
      }
      else if ( flag1 == 1)
      {
        Serial.println("sss");
        value1 = value1 + 1;
        flag1 = 0;
      }
    }
    if (state2 == LOW)
    {
      if ( flag2 == 0)
      {
        flag2 = 1;
      }
      else if ( flag2 == 1)
      { Serial.println("saaaaaass");
        value2 = value2 + 1;
        flag2 = 0;
      }
    }
    lcd.print("user1:");
    lcd.print(value1);
    lcd.setCursor(0, 1);
    lcd.print("user2:");
    lcd.print(value2);
    delay(50);
  }
  else {
    lcd.clear();
    if (value1 > value2)
    {
      lcd.print("WINNER-USER1");
      delay(2000);
    }
    else if (value1 == value2)
    {
      lcd.print("DRAW");
      delay(2000);
    }
    else if(value1 == value2 && value1>0 && value2>0)
    {
    lcd.print("PLZ...START!");
    delay(2000);
    }
    else
    {
      lcd.print("WINNER-USER2");
      delay(2000);
    }
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("HOLD BUTTON TO");
    lcd.setCursor(5, 1);
    lcd.print("RESTART");
    delay(2000);
    if (state1 == LOW || state2 == LOW)
    {
      previousMillis = millis();
      value1 = 0;
      value2 = 0;
      flag = 0;
      lcd.begin(16, 2);
      lcd.print("3...");
      delay(1000);
      lcd.clear();
      lcd.print("2..");
      delay(1000);
      lcd.clear();
      lcd.print("1.");
      delay(1000);
      lcd.clear();
      lcd.print("GO........");
      delay(1000);
      lcd.clear();
    }
  }
}




