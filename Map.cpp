#include"Map.h"
#include"StringFunctionality.h"
#include<iostream>

//Implementation of map class
using std::string;		using std::vector;
using std::ifstream;	using std::ofstream;
using std::cin;			using std::cout;
using std::endl;
typedef vector<Room> roomVec;

Map::Map()
{
	mCurRoom = new Room; //Initialize my pointer with value of empty room
}

Map::Map(roomVec rooms)
{
	mRooms = rooms;
}

Map::~Map()
{
	delete mCurRoom; //Delete instance of new room
}

void Map::loadRooms(ifstream& inFile)
{
	//Check file how many times the loop will execute
	string garbage;
	unsigned int roomsTotal;

	inFile >> garbage >> roomsTotal;
	mRooms.reserve(roomsTotal); //Reserves the space for vector, saving memory space

	while (!inFile.eof()) //Loop through all rooms in file
	{

		Room loadedRoom;
		loadedRoom.loadRoom(inFile);
		mRooms.push_back(loadedRoom); //Push one room into map

	}

}


void Map::printMap()
{
	for (roomVec::iterator it = mRooms.begin(); it != mRooms.end(); ++it)
	{
		it->printRoom();
	}
}

void Map::setCurrentRoom(Room& r1)
{
	mCurRoom = &r1;

}

void Map::setCurrentRoom(string& rName)
{
	mCurRoom = this->getAnyRoom(rName);
}

Room& Map::getCurrentRoom()
{
	return (*mCurRoom);//Gets pointer to the room we are currently in
}

bool Map::curRoomCheckExit(string& exit)
{
	return (*mCurRoom).checkForExit(exit);
}

bool Map::curRoomCheckObj(string& obj)
{
	return (*mCurRoom).isObjectInRoom(obj);

}

//Returns the pointer to the object we specify by name
Object* Map::curRoomGetAnyObj(string& objName)
{
	return (*mCurRoom).getAnyObject(objName);
}

//Returns the pointer to the room we specify by name
Room* Map::getAnyRoom(string& rName)
{
	bool found = false;

	for (roomVec::iterator iter = mRooms.begin(); iter != mRooms.end(); ++iter)
	{
		if (toLowerCase(iter->getName()) == toLowerCase(rName))
		{
			found = true;
			return &(*iter);
		}
	}
	if (found == false)
	{
		cout << "room Not found" << endl;
		return NULL;
	}


}

//Used when loading objects from file
void Map::putObjectInRoom(string& rName, Object& objectToPut)
{

	bool roomFound = false;
	for (roomVec::iterator iter = mRooms.begin(); iter != mRooms.end(); ++iter)
	{
		if (iter->getName() == rName)
		{
			iter->addObject(objectToPut);
			roomFound = true;
			break;
		}
	}
	if (roomFound == false)
	{
		cout << "room Not found" << endl;
	}
}


void Map::removeObjectInCurRoom(string& toRemove)
{
	mCurRoom->removeObject(toRemove);

}

void Map::printCurrentRoom()
{
	mCurRoom->printRoom();
}

void Map::loadPosition(ifstream& inFile)
{
	string position;
	inFile >> position;
	cout << position << endl;
	mCurRoom = this->getAnyRoom(position);
}

void Map::savePosition(ofstream& oFile)
{

	oFile << mCurRoom->getName();
}