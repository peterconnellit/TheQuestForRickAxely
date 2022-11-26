#include"Equiped.h"
#include"Object.h"
#include"StringFunctionality.h"
#include"GetPlayerInputFunctions.h"
#include<iostream>

//Implementation of equiped class
using std::list;	using std::string;
using std::cin;		using std::cout;
using std::endl;

//Class of objects that player has currently equiped

typedef list<Object> objectContainer;

Equipped::Equipped()
{

}

Equipped::Equipped(objectContainer& objs)
{
	objects = objs;
}

Equipped::~Equipped()
{

}

void Equipped::addToEquipped(Object& toAdd) //Object we want to add to equipped
{
	objects.push_back(toAdd);
}

objectContainer Equipped::getObjects()
{
	return objects; //Take the vector which represents the equipped and puts it where we want it
}

void Equipped::printEquipped()
{
	cout << "Equipped " << "slots: arm chest hand " << endl;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		//Print each object in equipped
		cout << "Item: " << it->getName() << endl;
	}

}

void Equipped::removeFromEquipped(Object toRemove)
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

void Equipped::removeFromEquipped(string& toRemove)
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
	if (itemFound == false)
	{
		cout << "Object not found" << endl;
	}
}


bool Equipped::checkIsEquipped(string& toCheck)
{

	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toCheck)) //Check is done without case sensitivity
		{
			itemFound = true;
			break;
		}

	}

	if (itemFound == false) //Not necessary just precaution
	{
		//cout << "Object is not equipped" << endl;
	}

	return itemFound;
}


Object* Equipped::getAnyEquipped(string& toCheck)
{

	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{

		if (toLowerCase(it->getName()) == toLowerCase(toCheck))
		{
			return &(*it);
			itemFound = true;
			break;
		}

	}

	if (itemFound == false) //Not necessary just precaution
	{
		cout << "getAnyEquipped false" << endl;
	}
}

bool Equipped::checkForSlot(string slot)
{

	bool itemFound = false;
	for (objectContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{

		if (toLowerCase(it->open()) == toLowerCase(slot))
		{
			itemFound = true; //If it is same slot return true
			break;
		}

	}

	if (itemFound == false) //Not necessary just precaution
	{
		//cout << "checkForSlot false" << endl;
	}

	return itemFound;

}