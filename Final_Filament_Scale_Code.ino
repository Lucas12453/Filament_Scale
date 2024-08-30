#include "HX711.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

HX711 scale;

const int btnPin = 4;
int spoolType = 1; // 1 = 0g; 2 = 138g; 3 = 185g; 4 = 195g
int btnState;
uint8_t dataPin  = 3;
uint8_t clockPin = 2;

void setup() {
  Serial.begin(115200);
  scale.begin(dataPin, clockPin);
  scale.set_offset(443979);
  scale.set_scale(-216.237655);
  pinMode (btnPin, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
}

void loop () {
  btnState = digitalRead (btnPin);

  while (btnState == LOW) {
    spoolType++;
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 20);
    display.print(spoolType);
    display.display ();
    delay (1000);

    if (spoolType > 3) {
      spoolType = 0;
    }

    btnState = digitalRead (btnPin);
  }

  float totalWeight = scale.get_units(10);
  int spoolWeight2 = 138;
  int spoolWeight3 = 185;
  int spoolWeight4 = 195;
  int filamentWeight;

  if (spoolType == 1) {
    filamentWeight = (totalWeight);
  }
  else if (spoolType == 2) {
    filamentWeight = (totalWeight - spoolWeight2);
  }
  else if (spoolType == 3) {
    filamentWeight = (totalWeight - spoolWeight3);
  }
  else {
    filamentWeight = (totalWeight - spoolWeight4);
  }

  if (filamentWeight == 0) {
    Serial.println (filamentWeight);
  }

  if (filamentWeight < 0) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("0");
    display.println (" g");

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 40);
    display.print("0");
    display.print (" m");
    display.display ();
    delay (100);
  }
  else {
    int filamentLength = (filamentWeight / 3);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(filamentWeight);
    display.println (" g");

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 40);
    display.print(filamentLength);
    display.print (" m");
    display.display ();
    delay (100);
  }

  if (spoolType == 0) {
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(100, 0);
    display.print(4);
    display.display ();
  }
  else {
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(100, 0);
    display.print(spoolType);
    display.display ();
  }
}
