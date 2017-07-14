 
#ifndef _BTSerial_h
#define _BTSerial_h

 #include "Arduino.h"

 
class BTSerial{  
  char rxChar;        //  serial readings
  int bps = 9600;     // data rate 

  public:
  BTSerial(int bps);  // Button constructor initializes button object variables
  void setup();     // setup the button object
  char BTread();    // Returns char  
  void BTpintln(char *message);  // print
};

#endif

