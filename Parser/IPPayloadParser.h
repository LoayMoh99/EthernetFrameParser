#pragma once
#include "../DEFS.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IPPayloadParser {

public:
	IPPayloadParser() {}

	virtual string ParsePayload(string payload) = 0;
};