#include "ball.h"
#include <cstdio>
#include <unistd.h>

//type: vitesse si 1: lent, si 2: moyen, si 3: rapide
ball :: ball(float diff,int type,lane * lane){     
    this->pos=0;
    this->actif=0;
    this->ln=lane;
    switch(type)
    {
        case 1:
            this->vitesse=500;
            this->r=255;
            this->v=0;
            this->b=0;
            break;
        case 2:
        this->vitesse=250;
            this->r=255;
            this->v=128;
            this->b=0;
            break;
        default:
        this->vitesse=0;
            this->r=0;
            this->v=255;
            this->b=0;
            break;
    }
}

void ball :: naissance(lane * lane){       //active la boule sur sa lane pour qu'elle puisse etre deplacée
    this->ln=lane;
    this->actif=1;
}

void ball :: deces(){                      //tue la boule quand elle annulée par la defense
    this->actif=0;
    this->pos=0;
}

lane * ball :: curlane(){                  //assesseur de la lane
    return this->ln;
}

int ball :: qpos(){                        //assesseur de la pos
    return this->pos;
}

int ball :: vivant(){                      //assesseur du int vivant
    return this->actif;
}

int ball :: avancer(){                     //fait avancer la balle d'une led 
    delay(this->vitesse);
    this->ln->avance(this->pos,this->r,this->v,this->b);
    this->pos+=1;
    if (this->pos==11){
        this->pos =0;
        this->actif=0;
        return 1;
    }
    else
        return 0;
}

