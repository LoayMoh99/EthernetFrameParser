#include "Packet.h"

Packet::Packet(){
	SetPacketType("Other"); // by default
}

Packet::Packet(string destMac, string srcMac, string typeLen, string payload, string checkSum)
	: destinationMAC(destMac), sourceMAC(srcMac), typeLength(typeLen), payload(payload), checksum(checkSum)
{
	SetPacketType("Other"); // by default 
	payloadLength = payload.size() / 2; // to be in bytes
}

void Packet::SetPacketType(string packType)
{
	packetType = packType;
}

string Packet::GetPayload() const
{
	return payload;
}

string Packet::ParsePayload()
{
	return ""; // since we don't support parsing of Other type packets
}

string Packet::GetPacketInfo() {
	string packetInfo = "";

	packetInfo += "Packet Type: " + packetType + "\n";
	packetInfo += "Destination MAC: 0x" + destinationMAC + "\n";
	packetInfo += "Source MAC: 0x" + sourceMAC + "\n";
	packetInfo += "Type/Length: 0x" + typeLength + "\n";
	packetInfo += "Payload: 0x" + payload + "\n";
	packetInfo += "Checksum: 0x" + checksum + "\n";
	packetInfo += "Payload Length: " + to_string(payloadLength) + " Bytes \n";

	packetInfo += this->ParsePayload() + "\n";
	packetInfo += "**************************************************************\n";
	return packetInfo;
}

Packet::~Packet()
{
}
