
 #include "Arduino.h"
 #include "Relay.h"

 
 Relay::Relay(int pin){
    relayPin = pin;
    relayState = 0;
  }

  void Relay::setup(){
    // initialize the Relay pin as an output:
    pinMode(relayPin, OUTPUT);  
  }

  void Relay::changeState(){
    if(relayState == 0){
      relayState = 1;    
    }else{
      relayState = 0;
    }
    digitalWrite(relayPin, relayState);
  }



