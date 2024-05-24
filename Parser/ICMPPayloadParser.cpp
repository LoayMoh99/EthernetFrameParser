#include "ICMPPayloadParser.h";

ICMPPayloadParser::ICMPPayloadParser()
{
}

string ICMPPayloadParser::ParsePayload(string payload)
{
	string parsedPayload = "Protocol: ICMP\n";
	// it is fixed 8 Bytes = 16 char = 2+2+4+4+4
	vector<pair<string, int>> payloadComponents = {
		{"ICMP Type: ", 2},
		{"ICMP Code: ", 2},
		{"ICMP Checksum: ", 4},
		{"ICMP Identifier: ", 4},
		{"ICMP Sequence Number: ", 4},
	};

	int startIndex = 0;
	for (auto& component : payloadComponents) {
		parsedPayload += "\t" + component.first + "0x" + payload.substr(startIndex, component.second) + "\n";
		startIndex += component.second;
	}
	parsedPayload += "\tICMP Data: " + payload.substr(startIndex) + "\n";

	return parsedPayload;
}

ICMPPayloadParser::~ICMPPayloadParser()
{
}
