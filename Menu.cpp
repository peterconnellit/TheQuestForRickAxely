#include "PrintFunctionality.h"
#include"GetPlayerInputFunctions.h"
#include <string>

using std::string;

//Implementation of simple menu
void showMenu()
{
	println("Do you wish to fight?");
	println("Yes (y) ");
	println("No (n) ");
}

void checkMenuInput()
{
	//Show simple menu
	showMenu();
	//Decide if to run or exit program
	string mChoice;
	//Check the user choice
	do
	{
		mChoice = userInput();
		if (mChoice == "y" || mChoice == "Y")
		{
			break;
		}
		else if (mChoice == "n" || mChoice == "N")
		{
			system("pause");
			exit(0);
		}
		else
		{
			println("Please enter a valid input");
		}
	} while (mChoice != "Y" || mChoice != "y" || mChoice != "n" || mChoice != "N");
}