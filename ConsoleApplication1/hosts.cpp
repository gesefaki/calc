#include "header.h"
#include "functions.h"

int Hosts(const int mask) {
	int result = 1;

	if (mask != 32) {
		int value = 32 - mask;
		result = pow(2, value);
		result -= 2;
	}

	return result;
}
// LOL EBAT VOT ETO FUNKCIONAL