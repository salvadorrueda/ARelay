 #include "Arduino.h"
 #include "ARTC.h"

  void ARTC::setHourTimeToMessage(char *message){
    int n0Hour, n1Hour, n0Minute, n1Minute; 
    
    if (RTC.read(tm)) {
      n0Hour = tm.Hour/10;
      n1Hour = tm.Hour-(n0Hour*10);

      n0Minute = tm.Minute/10;
      n1Minute = tm.Minute-(n0Minute*10);
       
      message[0]=n0Hour+'0';    
      message[1]=n1Hour+'0';
      message[3]=n0Minute+'0';
      message[4]=n1Minute+'0';
    }    
  }


