// TheQuestForRickAxely.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"Player.h"
#include"Map.h"
#include"LoadFunctions.h"
#include"GetPlayerInputFunctions.h"
#include"SetConsoleWindow.h"
#include"Parser.h"
#include"LoadedObjects.h"
#include"LoadedEnemies.h"

#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using std::string;		using std::vector;
using std::cout;		using std::cin;
using std::endl;		using std::ifstream;
using std::ostream;

//Simple game loop structure
int main()
{
	SetWindow(120, 50);

	Map myMap; //Create the map
	Player currPlayer; //Create the player
	LoadedObjects allObjects; //Create storage for all loaded game objects
	LoadedEnemies allEnemies; //Storage for all enemies

	//Functions that loads the files into map and object
	if (startFromSave() == true)
	{
		loadSavedPlayer(currPlayer);
		setupLoadedGame(myMap, currPlayer, allObjects);
		loadSavedEnemies(allEnemies);
	}
	else
	{
		loadNewPlayer(currPlayer);
		setCurPlayersName(currPlayer);
		printStory(currPlayer);
		setupNewGame(myMap, currPlayer, allObjects);
		loadEnemies(allEnemies);
	}

	//Game loop
	bool done = false;
	while (!done)
	{
		vector<string> sentence;
		while (sentence.size() == 0) //This will get rid of 'no keywords enterred when he does not type anything
		{
			sentence = getInputn(); //Get input to parse
		}
		//Parse any input and give you answer
		parse(myMap, currPlayer, sentence, allObjects, allEnemies);
	}

	return 0;
}