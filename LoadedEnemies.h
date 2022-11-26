#ifndef LOADEDENEMIES_H
#define LOADEDENEMIES_H

#include"Enemy.h"
#include<vector>
#include<fstream>


//Class to hold all enemies loaded in game
class LoadedEnemies
{
private:

	std::vector<Enemy> enemies;


public:
	LoadedEnemies();
	LoadedEnemies(std::vector<Enemy>& objs);
	~LoadedEnemies();

	std::vector<Enemy>* getAllEnemies();
	Enemy& getAnyEnemy(int i);
	void loadEnemies(std::ifstream& inFile);
	void saveEnemies(std::ofstream& inFile);
	bool checkForSave(std::string whereYouGo);
	Enemy& getTheSavedOne(std::string whereYouGo);
	void printAllEnemies();
};

#endif