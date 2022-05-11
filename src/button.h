#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class button {
  private: 
    int lane; 
    int pin; 
    int val; //(HIGH si bouton pas appuyé, LOW si bouton appuyé)
    int a; //1 si attaquant, 0 si défendeur 
  public: 
    //constructeur 
    button(int lane, int a); //ajouter si attaquant ou défendeur 

    //initialisation des pins
    //void init_pin(); 

    //val button 
    bool get_button(); //1 si appuyé 
  
};

#endif