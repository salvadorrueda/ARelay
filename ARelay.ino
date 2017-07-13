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

void setup() {
  // initialize the Relay pin as an output:
  pinMode(Relay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn Relay on:
    digitalWrite(Relay, HIGH);
  } else {
    // turn Relay off:
    digitalWrite(Relay, LOW);
  }
}
 
