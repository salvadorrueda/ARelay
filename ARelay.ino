/*
 * ARelay. Arduino Relay with extras.
 * 
 */

#include "Relay.h"
#include "Button.h"
#include "BTSerial.h"
#include "Oled.h"

Relay relay(13);    // Relay attached on pin 13
Button button(2);   // Button attached on pin 2
BTSerial btserial(9600); // data rate bps
Oled oled;   

void setup() {
  relay.setup();  
  button.setup();
  btserial.setup();
  oled.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
  
  
  menu(btserial.BTread());

  if(relay.getState()) oled.println("ON");
  else oled.println("OFF");
  
  relay.writeState();
}

void menu(char op){
  switch(op){
    case 'h': menuHelp(); break;
    case 'o': relay.setState(1); break;
    case 'f': relay.setState(0); break;
    case 'c': relay.changeState(); break;
    
  }  
}

void menuHelp(){
  btserial.BTpintln("Help: ");
  btserial.BTpintln(" h. Show this help ");
  btserial.BTpintln(" o. Relay set ON ");
  btserial.BTpintln(" f. Relay set OFF ");
  btserial.BTpintln(" c. Change Relay state");
}
 


