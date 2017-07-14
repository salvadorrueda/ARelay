/*
 * ARelay. Arduino Relay with extras.
 * 
 *  Button. ON/OFF the Relay
 */

#include "Relay.h"
#include "Button.h"


Relay relay(13);  // Relay attached on pin 13.
Button button(2); // Button attached on pin 2.

void setup() {
  relay.setup();  
  button.setup();
}

int i = 0;
void loop() {
  if(button.pressed()) relay.changeState();
  
  relay.writeState();
}
 
