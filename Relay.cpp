
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
  }

  void Relay::setState(int state){
    relayState = state;
  }

  int Relay::getState(){
    return relayState;
  }

  void Relay::writeState(){
    digitalWrite(relayPin, relayState);
  }

  void Relay::setRelayStateToMessage(char *message){
    
    if(relayState) {
      message[7]='N'; 
      message[8]=' ';
    }else{
      message[7]='F';
      message[8]='F';
    }
  }
 


