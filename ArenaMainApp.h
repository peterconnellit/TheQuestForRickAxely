#ifndef ARENAMAINAPP_H
#define ARENAMAINAPP_H

#include"Player.h"
#include"Enemy.h"
#include"LoadedEnemies.h"
#include"LoadedObjects.h"
#include<vector>

//This is arena main app interface to the user
void arenaStartApp(Player& currPlayer, LoadedObjects& allObjs);
void signUpPlayer();
std::vector<Enemy> enemysToFight(); //Create enemys with names
void addAttackBonuses(Enemy& enemy, Player& currPlayer); //Add bonuses depending on players choice
void fightEnemy(Player& curPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs, Enemy& toFight); //Fights randomly choosen enemy
Enemy& chooseRandomEnemy(LoadedEnemies& allEnem);
bool checkForFight(Player& currPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs, std::string& whereYouGo);
bool checkForRun();
#endif
