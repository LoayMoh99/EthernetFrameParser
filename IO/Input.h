#ifndef INPUT_H
#define INPUT_H
#include <vector>
#include <iostream>
using namespace std;
#include "./../DEFS.h"


class Input	
{
public:
	Input();	

	virtual vector<string> GetUserInput() const; 

	virtual ~Input();
};

#endif