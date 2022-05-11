#ifndef ATK_H
#define ATK_H
#include "button.h"
#include "ball.h"
#include "lane.h"

class attack{
    protected :
        lane *l1;
        lane *l2;
        lane *l3;
        bool val1;
        bool val2;
        bool val3; 
        button * b1;
        button * b2;
        button * b3;
    public:
        attack(lane * l1,lane *l2, lane *l3, button *b1, button *b2, button *b3);
        void get_sig();
        void lance_boule(ball * ball);
        //void change_lane();

};

#endif