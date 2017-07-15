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

void setup() {
  relay.setup();  
  button.setup();
  btserial.setup();
  oled.setup();
  rtc.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
  
  
  menu(btserial.BTread());

 //char *ntime = "00:00 ON  06:00 > OFF";
 
 String nSHourMinute = "00:00";
 char nCHourMinute[6] = "00:00";
 
 char *ntime = "00:00 ON  06:00 > OFF";

 
 nSHourMinute = rtc.getHourTime();
 nSHourMinute.toCharArray(nCHourMinute,6);

 //for(int i=0;i<6;i++) ntime[i] = nCHourMinute[i];

  if(relay.getState()) {
    ntime[7]='N'; 
    ntime[8]=' ';
  }else{
    ntime[7]='F';
    ntime[8]='F';
  }

 oled.println(ntime);    
 /*
  if (RTC.read(tm)) {
      n0Hour = tm.Hour/10;
      n1Hour = tm.Hour-(n0Hour*10);

      n0Minute = tm.Minute/10;
      n1Minute = tm.Minute-(n0Minute*10);
       
      ntime[0]=n0Hour+'0';    
      ntime[1]=n1Hour+'0';
      ntime[3]=n0Minute+'0';
      ntime[4]=n1Minute+'0';

 

   
    oled.println(ntime);    
  }

*/
  
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


