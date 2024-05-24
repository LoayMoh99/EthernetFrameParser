#pragma once
#include "Input.h"
#include <fstream>

class FileInput : public Input
{
public:
	FileInput();		//Consturctor

	vector<string> GetUserInput() const; //Read the user click and map to an action

	~FileInput();
};
