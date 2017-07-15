
 #include "Arduino.h"
 #include "ARTC.h"

 
  ARTC::ARTC(){
    int nHour=9;
  }

  void ARTC::setup(){
    int nHour=9;
    
  }

  String ARTC::getHourTime(){
    char *ntimes = "00:00 ON  06:00 > OFF";
    int nHour, nMinute, n0Hour, n1Hour, n0Minute, n1Minute; 
    //String nSHourMinute(ntime);
    String nSHourMinute;
    
    if (RTC.read(tm)) {
      n0Hour = tm.Hour/10;
      n1Hour = tm.Hour-(n0Hour*10);

      n0Minute = tm.Minute/10;
      n1Minute = tm.Minute-(n0Minute*10);
       
      ntimes[0]=n0Hour+'0';    
      ntimes[1]=n1Hour+'0';
      ntimes[3]=n0Minute+'0';
      ntimes[4]=n1Minute+'0';

//nSHourMinute(ntime);
    }
    
    return nSHourMinute;
  }


