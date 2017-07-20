#include "Arduino.h"
#include "AEEPROM.h"

void AEEPROM::eget(char *amessage){
  // Read from the EEPROM and set the Alarm
  EEPROM.get(eeAddress, EAlarm);

  for(int i=0; i<5; i++){
    amessage[i] = EAlarm.alarm[i];
  }
  
  if(EAlarm.ARelayState){
    amessage[5] = 'o';
  }else{
    amessage[5] = 'f';
  }

}

void AEEPROM::eput(char *amessage){
  
  for(int i=0; i<5; i++){
    EAlarm.alarm[i] = amessage[i];
  }
  
  if(amessage[5] == 'o'){
    EAlarm.ARelayState = 1;
  }else{ // amessage[5] = 'f';
    EAlarm.ARelayState = 0;
  }
  
  EEPROM.put(eeAddress, EAlarm);
}

