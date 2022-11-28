#include"StringFunctionality.h"
#include<iostream>

//Implementation of string functions
//Here are some functions that help me work with strings
using std::string;		using std::vector;
using std::cout;		using std::cin;
using std::endl;


//Takes what character you want to replace and replaces it with another 
string findCharAndReplace(string forReplace, char toReplace)
{
	//Find the char in the string
	for (string::size_type i = 0; i != forReplace.size(); i++) //Replace all the stars with spaces
	{
		if (forReplace[i] == toReplace)
		{
			forReplace[i] = ' ';
		}
	}

	return forReplace;
}

void printInLines(string toPrint, char newLine)
{
	//Find the char in the string
	for (string::size_type i = 0; i != toPrint.size(); i++) //Replace all the dots with new lines
	{
		cout << toPrint[i];
		if (toPrint[i] == newLine)
		{
			cout << endl;
		}
	}

}

//Converts whole string to lowercase
string toLowerCase(string toCast)//http://www.gamedev.net/topic/405347-tolowercase-and-touppercase-in-c/
{
	string str(toCast);

	for (string::size_type i = 0; i != toCast.size(); i++) //Replace all the stars with spaces
	{
		str[i] = tolower(str[i]);
	}

	return str;

}

//Replaces section of your choice
string checkAndReplace(string forReplace, string whatToReplace, string replaceWith)//http://stackoverflow.com/questions/5878775/how-to-find-and-replace-string
{

	size_t f = forReplace.find(whatToReplace);

	//Replaces text 
	return forReplace.replace(f, string(whatToReplace).length(), replaceWith);

}

//Removes words in vector of strings
vector<string> removeAllByname(vector<string> toRemove, string forRemove)//http://stackoverflow.com/questions/9121532/delete-strings-in-a-vector
{

	for (int q = 0; q < toRemove.size(); q++)
	{
		string theCurrentWord = toLowerCase(toRemove[q]);
		if (theCurrentWord == forRemove)
		{
			toRemove.erase(toRemove.begin() + q);
			//cout << "removed" << endl;
			--q;
		}
	}

	return toRemove;
}