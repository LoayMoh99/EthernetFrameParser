#include "UDPPayloadParser.h";

UDPPayloadParser::UDPPayloadParser()
{
}

string UDPPayloadParser::ParsePayload(string payload)
{
	string parsedPayload = "Protocol: UDP\n";

	vector<pair<string, int>> payloadComponents = {
		{"UDP Source Port: ", 4},
		{"UDP Destination Port: ", 4},
		{"UDP Length: ", 4},
		{"UDP Checksum: ", 4},
	};

	int startIndex = 0;
	for (auto& component : payloadComponents) {
		string componentPayload = payload.substr(startIndex, component.second);
		parsedPayload += "\t" + component.first + "0x" + componentPayload;
		if(component.first != "UDP Checksum: ")
			parsedPayload += " - Decimal: " + to_string(HexStringToInt(componentPayload));
		parsedPayload += "\n";
		startIndex += component.second;
	}
	parsedPayload += "\tUDP Data: " + payload.substr(startIndex) + "\n";

	return parsedPayload;
}

UDPPayloadParser::~UDPPayloadParser()
{
}
