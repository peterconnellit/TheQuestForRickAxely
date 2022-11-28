#include"Parser.h"
#include"Room.h"
#include"Player.h"
#include"Inventory.h"
#include"Object.h"
#include"Map.h"
#include"GetPlayerInputFunctions.h"
#include"StringFunctionality.h"
#include"ArenaMainApp.h"
#include"AddedItems.h"
#include<iostream>
#include<algorithm>
#include"LoadFunctions.h"

//Implementation of parser
using std::vector;		using std::string;
using std::cout;		using std::cin;
using std::endl;		using std::transform;

typedef vector<string> stringContainer; //Only change here for std::list 

//Pass reference to vector i want to check (before it was sentence)
void parse(Map& currentMap, Player& curPlayer, stringContainer& sentence, LoadedObjects& loadedObj, LoadedEnemies& allEnem, LoadedGames& allPuzzles)//if you sort the vector search time is faster so maybe use sorted vector
{
	//cout << "A of map" << &currentMap << endl;
	//Fits the vector to its actual size possibly saving memory
	sentence.shrink_to_fit(); //http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/

	bool foundConnection = false; //Connected verb with object

	if (foundInSentence(sentence, "go") == true)
	{
		//Search for room names
		//If it finds room (you are going to)
		//If fails sorry no option
		searchRoomExitNames(sentence, currentMap, curPlayer, allEnem, loadedObj);
	}
	else if (foundInSentence(sentence, "examine") == true)
	{
		//Search for object name
		//If it finds object (do something)
		//If fails sorry no option
		searchForObjectNameDescription(sentence, curPlayer);
	}
	else if (foundInSentence(sentence, "use") == true)
	{
		//Search for object name in inventory
		//If it finds object (do something)
		//If fails sorry no option
		isInInventoryUse(sentence, curPlayer, loadedObj);
	}
	else if (foundInSentence(sentence, "equip") == true)
	{
		//Search for object name in inventory
		//If it finds object (do something)
		//If fails sorry no option
		isInInventoryEquip(sentence, curPlayer, loadedObj);
	}
	else if (foundInSentence(sentence, "open") == true)
	{
		//Search for object name
		//If it finds object (do something)
		//If fails sorry no option
		isInInventoryOpen(sentence, curPlayer, loadedObj);
	}
	else if (foundInSentence(sentence, "pick") == true)
	{
		//search for object name
		//if it finds object (do something)
		//if fails sorry no option
		isObjectInRoom(sentence, currentMap, curPlayer, loadedObj);
	}
	else if (foundInSentence(sentence, "unequip") == true)
	{
		//search for object name
		//if it finds object (do something)
		//if fails sorry no option
		isInEquipedUnequip(sentence, curPlayer, loadedObj);
	}
	else if (foundInSentence(sentence, "show") == true)
	{
		curPlayer.getInventory().printInventory();
		curPlayer.getEquiped().printEquiped();
		curPlayer.print();
	}
	else if (foundInSentence(sentence, "exit") == true)
	{
		exit(0);
	}
	else if (foundInSentence(sentence, "attend") == true) //Checks if you are in arena and starts the fights
	{
		if (currentMap.getCurrentRoom().getName() == "Arena")
		{
			arenaStartApp(curPlayer, loadedObj);
		}
		else
		{
			cout << "You have to be in Arena to attend the matches." << endl;
		}

	}
	else if (foundInSentence(sentence, "help") == true)
	{
		cout << "Keywords: " << "go to, " << "examine, " << "open, " << "pick up, " << "show inventory, " << "use, " << "attend matches, " << "equip, " << "unequip, " << "exit, " << "save, " << "quicks, " << "solve" << endl;
	}
	else if (foundInSentence(sentence, "save") == true)
	{
		cout << "You have saved game" << endl;
		saveGame(loadedObj, curPlayer, currentMap, allEnem); //Save game and tracks all the objects

	}
	else if (foundInSentence(sentence, "quicks") == true)
	{
		cout << "You have quick saved game" << endl;
		quickSaveGame(loadedObj, curPlayer, currentMap, allEnem); //Save game and tracks all the objects but resets non important ones

	}
	else if (foundInSentence(sentence, "solve") == true)
	{
		//Load random game from possible games loaded from txt file
		allPuzzles.loadRandomGame();
		cout << "You got health potion for playing the minigame" << endl;
		addPotion(curPlayer, loadedObj);
	}
	else
	{
		//No words found for parser
		cout << "No keywords entered " << endl;
	}


}

