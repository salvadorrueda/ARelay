/*
 * 
 Moving to OOP thanks to http://paulmurraycbr.github.io/ArduinoTheOOWay.html
 Splitting in different files http://polygondoor.com.au/creating-classes-in-c-for-arduino/
 */

#include "Button.h"

class Relay{
  int relayPin;        // the number of the Relay pin  
  
  int relayState;    // state of the Relay
  
  public:
  Relay(int pin){
    relayPin = pin;
    relayState = 0;
  }

  void setup(){
    // initialize the Relay pin as an output:
    pinMode(relayPin, OUTPUT);  
  }

  void changeState(){
    if(relayState == 0){
      relayState = 1;    
    }else{
      relayState = 0;
    }
    digitalWrite(relayPin, relayState);
  }
};



Relay relay(13);
Button button(2);

void setup() {
  relay.setup();  
  button.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
}
 
