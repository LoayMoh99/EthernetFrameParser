#include "IPPacket.h"
#include "../Parser/ICMPPayloadParser.h"
#include "../Parser/UDPPayloadParser.h"


IPPacket::IPPacket(string destMac, string srcMac, string typeLen, string payload, string checkSum)
	: Packet(destMac,srcMac,typeLen,payload,checkSum)
{
	SetPacketType("IP");
}

/* Helper Functions */
Ip4PayloadProtocol IPPacket::CheckForIP4Protocol(string protcol)
{
    if (protcol == "01") return ICMP; // Byte = 0x01 = 1 decimal
    if (protcol == "11") return UDP;  // Byte = 0x11 = 17 decimal
    return Other; // other protocols not supported
}

string IPPacket::ParsePayload()
{
	string payload = GetPayload();
    string versionHeaderByte = payload.substr(0, 2);
    string parsedPayload = "IP Payload: \n";

    // validate the version should to be version 4 as this is payload of IPv4
    if (versionHeaderByte[0] != '4') {
        cout << "Wrong version in payload of IPv4 " << payload << endl;
        return parsedPayload + "Wrong version in payload of IPv4\n";
    }
    parsedPayload += "  IP Version: " + versionHeaderByte.substr(0,1) + "\n";
    parsedPayload += "  Internet Header Length: " + to_string((HexCharToInt(versionHeaderByte[0]) * HexCharToInt(versionHeaderByte[1]))) + "\n"; //i.e. 4*5 = 20 length

    vector<pair<string, int>> payloadComponents = {
        {"Type of Service: ", 2},
        {"Total Length: ", 4},
        {"Identification: ", 4},
        {"Flags and Fragment Offset: ", 4},
        {"Time to Live: ", 2},
        {"Protocol: ", 2},
        {"Header Checksum: ", 4},
        {"Source Address: ", 8},
        {"Destination Address: ", 8}
    };



    int startIndex = 2;
    IPPayloadParser* ipPayloadParser = nullptr;
    for (auto& component : payloadComponents) {
        if (component.first == "Protocol: ") {
            string ip4protcol = payload.substr(startIndex, component.second);
            //parsedPayload += component.first + "0x" + ip4protcol + "\n";

            switch (CheckForIP4Protocol(ip4protcol)) {
            case ICMP:
                ipPayloadParser = new ICMPPayloadParser();
                break;
            case UDP:
                ipPayloadParser = new UDPPayloadParser();
                break;

                /* Add more protocols here */

            default:
                break;
            }
        }
        else
            parsedPayload += "  " + component.first + "0x" + payload.substr(startIndex, component.second) + "\n";

        startIndex += component.second;
    }


    string protcolPayload = payload.substr(startIndex) + "\n";
    if (ipPayloadParser != nullptr) {
        parsedPayload += "  " + ipPayloadParser->ParsePayload(protcolPayload) + "\n";
        delete ipPayloadParser;
    }
    else {
        parsedPayload += "  IP4 Unsupported Protocol: " + protcolPayload + "\n";
    }
    return parsedPayload;
}


IPPacket::~IPPacket()
{
}
