#pragma once
#include "../Packets/Packet.h"
#include "../Packets/IPPacket.h"
#include "../Packets/ARPPacket.h"

class ApplicationManager;	//forward class declaration to prevent circuar dependency

class Parser {
private:
	int destinationMacSize = 12;// 6 Bytes (1 Byte = 2 Hexa)
	int sourceMacSize = 12;		// 6 Bytes
	int etherTypeSize = 4;		// 2 Bytes
	int checksumSize = 8;		// 4 Bytes
	int minPayloadSize = 92;	// 46 Bytes (payload should be [46-1500] Bytes)

protected:
	ApplicationManager* pManager;	//Parser needs AppMngr to do their job

public:
	Parser(ApplicationManager* pApp);

	int GetMetaDataSize(); // Calculate the sizes of all except payload

	bool ParseFrame(string frame);

	~Parser();
};