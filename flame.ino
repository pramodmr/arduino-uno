int ledg =12;
int ledr2 = 8;
int ledr1 = 7;
int buzzerPin = 13; //Define buzzerPin
/* Flame Sensor analog example.
Code by Reichenstein7 (thejamerson.com)

Flame Sensor Ordered from DX ( http://www.dx.com/p/arduino-flame-sensor-for-temperature-
detection-blue-dc-3-3-5v-118075?tc=USD&gclid=CPX6sYCRrMACFZJr7AodewsA-Q#.U_n5jWOrjfU )

To test view the output, point a serial monitor such as Putty at your arduino. 
*/

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:

 
Serial.begin(9600);  
pinMode(buzzerPin, OUTPUT);
pinMode(ledg, OUTPUT);   
  pinMode(ledr1, OUTPUT); 
  pinMode(ledr2, OUTPUT); 

}
void loop() {
  // read the sensor on analog A0:
	int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close Fire **");
    beep(50); //Beep
    beep(50); //Beep
    digitalWrite(ledr1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(ledr1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
digitalWrite(ledr2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(ledr2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second

    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire **");
    beep(50); //Beep
    beep(50); //Beep
    digitalWrite(ledr1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(ledr1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second

    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    digitalWrite(ledg, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(ledg, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second

    break;
  }
  delay(1);  // delay between reads
}
void beep(unsigned char delayms) { //creating function
  digitalWrite(buzzerPin,HIGH); //Setting pin to high
  delay(delayms); //Delaying
  digitalWrite(buzzerPin ,LOW); //Setting pin to LOW
  delay(500); //Delaying
  }
