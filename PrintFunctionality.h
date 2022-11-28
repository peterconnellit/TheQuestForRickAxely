#ifndef PRINTFUNCTIONALITY_H
#define PRINTFUNCTIONALITY_H

//Print functionality interface to the user
#include<string>


//Function that prints line of text into console
void println(const std::string line);
//Centered line
void printlnCenter(const std::string str);
//Add string center option
std::string centerString(const std::string toCenter);
std::string centerString(const std::string toCenter, int minus); //Returns center minus some spaces


#endif