bool foundInSentence(stringContainer& sentence, string toSearchFor) //Get meaning to word for example open== asociated with door in current room
{
	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (toLowerCase((*iter)) == toSearchFor)
		{
			return true; //Found word
		}
	}
	return false; //Didnt find word
}

//For GO
void searchRoomExitNames(stringContainer& sentence, Map& currMap, Player& currPlayer, LoadedEnemies& allEnem, LoadedObjects& allObjs)//check for exits http://stackoverflow.com/questions/919406/what-is-the-difference-between-accesing-vector-elements-using-an-iterator-vs-an
{
	bool foundExit = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		//Check if any word matches the exit name
		if (currMap.curRoomCheckExit((*iter)) == true)
		{
			cout << "You are walking to: " << (*iter) << endl;
			if (checkForFight(currPlayer, allEnem, allObjs, (*iter)))
			{
				cout << "After that scarry encounter you arrived in " << (*iter) << endl;
			}
			currMap.setCurrentRoom((*iter)); //Set the room in the map
			currMap.printCurrentRoom(); //Print the description of the room you are in now
			foundExit = true;
			break; //Prevents from printing more than once
		}
	}
	if (foundExit == false)
	{
		//no option
		cout << "You cannot go there" << endl;
	}
}

//For examine
void searchForObjectNameDescription(stringContainer& sentence, Player& currPlayer)
{
	bool foundObject = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (currPlayer.isInPInventory((*iter)) == true)
		{
			cout << (*currPlayer.getInventory().getObjectByName((*iter))).examine() << endl; //Returns the pointer	
			foundObject = true;
			break; //Prevents from printing more than once at the time
		}
	}
	if (foundObject == false)
	{
		//Sorry no option
		cout << "You dont have that object in inventory" << endl;
	}

}

//For open
void isInInventoryOpen(stringContainer& sentence, Player& currPlayer, LoadedObjects& loadedObj) //Pass player to check his inventory
{
	bool foundObject = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{

		if (currPlayer.isInPInventory((*iter)) == true)
		{
			if (currPlayer.getInventory().getObjectByName((*iter))->getisOpenable() == true)
			{
				//Choose from items you can get depending what is in open slot as item name
				if (currPlayer.getInventory().getObjectByName((*iter))->open() == "shield")
				{
					loadedObj.removeByName((*iter));
					cout << "You openned " << (*iter) << " and there was golden shield" << endl;
					addGoldenShield(currPlayer, loadedObj); //Add newly made object that appers in inventory
					currPlayer.removeFromInventory((*iter)); //Remove object	
				}
				else if (currPlayer.getInventory().getObjectByName((*iter))->open() == "armor")
				{
					loadedObj.removeByName((*iter));
					cout << "You openned " << (*iter) << " and there was golden armor" << endl;
					addGoldenArmor(currPlayer, loadedObj);
					currPlayer.removeFromInventory((*iter));
				}
				else
				{
					loadedObj.removeByName((*iter));
					cout << "You openned " << (*iter) << " and there was nothing" << endl;
					currPlayer.removeFromInventory((*iter));
				}

				foundObject = true;
				break; //Prevents from printing more than once at the time
			}
			else
			{
				cout << "You cannot open that" << endl;
				foundObject = true;
				break; //Prevents from printing more than once at the time;
			}
		}
	}
	if (foundObject == false)
	{
		//Sorry no option
		cout << "You dont have that object in inventory" << endl;
	}
}

