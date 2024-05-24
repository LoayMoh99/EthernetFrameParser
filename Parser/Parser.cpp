#include "Parser.h"
#include "../ApplicationManager.h"

Parser::Parser(ApplicationManager* pApp) {
	pManager = pApp;
}

// Calculate the sizes of all except payload
int Parser::GetMetaDataSize()
{
	return destinationMacSize+ sourceMacSize+ etherTypeSize+ checksumSize;
}

bool Parser::ParseFrame(string frame)
{
	// validations
	if (frame.size() < GetMetaDataSize() + minPayloadSize) {
		return false;
	}

	Packet* parsedPacket = nullptr;

	// Parse the components of the frame
	string destMac = frame.substr(0, destinationMacSize);
	string srcMac = frame.substr(destinationMacSize, sourceMacSize);
	string etherType = frame.substr(destinationMacSize + sourceMacSize, etherTypeSize);
	string checksum = frame.substr(frame.size() - checksumSize, checksumSize);
	string payload = frame.substr(destinationMacSize + sourceMacSize + etherTypeSize, frame.size() - GetMetaDataSize());

	if (etherType == "0800") {
		parsedPacket = new IPPacket(destMac, srcMac, etherType, payload,checksum);
	} else if (etherType == "0806") {
		parsedPacket = new ARPPacket(destMac, srcMac, etherType, payload, checksum);
	} 
	else {
		/* Add more packet types here */
		parsedPacket = new Packet(destMac, srcMac, etherType, payload, checksum); // Other Type Packets
	}
	pManager->AddPacket(parsedPacket);

	return true;
}

Parser::~Parser()
{
}
