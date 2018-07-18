int sensePin  = A0;
int ledPin = 2;
int buzzerPin = 7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzerPin, OUTPUT);
pinMode(ledPin,OUTPUT);
 beep(50); //Beep
  beep(50); //Beep
  delay(1000); //Add a little delay
}

void loop() { 
  int val = analogRead(sensePin);
  Serial.println(val);
  
  if(val<600)
  {
    beep(1000);
digitalWrite(ledPin, HIGH);   
 delay(2000);
 digitalWrite(ledPin,LOW);
 delay(2000);}
 // wait for a second
  }
  // put your main code here, to run repeatedly:


void beep(unsigned char delayms) { //creating function
  digitalWrite(buzzerPin,HIGH); //Setting pin to high
  delay(delayms); //Delaying
  digitalWrite(buzzerPin ,LOW); //Setting pin to LOW
  delay(500); //Delaying
}
