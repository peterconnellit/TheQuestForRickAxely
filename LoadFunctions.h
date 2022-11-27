#ifndef LOADFUNCTIONS_H
#define LOADFUNCTIONS_H

#include "Map.h"
#include"Player.h"
#include"LoadedObjects.h"
#include"LoadedEnemies.h"

//Load function interface to the user
void setupNewGame(Map& myMap, Player& currPlayer, LoadedObjects& allObj);
void setupGameParts(Map& myMap, Player& currPlayer, LoadedObjects& allObj);
void setCurPlayersName(Player& currPlayer);
void printStory(Player& currPlayer);
void saveGame(LoadedObjects& allObj, Player& currPlayer, Map& currMap, LoadedEnemies& allEnem);
void quickSaveGame(LoadedObjects& allObj, Player& currPlayer, Map& currMap, LoadedEnemies& allEnem);
void loadNewPlayer(Player& currPlayer);
void loadSavedPlayer(Player& currPlayer);
void loadEnemies(LoadedEnemies& allEnem);
void loadSavedEnemies(LoadedEnemies& allEnem);
bool startFromSave();

#endif
