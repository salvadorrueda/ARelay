/*
 * ARelay. Arduino Relay with extras.
 *
 */

#include "Relay.h"
#include "Button.h"
#include "BTSerial.h"
#include "Oled.h"
#include "ARTC.h"
#include "AEEPROM.h"

Relay relay(9);    // Relay attached on pin 9
Button button(2);   // Button attached on pin 2
BTSerial btserial(9600); // data rate bps
Oled oled;
ARTC rtc;
AEEPROM eeprom;

char message[23] = "00:00 ON  06:00 > OFF.";
                 // 012345678901234567890 1rs line oled display
                 
char amessage[7] = "EEPROM"; // "06:00o"; // alarm readed from EEPROM or BT Serial 

void setup() {
  relay.setup();
  button.setup();
  btserial.setup();
  oled.setup();
  eeprom.eget(amessage); // Read the Alarm stored in the EEPROM
  msetAlarmRelay('e');   // Set the 'e' Alarm readed from the EEPROM in ARelay

}

void loop() {
  // if the button is pressed change the state of the Relay.
  if(button.pressed()) relay.changeState();

  // read from the Serial line an then execute then command.
  menu(btserial.BTread());

  // if it is Alarm time then set the Relay to the AlarmRelayState.
  if(rtc.checkAlarm())
   relay.setState(rtc.getAlarmRelayState());

  // set the Hour and Minutes to the message variable.
  rtc.setHourTimeToMessage(message);

  // set the Relay State to the message variable.
  relay.setRelayStateToMessage(message);

  // display message on oled screen.
  oled.println(message);

  // digitalWrite on relayPin the relayState.  
  relay.writeState();
}

void menu(char op){
  switch(op){
    case 'h': menuHelp(); break;
    case 'o': relay.setState(1); break;
    case 'f': relay.setState(0); break;
    case 'c': relay.changeState(); break;
    case 'i': btserial.BTprintln(message);break;
    case 'a': msetAlarmRelay('a'); break;
  }
}

void menuHelp(){
  btserial.BTprintln("Help: ");
  btserial.BTprintln(" h: Show this help ");
  btserial.BTprintln(" i: ARelay info ");
  btserial.BTprintln(" o: Relay set ON ");
  btserial.BTprintln(" f: Relay set OFF ");
  btserial.BTprintln(" c: Change Relay state ");
  btserial.BTprintln(" a: Alarm Relay Ex a06:00o Alarm at 6:00 relay ON.");
}


 void msetAlarmRelay(char a){
  // 'a' option from menu has been selected.
  // 'e' option for reading alarm from EEPROM
  
  //a. Alarm Relay. Ex a06:00o. Alarm at 6:00 relay ON

  char c;
  //char sAlarm[6] = "00:00";
  
  if(a=='a'){   
    for (int i=0; i<6; i++){
      do{
        amessage[i] = btserial.BTread();
      }while(amessage[i] == ' ');
      // sometimes there are not data avaible and 
      // btserial.BTread() returns ' '.      
    } //else  (a == 'e') // Called from setup reading alarm from EEPROM
  }
  
  rtc.setAlarmRelay(amessage);

  // Read the Relay State must be set when the Alarms triggers
  //c = btserial.BTread();
  c = amessage[5];
  if( c == 'o') {
    rtc.setAlarmRelayState(1);
  }
  else if (c == 'f'){
    rtc.setAlarmRelayState(0);
  }

  // Write to EEPROM
  eeprom.eput(amessage);
}
