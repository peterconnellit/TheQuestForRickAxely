#ifndef ENEMY_H
#define ENEMY_H
//this is enemy class interface to the user
//enemy class that extends player class

#include"Equiped.h"
#include "Inventory.h"
#include <string>
#include<fstream>
#include"Player.h"

class Enemy : public Player
{
protected:
	std::string position;
public:
	//Constructors
	Enemy();
	Enemy(std::string nm);
	Enemy(int arm, int atc, int blR, std::string nm, Inventory pInv, Equiped pHasEquiped, std::string pos, int level, int exp, int maxHel);
	//Destructor
	~Enemy();
	void saveEnemy(std::ofstream& oFile);
	void loadEnemy(std::ifstream& inFile);
	std::string getPosition();
	void setPosition(std::string pos);
	void printEnemy();
	//Constructors are not inherited. They are called implicitly or explicitly by the child constructor.  http://stackoverflow.com/questions/347358/inheriting-constructors

};

#endif
