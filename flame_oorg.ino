int led1 = 2;
int led2 = 8;

int Buzzer = 7; // Use buzzer for alert 
int FlamePin = A0;  // This is for input pin
int Flame;  // HIGH when FLAME Exposed

void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(FlamePin, INPUT);
  Serial.begin(9600);
   pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT); 
  
}

void loop() {
  Flame = analogRead(FlamePin);
  Serial.println(Flame);
  if (Flame>400)
  { 
digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
       

    Serial.println("HIGH FLAME");
    digitalWrite(Buzzer, HIGH);
  delay(500);}
  else
  {
    Serial.println("No flame");

      digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(500);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);      
  }
 digitalWrite(Buzzer,LOW);}

