#include "monApplication.h"
using namespace std; 

#define NB_BOULES 6 //attention aux instanciations si modifications
#define DIFF 200  // a DECREMENTER pour augmenter la vitesse des balles
#define VIE 3


void MonApplication::Init(){
  //mettre pin D3 à 0 
  digitalWrite(D3, LOW); 

  this->score = 0; 
  this->next_available = 1; 
  led *ld1 = new led(1);
  led *ld2 = new led(2);
  led *ld3 = new led(3);

  mesLeds.push_back(ld1);
  mesLeds.push_back(ld2);
  mesLeds.push_back(ld3);

  button *batk1 = new button(1, 1); //boutons attaquants
  button *batk2 = new button(2, 1);
  button *batk3 = new button(3, 1);
  button *bdef1 = new button(1, 2); //boutons defense
  button *bdef2 = new button(2, 2); 
  button *bdef3 = new button(3, 2);

  mesBout.push_back(batk1); 
  mesBout.push_back(batk2); 
  mesBout.push_back(batk3); 
  mesBout.push_back(bdef1); 
  mesBout.push_back(bdef2); 
  mesBout.push_back(bdef3); 


  lane *l_vide = new lane(0,NULL);
  lane *l1 = new lane(1, (mesLeds[0])); 
  lane *l2 = new lane(2,(mesLeds[1])); 
  lane *l3 = new lane(3,(mesLeds[2]));

  mesLanes.push_back(l_vide);
  mesLanes.push_back(l1);
  mesLanes.push_back(l2);
  mesLanes.push_back(l3);



  ball *b1 = new ball(DIFF,1,(mesLanes[0]));
  ball *b2 = new ball(DIFF,1,(mesLanes[0]));  //2 boules lentes

  ball *b3 = new ball(DIFF,2,(mesLanes[0]));
  ball *b4 = new ball(DIFF,2,(mesLanes[0]));  //2 boules moyennes

  ball *b5 = new ball(DIFF,3,(mesLanes[0]));
  ball *b6 = new ball(DIFF,3,(mesLanes[0]));  //2 boules rapides
  
  mesBall.push_back(b1);
  mesBall.push_back(b2);
  mesBall.push_back(b3);
  mesBall.push_back(b4);
  mesBall.push_back(b5);
  mesBall.push_back(b6);

  attack *atk = new attack((mesLanes[1]),(mesLanes[2]),(mesLanes[3]),(mesBout[0]),(mesBout[1]),(mesBout[2]));

  mesAttack.push_back(atk); 
  
  defense *def = new defense((mesLanes[1]),(mesLanes[2]),(mesLanes[3]),(mesBout[3]),(mesBout[4]),(mesBout[5]));

  mesDefense.push_back(def); 

  //mettre pin D3 à 0 
  digitalWrite(D3, LOW); 
}

void MonApplication::Loop(){
  Serial.println(score);
  if (score!=VIE)
  {
    (*mesAttack[0]).get_sig();
    (*mesDefense[0]).get_sig();


    switch(next_available){
      case 1: 
          (*mesAttack[0]).lance_boule((mesBall[0]));
          next_available=2;
          break;
      case 2:
          (*mesAttack[0]).lance_boule((mesBall[1]));
  
          next_available=3;
          break;
      case 3:
          (*mesAttack[0]).lance_boule((mesBall[2]));

          next_available=4;
          break;
      case 4:
          (*mesAttack[0]).lance_boule((mesBall[3]));
          next_available=5;
          break;
        
      case 5:
          (*mesAttack[0]).lance_boule((mesBall[4]));
  
          next_available=6;
          break;
      case 6:
          (*mesAttack[0]).lance_boule((mesBall[5]));
          next_available=1;
          break;

   }
  if ((*mesBall[0]).vivant()==1){
      score+=(*mesBall[0]).avancer();}
  if ((*mesBall[1]).vivant()==1)
      score+=(*mesBall[1]).avancer();
  if ((*mesBall[2]).vivant()==1)
      score+=(*mesBall[2]).avancer();
  if ((*mesBall[3]).vivant()==1)
      score+=(*mesBall[3]).avancer();
  if ((*mesBall[4]).vivant()==1)
      score+=(*mesBall[4]).avancer();
  if ((*mesBall[5]).vivant()==1)
      score+=(*mesBall[5]).avancer();
  
  
  (*mesDefense[0]).kill(mesBall[0]);
  (*mesDefense[0]).kill(mesBall[1]);
  (*mesDefense[0]).kill(mesBall[2]);
  (*mesDefense[0]).kill(mesBall[3]);
  (*mesDefense[0]).kill(mesBall[4]);
  (*mesDefense[0]).kill(mesBall[5]);


  if (this->score==VIE)
  {
      (*mesLanes[1]).win();
      (*mesLanes[2]).win();
      (*mesLanes[3]).win();
  }


  }
  
  delay(DIFF);
  
}
