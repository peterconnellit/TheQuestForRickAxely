#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include<string>
#include"Room.h"
#include"Player.h"
#include"Map.h"
#include"LoadedObjects.h"
#include"LoadedEnemies.h"


//Parser interface to the user

//Function that checks player input for examine, use ... with ... and open
void parse(Map& currentMap, Player& curPlayer, std::vector<std::string>& sentence, LoadedObjects& loadeObj, LoadedEnemies& allEnem, LoadedGames& allPuzzles);//pass player and map to adjust changes according to input

bool foundInSentence(std::vector<std::string>& sentence, std::string toSearchFor);
void searchRoomExitNames(std::vector<std::string>& sentence, Map& currentMap, Player& curPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs);
void searchForObjectNameDescription(std::vector<std::string>& sentence, Player& currPlayer);

void isInInventoryOpen(std::vector<std::string>& sentence, Player& curPlayer, LoadedObjects& loadedObj);
void isObjectInRoom(std::vector<std::string>& sentence, Map& currMap, Player& curPlayer, LoadedObjects& loadedObj);
bool searchFromSentenceInInventory(std::vector<std::string>& sentence, Player& curPlayer);
void isInInventoryUse(std::vector<std::string>& sentence, Player& currPlayer, LoadedObjects& loadedObj);
void readObjectStats(Player& currPlayer, std::string& objName);
void uneadObjectStats(Player& currPlayer, std::string& objName);
void foundInvEquip(std::string whatObject, Player& currPlayer, LoadedObjects& loadedObj);
void isInInventoryEquip(std::vector<std::string>& sentence, Player& currPlayer, LoadedObjects& loadedObj);
void isInEquipedUnequip(std::vector<std::string>& sentence, Player& currPlayer, LoadedObjects& loadedObj);

#endif // !PARSER_H
