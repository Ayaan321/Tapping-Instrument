  int ledPin = 13;
  
 
  int sensorPin = A0; 
  

  int tapThreshold = 50;
  


int tapTally = 0; 
void setup() {
 pinMode(ledPin, OUTPUT); /
}

void loop() {

  if (analogRead(sensorPin) > tapThreshold) {
    tapTally++; 
    digitalWrite(ledPin, HIGH); 
    delay(250); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  /
  if (tapTally == 3) {
    digitalWrite(ledPin, HIGH); 
    pinMode(sensorPin, OUTPUT); 

    play(262); 
    play(196);
    play(196);
    play(220);
    play(196);
    
    delay(250);
    
    play(247);
    play(262);
    
    tapTally = 0; 
    pinMode(sensorPin, INPUT);   }
}

void play(int hz) {
  tone(sensorPin, hz);
  delay(250);
  
  noTone(sensorPin); 
  delay(50);
}
