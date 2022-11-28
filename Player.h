#ifndef PLAYER_H
#define PLAYER_H

//This is player class interface to the user

//Player class
#include<string>
#include"Inventory.h"
#include"Equipped.h"
#include<fstream>

class Enemy;

class Player
{
protected: //Set the variables to be private
	int health;
	int maxHealth;
	int armor;
	int attack;
	int blockChance;
	int level;
	int currExperience;
	std::string name;
	Inventory pInventory; //Create new inventory for player
	Equipped pHasEquiped; //Create new equiped 

public:
	//Default constructor
	Player();
	Player(std::string nm);
	//Full constructor
	Player(int arm, int atc, int blR, std::string nm, Inventory pInv, Equipped pHasEquiped, int level, int curExp, int maxH);
	//Create getters and setters
	double getHealth();
	void setHealth(int hel);
	void addHealth(int hel);

	void addMaxHealth(int hel);
	double getArmor();
	void setArmor(int arm);
	double getAttack();
	void setAttack(int atc);
	double getBlockChance();
	void setBlockChance(int blC);
	std::string getName();
	void setName(std::string nm);
	//Simple print to see what is in variables
	void print();
	void fight(Enemy& e);
	bool isDeath();

	//Add object to player inventory
	void pickUp(Object& toAdd);
	bool isInPInventory(std::string toCheck);
	bool isInEquiped(std::string toCheck);
	Inventory getInventory();
	void removeFromInventory(Object& toRemove);
	void removeFromInventory(std::string& toRemove);
	void equip(Object& toAdd);

	Equipped getEquiped();
	void removeFromEquiped(Object& toRemove);
	void removeFromEquiped(std::string& toRemove);
	bool checkUseWith(std::string& toCheck);

	void loadPlayer(std::ifstream& inFile);
	void savePlayer(std::ofstream& oFile);
	void addExperience(int amount);
	int getExperience();
	void checkForLvlUp();
	int getCurrLevel();
	//Deconstructor
	~Player();
};


#endif