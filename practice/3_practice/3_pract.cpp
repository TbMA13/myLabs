#include <iostream>
#include <fstream>

bool findLiters(unsigned char liter) {
	unsigned char vowels[20] = { 'À', 'à', 'Î', 'î', 'Ó', 'ó', 'Ý', 'ý', 'Û', 'û', 'ß', 'ÿ', '¨', '¸', 'Þ', 'þ', 'Å', 'å', 'È', 'è'};
	for (int u = 0; u < 20; u++) {
		if (liter == vowels[u]) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "RUS");

	std::ifstream readObj;
	readObj.open("assets/input.txt");

	std::ofstream writeObj;
	writeObj.open("assets/output.txt", std::ofstream::trunc);

	while (!readObj.eof()) {
		std::string tempStr;
		readObj >> tempStr;
		bool flag = false;
		for (int i = 0; i < tempStr.length() - 1; i++) {
			for (int j = i + 1; j < tempStr.length(); j++) {
				if (toupper(tempStr[i]) == toupper(tempStr[j]) && findLiters(tempStr[i])) {
					flag = true;
					break;
				}
			}
			if (flag) {
				writeObj << tempStr << ' ' << "(" << (char)toupper((tempStr[i])) << (char)toupper((tempStr[i])) << ")" << ' ';
				break;
			}
		}
		if (!flag) {
			writeObj << tempStr << ' ';
		}


	}

	readObj.close();
	writeObj.close();
	return 0;
}