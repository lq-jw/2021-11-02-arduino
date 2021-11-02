// For a connection via I2C using the Arduino Wire include:
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"

SSD1306Wire display(0x3c, 21, 22);   


void setup() {
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_24);
  pinMode(13, INPUT);
}

void loop() {
  display.clear();
  int input = analogRead(13);
  String myString = String(input);  
  display.drawString(0, 0, "Value");
  display.drawString(0, 30, myString);
  display.display();
  Serial.println(input);
}
