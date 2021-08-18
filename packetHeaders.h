#include <pcap.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct IPHeader {
    uint8_t headerLength : 4;
    uint8_t version : 4;
    uint8_t typeOfService;
    uint16_t totalPacketLength;
    uint16_t identifier;
    uint16_t fragmentOffset;
    uint8_t ttl;
    uint8_t protocolID;
    uint8_t headerChecksum;
    struct in_addr sourceIP;
    struct in_addr destinationIP;
}IpHeader;

typedef struct tcpHeader {
    uint16_t sourcePort;
    uint16_t destinationPort;
    uint32_t sequenceNumber;
    uint32_t acknowledgeNumber;
    uint8_t _unused : 4;
    uint8_t offset : 4;
    uint8_t flags;
    uint16_t windowSize;
    uint16_t checksum;
    uint16_t urgentPointer;
}TcpHeader;
