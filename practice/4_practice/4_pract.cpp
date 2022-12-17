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
	unsigned char* numbersMas = new unsigned char[n];
	short count = -1;
	
	while (count != n - 1) {
		short currentNumber = 0;
		short currentNumber2 = 15;
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
		short decTempValue = (currentNumber << 4) | currentNumber2;
		numbersMas[count % 2 == 0 ? count >> 1 : (count - 1) >> 1] = decTempValue;
	}
	for (short i = 0; i < (count % 2 == 0 ? count >> 1 : (count - 1) >> 1) + 1; i++) {
		short currentNumber = (int)(numbersMas[i]);
		short currentNumber2 = ((currentNumber >> 3) % 2) << 3 | ((currentNumber >> 2) % 2) << 2 | ((currentNumber >> 1) % 2) << 1 | (currentNumber % 2);
		short currentNumber1 = ((currentNumber >> 7) % 2) << 3 | ((currentNumber >> 6) % 2) << 2 | ((currentNumber >> 5) % 2) << 1 | ((currentNumber >> 4) % 2);

		std::cout << currentNumber1 << std::endl;

		if (currentNumber2 != 15) {
			std::cout << currentNumber2 << std::endl;
		}
	}
	return 0;
}	