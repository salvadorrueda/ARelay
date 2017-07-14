
 #include "Arduino.h"
 #include "BTSerial.h"
 
  BTSerial::BTSerial(int bps){
    bps = bps;
  } 

  void BTSerial::setup(){
    // initialize the speed of the serial line
      Serial.begin(bps);
  }

  char BTSerial::BTread(){
    char rxChar = ' ';
    if(Serial.available()){
      rxChar = Serial.read();
    }
    return rxChar;
  }

  void BTSerial::BTpintln(char *message){
    Serial.println(message);
  }



