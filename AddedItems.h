#ifndef ADDEDITEMS_H
#define ADDEDITEMS_H

#include"Player.h"
#include"LoadedObjects.h"


//This is added items interface to the user
//All aditional new objects resulting from player actions

void addGoldenArmor(Player& currPlayer, LoadedObjects& allObjs);
void addGoldenShield(Player& currPlayer, LoadedObjects& allObjs);
void addPotion(Player& currPlayer, LoadedObjects& allObjs);

#endif