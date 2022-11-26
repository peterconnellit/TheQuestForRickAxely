#include"LoadedObjects.h"
#include"StringFunctionality.h"
#include<iostream>

using std::string;		using std::vector;
using std::cout;		using std::endl;
using std::ofstream;	using std::ifstream;
typedef vector<Object> objContainer;

LoadedObjects::LoadedObjects()
{

}


LoadedObjects::LoadedObjects(std::vector<Object>& objs, std::vector<Object>& notImportantObjs)
{
	objects = objs;
	notImportantOnes = notImportantObjs;
}


LoadedObjects::~LoadedObjects()
{

}

void LoadedObjects::loadAllObjects(ifstream& inFile)
{

	while (!inFile.eof()) //Loop through all file objects
	{
		Object loadedObj;
		loadedObj.loadObject(inFile);
		if (loadedObj.getName() == "")
		{
			//cout << "Discarding empty obj" << endl;
		}
		else
		{
			objects.push_back(loadedObj);
		}
	}

}

void LoadedObjects::loadAllObjectsParts(ifstream& inFileStatic, ifstream& inFileChanging)
{

	while (!inFileStatic.eof()) //Loop through all file objects
	{
		Object loadedObj;
		loadedObj.loadStaticObjectParts(inFileStatic);
		loadedObj.loadChangingObjectParts(inFileChanging);
		if (loadedObj.getName() == "")
		{
			//cout << "Discarding empty obj" << endl;
		}
		else
		{
			objects.push_back(loadedObj);
		}

	}
}

//Sort loaded objects between players inventory equipped and map rooms
void LoadedObjects::sortAllObjects(Map& currMap, Player& currPlayer)
{
	bool found = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if (it->getWhereIsObj() == "inventory")
		{
			currPlayer.pickUp(*it);
			//cout << "picking sorting" << endl;
			found = true;
		}
		else if (it->getWhereIsObj() == "equipped")
		{
			currPlayer.equip(*it);
			//cout << "equipping sorting" << endl;
			found = true;
		}
		else if (it->getWhereIsObj() == "nowhere")
		{

			//cout << "equipping sorting" << endl;
			found = true;
		}
		else
		{
			currMap.putObjectInRoom(it->getWhereIsObj(), *it);
			//cout << "Into room sorting" << endl;
			//cout << "Loaded obj address of "<<it->getName() << &(*it) << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "didn't find where to put obj" << endl;
	}

}
//Set the position of the objects between player and rooms according to changes in game
void LoadedObjects::setWhereitIS(string toChange, string actualWhereItis)
{
	Object toClone;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toChange))
		{
			//If the object is not important, clone it for quick save so that it will be returned into game
			if (it->getIsImportant() == false)
			{
				toClone = (*it);
				notImportantOnes.push_back(toClone); //Push the object into vector we save with quick save to reset the state of game
			}
			else
			{
				//Change where object is after
			}
			it->setWhereItIS(actualWhereItis);
		}
	}
}
//Clone potion, adds to players inventory and loaded objects for saving later if player has not used all potions
void LoadedObjects::addPotionAfterBattleWithClone(Player& currPlayer)
{
	Object toClone;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if (toLowerCase(it->getName()) == "potionb")
		{
			toClone = (*it);
			toClone.setWhereItIS("inventory");
			objects.push_back(toClone);
			currPlayer.pickUp(toClone);
			break;
		}
	}

}


void LoadedObjects::removeByName(string toRemove)
{
	bool erased = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toRemove))
		{
			objects.erase(it);
			erased = true;
			break; //Iterator is invalidated. Instead of validating it again, break after you found object
		}
	}
	if (erased == false)
	{
		cout << "didn't erase it" << endl;
	}
}

Object& LoadedObjects::getByName(string toGet)
{
	bool found = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toGet))
		{
			return *it;
			found = true;
			break;//Iterator is invalidated. Instead of validating it again, break after you found it
		}
	}
	if (found == false)
	{
		cout << "didn't find it" << endl;
	}
}
//Full game save that tracks all objects
void LoadedObjects::saveAllObjects(ofstream& oFile)
{
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		it->saveObject(oFile);
	}
}

//Do the full save and reset the state of unimportant objects
void LoadedObjects::quickSaveAllObjects(ofstream& oFile)
{
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		it->saveObject(oFile);
	}
	for (objContainer::iterator ite = notImportantOnes.begin(); ite != notImportantOnes.end(); ite++)
	{
		ite->saveObject(oFile);
	}
}


void LoadedObjects::printAllObjs()
{
	for (objContainer::iterator it = objects.begin(); it != objects.end(); it++)
	{
		it->printObject();
	}
}