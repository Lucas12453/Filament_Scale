#include "HX711.h"

HX711 scale;

//uint8_t dataPin = 6;
//uint8_t clockPin = 7;
uint8_t dataPin  = 3;//for esp32
uint8_t clockPin = 2;//for esp32

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int btnPin = 4;

int spltype = 1;
int bState;

void setup()
{ //ikhiih
  
 
  
  Serial.begin(115200);
  

  scale.begin(dataPin, clockPin);

 


  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

 scale.set_offset(448496);
 scale.set_scale(-216.049407); 
 pinMode (btnPin, INPUT_PULLUP);
 // 465022-213.831405
}
 

void loop () {

  bState = digitalRead (btnPin);  
  
  while (bState == LOW) {
    
    spltype++;
    
   display.clearDisplay();

  display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(60, 20);
 display.print(spltype);
 display.display ();
delay (1000);

    if (spltype > 3) { // i have theory on why i had to put this as spltype > 1, its because if it printed 2, the value would be 0 and the nw for 2 was a else statement not an else if, it still worked.
      //now, i might have to change it from else if 4 to just else.
      spltype = 0;
      }
    bState = digitalRead (btnPin);   
    
  }


float gw = scale.get_units(10);
int sw2 = 138;
int sw3 = 185;
int sw4 = 195;
int nw;


if (spltype == 1) {
  nw = (gw);                                       // test if works
}

else if (spltype == 2) {
  nw = (gw - sw2);
}
else if (spltype == 3) {
  nw = (gw - sw3);
}
else //if (spltype == 4) 
{
  nw = (gw - sw4);
}
  
if (nw == 0) {Serial.println (nw); }
if(nw < 0) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
 display.print("0");
 display.println (" g");


   display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 40);
 display.print("0");
 display.print (" m");
display.display ();
delay (100);
   
  }
else {
  int lengt = (nw/3);
  display.clearDisplay();

  display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
 display.print(nw);
 display.println (" g");


   display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 40);
 display.print(lengt);
 display.print (" m");
display.display ();
delay (100);
}
if (spltype == 0) {
  display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(100, 0);
 display.print(4);   //changed to display.print (4)
 display.display ();
}
else {
display.setTextSize(2); // Draw 1-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(100, 0);
 display.print(spltype);
 display.display ();
}
}
