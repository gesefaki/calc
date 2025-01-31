#include "header.h"
#include "functions.h"

string firstAddress(const string& netIP) {
	string first = netIP;
	first.back()++;
	
	return first;
}

string lastAddress(const string& broadIP) {
	string last = broadIP;
	last.back()--;

	return last;
}