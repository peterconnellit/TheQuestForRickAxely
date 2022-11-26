#include"Inventory.h"
#include"StringFunctionality.h"
#include<iostream>

//Implementation of inventory class

using std::list;
using std::cin;		using std::cout;
using std::endl;	using std::string;

//Implementation of inventory class that holds objects for player

typedef list<Object> objectContainer;

Inventory::Inventory()
{
}

Inventory::Inventory(objectContainer& objs)
{
	objects = objs;
}

Inventory::~Inventory()
{
}

void Inventory::addToInventory(Object& toAdd) //Object we want to add to inventory
{
	objects.push_back(toAdd);
}

objectContainer Inventory::getObjects()
{
	return objects; //Take vector which represents the inventory and puts it where we want it
}

void Inventory::printInventory()
{
	cout << "Inventory" << endl;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		//Print each object in inventory	
		cout << "Item: " << it->getName() << endl;
	}
}

void Inventory::removeFromInventory(Object toRemove)
{
	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (it->getName() == toRemove.getName())
		{
			objects.erase(it);
			itemFound = true;
			break;
		}
	}
	if (itemFound == false) //Not necessary just precaution
	{
		cout << "Object not found" << endl;
	}
}

void Inventory::removeFromInventory(string& toRemove)
{
	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toRemove))
		{
			objects.erase(it);
			itemFound = true;
			break;
		}
	}
	if (itemFound == false) //Not necessary just precaution
	{
		cout << "Object not found" << endl;
	}
}


bool Inventory::checkIsInInventory(string toCheck)
{
	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toCheck))
		{
			toCheck = it->getName();
			itemFound = true;
			break;
		}
	}
	if (itemFound == false) //not Necessary just precaution
	{
		//cout << "Object not found" << endl;
	}

	return itemFound;
}

Object* Inventory::getObjectByName(string& toGet)
{

	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toGet))
		{
			toGet = it->getName();
			return &(*it);
			break;
		}
	}
	if (itemFound == false) //Not necessary just precaution
	{
		//cout << "Object not found" << endl;
	}
	return NULL;
}


bool Inventory::checkUseWith(std::string& toCheck)
{
	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (getObjectByName(toCheck)->useWith((*it)) == true) //If the object is in inventory and you could use it with another one
		{
			cout << "You used " << toCheck << " with " << it->getName() << endl;
			objects.erase(it); //Erase net and let vase to be openable
			itemFound = true;
			break;
		}
	}
	if (itemFound == false)
	{
		//cout << "There is nothing you can use with this object in inventory" << endl;
	}

	return itemFound;
}