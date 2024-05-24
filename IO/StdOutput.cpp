#include "StdOutput.h"


StdOutput::StdOutput(): Output()
{}

void StdOutput::UpdateOutput(string out) {
	cout << out << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////
StdOutput::~StdOutput()
{
}

