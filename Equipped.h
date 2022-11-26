#ifndef EQUIPED_H
#define EQUIPED_H
#include<string>
#include<list>
#include"Object.h"

//This is Equipped class interface to the user
class Equipped
{
private:
	std::list<Object> objects; //You can add size...

public:
	//Constructors
	Equipped();
	Equipped(std::list<Object>& objs);
	//Deconstructor
	~Equipped();
	//Getters setters and functions
	void addToEquipped(Object& toAdd); //Add object
	void removeFromEquipped(Object toAdd);
	void removeFromEquipped(std::string& toRemove);
	bool checkIsEquipped(std::string& toCheck);
	std::list<Object> getObjects(); //Return all objects in inventory

	Object* getAnyEquipped(std::string& toCheck);
	bool checkForSlot(std::string slot);

	void printEquipped();
};

#endif