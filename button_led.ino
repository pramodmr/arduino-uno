/* Learn to use pushbutton (button switch) with Arduino - Tutorial
   More info and circuit schematic: http://www.ardumotive.com/arduino-tutorials/category/button
   Dev: Michalis Vasilakis / Date: 19/10/2014  
   UPDATED 2/6/2016 - LED to Arduino pin 3 and button to Arduino pin 4*/



int value=0;
const int buttonPin = 7;     
const int ledPin =  13;     
int buttonState = 0;
int flag=0;
int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"


void setup() {
  //Input or output?
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);   
 Serial.begin(9600);
  pinMode(buttonPin,INPUT);   
 pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
}

void loop(){
  //Read button state (pressed or not pressed?)
  buttonState = digitalRead(buttonPin);
  //If button pressed...
  if (buttonState == LOW) 
  { //...ones, turn led on!
    if ( flag == 0)
    {
      Serial.println("sss");
      digitalWrite(ledPin, HIGH);
      flag=1;
      turnOff();
      //change flag variable
      }
    //...twice, turn led off!
    else if ( flag == 1)
    {
      digitalWrite(ledPin,LOW);
      value=value+1;
      if(value > 9)
      {
        Serial.println("aeddd");
        value=0;
      }
      displayDigit(value); 
      flag=0; //change flag variable again 
  }}
  delay(200);   
} 
void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
  //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
digitalWrite(g,HIGH);
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
} 
