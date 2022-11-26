#ifndef INVENTORY_H
#define INVENTORY_H

#include<string>
#include<list>
#include"Object.h"

//Inventory class interface to the user
class Inventory
{
private:
	std::list<Object> objects;//  http://www.cplusplus.com/reference/stl/  list constant time in inserting and deleting if we need to save memory vector more efficient
	//vector can be faster than list http://stackoverflow.com/questions/8742462/stdforward-list-and-stdforward-listpush-back with right implementation

public:
	Inventory();
	Inventory(std::list<Object>& objs);
	~Inventory();

	void addToInventory(Object& toAdd); //Add object
	void removeFromInventory(Object toRemove);
	void removeFromInventory(std::string& toRemove);
	bool checkIsInInventory(std::string toCheck);

	Object* getObjectByName(std::string& toGet);

	std::list<Object> getObjects(); //Return all objects in inventory
	bool checkUseWith(std::string& toCheck);
	void printInventory();

};

#endif