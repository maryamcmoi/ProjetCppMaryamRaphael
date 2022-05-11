#include "lane.h"

#define NB_LED 10

lane::lane(int num, led * ld){
        this->num=num;
        this->ld=ld;
}

int lane::numero(){                                      //assesseur du numéro de lane
        return this->num;
}

void lane ::avance (int pos, int r, int v, int b){       //eteint l'ancinne position de la boule et allume la nouvelle
        if (pos>=1)
       {this->ld->eteindre_led_pos(pos-1);}
       if (pos>=0)
       {this->ld->allumer_led_pos_color(pos,r,v,b);}

}

void lane :: win(){                                      //allume tout en vert en cas de victoire de l'attaquant
    for (int i=0;(i<NB_LED);i++)
      {  this->ld->allumer_led_pos_color(i,255,0,0);
      }
}

bool operator == (lane& un, lane& autre) {
return (un.numero()==autre.numero());}    