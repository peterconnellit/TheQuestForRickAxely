#include "Player.h"
#include"Enemy.h"
#include "Inventory.h"
#include<iostream> 
#include <Windows.h>
#include <string>
#include "Object.h"
#include"StringFunctionality.h"
#include"PrintFunctionality.h"
#include"MathFunctionality.h"
#include"Enums.h"

//Implementation of player class

using std::endl;		using std::cout;
using std::string;		using std::ifstream;
using std::ofstream;

//Player class and its functions
Player::Player()
{
	name = "no name";
	health = 150;
	maxHealth = 500;
	armor = 8;
	attack = 25;
	blockChance = 20;
	level = 1;
	currExperience = 0;
}

Player::Player(string nameN)
{
	name = nameN;
	health = 150;
	maxHealth = 500;
	armor = 8;
	attack = 25;
	blockChance = 20;
	level = 1;
	currExperience = 0;
}

Player::Player(int arm, int atc, int blR, string nameN, Inventory pInvent, Equiped phasEq, int level, int curExp, int maxH)
{
	name = nameN;
	health = 150;
	maxHealth = maxH;
	armor = arm;
	attack = atc;
	blockChance = blR;
	pInventory = pInvent; //Get the inventory to player
	pHasEquiped = phasEq;
}
//Deconstructor
Player::~Player(void)
{
}

//Inventory functionality

//Add object to player inventory
void Player::pickUp(Object& toAdd)
{
	pInventory.addToInventory(toAdd);
}

void Player::removeFromInventory(Object& toRemove)
{
	pInventory.removeFromInventory(toRemove);
}

void Player::removeFromInventory(string& toRemove)
{
	pInventory.removeFromInventory(toRemove);
}

Inventory Player::getInventory()
{
	return pInventory;
}

bool Player::isInPInventory(string toCheck)
{
	return pInventory.checkIsInInventory(toCheck);
}
bool Player::checkUseWith(string& toCheck)
{
	return pInventory.checkUseWith(toCheck);
}

//Equipment functionality

void Player::equip(Object& toAdd)
{

	pHasEquiped.addToEquiped(toAdd);
}

Equiped Player::getEquiped()
{
	return pHasEquiped;
}

void Player::removeFromEquiped(Object& toRemove)
{
	pHasEquiped.removeFromEquiped(toRemove);
}

void Player::removeFromEquiped(string& toRemove)
{
	pHasEquiped.removeFromEquiped(toRemove);
}
bool Player::isInEquiped(string toCheck)
{
	return pHasEquiped.checkIsEquiped(toCheck);
}

//Variable functionality

void Player::addHealth(int hel)
{
	health = health + hel;
	if (health >= maxHealth)
	{
		cout << "You are at maximum health." << endl;
		health = maxHealth;
	}
}

void Player::addMaxHealth(int hel)
{
	maxHealth += hel;
}

//Create getters and setters
double Player::getHealth()
{
	return health;
}

void Player::setHealth(int hel)
{
	health = hel;
}


double Player::getArmor()
{
	return armor;
}

void Player::setArmor(int arm)
{
	armor += arm;
}

double Player::getAttack()
{
	return attack;
}

void Player::setAttack(int atc)
{
	attack += atc;
}

double Player::getBlockChance()
{
	return blockChance;
}

void Player::setBlockChance(int blC)
{
	blockChance += blC;
}


string Player::getName()
{
	return name;
}

void Player::setName(string nm)
{
	name = nm;
}


//Fight functionality

//Simple print to see what is in variables
void Player::print()
{
	cout << "Your name: " << name << endl;
	cout << "Your level is " << level << " your health " << health << " your max health " << maxHealth << " your armor " << armor << " your attack " << attack << " your block " << blockChance << endl;
}