//For pick up
void isObjectInRoom(stringContainer& sentence, Map& currMap, Player& curPlayer, LoadedObjects& loadedObj)
{
	//cout << "A of map" << &currMap << endl;
	bool foundObj = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (currMap.curRoomCheckObj((*iter)) == true)
		{
			//Remove from room	
			curPlayer.pickUp((*currMap.curRoomGetAnyObj((*iter))));
			//cout << "address you are picking up" << &(*currMap.curRoomGetAnyObj((*iter)))<<endl;
			currMap.removeObjectInCurRoom((*iter)); //Remove object		
			cout << "You picked up " << (*iter) << endl;
			loadedObj.setWhereitIS((*iter), "inventory");
			foundObj = true;
			break; //Prevents from looping more
		}
	}
	if (foundObj == false)
	{
		//Sorry no option
		cout << "There is nothing by that name to be picked up in this room" << endl;
	}
}

//For use
void isInInventoryUse(stringContainer& sentence, Player& currPlayer, LoadedObjects& loadedObj) //Pass player to check his inventory
{
	bool foundObject = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (currPlayer.isInPInventory((*iter)) == true)
		{
			if (currPlayer.getInventory().getObjectByName((*iter))->getIsUsable() == true) //If it is usable use it
			{
				cout << "You used " << (*iter) << endl;
				readObjectStats(currPlayer, (*iter));
				currPlayer.removeFromInventory((*iter)); //Remove object
				loadedObj.removeByName((*iter));
				foundObject = true;
				break; //Prevents from using more than once
			}
			else if (currPlayer.getInventory().getObjectByName((*iter))->getUseWith() != "nothing") //If you can use it with something
			{
				if (currPlayer.checkUseWith((*iter)) == true) //If there is something that you can use it with in inventory 
				{
					cout << "Now you can open " << (*iter) << endl;
					loadedObj.setWhereitIS((*iter), "inventory");
					loadedObj.removeByName("net");
				}
				else
				{
					cout << "There is nothing you can use with this object in inventory" << endl;
				}
				foundObject = true;
				break; //Prevents from using more than once
			}
			else
			{
				cout << "You cannot use that" << endl;
				foundObject = true;
				break; //Prevents from using more than once
			}
		}
	}
	if (foundObject == false)
	{
		//Sorry no option
		cout << "You dont have that object in inventory" << endl;
	}
}

//Adds the bonus stats from object and prints them if they are more or less than 0
void readObjectStats(Player& currPlayer, string& objName)
{
	currPlayer.setArmor(currPlayer.getInventory().getObjectByName(objName)->getArmorAdd());
	//If it is 0 then dont print it
	if (currPlayer.getInventory().getObjectByName(objName)->getArmorAdd() == 0)
	{
	}
	else
	{
		cout << "You were added " << currPlayer.getInventory().getObjectByName(objName)->getArmorAdd() << " armor" << endl;
	}
	currPlayer.setAttack(currPlayer.getInventory().getObjectByName(objName)->getAttackAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getAttackAdd() == 0)
	{
	}
	else
	{
		cout << "You were added " << currPlayer.getInventory().getObjectByName(objName)->getAttackAdd() << " attack" << endl;
	}
	currPlayer.setBlockChance(currPlayer.getInventory().getObjectByName(objName)->getBlockAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getBlockAdd() == 0)
	{
	}
	else
	{
		cout << "You were added " << currPlayer.getInventory().getObjectByName(objName)->getBlockAdd() << " block" << endl;
	}
	currPlayer.addHealth(currPlayer.getInventory().getObjectByName(objName)->getHealthAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getHealthAdd() == 0)
	{
	}
	else
	{
		cout << "You were added " << currPlayer.getInventory().getObjectByName(objName)->getHealthAdd() << " health" << endl;
	}
	cout << "Your new stats" << endl;
	currPlayer.print();
}

