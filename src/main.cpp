#include "monApplication.h"
#include <Arduino.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

MonApplication app; 

void setup() {
  
  Serial.begin(9600); 
  while (!Serial);
  //pinMode(D1, INPUT);
  app.Init();
  
}

void loop() {
   app.Loop();

}