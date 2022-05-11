#include "attack.h"
#include <stdio.h>

attack :: attack(lane * l1,lane *l2, lane *l3,button * b1, button *b2, button * b3){ 
    this->b1=b1;
    this->b2=b2;
    this->b3=b3;
    this->val1=false;
    this->val2=false;
    this->val3=false;
    this->l1=l1;
    this->l2=l2;
    this->l3=l3;
}

void attack :: get_sig(){                     //récupere l'etat des boutons
    this->val1=this->b1->get_button();
    this->val2=this->b2->get_button();
    this->val3=this->b3->get_button();
}

void attack :: lance_boule(ball * ball){       //lance une boule si le bouton d'attaque est pressé
    if (val1==true){
        ball->naissance(l1);
        val1=false;
        }
    /* 
    if (val2==true){
        ball->naissance(l2);
        val2=false;
        }*/
        /*
    if (val3==true){
        ball->naissance(l3);
        val3=false;
        }*/
}

/*void attack:: change_lane(){                        //change la current lane en fct de la pos du joystick
    switch (posjs){
        case 1:
            if ((this->currentlane==this->l1) || (this->currentlane==this->l2))
                this->currentlane=this->l1;
            else if (this->currentlane==this->l3)
                this->currentlane=this->l2;
            else if (this->currentlane==this->l4)
                this->currentlane=this->l3;
            break;
        case 2:
            if ((this->currentlane==this->l3) || (this->currentlane==this->l4))
                this->currentlane=this->l4;
            else if (this->currentlane==this->l2)
                this->currentlane=this->l3;
            else if (this->currentlane==this->l1)
                this->currentlane=this->l2;
            break;
    }
}
    */