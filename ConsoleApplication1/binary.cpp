#include "header.h"
#include "functions.h"

string Binary(const string& IP) {
	string binaryIP; // результат
	string octet; // текущий октет
	try {
		for (char ch : IP) {
			if (ch == '.') {
				if (octet.empty()) {
					throw invalid_argument("Некорректный IP: пустой октет.");
				}

				// преобразуем октет в число и затем в двоичку
				int num = stoi(octet);
				if (num < 0 || num > 255) {
					throw invalid_argument("Октет вне диапазона: необходимо число от 0 до 255.");
				}
				bitset<8> binary(num);
				binaryIP += binary.to_string();
				octet.clear(); //очищаем октет для следующего числа
			}
			else if (isdigit(ch)) {
				octet += ch; // +цифра к новому октету
			}
			else {
				throw invalid_argument("Недопустимый символ");
			}
		}

		int num = stoi(octet);
		bitset<8> binary(num);
		binaryIP += binary.to_string();
	}
	catch (const invalid_argument& e) {
		cerr << "Ошибка: " <<  e.what() << endl;
		return " ";
	}

	return binaryIP;
}