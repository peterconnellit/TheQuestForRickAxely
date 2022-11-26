#include"GetPlayerInputFunctions.h"
#include"StringFunctionality.h"
#include<cctype> //Defines isspace
#include<iostream>

using std::vector;		using std::string;
using std::cin;			using std::cout;
using std::endl;

//Implementation of functions for player input

//Take sentence and return vector of words
vector<string> getInputn()
{
	expInput();
	string sentence = "";
	//Get line of input from user and store it

	getline(cin, sentence);

	vector<string> words = split(sentence);

	return words;

}


//Take sentence and split it into vector
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type stringSize;
	stringSize i = 0;

	//Loop through characters in sentence and sort them
	while (i != s.size())
	{
		//Check and jump over space if we are not at the end of sentence
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}
		//Get the beginning of the word
		stringSize j = i;
		//If there are no spaces and we are not at the end increase j
		while (j != s.size() && !isspace(s[j]))
		{
			++j;
		}

		//If we found some nonwhite spaces put them into vector as one string
		if (i != j)
		{

			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	} //Stops at end of the sentence
	//Return vector of strings
	return ret;

}

//Puts > before user input
void expInput()
{
	cout << ">";
}
//Function that takes input
string userInput()
{
	string word = "";

	//This ads > before input
	expInput();
	cin >> word;

	return word;
}