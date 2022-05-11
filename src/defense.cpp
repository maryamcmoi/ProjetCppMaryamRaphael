#include "defense.h"


defense :: defense(lane *l1,lane *l2, lane *l3,button * b1,button * b2, button * b3){
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


void defense :: kill(ball * ball){                           //annule la boule si elle est en position 7 et que le bouton est presse
    if ((val1)&&(ball->curlane()==l1)&&((ball->qpos()==7))){//||(ball->qpos()==8)||(ball->qpos()==9)))
        ball->deces();
        val1=false;}

    /*if ((val2)&&(ball->curlane()==l2)&&((ball->qpos()==7))){//||(ball->qpos()==8)||(ball->qpos()==9)))
        ball->deces();
        val2=0;}
        /*

    if ((val3)&&(ball->curlane()==l3)&&((ball->qpos()==7))){//||(ball->qpos()==8)||(ball->qpos()==9)))
        ball->deces();
        val3=0;}
*/

}

void defense :: get_sig(){                            //recupere l'etat des boutons
    this->val1=this->b1->get_button();                
    this->val2=this->b2->get_button();
    this->val3=this->b3->get_button();  
}