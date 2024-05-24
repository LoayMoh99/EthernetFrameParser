#pragma once
#include "Output.h"

class StdOutput : public Output
{
private:	
public:
	StdOutput();	
	void UpdateOutput(string);
	~StdOutput();
};
