#ifndef MONAPPLICATION_H
#define MONAPLICATION_H

#include "button.h"
#include <Arduino.h>
#include "led.h"
#include "lane.h"
#include "ball.h"
#include "defense.h"
#include "attack.h"
#include <unistd.h>
#include <stdio.h>
#include <vector>

using namespace std; 

class MonApplication{
  vector <button *> mesBout; 
  vector <led *> mesLeds; 
  vector <lane *> mesLanes; 
  vector <ball *> mesBall;
  vector <attack *> mesAttack; 
  vector <defense *> mesDefense;  

  public: 
    void Init();
    void Loop(); 

  private: 
    int score; 
    int next_available; 
};

#endif
