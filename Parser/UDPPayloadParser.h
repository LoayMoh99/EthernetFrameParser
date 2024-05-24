#pragma once
#include "IPPayloadParser.h"
#include <iostream>
#include <string>
using namespace std;

class UDPPayloadParser : public IPPayloadParser {
private:

public:
	UDPPayloadParser();

	string ParsePayload(string payload);
	
	~UDPPayloadParser();
};