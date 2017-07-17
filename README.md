# ARelay
ARelay is an Arduino Relay with some extras.

The relay can be turned ON/OFF by pressing the button.

It can also be done by using the serial connection with an app like Bluetooth terminal. Using serial you can interact with ARelay and program an alarm to turn on or off the relay.  

A good start is to send "hi" without quotes.
ARelay will respond with something like this:

  h. Show this help
  i. ARelay info
  o. Relay set ON
  f. Relay set OFF ");
  c. Change Relay state ");
  a. Alarm Relay. Ex a06:00o. Alarm at 6:00 relay ON
  12:34 OFF  ALARM > OFF

Note that you are sending two commands 'h' for help and 'i' for info.

V1.0

Hardware:
 Arduino Nanno
 Relay
 Button ON/OFF the Relay
 HC-06 Serial Bluetooth
 Oled 0.96 128x64 SSD1306 I2C
 RTC DS1307

Improvements
 Store the alarm on the Arduino's EEPROM



Documentation & Resources:
Thanks to people that helped me with their publications.

Arduino the Object Oriented way
http://paulmurraycbr.github.io/ArduinoTheOOWay.html

Creating Classes in C for Arduino
http://polygondoor.com.au/creating-classes-in-c-for-arduino/
