#pragma once
#include "Output.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileOutput : public Output
{
private:	
	string filename;
public:
	FileOutput();	
	void UpdateOutput(string);
	~FileOutput();
};
