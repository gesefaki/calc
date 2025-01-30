#include "header.h"
#include "functions.h"

string netAddress(const string& binaryIP, const int mask) {
	string decimal;
	string netIP = binaryIP;

	for (size_t i = mask; i < netIP.size(); i++) {
		netIP[i] = '0';
	}

	//разбиваем на 4 части по 8 бит
	string decimalIP;
	for (int i = 0; i < 4; i++) {
		string octet = netIP.substr(i * 8, 8);
		int decimalValue = stoi(octet, nullptr, 2);
		decimalIP += to_string(decimalValue);
		if (i < 3) decimalIP += ".";
	}

	return decimalIP;
}

string broadAddress(const string& binaryIP, const int mask) {
	string broadIP = binaryIP;

	for (size_t i = mask; i < broadIP.size(); i++) {
		broadIP[i] = '1';
	}

	string decimalIP;
	for (int i = 0; i < 4; i++) {
		string octet = broadIP.substr(i * 8, 8);
		int decimalValue = stoi(octet, nullptr, 2);
		decimalIP += to_string(decimalValue);
		if (i < 3) decimalIP += ".";
	}


	return decimalIP;
}