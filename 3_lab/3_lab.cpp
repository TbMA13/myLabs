#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	int temp = 1;
	int maxNumber = -9999;
	int n;
	int lastIndex;
	cin >> n;
	int currentNumber;
	for (int i = 0; i < n; i++) {
		cin >> currentNumber;
		string currentStringNumber = to_string(currentNumber);
		if (currentStringNumber[currentStringNumber.length() - 1] == '2') {
			temp = temp * currentNumber;
			if (maxNumber < currentNumber) {
				maxNumber = currentNumber;
				lastIndex = i + 1;

			}
		}
		
	}
	cout << "Произведение чисел = " << temp << "\n";
	cout << "Наибольшее число = " << maxNumber << "\n";
	cout << "Индекс этого числа = " << lastIndex << "\n";
}