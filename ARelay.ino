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

char ntime[22] = "00:00 ON  06:00 > OFF";


void setup() {
  relay.setup();  
  button.setup();
  btserial.setup();
  oled.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
  
  menu(btserial.BTread());
   
  rtc.getHourTime(ntime);
  getRelayState(ntime);
  
 oled.println(ntime);    
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
void getRelayState(char *ntime){
   if(relay.getState()) {
    ntime[7]='N'; 
    ntime[8]=' ';
  }else{
    ntime[7]='F';
    ntime[8]='F';
  }
}

