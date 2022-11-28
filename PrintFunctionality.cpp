#include <string>
#include <iostream>
#include <Windows.h>
#include"PrintFunctionality.h"

//Implementation of print functionality
using std::string;		using std::cout;
using std::endl;		using std::cin;

//Prints line and sets value for delay for type animation
void println(const string str)
{
	for (unsigned i = 0; i < str.length(); i++)
	{
		//Print each character
		cout << str[i];
		//You can adjust the time here
		Sleep(20);  //for Visual C http://www.dreamincode.net/forums/topic/228382-make-text-to-appear-letter-by-letter-in-console/
		// http://www.cplusplus.com/forum/unices/60161/ 
	}

	cout << endl;
}
//Prints centered line with delay
void printlnCenter(const string str)
{

	string centerd = centerString(str);


	for (unsigned i = 0; i < centerd.length(); i++)
	{
		cout << centerd[i]; //Be carefull when you are changing code

		//Can adjust the time here
		//Sleep(0);

	}

	cout << endl;
}

//Center string into middle of screen
string centerString(const string toCenter)
{

	//Get the size and width of current window
	CONSOLE_SCREEN_BUFFER_INFO winInfo;

	//Handle is an object which is declared at the start. This is active console output screen buffer.
	HANDLE activeconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Initialise window
	GetConsoleScreenBufferInfo(activeconsole, &winInfo);

	//This places width of current window into interger
	int colums;
	colums = winInfo.srWindow.Right - winInfo.srWindow.Left + 1;

	string centerSpace = "";
	unsigned l = toCenter.length();

	//Divides the current window int half
	unsigned pos = (int)((colums - l) / 2);

	for (unsigned i = 0; i < pos; i++)
	{
		centerSpace = centerSpace + " ";
	}

	return centerSpace + toCenter;

}
//Center string into middle of screen and subtract value you desire from it
string centerString(const string toCenter, int minus)
{

	//Get the size and width of current window
	CONSOLE_SCREEN_BUFFER_INFO winInfo;

	//Handle is an object which is declared at the start. This is active console output screen buffer.
	HANDLE activeconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Initialise window
	GetConsoleScreenBufferInfo(activeconsole, &winInfo);

	//Places width of current window into interger
	int colums;
	colums = winInfo.srWindow.Right - winInfo.srWindow.Left + 1;

	string centerSpace = "";
	unsigned l = toCenter.length();

	//Divides the current window int half
	unsigned pos = (int)((colums - (l + minus)) / 2);

	for (unsigned i = 0; i < pos; i++)
	{
		centerSpace = centerSpace + " ";
	}

	return centerSpace + toCenter;

}