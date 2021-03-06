#include "utils.h"
#include "packetHeaders.h"
#include <string>

int isHostDetected = 0;

void usage() {
    printf("usage : sudo ./netfilter-test <host-domain>\n");
}

std::vector<int> getPi(const char * word) {
    int wordLength = strlen(word);
    std::vector<int> pi(wordLength, 0);

    for(int nowIdx = 1, matchIdx = 0; nowIdx < wordLength; ++nowIdx) {
        if(word[nowIdx] == word[matchIdx]) {
            pi[nowIdx] = ++matchIdx;
        }
        else if (matchIdx != 0) {
            --nowIdx; matchIdx = pi[matchIdx - 1];
        }
    }

    return pi;
}

int useKMP(const char * sentence, const char * word) {
    std::vector<int> pi = getPi(word);

    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    for(int nowIdx = 0, matchIdx = 0; nowIdx < sentenceLength; ++nowIdx) {
        if(sentence[nowIdx] == word[matchIdx]){
            if(++matchIdx == wordLength) {
                return 1;
            }
        } 
        else if (matchIdx != 0) {
            --nowIdx; matchIdx = pi[matchIdx - 1];
        }
    }

    return 0;
}

void scanHTTPHeader(unsigned char * buf, int size) {

	IpHeader *ipHdr = (IpHeader *)buf;
    int ipHeaderLength = (int)(ipHdr->headerLength * 4);

    if(ipHdr->protocolID != 0x06) return;

    TcpHeader *tcpHdr = (TcpHeader *)(buf + ipHeaderLength);
    int tcpHeaderLength = (int)(tcpHdr->offset * 4);

    char *httpPayload = (char *)(buf + ipHeaderLength + tcpHeaderLength);

    std::string host(hostDomain);
    std::string keyWord = "Host: " + host;

    isHostDetected = useKMP(httpPayload, keyWord.c_str());
}