void Player::fight(Enemy& e)
{
	//This center outputs strings 
	string centerSpace = centerString("", 10);
	int damageDealth = 0; //Damage they deal to each other

	//Generate secret number between 1 and 3
	int ranNum = Random(1, 3);

	int ranBlock = Random(1, 100);

	//Block succesfull for player
	if (blockChance >= ranBlock)
	{
		cout << centerSpace << "You blocked attack" << endl;
	}
	else //Block not succesfull
	{
		damageDealth = (e.getAttack() + ranNum) - armor;
		if (damageDealth < 0) //This prevents negative numbers
		{
			damageDealth = 0;
		}
		cout << centerSpace << "You took " << damageDealth << " damage" << endl;
		health -= damageDealth;
		if (health <= 0)
		{
			health = 0; //Sets health to 0 if is negative
		}
		cout << centerSpace << "Your health is " << health << endl;
	}

	//Block succesfull for enemy
	if (e.getBlockChance() >= ranBlock)
	{
		cout << centerSpace << "Enemy blocked attack" << endl;
	}
	else //Block not succesfull
	{

		damageDealth = (attack + ranNum) - e.getArmor();

		if (damageDealth < 0) //This prevents from negative numbers
		{
			damageDealth = 0;
		}
		cout << centerSpace << "Enemy took " << damageDealth << " damage" << endl;
		e.setHealth(e.getHealth() - damageDealth);
		if (e.getHealth() <= 0)
		{
			e.setHealth(0); //Sets health to 0 if is negative
		}

		cout << centerSpace << "Enemy health is " << e.getHealth() << endl;
	}

}

bool Player::isDeath()
{
	if (health <= 0) //Yes is death
	{
		return true;
	}
	return false;
}


void Player::loadPlayer(ifstream& inFile)
{
	string garbage;

	inFile >> garbage >> name; //Read the object name
	inFile >> garbage >> health;
	inFile >> garbage >> maxHealth;
	inFile >> garbage >> armor;
	inFile >> garbage >> attack;
	inFile >> garbage >> blockChance;
	inFile >> garbage >> level;
	inFile >> garbage >> currExperience;

}

void Player::savePlayer(ofstream& oFile)
{
	oFile << "name " << name << endl;
	oFile << "health " << health << endl;
	oFile << "maxHealth " << maxHealth << endl;
	oFile << "armor " << armor << endl;
	oFile << "attack " << attack << endl;
	oFile << "blockCHance " << blockChance << endl;
	oFile << "level " << level << endl;
	oFile << "CurrentExperience " << currExperience << endl;
}

void Player::addExperience(int amount)
{
	currExperience += amount;
}

int Player::getExperience()
{
	return currExperience;
}

void Player::checkForLvlUp()
{
	if ((currExperience >= LEVEL1) && (level == 1))
	{
		currExperience = 0;
		cout << "You leveled up" << endl;
		level++;
		cout << "You current level is " << level << endl;
		cout << "You got " << HEALTHBONUS << " bonus to  maximum health." << endl;
		maxHealth += HEALTHBONUS;
		cout << "You need " << LEVEL2 << " exp to next level." << endl;


	}
	if ((currExperience >= LEVEL2) && (level == 2))
	{
		currExperience = 0;
		cout << "You leveled up" << endl;
		level++;
		cout << "You got " << HEALTHBONUS << " bonus to  maximum health." << endl;
		maxHealth += HEALTHBONUS;
		cout << "You current level is " << level << endl;
		cout << "You need " << LEVEL3 << " exp to next level." << endl;

	}
	if ((currExperience >= LEVEL3) && (level == 3))
	{
		currExperience = 0;
		cout << "You leveled up" << endl;
		level++;
		cout << "You got " << HEALTHBONUS << " bonus to  maximum health." << endl;
		maxHealth += HEALTHBONUS;
		cout << "You current level is " << level << endl;
		cout << "You need " << LEVEL4 << " exp to next level." << endl;

	}
	if ((currExperience >= LEVEL4) && (level == 4))
	{
		currExperience = 0;
		cout << "You leveled up" << endl;
		level++;
		cout << "You got " << HEALTHBONUS << " bonus to  maximum health." << endl;
		maxHealth += HEALTHBONUS;
		cout << "You current level is " << level << endl;
		cout << "You need " << LEVEL5 << " exp to next level." << endl;

	}
	if ((currExperience >= LEVEL5) && (level == 5))
	{
		currExperience = 0;
		cout << "You leveled up" << endl;
		level++;
		cout << "You got " << HEALTHBONUS << " bonus to  maximum health." << endl;
		maxHealth += HEALTHBONUS;
		cout << "You current level is " << level << endl;
		cout << "You are at the maximum level." << endl;

	}

}

int Player::getCurrLevel()
{
	return level;
}