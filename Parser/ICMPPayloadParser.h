#pragma once
#include "IPPayloadParser.h"
#include <iostream>
#include <string>
using namespace std;

class ICMPPayloadParser : public IPPayloadParser {
private:

public:
	ICMPPayloadParser();

	string ParsePayload(string payload);
	
	~ICMPPayloadParser();
};