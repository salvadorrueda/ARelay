#ifndef _ARTC_h
#define _ARTC_h

#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include "Arduino.h"

 class ARTC{
  tmElements_t tm; 
  
  public:
  void setHourTimeToMessage(char *message);
 };

#endif

