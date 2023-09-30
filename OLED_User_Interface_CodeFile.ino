#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
    display.setTextSize(1);           // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("The model features a self-driving vehicle running on Arduino   Nano");
  display.display();
  delay(5000); // Pause for 2 seconds
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("This vehicle uses theHC-SR04 ultrasonic   sensors to stay");
  display.display();
  delay(5000); // Pause for 2 seconds
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("on a specific path.  The unique part of   this project is that the");
  display.display();
  delay(5000); // Pause for 2 seconds
  display.clearDisplay();  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("robot stops if it    detects that another vehicle is in front  of it");
  display.display();
  delay(5000); // Pause for 2 seconds
  display.clearDisplay();   
}
