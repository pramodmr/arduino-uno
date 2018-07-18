#include <IRremote.h>     
const int ledPin1 =  4;     
const int ledPin2 =  7; 
const int ledPin3 =  8; 
int RECV_PIN = 11;
int flag1=0;
int flag2 =0;
int flag3 =0;
IRrecv irrecv(RECV_PIN);

decode_results results;
//Variables
void setup() {
  //Input or output?
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);      
  pinMode(ledPin3, OUTPUT); 
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop(){
  if (irrecv.decode(&results))
   {
    if(results.value == 16724175)
    {Serial.println("results.value");
    if ( flag1 == 0){
      digitalWrite(ledPin1, HIGH);
      flag1=1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag1 == 1){
      digitalWrite(ledPin1, LOW);
      flag1=0; //change flag variable again 
    }
    delay(50);
    irrecv.resume(); // Receive the next value
  }
   if(results.value == 16718055)
   {Serial.println("results.value");
    if ( flag2 == 0){
      digitalWrite(ledPin2, HIGH);
      flag2=1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag2 == 1){
      digitalWrite(ledPin2, LOW);
      flag2=0; //change flag variable again 
    }    
    delay(50);
    irrecv.resume(); // Receive the next value
  }
  if(results.value == 16743045)
{
   {
    if ( flag3 == 0){
      digitalWrite(ledPin3, HIGH);
      flag3=1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag3 == 1){
      digitalWrite(ledPin3, LOW);
      flag3=0; //change flag variable again 
    }    
    delay(50);
    irrecv.resume(); // Receive the next value
  }}
  delay(200);}} //Small delay
