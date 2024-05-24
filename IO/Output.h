#ifndef OUPTUT_H
#define OUPTUT_H
#include <iostream>
#include <string>
using namespace std;

class Output	
{
private:	
public:
	Output();	
	virtual void UpdateOutput(string);
	virtual ~Output();
};

#endif