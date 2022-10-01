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
int literCount(string word) {
	int size = word.length();
	int litersCount[256] = { 0 };
	for (int i = 0; i < size; i++) {
		litersCount[abs((char)word[i])] += 1;
	}
	int maxNumber = 0;
	for (int i = 0; i < 256; i++) {
		if (litersCount[i] > maxNumber) {
			maxNumber = litersCount[i];
		}
	}
	return maxNumber;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int change;
	cout << "Выберите задание (\"1\" или \"2\")?\n>>> ";
	cin >> change;
	if (change == 1) {
		int punctuationMarks[] = { 33, 34, 39, 40, 41, 44, 45 ,46, 58, 59, 63 };
		cout << "Введите строку\n>>> ";
		char line[101];
		cin >> line;
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
			int currentSymbol = static_cast<int>(line[i]);
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
		string wordsArray[5000] = {};
		string MyText;
		int count = 0;
		fstream fileRead("5_lab.txt", std::ios::in);
		while (!fileRead.eof()) {
			fileRead >> MyText;
			wordsArray[count] = MyText;
			count++;
			//cout << MyText << endl;
		}
		int litersInWordsCount[5000] = { 0 };
		for (int j = 0; j < count; j++) {
			string currentWord = wordsArray[j];
			int maxLitersInWord = literCount(currentWord);
			litersInWordsCount[j] = maxLitersInWord;
		}
		int maxCount = 0;
		for (int i = 0; i < count; i++) {
			if (maxCount < litersInWordsCount[i]) {
				maxCount = litersInWordsCount[i];
			}
		}
		for (int i = 0; i < count - 1; i++) {
			for (int j = 1; j < count; j++) {
				if (litersInWordsCount[j - 1] < litersInWordsCount[j]) {
					std::swap(litersInWordsCount[j - 1], litersInWordsCount[j]);
					std::swap(wordsArray[j - 1], wordsArray[j]);
				}
			}
		}
		for (int i = 0; i < count; i++) {
			cout << wordsArray[i] << " " << litersInWordsCount[i] << endl;
		}
	}
}