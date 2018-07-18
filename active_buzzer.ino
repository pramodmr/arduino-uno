int buzzerPin = 8; //Define buzzerPin

void setup() {
  pinMode(buzzerPin, OUTPUT); //Set buzzerPin as output
  beep(50); //Beep
  beep(50); //Beep
  delay(1000); //Add a little delay

}

void loop() {  beep(500); //Beep every 500 milliseconds

}

void beep(unsigned char delayms) { //creating function
  digitalWrite(buzzerPin,HIGH); //Setting pin to high
  delay(delayms); //Delaying
  digitalWrite(buzzerPin ,LOW); //Setting pin to LOW
  delay(500); //Delaying
  }

