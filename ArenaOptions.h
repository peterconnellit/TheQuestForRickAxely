#ifndef ARENAOPTIONS_H
#define ARENAOPTIONS_H

#include"Player.h"

//This is arena options interface to the user
//Function prototypes

//Checks user attack choice
int attackChoice();
//Add the surrender option
bool surrenderOption();
bool checkForOption(std::string optForTrue, std::string opt2);

#endif // ! SETEQUIPMENT_H
