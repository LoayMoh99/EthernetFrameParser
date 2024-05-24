#pragma once
#include "Packet.h"
#include "../DEFS.h"
#include "../Parser/IPPayloadParser.h"
#include <vector>

class IPPacket : public Packet{
private:
	Ip4PayloadProtocol CheckForIP4Protocol(string protcol);

public:
	IPPacket(string destMac, string srcMac, string typeLen, string payload, string checkSum);
	
	string ParsePayload();

	~IPPacket();
};