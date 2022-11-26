#ifndef GETPLAYERINPUT_H
#define GETPLAYERINPUT_H

#include<string>
#include<vector>

//Get player input interface to the user

//This takes player input and returns vector of words
std::vector<std::string> getInputn();

//This takes sentence and splits it into vector
std::vector<std::string> split(const std::string& s);

//Puts > before user input
void expInput();

//Function that takes input
std::string userInput();

#endif