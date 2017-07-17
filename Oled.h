#ifndef _Oled_h
#define _Oled_h
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define XPOS 0
#define YPOS 1

 #include "Arduino.h"

 class Oled{

  public:
  Oled();
  void setup();
  void println(char *msg);
 };

#endif

