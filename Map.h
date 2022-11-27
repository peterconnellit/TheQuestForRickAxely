#ifndef MAP_H
#define MAP_H

#include"Room.h"
#include<vector>
#include<fstream>
#include<string>

//Map class interface to the user
class Map
{

private:
	std::vector<Room> mRooms; //Vector is the best data types small memory 
	//Consumption and fast acces with assigning memory before you put stuff inside you can even save time
	Room* mCurRoom; //Room that you are currently shown http://www.cplusplus.com/articles/ENywvCM9/ pointers and references

public:

	Map();
	//Full constructor
	Map(std::vector<Room> rooms);

	~Map();

	void loadRooms(std::ifstream& inFile);
	//Current room functionality
	void setCurrentRoom(Room& r1);
	void setCurrentRoom(std::string& rName);
	bool curRoomCheckExit(std::string& exit);
	bool curRoomCheckObj(std::string& obj);
	Object* curRoomGetAnyObj(std::string& objName);
	void removeObjectInCurRoom(std::string& toRemove);

	Room& getCurrentRoom();

	Room* getAnyRoom(std::string& rName);
	void putObjectInRoom(std::string& rName, Object& objectToPut);


	void printCurrentRoom();

	void printMap();
	void loadPosition(std::ifstream& inFile);
	void savePosition(std::ofstream& oFile);

};

#endif
