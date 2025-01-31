#include "header.h"
#include "functions.h"

string Binary(const string& IP) {
	string binaryIP; // result
	string octet; // ������� �����
	try {
		for (char ch : IP) {
			if (ch == '.') {
				if (octet.empty()) {
					throw invalid_argument("Invalip IP: Empty Octet");
				}

				// octet to int => decimal to binary
				int num = stoi(octet);
				if (num < 0 || num > 255) {
					throw invalid_argument("Out of data 0-255");
				}
				bitset<8> binary(num);
				binaryIP += binary.to_string();
				octet.clear(); // clear octet for next numb
			}
			else if (isdigit(ch)) {
				octet += ch; // +1 to octet
			}
			else {
				throw invalid_argument("Delimiter is not a dot");
			}
		}

		int num = stoi(octet);
		bitset<8> binary(num);
		binaryIP += binary.to_string();
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
		return " ";
	}

	return binaryIP;
}
