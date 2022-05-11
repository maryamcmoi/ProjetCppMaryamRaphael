#ifndef DEF_H
#define DEF_H
#include "lane.h"
#include "ball.h"
#include "button.h"

class defense{
    protected:
        bool val1,val2,val3;
        lane *l1;
        lane *l2;
        lane *l3;
        button *b1,*b2,*b3;
    public:
        defense(lane *l1,lane *l2, lane *l3,button * b1,button * b2, button * b3);
        void kill(ball * ball);
        void get_sig();


};

#endif