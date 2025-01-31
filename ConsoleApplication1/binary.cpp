#include "header.h"
#include "functions.h"

string Binary(const string& IP) {
	using namespace std;
	string binaryIP; // ðåçóëüòàò
	string octet; // òåêóùèé îêòåò
	try {
		for (char ch : IP) {
			if (ch == '.') {
				if (octet.empty()) {
					throw invalid_argument("Íåêîððåêòíûé IP: ïóñòîé îêòåò.");
				}

				// ïðåîáðàçóåì îêòåò â ÷èñëî è çàòåì â äâîè÷êó
				int num = stoi(octet);
				if (num < 0 || num > 255) {
					throw invalid_argument("Îêòåò âíå äèàïàçîíà: íåîáõîäèìî ÷èñëî îò 0 äî 255.");
				}
				bitset<8> binary(num);
				binaryIP += binary.to_string();
				octet.clear(); //î÷èùàåì îêòåò äëÿ ñëåäóþùåãî ÷èñëà
			}
			else if (isdigit(ch)) {
				octet += ch; // +öèôðà ê íîâîìó îêòåòó
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
