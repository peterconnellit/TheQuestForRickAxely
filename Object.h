#ifndef OBJECT_H
#define OBJECT_H

#include<string>
#include<fstream>
//Object class interface to the user

class Object
{
private:
	std::string name;
	std::string description;
	std::string mUseWith;
	std::string mOpen;
	bool isOpenable; //Can you open the object
	bool isUsable;
	bool isEquipable;
	bool isImportant;
	int healthAdd;
	int armorAdd;
	int blockAdd;
	int attackAdd;
	std::string whereIsObj;


public:
	Object();
	Object(std::string name, std::string description, bool isOpenable, bool isU, bool isE, bool isIm, std::string useWith, std::string open, int h, int arm, int blc, int atck, std::string whereIsObj);
	~Object();

	std::string examine();
	std::string open();

	//Getters and Setters for name etc.
	std::string getName();
	void setName(std::string nName);
	std::string getDescription();
	void setDescription(std::string desc);
	void setOpenable(bool openable);

	void setUseWith(std::string useWith);
	bool useWith(Object& useWith);
	std::string getUseWith();
	void setOpenDesc(std::string openDesc);

	void printObject();
	bool getisOpenable();
	bool getIsUsable();
	bool getIsImportant();

	bool getIsEquipable();
	int getHealthAdd();
	int getArmorAdd();
	int getBlockAdd();
	int getAttackAdd();
	std::string getWhereIsObj();
	void setWhereItIS(std::string location);

	void loadObject(std::ifstream& inFile);
	void saveObject(std::ofstream& oFile);
	void loadStaticObjectParts(std::ifstream& inFile);
	void loadChangingObjectParts(std::ifstream& inFile);
};


#endif