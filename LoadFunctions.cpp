#include"LoadFunctions.h"
#include"GetPlayerInputFunctions.h"
#include"Player.h"
#include"PrintFunctionality.h"
#include<fstream>
#include<iostream>
#include<string>

//Implementation of load functions

using std::ifstream;		using std::cout;
using std::endl;			using std::string;
using std::ofstream;		using std::cin;

//Function to load the files into map and object
void setupNewGame(Map& myMap, Player& currPlayer, LoadedObjects& allObj)
{
	//cout << "A of map" << &myMap << endl;
	//Get txt file into program
	ifstream inFile("rooms.txt");
	if (inFile)
	{
		myMap.loadRooms(inFile); //Load all rooms into map
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();
	//Get txt file into program
	ifstream inFile2("objects.txt");
	//Ifstream inFile2("savedObjects.txt");
	if (inFile2)
	{
		allObj.loadAllObjects(inFile2); //Load all objects into  map
		allObj.sortAllObjects(myMap, currPlayer); //Split objects between map and player
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile2.close();
	//Print the first room
	ifstream posFile("roomPosition.txt");
	if (posFile)
	{
		myMap.loadPosition(posFile); //Load players position
	}
	else
	{
		cout << "loading failed" << endl;
	}
	posFile.close();
	myMap.printCurrentRoom();
}

void setupLoadedGame(Map& myMap, Player& currPlayer, LoadedObjects& allObj)
{
	//cout << "A of map" << &myMap << endl;
	//Get the file into program
	ifstream inFile("rooms.txt");
	if (inFile)
	{
		myMap.loadRooms(inFile); //Load all rooms into map
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();
	//Get the file into program
	ifstream inFile2("savedObjects.txt");
	if (inFile2)
	{

		allObj.loadAllObjects(inFile2); //Load all objects into  map
		allObj.sortAllObjects(myMap, currPlayer); //Split objects between map and player
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile2.close();
	//Print the first room
	ifstream posFile("savedRoomPosition.txt");
	if (posFile)
	{
		myMap.loadPosition(posFile); //Load players position
	}
	else
	{
		cout << "loading failed" << endl;
	}
	posFile.close();
	myMap.printCurrentRoom();
}

void setupGameParts(Map& myMap, Player& currPlayer, LoadedObjects& allObj)
{
	//cout << "A of map" << &myMap << endl;
	//Get the file into program
	ifstream inFile("rooms.txt");
	if (inFile)
	{
		myMap.loadRooms(inFile); //Load all room into map
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();
	//Get the file into program
	ifstream inFileStatic("objectsStaticParts.txt");
	ifstream inFileChanging("objectsChangingParts.txt");
	if ((inFileStatic) && (inFileChanging))
	{
		allObj.loadAllObjectsParts(inFileStatic, inFileChanging);
		allObj.sortAllObjects(myMap, currPlayer); //Split objects between map and player
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFileStatic.close();
	inFileChanging.close();
	//Print the first room
	ifstream posFile("roomPosition.txt");
	if (posFile)
	{
		myMap.loadPosition(posFile); //Load players position
	}
	else
	{
		cout << "loading failed" << endl;
	}
	posFile.close();
	myMap.printCurrentRoom();
}

void loadNewPlayer(Player& currPlayer)
{
	//Get the file into program
	ifstream inFile("player.txt");
	if (inFile)
	{
		currPlayer.loadPlayer(inFile); //Load all players details
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();

}

void loadSavedPlayer(Player& currPlayer)
{
	//Get the file into program
	ifstream inFile("savedPlayer.txt");
	if (inFile)
	{
		currPlayer.loadPlayer(inFile); //Load all players details
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();

}

void loadEnemies(LoadedEnemies& allEnem)
{
	//Get the file into program
	ifstream inFile("enemies.txt");
	if (inFile)
	{
		allEnem.loadEnemies(inFile);
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();

}

void loadSavedEnemies(LoadedEnemies& allEnem)
{
	//Get the file into program
	ifstream inFile("savedEnemies.txt");
	if (inFile)
	{
		allEnem.loadEnemies(inFile);
	}
	else
	{
		cout << "loading failed" << endl;
	}
	inFile.close();

}


void printStory(Player& currPlayer)
{
	cout << "Type 'help' to show available commands.\n\n" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "You " << currPlayer.getName() << " are the hero on the path of adventure around the country." << endl;
	cout << "You ask the local book seller 'Warren Peace' about rumors of a short adventure." << endl;
	cout << "Warren = Is that the one with Dwarfs and Halflings?" << endl;
	cout << "you inform Warren that recently you've heard there is BATTLE ARENA in the town of 'Never EndsWell'." << endl;
	cout << "Warren = AHHHH yes!!!, then you are looking for the great Fire Mage 'Hal Apenyo'. He stole a Hobbits new invention... it is a frodotype." << endl;
	cout << "you have indeed heard of this new invention, the great weapon 'Rick Axely'. Legend tells 'Rick Axely will never let you down!'" << endl;
	cout << "Warren = YOU MUST BEWARE " << currPlayer.getName() << " Hal Apenyo has hired many mercenaries to fight in the arena" << endl;
	cout << "1.'Pepper' the dwarf = a seasoned warrior." << endl;
	cout << "2.'Elf-is Presley' = the legendary bard of many 'elf esteem songs." << endl;
	cout << "3.'Ed Basher' = the mighty barbarian." << endl;
	cout << "4.'Neck-romancer' = the vampire. He's always looking for an a new fight....something he can really sink my teeth into." << endl;
	cout << "Warren = Before You go... wanna by a discount swimming educational book 'Don't drown learning SEA++'...no?...OK." << endl;
	cout << "Feeling brave, You decide to head there to prove yourself, take back Rick Axely for the tiny folk and prove you are the best fighter in Never EndsWell!!." << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
}

void setCurPlayersName(Player& currPlayer)
{
	cout << "--------------------------------------------------" << endl;
	cout << "Hello adventurer! Please enter you characters name." << endl;
	string name = "";
	name = userInput();
	currPlayer.setName(name);

}


void saveGame(LoadedObjects& allObj, Player& currPlayer, Map& currMap, LoadedEnemies& allEnem)
{

	ofstream oFile("savedObjects.txt");
	if (oFile)
	{
		allObj.saveAllObjects(oFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oFile.close();

	ofstream oFile2("savedPlayer.txt");
	if (oFile)
	{
		currPlayer.savePlayer(oFile2);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oFile2.close();

	ofstream oPosFile("savedRoomPosition.txt");
	if (oPosFile)
	{
		currMap.savePosition(oPosFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oPosFile.close();

	ofstream enemFile("savedEnemies.txt");
	if (enemFile)
	{
		allEnem.saveEnemies(enemFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	enemFile.close();
}

void quickSaveGame(LoadedObjects& allObj, Player& currPlayer, Map& currMap, LoadedEnemies& allEnem)
{

	ofstream oFile("savedObjects.txt");
	if (oFile)
	{
		allObj.quickSaveAllObjects(oFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oFile.close();

	ofstream oFile2("savedPlayer.txt");
	if (oFile)
	{
		currPlayer.savePlayer(oFile2);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oFile2.close();

	ofstream oPosFile("savedRoomPosition.txt");
	if (oPosFile)
	{
		currMap.savePosition(oPosFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	oPosFile.close();

	ofstream enemFile("savedEnemies.txt");
	if (enemFile)
	{
		allEnem.saveEnemies(enemFile);
	}
	else
	{
		cout << "saving failed" << endl;
	}
	enemFile.close();
}

bool startFromSave()
{
	printlnCenter("----------------------------------------------");
	printlnCenter("Welcome to the Quest for Rick Axely.");
	printlnCenter("----------------------------------------------");
	//cout << "Welcome to the Quest for Rick Axely." << endl;
	cout << "Do you want to start new game type 'n' or continue from last save type 's' ?" << endl;
	string choice = "";
	bool flag = false;
	//This will loop unless player enters n or s as his choice
	do
	{
		//Adds > before input
		expInput();
		cin >> choice;
		if (choice == "n" || choice == "s")
		{
			flag = true;
		}
		else
		{
			println("Only (n) or (s) allowed as input");
			//Need to clear the buffer here

			cin.clear(); //Clears the buffer
			cin.ignore(80, '\n'); //Ignores characters until end of line
		}
	} while (flag == false);

	if (choice == "s")
	{
		return true;
	}

	return false;
}