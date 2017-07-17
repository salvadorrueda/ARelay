 #include "Arduino.h"
 #include "Oled.h"
 
 #define OLED_RESET 4
 Adafruit_SSD1306 display(OLED_RESET);

 
 Oled::Oled(){
  }

  void Oled::setup(){

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  }

  void Oled::println(char *msg){
    display.clearDisplay();
    // text display tests
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println(msg);
    display.display();       
  }

