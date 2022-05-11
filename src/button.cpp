#include "button.h"
//correspondance pin et boutons 
#define PIN_BA1 D4 
#define PIN_BA2 D8
#define PIN_BA3 D1
#define PIN_BD1 D2
#define PIN_BD2 D3
#define PIN_BD3 D0


//constructeur 
button::button(int lane, int a){
  this->lane=lane; 
  //definition de la valeur du pin
  switch(lane){
    case(1): 
      if (a == 1) {
        this->pin = PIN_BA1;
        pinMode(PIN_BA1, INPUT); 
      } else {
        this->pin = PIN_BD1;
        pinMode(PIN_BD1, INPUT); 
      }      
      break;   
    case(2):
      if (a == 1) {
        this->pin = PIN_BA2;
        pinMode(PIN_BA1, INPUT); 
      } else {
        this->pin = PIN_BD2;
        pinMode(PIN_BD2, INPUT); 
      }      
      break;   
    case(3): 
      if (a == 1) {
        this->pin = PIN_BA3;
        pinMode(PIN_BA3, INPUT); 
      } else {
        this->pin = PIN_BD3;
        pinMode(PIN_BD3, INPUT); 
      }      
      break;
      
    case(4): 
      if (a == 1) {
        this->pin = PIN_BA3;
        pinMode(PIN_BA3, INPUT); 
      } else {
        this->pin = PIN_BD3;
        pinMode(PIN_BD3, INPUT); 
      }      
      break;
     
    default: 
      break; 
  }
}


//val_button
bool button::get_button(){
  this->val = digitalRead(this->pin); 
  if (this->val == LOW) return 1 ;  //quand on appuie sur le bouton on est en LOW; le bouton par default est en HIGH 
  else return 0; 
}

 

//destructeur?? 