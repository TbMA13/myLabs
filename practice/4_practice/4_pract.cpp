#include <iostream>

int main() {
	// unsigned char char2 = 52; // 0011 0100 = 3 4
	//std::cout << (int) * (&char2);
	setlocale(LC_ALL, "RUS");
	short n;
	std::cout << "Введите количество чисел\n>>> ";
	std::cin >> n;
	short currentNumber = 0;
	short currentNumber2 = 0;
	unsigned char* numbersMas = new unsigned char[n];
	short count = -1;

	std::cout << "Введите любые числа из диапазона [0, 8]\nКаждое число на новой строке";
	
	while (count != n - 1) {
		std::cout << "\n>>> ";
		std::cin >> currentNumber;
		count++;
		if (count != n - 1) {
			std::cout << "\n>>> ";
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


	std::cout << (int) * (numbersMas) << ' ' << (int) * (numbersMas + 1) << ' ' << (int)*(numbersMas + 2);


	for (short i = 0; i < (count % 2 == 0 ? count / 2 : (count - 1) / 2); i++) {
		short tempNumber = 0;
		short currentNumber = numbersMas[i];
		short currentNumber1 = currentNumber / 1000;
		short currentNumber2 = currentNumber % 10000;
		//todo сделать распаковку
		/*while (((currentNumber2 / 8) % 2) * pow(10, 3) + ((currentNumber2 / 4) % 2) * pow(10, 2) + ((currentNumber2 / 2) % 2) * 10 + (currentNumber2 % 2) > 0) {
			decTempValue += (binTempValue % 10) * pow(2, i);
			currentNumber2 /= 10;
			i++;
		}*/

	}
	return 0;
}	