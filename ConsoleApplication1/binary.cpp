#include "header.h"
#include "functions.h"

string Binary(const string& IP) {
	string binaryIP; // result string
	string octet; // current octet
	try {
		for (char ch : IP) {
			if (ch == '.') {
				if (octet.empty()) {
					throw invalid_argument("Íåêîððåêòíûé IP: ïóñòîé îêòåò.");
				}

				int num = stoi(octet);
				if (num < 0 || num > 255) {
					throw invalid_argument("Îêòåò âíå äèàïàçîíà: íåîáõîäèìî ÷èñëî îò 0 äî 255.");
				}
				bitset<8> binary(num);
				binaryIP += binary.to_string();
				octet.clear(); 
			}
			else if (isdigit(ch)) {
				octet += ch; /
			}
			else {
				throw invalid_argument("Íåäîïóñòèìûé ñèìâîë");
			}
		}

		int num = stoi(octet);
		bitset<8> binary(num);
		binaryIP += binary.to_string();
	}
	catch (const invalid_argument& e) {
		cerr << "Îøèáêà: " <<  e.what() << endl;
		return " ";
	}

	return binaryIP;
}
