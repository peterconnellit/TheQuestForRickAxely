#include <string>
#include <iostream>
#include <Windows.h>

#include"ArenaOptions.h"
#include"PrintFunctionality.h"
#include"GetPlayerInputFunctions.h"

//Implementations of arena options
using std::string;		using std::cout;
using std::endl;		using std::cin;

//Same as equipment choice but another function for clearer read of code and future changes
int attackChoice()
{
	cout << "Enter attack you want to use 1 for fast attack (enemys block chance reduced) 2 for heavy attack (you get bonus damage)" << endl;
	int choice = 0;
	bool flag = false;
	//This will loop unless player enters 1 ro 2 as his choice
	do
	{
		//This adds > before input
		expInput();
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			flag = true;
		}
		else
		{
			println("Only 1 or 2 allowed as input");
			//Need to clear the buffer here
			cin.clear(); //Clears the buffer
			cin.ignore(80, '\n'); //ignores characters until end of line
		}

	} while (flag == false);

	if (choice == 1)
	{
		println("                     You thrust your speed");
	}
	else
	{
		println("                     Swinging mighty!!!");
	}

	return choice;
}

//Surrender option to exit program
bool surrenderOption()
{
	println("Do you want to fight another enemy type (f) enemy or you want to leave matches for now (l) ? ");
	string choice = "";
	bool flag = false;
	//This will loop unless player enters 1 ro 2 as his choice
	return checkForOption("l", "f");
}


bool checkForOption(string optForTrue, string opt2)
{
	string choice = "";
	bool flag = false;
	//This will loop unless player enters 1 ro 2 as his choice
	do
	{
		//This adds > before input
		expInput();
		cin >> choice;
		if (choice == optForTrue || choice == opt2)
		{
			flag = true;
		}
		else
		{
			cout << "Only " << optForTrue << " or " << opt2 << " allowed" << endl;
			//Need to clear the buffer here

			cin.clear(); //Clears the buffer
			cin.ignore(80, '\n'); //Ignores characters until end of line
		}
	} while (flag == false);

	//If player chooses to surrender, program exits
	if (choice == optForTrue)
	{
		return true;
	}
	return false;
}