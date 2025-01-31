#include "header.h"
#include "functions.h"

int main() {
	string IP;
	int mask = 0;

	while (true) {

		cout << "IP: ";
		cin >> IP;
		cin.ignore();

		cout << "Subnet mask: ";
		cin >> mask;
		cin.ignore();

		cout << "Address: " << IP << "/" << mask << endl <<
			"Correct? ENTER - YES; ANYTHING ELSE - NO.";

		string input;
		getline(cin, input);
		if (input.empty())
			break;

	}

	string binaryIP = Binary(IP);
	if (!binaryIP.empty()) {
		ostringstream formatted;
		for (size_t i = 0; i < binaryIP.size(); i++) {
			formatted << binaryIP[i];
			if ((i + 1) % 8 == 0 && i != binaryIP.size() - 1) {
				formatted << ".";
			}
		}
		cout << "\nbinary: " << formatted.str() << endl;
	}

	string netIP = netAddress(binaryIP, mask);
	string broadIP = broadAddress(binaryIP, mask);
	cout << "net: " << netIP;
	cout << "\nbroad: " << broadIP;

	int hosts = Hosts(mask);
	cout << "\nhosts: " << hosts << endl;

	string firstAdd = firstAddress(netIP);
	cout << "first: " << firstAdd;

	string lastAdd = lastAddress(broadIP);
	cout << "\nlast: " << lastAdd;

	return 0;
}