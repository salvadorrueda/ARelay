/*
  Button

 Turns on and off the relay, when a pushbutton attached to pin 2 is pressed.

 The circuit:
 * Relay attached to pin 9
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground


 Thanks to DojoDave and Tom Igoe for initial code.
 http://www.arduino.cc/en/Tutorial/Button

 This example code is in the public domain.


 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int Relay =  9;        // the number of the Relay pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;     // previous state of the button
int RelayState = 0;          // state of the Relay

void setup() {
  // initialize the Relay pin as an output:
  pinMode(Relay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
     // if the state has changed, increment the counter
     if (buttonState == HIGH) {
       // if the current state is HIGH then the button
       // wend from off to on:
       if(RelayState == 0){
         RelayState = 1;
       }else{
         RelayState = 0;
       }
     digitalWrite(Relay, RelayState);
     // Delay a little bit to avoid bouncing
     //  when the button is pressed
     delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;
}
 
