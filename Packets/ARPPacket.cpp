#include "ARPPacket.h"


ARPPacket::ARPPacket(string destMac, string srcMac, string typeLen, string payload, string checkSum)
	: Packet(destMac,srcMac,typeLen,payload,checkSum)
{
	SetPacketType("ARP");
}

string ARPPacket::ParsePayload()
{
	string payload = GetPayload();
	// since ARP has a fixed structure; will parse the components of the payload here
	string parsedPayload = "ARP Payload: \n";

	// This is ordered like :- hardwareType, protocolType, hardwareAddrLen, protocolAddrLen, 
	//			operationCode, senderHardAddr, senderProtAddr, targetHardAddr, targetProtAddr -> respectivly
	vector<pair<string, int>> payloadComponents = {
		{"Hardware Type: ", 4},
		{"Protocol Type: ", 4},
		{"Hardware Address Length: ", 2},
		{"Protocol Address Length: ", 2},
		{"Operation Code: ", 4},
		{"Sender Hardware Address: ", 12},
		{"Sender Protocol Address: ", 8},
		{"Target Hardware Address: ", 12},
		{"Target Protocol Address: ", 8}
	};

	int startIndex = 0;
	for (auto& component : payloadComponents) {
		parsedPayload += "  " + component.first + "0x" + payload.substr(startIndex, component.second) + "\n";
		startIndex += component.second;
	}
	return parsedPayload;
}

ARPPacket::~ARPPacket()
{
}
