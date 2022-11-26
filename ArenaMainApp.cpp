//Simple arena game that gives player life points and calculate damage based on attack and defence types

//Implementation of main arena app
#include<iostream>
#include<string>
#include<vector>
#include <windows.h> 


#include <stdio.h>      // printf, scanf, puts, NULL //
#include <stdlib.h>     // srand, rand //
//#include <time.h>       /* time  http://www.cplusplus.com/reference/cstdlib/rand/ */ does not work because the numbers are generated at the same time               

#include "Player.h"
#include "Enemy.h"
#include"ArenaOptions.h"
#include "Menu.h"
#include "SetConsoleWindow.h" 
#include "Logos.h"
#include "PrintFunctionality.h"
#include"GetPlayerInputFunctions.h"
#include"ArenaMainApp.h"
#include"AddedItems.h"
#include"Enums.h"
#include"MathFunctionality.h"


//Include usings
using std::cin;				using std::cout;
using std::endl;			using std::string;
using std::vector;

typedef vector<Enemy> enemyContainer;

void arenaStartApp(Player& currPlayer, LoadedObjects& allObjs)
{
	signUpPlayer();
	enemyContainer enemyes = enemysToFight(); // Names to give to enemies
	enemyes.shrink_to_fit(); //If we have loads of enemies we can save some memory
	//Counter that count killed enemies
	int eCounter = 0;
	bool victory = false;
	Enemy* enemy;
	do
	{
		//Place enemy pointer from vector into enemy to fight
		enemy = &enemyes[eCounter];
		do
		{
			addAttackBonuses((*enemy), currPlayer);
			//Check if you are still alive and can fight after the swing
			if (currPlayer.isDeath() == true)
			{
				if (enemy->isDeath() == true)
				{
					cout << enemy->getName() << " killed you before he died " << endl;
					//Add to the killed enemies
					eCounter += 1;
					//Exits first loop
					break;
				}
				else
				{
					cout << enemy->getName() << " killed you " << endl;
					//Exits first loop
					break;
				}
			}
		//This exits loop after you kill enemy
		} while (enemy->isDeath() == false);

		//Check if player is still alive
		if (currPlayer.isDeath() == false)
		{
			eCounter += 1;
			cout << "You killed " << enemy->getName() << endl;
			if (eCounter == 4)
			{
				printlnCenter("You killed enough of opponents you became the new lord of the arena !!!");
				printlnCenter("You got health potion to get some of that lost health back");
				addPotion(currPlayer, allObjs);
				printCup();
				victory = true;
				break;
				//Exits program
			}
			if (surrenderOption() == true)
			{
				victory = true;//he wants to leave so he won against one oponent
				break;
			}
			println("Next enemy is coming to fight you");
		}
		//Exits loop when player dies
	} while (currPlayer.isDeath() == false);

	if (victory == false)
	{
		//When you die prints picture of skull
		cout << "You killed " << eCounter << " enemies in total" << endl;
		println("You died GAME OVER");
		println("Maybe next time you do better");
		//Print skull logo
		printSkull();
		system("pause");
		exit(0);
	}


}

void signUpPlayer()
{

	checkMenuInput();
	println("Please enter your name to sign up for THE ARENA");
	string name = "";
	name = userInput();
	println("Hello " + name);
	println("Now is your time to shine and show your skills ");

	println("You walk into the arena and see your first enemy approaching");
	printlnCenter("Prepare for battle !!!");
	//Shield logo
	printShield();

}

//This creates and vector of enemys with names and pass it to the application
enemyContainer enemysToFight()//http://stackoverflow.com/questions/9963453/c-pointer-to-vector  returning pointer is inefficient
{
	enemyContainer enemyes;  //Defining the vector size wont work!!!!!!!!!!!!!
	enemyes.push_back(Enemy("Ringo"));
	enemyes.push_back(Enemy("Cassius"));
	enemyes.push_back(Enemy("Sebastian"));
	enemyes.push_back(Enemy("Bane the Arena Lord"));

	return enemyes;
}

//Add bonuses depending on players choice of attack
void addAttackBonuses(Enemy& enemy, Player& currPlayer)
{
	int atkChosen = attackChoice();

	//Set player and enemy attack and block acording the choice
	if (atkChosen == 1) //Reduced block
	{
		enemy.setBlockChance(-BONUSBLOCK); //-10%block
	}
	else //Bonus atck
	{
		currPlayer.setAttack(+BONUSATACK); //+5atack
	}
	//Simple fight function
	currPlayer.fight(enemy);
	//After swing set the values to default otherwise they will grow after each enemy
	if (atkChosen == 1)
	{
		enemy.setBlockChance(BONUSBLOCK);
	}
	else
	{
		currPlayer.setAttack(-BONUSATACK);
	}
}

void fightEnemy(Player& currPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs, Enemy& enemy)
{

	do
	{
		addAttackBonuses(enemy, currPlayer);
		//Check if you are still alive and can fight after the swing
		if (currPlayer.isDeath() == true)
		{
			if (enemy.isDeath() == true)
			{
				cout << enemy.getName() << " killed you before he died " << endl;
				system("pause");
				//Exits game
				exit(0);
			}
			else
			{
				cout << enemy.getName() << " killed you " << endl;
				system("pause");
				//Exits game
				exit(0);
			}
		}
		//This exits loop after you kill enemy
	} while (enemy.isDeath() == false);

	cout << "You killed " << enemy.getName() << endl;
	currPlayer.addExperience(enemy.getExperience());
	if (currPlayer.getCurrLevel() == 6)
	{
	}
	else
	{
		cout << "You got " << enemy.getExperience() << " experience." << endl;
		currPlayer.checkForLvlUp();
	}
	printlnCenter("You got health potion to get some of that lost health back");
	addPotion(currPlayer, allObjs);

}


Enemy& chooseRandomEnemy(LoadedEnemies& allEnem)
{
	int choosenEnem = Random(0, allEnem.getAllEnemies()->size() - 1);
	return allEnem.getAnyEnemy(choosenEnem);
}
//When the player walks from room to room, check for enemy
bool checkForFight(Player& currPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs, string& whereYouGo)
{



	//Places enemy pointer from vector into enemy to fight
	Enemy& enemyRandom = chooseRandomEnemy(allEnem);
	//First we check if we have any enemy on the road that we skipped last time
	if (allEnem.checkForSave(whereYouGo) == true)
	{

		Enemy& savedOne = allEnem.getTheSavedOne(whereYouGo); //Get the saved enemy fight it and set its position to nowhere
		fightEnemy(currPlayer, allEnem, allObjs, savedOne);
		savedOne.setPosition("none");
	}
	else
	{
		//50% chance to find enemy
		int roll = Random(0, 1);
		if (roll == 0)
		{
			//cout << "No enemy to fight on road" << endl;
			return false;
		}
		cout << "There was a bandit ont the road that attacked you " << endl;

		if (checkForRun() == true) //Yes you run away
		{
			//Save the enemy here that you run away from
			enemyRandom.setPosition(whereYouGo);
		}
		else
		{
			fightEnemy(currPlayer, allEnem, allObjs, enemyRandom);
		}

	}
	return true;
}

bool checkForRun()
{
	cout << "Do you want to fight (f) or try to run(r)?" << endl;
	if (checkForOption("r", "f") == true)
	{
		int roll = Random(0, 1);
		//50%chance to run
		if (roll == 1)
		{
			cout << "You were faster than bandit and escaped" << endl;
			return true; //Yes you run away
		}
		else
		{
			cout << "You couldnt escape the battle" << endl;
			return false;
		}
	}
	return false;
}