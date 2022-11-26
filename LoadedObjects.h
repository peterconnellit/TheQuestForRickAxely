#ifndef LOADED_H
#define LOADED_H

#include<string>
#include<vector>
#include<fstream>
#include"Object.h"
#include"Map.h"
#include"Player.h"

//Class that holds all objects loaded in game
class LoadedObjects
{
private:

	std::vector<Object> objects;
	std::vector<Object>notImportantOnes;


public:
	LoadedObjects();
	LoadedObjects(std::vector<Object>& objs, std::vector<Object>& notImportantObjs);
	~LoadedObjects();

	void printAllObjs();
	void loadAllObjects(std::ifstream& inFile);
	void loadAllObjectsParts(std::ifstream& inFileStatic, std::ifstream& inFileChanging);
	void saveAllObjects(std::ofstream& oFile);
	void quickSaveAllObjects(std::ofstream& oFile);
	void sortAllObjects(Map& currMap, Player& currPlayer);
	void setWhereitIS(std::string toChange, std::string actualWhereItis);
	void removeByName(std::string toRemove);
	void addPotionAfterBattleWithClone(Player& currPlayer);
	Object& getByName(std::string toGet);
};

#endif