//For equip
void isInInventoryEquip(stringContainer& sentence, Player& currPlayer, LoadedObjects& loadedObj) //Pass player to check his inventory and equiped
{
	bool foundObject = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (currPlayer.isInPInventory((*iter)) == true)
		{
			if (currPlayer.getInventory().getObjectByName((*iter))->getIsEquipable() == true)
			{
				foundInvEquip((*iter), currPlayer, loadedObj);
				foundObject = true;

				break; //Prevents from using more than once
			}
			else
			{
				cout << "You canot equip that" << endl;
				foundObject = true;
				break; //Prevents from using more than once
			}
		}
	}
	if (foundObject == false)
	{
		//Sorry no option
		cout << "You dont have that object in inventory" << endl;
	}
}

//If the object is in inventory you can equip it
void foundInvEquip(string whatObject, Player& currPlayer, LoadedObjects& loadedObj)
{
	string slot = (*currPlayer.getInventory().getObjectByName(whatObject)).open();
	if (currPlayer.getEquiped().checkForSlot(slot) == true)
	{
		cout << "You have already equiped item in that slot" << endl;
	}
	else
	{
		loadedObj.setWhereitIS(whatObject, "equiped");
		cout << "You equiped " << whatObject << endl;
		currPlayer.equip((*currPlayer.getInventory().getObjectByName(whatObject)));
		readObjectStats(currPlayer, whatObject); //Have to subtract when taken off
		currPlayer.removeFromInventory((*currPlayer.getInventory().getObjectByName(whatObject))); //Remove object
	}
}

//for unequip
void isInEquipedUnequip(stringContainer& sentence, Player& currPlayer, LoadedObjects& loadedObj) //Pass player to check his equiped and unequiped
{
	bool foundObject = false;

	for (stringContainer::iterator iter = sentence.begin(); iter != sentence.end(); ++iter)
	{
		if (currPlayer.isInEquiped((*iter)) == true)
		{
			loadedObj.setWhereitIS((*iter), "inventory");
			cout << "You unequiped " << (*iter) << endl;
			currPlayer.pickUp((*currPlayer.getEquiped().getAnyEquiped((*iter))));
			uneadObjectStats(currPlayer, (*iter)); //Have to subtract when taken off
			currPlayer.removeFromEquiped((*currPlayer.getInventory().getObjectByName((*iter)))); //Remove object
			foundObject = true;
		}
	}
	if (foundObject == false)
	{
		//Sorry no option
		cout << "You dont have that object in equiped" << endl;
	}
}

//Adds the bonus stats from object and prints them if they are more or less than 0
void uneadObjectStats(Player& currPlayer, string& objName)
{
	currPlayer.setArmor(-currPlayer.getInventory().getObjectByName(objName)->getArmorAdd());
	//If it is 0 then dont print it
	if (currPlayer.getInventory().getObjectByName(objName)->getArmorAdd() == 0)
	{
	}
	else
	{
		cout << "You were subtracted " << currPlayer.getInventory().getObjectByName(objName)->getArmorAdd() << " armor" << endl;
	}
	currPlayer.setAttack(-currPlayer.getInventory().getObjectByName(objName)->getAttackAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getAttackAdd() == 0)
	{
	}
	else
	{
		cout << "You were subtracted " << currPlayer.getInventory().getObjectByName(objName)->getAttackAdd() << " attack" << endl;
	}
	currPlayer.setBlockChance(-currPlayer.getInventory().getObjectByName(objName)->getBlockAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getBlockAdd() == 0)
	{
	}
	else
	{
		cout << "You were subtracted " << currPlayer.getInventory().getObjectByName(objName)->getBlockAdd() << " block" << endl;
	}
	currPlayer.addHealth(-currPlayer.getInventory().getObjectByName(objName)->getHealthAdd());
	if (currPlayer.getInventory().getObjectByName(objName)->getHealthAdd() == 0)
	{
	}
	else
	{
		cout << "You were subtracted " << currPlayer.getInventory().getObjectByName(objName)->getHealthAdd() << " health" << endl;
	}
	cout << "Your new stats" << endl;
	currPlayer.print();
}