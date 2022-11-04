#include <iostream>

int main() {
	// unsigned char char2 = 52; // 0011 0100 = 3 4
	//std::cout << (int) * (&char2);
	setlocale(LC_ALL, "RUS");
	short n;
	std::cout << "Укажите количество чисел\n>>> ";
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Введите любые числа из диапазона [0, 8]\nКаждое число на новой строке\n";
	short currentNumber = 0;
	short currentNumber2 = 0;
	unsigned char* numbersMas = new unsigned char[n];
	short count = -1;
	
	while (count != n - 1) {
		std::cout << ">>> ";
		std::cin >> currentNumber;
		count++;
		if (count != n - 1) {
			std::cout << ">>> ";
			std::cin >> currentNumber2;
			count++;
		}
		else {
			currentNumber2 = 15;
		}
		int binTempValue = 11111111;
		binTempValue = ((currentNumber / 8) % 2) * pow(10, 7) + ((currentNumber / 4) % 2) * pow(10, 6) + ((currentNumber / 2) % 2) * pow(10, 5) + (currentNumber % 2) * pow(10, 4) + ((currentNumber2 / 8) % 2) * pow(10, 3) + ((currentNumber2 / 4) % 2) * pow(10, 2) + ((currentNumber2 / 2) % 2) * 10 + (currentNumber2 % 2);
		short decTempValue = 0;
		short i = 0;
		while (binTempValue > 0) {
			decTempValue += (binTempValue % 10) * pow(2, i);
			binTempValue /= 10;
			i++;
		}
		numbersMas[count % 2 == 0 ? count / 2 : (count - 1) / 2] = decTempValue;
	}
	for (short i = 0; i < (count % 2 == 0 ? count / 2 : (count - 1) / 2) + 1; i++) {
		short tempNumber1 = 0;
		short tempNumber2 = 0;
		short currentNumber = (int)(numbersMas[i]);
		short currentNumber2 = ((currentNumber / 8) % 2) * pow(10, 3) + ((currentNumber / 4) % 2) * pow(10, 2) + ((currentNumber / 2) % 2) * 10 + (currentNumber % 2);
		short currentNumber1 = ((currentNumber / 128) % 2) * pow(10, 3) + ((currentNumber / 64) % 2) * pow(10, 2) + ((currentNumber / 32) % 2) * 10 + ((currentNumber / 16) % 2);
		short j = 0;
		while (currentNumber1 > 0) {
			tempNumber1 += (currentNumber1 % 10) * pow(2, j);
			currentNumber1 /= 10;
			j++;
		}
		std::cout << tempNumber1 << std::endl;
		if (currentNumber2 == 1111) {
			return 0;
		}
		else {
			j = 0;
			while (currentNumber2 > 0) {
				tempNumber2 += (currentNumber2 % 10) * pow(2, j);
				currentNumber2 /= 10;
				j++;
			}
			std::cout << tempNumber2 << std::endl;
		}
	}
	return 0;
}	