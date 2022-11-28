#include "Object.h"
#include <iostream>

//Implementation of object class
using std::string;		using std::ifstream;
using std::cout;		using std::cin;
using std::endl;		using std::ofstream;


//Object class
//Constructors & Destructors
Object::Object()
{
}

Object::Object(string nName, string descrip, bool isOpe, bool isU, bool isE, bool isIm, string useWith, string open, int h, int arm, int blc, int atck, string whIsObj)
{
	name = nName;
	description = descrip;
	isOpenable = isOpe;
	mUseWith = useWith;
	mOpen = open;
	isUsable = isU;
	isEquipable = isE;
	isImportant = isIm;
	healthAdd = h;
	armorAdd = arm;
	blockAdd = blc;
	attackAdd = atck;
	whereIsObj = whIsObj;

}

Object::~Object()
{
}
//Getter & setter functions self explanatory names
bool Object::getisOpenable()
{
	return isOpenable;
}
bool Object::getIsUsable()
{
	return isUsable;
}
bool Object::getIsEquipable()
{
	return isEquipable;
}
bool Object::getIsImportant()
{
	return isImportant;
}
int Object::getHealthAdd()
{
	return healthAdd;
}
int Object::getArmorAdd()
{
	return armorAdd;
}
int Object::getBlockAdd()
{
	return blockAdd;
}
int Object::getAttackAdd()
{
	return attackAdd;
}
string Object::getName()
{
	return name;
}

void Object::setName(string nName)
{
	name = nName;
}
string Object::getDescription()
{
	return description;
}
void Object::setDescription(string desc)
{
	description = desc;
}

string Object::examine()
{
	return description;
}

string Object::open()
{
	return mOpen;
}
string Object::getUseWith()
{
	return mUseWith;
}
void Object::setOpenable(bool openable)
{
	isOpenable = openable;
}
void Object::setUseWith(string useW)
{
	mUseWith = useW;
}
void Object::setOpenDesc(string openD)
{
	mOpen = openD;
}

string Object::getWhereIsObj()
{
	return whereIsObj;
}

void Object::setWhereItIS(string location)
{
	whereIsObj = location;
	//cout << "setting location to "<<location << endl;
}


void Object::printObject()
{
	cout << "Obj name: " << name << endl;
	//cout << "Obj description: " << description << endl;
	//cout << "Obj isOpenable: " << isOpenable << endl;
	//cout << "Obj mUseWith: " << mUseWith << endl;
	cout << "Obj whereitis: " << whereIsObj << endl;
}

bool Object::useWith(Object& useWith) //check if the two objects are compatibile
{
	//If i type use pmv with net 
	if (mUseWith == useWith.getName())
	{
		isOpenable = true;
		return true;
	}
	else
	{
		return false;
	}


}

void Object::loadObject(ifstream& inFile)
{

	string garbage;

	inFile >> garbage >> name; //Read the object name
	//Read all of the objects member variables
	inFile >> garbage;
	getline(inFile, description);
	inFile >> garbage >> mUseWith;
	inFile >> garbage >> mOpen;
	inFile >> garbage >> isOpenable;
	inFile >> garbage >> isUsable;
	inFile >> garbage >> isEquipable;
	inFile >> garbage >> isImportant;
	inFile >> garbage >> healthAdd;
	inFile >> garbage >> armorAdd;
	inFile >> garbage >> blockAdd;
	inFile >> garbage >> attackAdd;
	inFile >> garbage >> whereIsObj;
}

void Object::saveObject(ofstream& oFile)
{
	oFile << "ObjectName " << name << endl;
	oFile << "description " << description << endl;
	oFile << "UseWith " << mUseWith << endl;
	oFile << "Open " << mOpen << endl;
	oFile << "isOpenable " << isOpenable << endl;
	oFile << "isUsable " << isUsable << endl;
	oFile << "isEquipable " << isEquipable << endl;
	oFile << "isImportant " << isImportant << endl;
	oFile << "healthAdd " << healthAdd << endl;
	oFile << "armorAdd " << armorAdd << endl;
	oFile << "blockAdd " << blockAdd << endl;
	oFile << "attackAdd " << attackAdd << endl;
	oFile << "RoomWhereItIs " << whereIsObj << endl;
	oFile << endl;
	/*ObjectName = Net
	description = Simple net for fishing.
	UseWith = nothing
	Open = canotOpen
	isOpenable = 0
	isUsable = 0
	isEquipable = 0
	healthAdd = 0
	armorAdd = 0
	blockAdd = 0
	attackAdd = 0
	RoomWhereItIs = Dock*/

}

void Object::loadStaticObjectParts(ifstream& inFile)
{

	string garbage;

	inFile >> garbage >> name; //Read the object name
	//Read all of the objects member variables
	inFile >> garbage;
	getline(inFile, description);
	inFile >> garbage >> healthAdd;
	inFile >> garbage >> armorAdd;
	inFile >> garbage >> blockAdd;
	inFile >> garbage >> attackAdd;

}

void Object::loadChangingObjectParts(ifstream& inFile)
{

	string garbage;

	inFile >> garbage >> mUseWith;
	inFile >> garbage >> mOpen;
	inFile >> garbage >> isOpenable;
	inFile >> garbage >> isUsable;
	inFile >> garbage >> isEquipable;
	inFile >> garbage >> isImportant;
	inFile >> garbage >> whereIsObj;
}