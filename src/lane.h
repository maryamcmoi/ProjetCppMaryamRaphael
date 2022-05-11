#ifndef LANE_H
#define LANE_H
#include "led.h"

class lane{
    private:
    int num;
    led * ld;
    public:
    lane(int num,led * ld);
    int numero();
    void avance(int pos, int r, int v, int b);
    void win();
};

#endif
