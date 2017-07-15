/*
 * ARelay. Arduino Relay with extras.
 * 
 */

#include "Relay.h"
#include "Button.h"
#include "BTSerial.h"
#include "Oled.h"
#include "ARTC.h"

Relay relay(13);    // Relay attached on pin 13
Button button(2);   // Button attached on pin 2
BTSerial btserial(9600); // data rate bps
Oled oled;   
ARTC rtc;

char message[22] = "00:00 ON  06:00 > OFF";


void setup() {
  relay.setup();  
  button.setup();
  btserial.setup();
  oled.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
  
  menu(btserial.BTread());
   
  rtc.setHourTimeToMessage(message);
  relay.setRelayStateToMessage(message);
  
  oled.println(message);    
  relay.writeState();
}

void menu(char op){
  switch(op){
    case 'h': menuHelp(); break;
    case 'o': relay.setState(1); break;
    case 'f': relay.setState(0); break;
    case 'c': relay.changeState(); break;
    case 'i': btserial.BTprintln(message);break;
    
  }  
}

void menuHelp(){
  btserial.BTprintln("Help: ");
  btserial.BTprintln(" h. Show this help ");
  btserial.BTprintln(" o. Relay set ON ");
  btserial.BTprintln(" f. Relay set OFF ");
  btserial.BTprintln(" c. Change Relay state");
  btserial.BTprintln(" i. ARelay info");
}
 


