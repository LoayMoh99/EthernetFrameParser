#pragma once
#include "Input.h"
#include <iostream>
using namespace std;

class StdInput : public Input
{
public:
	StdInput();		//Consturctor

	vector<string> GetUserInput() const; 

	~StdInput();
};
