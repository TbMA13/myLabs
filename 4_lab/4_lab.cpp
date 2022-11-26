#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Test");
    return 0;
}

/*#include <iostream>
#include <string>
using namespace std;

const int row = 4;
const int column = 4;
int matrixArray[row][column] = {
		{1, 2, 3, 4},
		{64, 1, 98, 110},
		{54, 1, 0, 32},
		{102, 56, 98, 88}
};



bool isProst(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int* delArrayElement(int* values, size_t size, int elementIndex) {
	for (int i = elementIndex; i < size - 1; i++) {
		values[i] = values[i + 1];
	}
	return values;
}
int minSearch(int* values, size_t size) {
	int minNumber = 99999;
	int index;
	for (size_t j = 0; j < size; j++) {
		if (values[j] < minNumber) {
			minNumber = values[j];
			index = j;
		}
	}
	return index;
}
void arrayCreating(int* values, size_t size) {
	int mainSize = size;
	int newFirstArray[10000] = { 0 };
	for (int i = 0; i < mainSize; i++) {
		int tempIndex = minSearch(values, size);
		newFirstArray[i] = values[tempIndex];
		values = delArrayElement(values, size, tempIndex);
		--size;
	}
	for (int i = 0; i < mainSize; i++) {
		cout << newFirstArray[i] << " ";
	}
	cout << endl;
}
void first(int* values, size_t size) {
	bool flag = false;
	for (size_t i = 0; i < size; i++) {
		if (isProst(values[i] == true)) {
			flag = true;
			arrayCreating(values, size);
			break;
		}
	}
}



int multiSearch(int number) {
	int result = 1;
	string text = to_string(number);
	int n = text.length();
	for (int i = 0; i < n; i++) {
		result *= text[i] - '0';
	}
	return result;
}
int minMultiSearch(int* values, size_t size) {
	int minMulti = 730;
	int firstMinNum = 9;
	int minNumber = 1001;
	int index;
	for (size_t j = 0; j < size; j++) {
		if ((multiSearch(values[j]) < minMulti) || ((multiSearch(values[j]) == minMulti) && (to_string(values[j]))[0] < firstMinNum) ||
			((multiSearch(values[j]) == minMulti) && (to_string(values[j]))[0] == firstMinNum && values[j] < minNumber) ){
			minMulti = multiSearch(values[j]);
			firstMinNum = (to_string(values[j]))[0] - '0';
			minNumber = values[j];
			index = j;
		}
	}
	return index;
}

void second(int* values, size_t size) {
	int mainSize = size;
	int newFirstArray[10000] = { 0 };
	for (int i = 0; i < mainSize; i++) {
		int tempIndex = minMultiSearch(values, size);
		newFirstArray[i] = values[tempIndex];
		values = delArrayElement(values, size, tempIndex);
		--size;
	}
	for (int i = 0; i < mainSize; i++) {
		cout << newFirstArray[i] << " ";
	}
	cout << endl;
}



void third() {
	int countArray[100] = {};
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (matrixArray[i][j] % 2 == 0) {
				countArray[i] = countArray[i] + 1;
			}
		}
	}
	int maxNumber = countArray[0];
	int maxIndex;
	int countArraySize = sizeof(countArray) / sizeof(countArray[0]);
	for (int i = 0; i < countArraySize; i++) {
		if (countArray[i] > maxNumber) {
			maxNumber = countArray[i];
			maxIndex = i;
		}
	}
	for (int i = 0; i < column; i++) {
		matrixArray[maxIndex][i] = matrixArray[maxIndex][i] * matrixArray[maxIndex][i];
		cout << matrixArray[maxIndex][i] << " ";
	}
	cout << endl;
}
int main() {

	setlocale(LC_ALL, "");
	int firstArray[] = { 11, 32, 33, 4, 15, 6, 7, 8, 9, 10 };
	int arraySize = sizeof(firstArray) / sizeof(firstArray[0]);
	first(firstArray, arraySize);
	second(firstArray, arraySize);
	third();
}*/