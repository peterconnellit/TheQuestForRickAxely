#ifndef STRINGFUNCTIONALITY_H
#define STRINGFUNCTIONALITY_H

//String functionality interface to the user

#include<string>
#include<vector>

std::string findCharAndReplace(std::string forReplace, char toReplace);
void printInLines(std::string toPrint, char newLine);
std::string toLowerCase(std::string toCast);
std::string checkAndReplace(std::string forReplace, std::string whatToReplace, std::string replaceWith);
std::vector<std::string> removeAllByname(std::vector<std::string> toRemove, std::string forRemove);

#endif