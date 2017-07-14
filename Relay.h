#ifndef _Relay_h
#define _Relay_h

 #include "Arduino.h"

 class Relay{
  int relayPin;        // the number of the Relay pin  
  
  int relayState;    // state of the Relay
  
  public:
  Relay(int pin);
  void setup();
  void changeState();
  void setState(int state);
  int getState();
  void writeState();
 };

#endif

