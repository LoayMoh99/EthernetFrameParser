#ifndef DEFS_H
#define DEFS_H

#include <iostream>
using namespace std;

//This file contains any global constants and definitions to be used in the project.

enum ActionType 
{
	STD_IO =1,		//Get input/output from/to std (standard library)  
	FILE_IO,		//Get input/output from/to file 
	GUI_IO,			//Get input/output from/to GUI - NOT YET Supported :(
	EXIT,			//Exit
};

enum Ip4PayloadProtocol
{
	ICMP = 50,			
	UDP,	
	TCP,		// NOT YET Supported :(
	Other,
};

static int HexCharToInt(char c) {
	if (isdigit(c)) {
		return c - '0'; // Convert '0'-'9' to 0-9
	}
	else if (isxdigit(c)) {
		return toupper(c) - 'A' + 10; // Convert 'A'-'F'/'a'-'f' to 10-15
	}
	return -1; // invalid char
}

static int HexStringToInt(string hex) {
	int hexNum = 0;
	for (char c : hex) {
		int hexCharNum = HexCharToInt(c);
		if (hexCharNum != -1) {
			hexNum = hexNum * 16 + hexCharNum;
		}
		else {
			// Invalid hex character
			return -1; 
		}
	}
	return hexNum;
}

#endif