#include"Room.h"
#include"PrintFunctionality.h"
#include"ArenaMainApp.h"
#include"StringFunctionality.h"
#include"GetPlayerInputFunctions.h"

//Implementation of room class

#include<string>
#include<iostream>
#include<vector>

using std::string;		using std::vector;
using std::cout;		using std::cin;
using std::endl;		using std::ifstream;

//Defines types, change here if desired
typedef vector<Object> objContainer;
typedef vector<string> strContainer;

Room::Room()
{
	name = "no name";
	description = "no description";
	roomNumber = 99;
}

Room::Room(string nName, string desc, unsigned int roomN, strContainer ext, objContainer obj)
{
	name = nName;
	description = desc;
	roomNumber = roomN;
	exits = ext; //Puts whole vector in
	objects = obj;
}

Room::~Room()
{
}


string Room::getName()
{
	return name;
}

void Room::setName(std::string nName)
{
	name = nName;
}
string Room::getDescription()
{
	return description;
}
void Room::setDescription(std::string desc)
{
	description = desc;
}
unsigned int Room::getRoomNumber()
{
	return roomNumber;
}

strContainer Room::getExits()
{
	return exits;
}
//If user wants to leave room, we have to check if he can use exit input typed
bool  Room::checkForExit(string& exitName)
{
	bool exitFound = false;
	for (strContainer::iterator it = exits.begin(); it != exits.end(); ++it)
	{
		if (toLowerCase((*it)) == toLowerCase(exitName))
		{
			exitName = (*it); //To add capital letter at the beginning if user didnt type it and we want to use it
			exitFound = true;
			break;
		}
	}
	return exitFound;
}

void Room::setObjects(objContainer objsToAdd)
{
	objects = objsToAdd;
}

objContainer Room::getObjects()
{
	return objects;
}

void Room::goToRoom(Room& r) //Load new room according to previous room
{
	std::cout << "going into room" << std::endl;
}

void Room::setRoomNumber(unsigned int rNum)
{
	roomNumber = rNum;
}

void Room::setExits(strContainer exit)
{
	exits = exit;
}

void Room::printRoom()
{
	cout << "Area number: " << roomNumber << endl;
	printlnCenter("--------------------------------------------------");
	printlnCenter("Area name: " + name);
	printlnCenter("--------------------------------------------------");
	cout << "Area desc: " << endl;
	printInLines(description, '.');
	cout << "You can see objects: ";
	for (objContainer::iterator it = objects.begin(); it != objects.end(); ++it) //Print objects
	{
		cout << " " << it->getName();
	}
	cout << endl;
	cout << "From here you can go to: ";
	for (strContainer::size_type i = 0; i != exits.size(); i++) //Print exits
	{
		cout << " " << exits[i] << "-->";
	}
	cout << endl;
	cout << "What do you want to do ? " << endl;
}

void Room::addObject(Object& objToAdd)
{
	objects.push_back(objToAdd);
	//cout << "Address in room"<< &objToAdd << endl;
}

bool Room::removeObject(string& toRemove)
{
	bool removed = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(toRemove))
		{
			///cout << "address when removing:" << &it << endl;
			objects.erase(it); //Remove the object at the position of pointer
			removed = true;
			break;
		}
	}

	return removed;
}

//Returns true or false if object typed is in room
bool Room::isObjectInRoom(string& objToCHeck)
{
	bool itIs = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(objToCHeck))
		{
			objToCHeck == it->getName();
			itIs = true;
			break;
		}
	}

	return itIs;
}

//Returns pointer to the object wy want to get
Object* Room::getAnyObject(string& objToGet)
{
	bool itIs = false;
	for (objContainer::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		if (toLowerCase(it->getName()) == toLowerCase(objToGet))
		{
			objToGet == it->getName();
			return &(*it);
			break;
		}
	}
	return NULL;
}

void Room::loadRoom(ifstream& inFile)
{
	string garbage = "";
	int exitNumber = 0; //For loop 
	string curExit = "";
	std::vector<Object> objects;
	//Read the rooms member variables
	inFile >> garbage >> roomNumber; //Read the room number
	inFile >> garbage >> name;
	inFile >> garbage;
	getline(inFile, description); //Gets the description as the whole line with spaces
	inFile >> garbage >> exitNumber;

	for (unsigned int i = 0; i != exitNumber; i++)
	{
		inFile >> garbage >> curExit;
		exits.push_back(curExit); //Get all the exit names
	}

}