#include "Enemy.h"
#include<iostream>
#include"Player.h"

//Implementation of enemy class
using std::endl;		using std::cout;
using std::string;		using std::ifstream;
using std::ofstream;

//Enemy class, attributes, methods and functions
//Inherits player class
Enemy::Enemy() :Player()
{
	position = "none";
}

Enemy::Enemy(std::string nm) :Player(nm)
{
}

Enemy::Enemy(int arm, int atc, int blR, std::string nm, Inventory pInv, Equiped pHasEquiped, string pos, int level, int exp, int maxHel) : Player(arm, atc, blR, nm, pInv, pHasEquiped, level, exp, maxHel), position(pos)
{

}

//Deconstructor
Enemy::~Enemy()
{

}

void Enemy::saveEnemy(ofstream& oFile)
{
	this->savePlayer(oFile);
	oFile << "position= " << position << endl;
	oFile << endl;
}

void Enemy::loadEnemy(ifstream& inFile)
{
	string garbage;
	this->loadPlayer(inFile);
	inFile >> garbage >> position;
}

string Enemy::getPosition()
{
	return position;
}

void Enemy::setPosition(string pos)
{
	position = pos;
}

void Enemy::printEnemy()
{
	this->print();
	cout << "Position " << position << endl;

}