/*
  Button OOP (Object Oriented Programming)

 Turns on and off the relay, when a pushbutton attached to pin 2 is pressed.

 The circuit:
 * Relay attached to pin 9
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 Moving to OOP thanks to http://paulmurraycbr.github.io/ArduinoTheOOWay.html
 */

class Relay{
  int relayPin;        // the number of the Relay pin  
  
  int relayState;    // state of the Relay
  
  public:
  Relay(int pin){
    relayPin = pin;
    relayState = 0;
  }

  void setup(){
    // initialize the Relay pin as an output:
    pinMode(relayPin, OUTPUT);  
  }

  void changeState(){
    if(relayState == 0){
      relayState = 1;    
    }else{
      relayState = 0;
    }
    digitalWrite(relayPin, relayState);
  }
};


class Button{  
  int buttonPin;     // the number of the pushbutton pin

  // variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status    
  unsigned long buttonDownMs;  // to avoid bouncing recording number of ms button is down


  public:
  Button(int pin){
    buttonPin = pin;
    
    buttonState = LOW;         // variable for reading the pushbutton status    
  }

  void setup(){
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
  }

  int pressed(){
    // Returns 1 if the button is pressed
    
    int pressed = 0;
    int lastButtonState = buttonState;     // previous state of the button
    
    buttonState = digitalRead(buttonPin);
    if (lastButtonState == HIGH && buttonState == LOW){
      buttonDownMs = millis();
    }else if (lastButtonState == LOW && buttonState == HIGH){
      if (millis() - buttonDownMs < 50){
        // ignore this for debonce
      }else{
        pressed = 1;
      }   
    }
    return pressed;
  }
};


Relay relay(13);
Button button(2);

void setup() {
  relay.setup();  
  button.setup();
}

void loop() {
  if(button.pressed()) relay.changeState();
}
 
