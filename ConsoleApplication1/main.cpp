#include "header.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "RUS");

	string IP;
	int mask = 0;

	while (true) {

		cout << "qq, введи IP: ";
		cin >> IP;
		cin.ignore();

		cout << "введи маску: ";
		cin >> mask;
		cin.ignore();

		cout << "результат: " << IP << "/" << mask << endl <<
			"если ввод корректный, нажми ENTER. если нет, введи что-нибудь другое";

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
		cout << "\nдвоичка: " << formatted.str() << endl;
	}

	string netIP = netAddress(binaryIP, mask);
	string broadIP = broadAddress(binaryIP, mask);
	cout << "net: " << netIP;
	cout << "\nbroad: " << broadIP;

	int hosts = Hosts(mask);
	cout << "\nhosts: " << hosts << endl;



	return 0;
}