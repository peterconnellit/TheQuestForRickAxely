#ifndef ROOM_H
#define ROOM_H

#include<string>
#include<vector>
#include<fstream>
#include"Object.h"

//Room class interface to the user

class Room
{
private:
	std::string name;
	std::string description;
	unsigned int roomNumber;
	std::vector<std::string> exits;
	std::vector<Object> objects;

public:

	Room();
	Room(std::string name, std::string description, unsigned int roomNumber, std::vector<std::string> exits, std::vector<Object> objects);
	~Room();

	void goToRoom(Room& r);

	//Getters and Setters for name etc.
	std::string getName();
	void setName(std::string nName);
	std::string getDescription();
	void setDescription(std::string desc);
	std::vector<std::string>getExits();
	std::vector<Object>getObjects();
	void setObjects(std::vector<Object> objsToAdd);
	unsigned int getRoomNumber();
	void setRoomNumber(unsigned int rNum);
	void setExits(std::vector<std::string> exits);
	//Additional functionality
	bool  checkForExit(std::string& exitName);
	void addObject(Object& objToAdd);
	bool removeObject(std::string& toRemove);
	bool isObjectInRoom(std::string& objToCHeck);
	Object* Room::getAnyObject(std::string& objToGet);
	void printRoom();
	//Load function
	void loadRoom(std::ifstream& inFile);
};

#endif 
