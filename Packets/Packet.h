#pragma once
#include <iostream>
#include <string>
using namespace std;

class Packet {
private:
	string packetType;
	string destinationMAC;
	string sourceMAC;
	string typeLength;
	string payload;
	string checksum;
	int payloadLength;
public:
	Packet();
	Packet(string destMac, string srcMac, string typeLen, string payload, string checkSum);
	void SetPacketType(string packType);
	string GetPayload() const;
	
	virtual string ParsePayload();
	string PrintPacketInfo();

	~Packet();
};