#include "led.h"    
#include <stdlib.h>  


#define PIN_LED1 D5
#define PIN_LED2 D6//a changer 
#define PIN_LED3 D7
//#define PIN_LED4 D7
#define BRIGHTNESS 50

//constructeur 
led::led(){
  this->pin = PIN_LED2; 
  this->lane = 1; 
  this->pixels = new Adafruit_NeoPixel(10, this->pin, NEO_GRB + NEO_KHZ800);
  this->pixels->begin();
  this->brightness = 250; 
  this->pixels->setBrightness(this->brightness);
  this->pixels->show(); 
}

led::led(int pin, int lane, int brightness){
    this->pin = pin; 
    this->lane = lane; 
    this->pixels = new Adafruit_NeoPixel(10, this->pin, NEO_GRB + NEO_KHZ800);
    this->pixels->begin();
    this->brightness = brightness;  
    this->pixels->setBrightness(this->brightness);
    this->pixels->show(); 
}

led::led(int lane) {
  switch(lane) {
    this->lane = lane;
    case (1): 
      Serial.println("lane 1 - pin D3"); 
      Serial.flush();
      this->pin = PIN_LED1; 
      break;
    case (2):
      Serial.println("lane 2 - pin D5"); 
      Serial.flush();
      this->pin = PIN_LED2;
      break;
    case (3): 
      Serial.println("lane 3 - pin D6"); 
      Serial.flush();
      this->pin = PIN_LED3;
      break;
    //case (4): 
      //Serial.println("lane 1 - pin D7"); 
      //Serial.flush();
      //this->pin = PIN_LED4;
      //break;
    default : 
      Serial.println("no pin correspondance"); 
      Serial.flush(); 
      break; 
  }
  this->brightness = BRIGHTNESS;
  this->pixels = new Adafruit_NeoPixel(10, this->pin, NEO_GRB + NEO_KHZ800);
  this->pixels->begin();
  this->pixels->setBrightness(this->brightness);
  this->pixels->show(); 
}

    
//fonction pour allumer une led en fonction possition 
void led::allumer_led_pos(int pos){

  this->pixels->setPixelColor(pos, this->pixels->Color(0, 150, 0));
  this->pixels->show();
}

//eteindre led en fonction de la position pos
void led::eteindre_led_pos(int pos){
  this->pixels->setPixelColor(pos, this->pixels->Color(0, 0, 0));

  this->pixels->show();
}


//allumer led pos color 
void led::allumer_led_pos_color(int pos, int r, int g, int b){
  this->pixels->setPixelColor(pos, this->pixels->Color(r, g, b));
  this->pixels->show();
}

int led::get_numero(){
        return this->lane;
}
void led::allumer_gagnant(char gagnant){
    //int a = 1; //1 si attaquant est gagnant, 2 si défendeur est gagnant
    //a++;
  int deb_coul; 
  int fin_coul; delay(500);
  //fonction volé : theatre chase rainbow 
 
  for (int j = deb_coul; j < fin_coul; j++) {   // cycle all 256 colors in the wheel
      for (int q = 0; q < 3; q++) {
          for (uint16_t i = 0; i < this->pixels->numPixels(); i = i + 3) {
              pixels->setPixelColor(i + q, Wheel((i + j) % 255)); //turn every third pixel on
          }
          pixels->show();

          
          delay(50);

          for (uint16_t i = 0; i < this->pixels->numPixels(); i = i + 3) {
              this->pixels->setPixelColor(i + q, 0);      //turn every third pixel off
          }
      }
  }
  
} 

//fonction pour envoyer une balle couleur aléatoire
void led::envoyer_balle(int vitesse){
  //generation couleur random
  int a = rand()%150;
  int b = rand()%150;
  int c = rand()%150;
    
  //envoie balle
  for(int i=0; i<10; i++) { // For each pixel...
    this->pixels->setPixelColor(i, this->pixels->Color(a, b, c));
    this->pixels->show();   //Send the updated pixel colors to the hardware.
    delay(vitesse);      //temps en milliseconde - Pause before next pass through loop
  } 
  this->pixels->setPixelColor(2, this->pixels->Color(0, 0, 0));
        
}


//fonction volé 
uint32_t led::Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return this->pixels->Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
    }
    if (WheelPos < 170) {
        WheelPos -= 85;
        return this->pixels->Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    WheelPos -= 170;
    return this->pixels->Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}
