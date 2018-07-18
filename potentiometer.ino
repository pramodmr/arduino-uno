 /* Learn how to use a potentiometer to fade an LED with Arduino - Tutorial
   More info and circuit schematic: http://www.ardumotive.com/arduino-tutorials/arduino-fade-led
   Dev: Michalis Vasilakis / Date: 25/10/2014                                                   */
   

//Constants:
const int ledPin = 11;  //pin 9 has PWM funtion
const int potPin = A0; //pin A0 to read analog input
int buzzerPin = 9; //Define buzzerPin
int value;
void setup(){
  //Input or output?
  pinMode(ledPin, OUTPUT); 
  pinMode(potPin, INPUT); //Optional 
Serial.begin(9600);
 pinMode(buzzerPin, OUTPUT); //Set buzzerPin as output
  //beep(50); //Beep
 // beep(50); //Beep
  delay(1000); //Add a little delay

}

void loop(){
  
  value = analogRead(potPin);          //Read and save analog value from potentiometer
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);                          //Small delay
 Serial.println(value); 
beep(50); //Beep every 500 milliseconds
  delay(500);
 beep(50); //Beep every 500 milliseconds
  delay(500);
}

void beep(unsigned char delayms) { //creating function
  analogWrite(buzzerPin, 191); //Setting pin to high
 // delay(delayms); //Delaying
  //analogWrite(buzzerPin); //Setting pin to LOW
  //delay(delayms); //Delaying
  
}
                           
