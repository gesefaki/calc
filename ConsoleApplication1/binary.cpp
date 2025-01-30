#include "header.h"
#include "functions.h"

string Binary(const string& IP) {
	string binaryIP; // ���������
	string octet; // ������� �����
	try {
		for (char ch : IP) {
			if (ch == '.') {
				if (octet.empty()) {
					throw invalid_argument("������������ IP: ������ �����.");
				}

				// ����������� ����� � ����� � ����� � �������
				int num = stoi(octet);
				if (num < 0 || num > 255) {
					throw invalid_argument("����� ��� ���������: ���������� ����� �� 0 �� 255.");
				}
				bitset<8> binary(num);
				binaryIP += binary.to_string();
				octet.clear(); //������� ����� ��� ���������� �����
			}
			else if (isdigit(ch)) {
				octet += ch; // +����� � ������ ������
			}
			else {
				throw invalid_argument("������������ ������");
			}
		}

		int num = stoi(octet);
		bitset<8> binary(num);
		binaryIP += binary.to_string();
	}
	catch (const invalid_argument& e) {
		cerr << "������: " <<  e.what() << endl;
		return " ";
	}

	return binaryIP;
}