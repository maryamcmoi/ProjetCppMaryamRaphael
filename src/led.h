#ifndef LED_H
#define LED_H
#include "Adafruit_NeoPixel.h"
#include <Arduino.h>


/*#ifdef __AVR__
    #include <avr/power.h>
#endif
*/

//class LED 
class led {
  private: 
    int lane; 
    int pin;
    int pos; 
    int brightness; 
    Adafruit_NeoPixel *pixels; 
    

public: 
//constructeur 
    led(); 
    led(int pin, int lane, int brightness); 
    led(int lane); 
   
//fonction pour allumer LEd en fonction position et en fonction couleur
    void allumer_led_pos_color(int pos, int r, int g, int b); 
    
//fonction pour allumer une led en fonction possition 
    void allumer_led_pos(int pos); //en vert pour le moment

//fonction pour etteindre la led en fonction de la position 
    void eteindre_led_pos(int pos); 

//fonction pour allumer toutes les leds en même temps en mode guirlande pour signaler qui est le gagnant 
    void allumer_gagnant(char gagnant); //a si attaquant est gagnant, d si défendeur est gagnant
    uint32_t Wheel( byte WheelPos); 

//fonction pour envoyer une balle couleur aléatoire en fonction vitesse en milliseconde
    void envoyer_balle(int vitesse); 

    int get_numero();
    




};

#endif