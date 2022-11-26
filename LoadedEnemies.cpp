#include"LoadedEnemies.h"
#include<iostream>
#include"StringFunctionality.h"

using std::vector;		using std::ifstream;
using std::iterator;	using std::ofstream;
using std::string;		using std::cout;
using std::endl;
typedef vector<Enemy> enemyContainer;

LoadedEnemies::LoadedEnemies()
{

}


LoadedEnemies::LoadedEnemies(enemyContainer& enem)
{
	enemies = enem;
}


LoadedEnemies::~LoadedEnemies()
{

}

vector<Enemy>* LoadedEnemies::getAllEnemies()
{
	return &enemies;
}

Enemy& LoadedEnemies::getAnyEnemy(int i)
{
	return enemies[i];
}
void LoadedEnemies::loadEnemies(ifstream& inFile)
{

	while (!inFile.eof()) //Loop throught all the files objects
	{
		Enemy loadedEnem;
		loadedEnem.loadEnemy(inFile);
		if (loadedEnem.getName() == "")
		{
			//cout << "Discarding empty obj" << endl;
		}
		else
		{
			if (loadedEnem.getName() == "no name")
			{

			}
			else
			{
				enemies.push_back(loadedEnem);
			}

		}
	}

}

void LoadedEnemies::saveEnemies(ofstream& oFile)
{

	for (enemyContainer::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		it->saveEnemy(oFile);
	}
}
void LoadedEnemies::printAllEnemies()
{

	for (enemyContainer::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		it->printEnemy();

	}

}

//Check if enemy we ran from is waiting on the road 
bool LoadedEnemies::checkForSave(string whereYouGo)
{
	for (enemyContainer::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		if (toLowerCase(it->getPosition()) == toLowerCase(whereYouGo))
		{
			cout << "There is the enemy you ran away from waiting for you on the same road" << endl;
			return true;
		}

	}

	return false;
}

//Get the pointer to the enemy which is at the previous position you ran away from
Enemy& LoadedEnemies::getTheSavedOne(string whereYouGo)
{
	for (enemyContainer::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		if (toLowerCase(it->getPosition()) == toLowerCase(whereYouGo))
		{
			return (*it);
		}

	}

	return enemies[0];
}