#include <iostream>
#include <string>
#include "stdio.h"
#include <fstream>
using namespace std;

bool markSearch(int* marks, int currentSymbolCode) {
	for (int i = 0; i < 11; i++) {
		if (marks[i] == currentSymbolCode) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "");
	int change;
	cout << "Выберите задание (\"1\" или \"2\")?\n>>> ";
	cin >> change;
	cout << endl;
	if (change == 1) {
		int punctuationMarks[] = { 33, 34, 39, 40, 41, 44, 45 ,46, 58, 59, 63 };
		string firstLine;
		cout << "Введите строку\n>>> ";
		char line[101];
		gets_s(line);
		int N = 0;
		for (int i = 0; i < 101; i++) {
			if (line[i] == 0) {
				break;
			}
			else {
				N += 1;
			}
		}

		string newLine[100];
		int count = 0;
		for (int i = 0; i < N; i++) {
			int currentSymbol = line[i];
			if (markSearch(punctuationMarks, currentSymbol)) {
				continue;
			}
			else if (currentSymbol == 0) {
				break;
			}
			else {
				newLine[count] = currentSymbol;
				count += 1;
			}
		}
		for (int i = 0; i < count; i++) {
			cout << newLine[i];
		}
	}
	else if (change == 2) {
		string MyText;
		fstream fileRead("5_lab.txt");
		while (getline(fileRead, MyText)) {
			cout << MyText;
		}
		/*std::istream file("5_lab.txt");
		fileRead.close();*/
	}
}