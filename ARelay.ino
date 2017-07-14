/*
 * ARelay. Arduino Relay with extras.
 * 
 *  Button. ON/OFF the Relay
 */

#include "Relay.h"
#include "Button.h"
#include "BTSerial.h"

Relay relay(13);    // Relay attached on pin 13
Button button(2);   // Button attached on pin 2
BTSerial btserial(9600); // data rate bps


void setup() {
  relay.setup();  
  button.setup();
  btserial.setup();
}

char op;
void loop() {
  if(button.pressed()) relay.changeState();
  
  op = btserial.BTread();
        if( op == 'A' )
        {
            digitalWrite(13, HIGH);
            Serial.println("ON");
            relay.setState(1);
        }
        else if ( op == 'a' )
        {
            digitalWrite(13, LOW);
            Serial.println("OFF");
            relay.setState(0);
        }
  relay.writeState();
}
 
