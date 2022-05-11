#ifndef BALL_H
#define BALL_H
#include "lane.h"

class ball{
    protected :
    int r,v,b,pos,type;
    float vitesse;
    int actif;
    lane * ln;
    public:
        ball(float diff,int type,lane * lane);
        int avancer();
        void naissance(lane * lane);
        void deces();
        int qpos();
        int vivant();
        lane * curlane();
};
#endif