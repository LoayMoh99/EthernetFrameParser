#pragma once
#include "Packet.h"
#include <vector>

class ARPPacket : public Packet{
public:
	ARPPacket(string destMac, string srcMac, string typeLen, string payload, string checkSum);
	
	string ParsePayload();

	~ARPPacket();
};