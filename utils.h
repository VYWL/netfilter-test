#include <vector>
#include <stdio.h>
#include <string.h>

typedef long long ll;
extern char * hostDomain;
extern int isHostDetected;

void usage();

std::vector<int> getPi(const char * word);
int useKMP(const char * targetString, const char * word);

void scanHTTPHeader(unsigned char * buf, int size);
