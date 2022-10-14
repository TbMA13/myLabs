#include <iostream>
#include <string>
using namespace std;

int add(char A[1000], char B[1000], char res[1001], int lenA, int lenB) {
	//todo сделать аргумент длин массивов
	res[1001] = {};
	int minSize = min(lenA, lenB);
	int maxSize = max(lenA, lenB);
	int tempLen = minSize;
	int temp = 0;
	for (int i = 0; i < minSize; i++) {
		char tempA;
		char tempB;

		if (lenA > lenB) {
			tempA = A[tempLen - 1 + maxSize - minSize - i];
			tempB = B[tempLen - 1 - i];
			tempLen--;
		}
		else {
			tempA = A[tempLen - 1 - i];
			tempB = B[tempLen - 1 + maxSize - minSize - i];
			tempLen--;
		}

		if ((tempA - '0') + (tempB - '0') + temp <= 9) {
			res[i] = (tempA - '0') + (tempB - '0') + temp;
			temp = 0;
		}
		else if ((tempA - '0') + (tempB - '0')  + temp > 9) {
			res[i] = ((tempA - '0') + (tempB - '0') + temp) % 10;
			temp = ((tempA - '0') + (tempB - '0') + temp) / 10;
		}
	}
	if (lenA == lenB) {
		if (temp != 0) {
			res[minSize] = temp;
		}
	}
	if (lenB > lenB) {
		for (int i = 0; i < maxSize - minSize; i++) {
			char tempA = A[maxSize - minSize - 1 - i];
			tempLen--;
			if (((tempA - '0') + temp) <= 9) {
				res[i + minSize] = ((tempA - '0') + temp);
			}
			else {
				res[i + minSize] = ((tempA - '0') + temp) % 10;
				res[i + minSize + 1] = ((tempA - '0') + temp) / 10;
			}

		}
	}
	else {
		for (int i = 0; i < maxSize - minSize; i++) {
			char tempB = B[maxSize - minSize - 1 - i];
			tempLen--;
			if (((tempB - '0') + temp) <= 9) {
				res[i + minSize] = ((tempB - '0') + temp);
			}
			else {
				res[i + minSize] = ((tempB - '0') + temp) % 10;
				res[i + minSize + 1] = ((tempB - '0') + temp) / 10;
			}
		}
	}
	return temp;
	
}

//void multiply(string A, string B, char res[1000]) {
//	string multiplySumma = "";
//	for (int i = 0; i < 1000; i++) {
//		multiplySumma += '0';
//	}
//	for (int i = A.length() - 1; i > - 1; i--) {
//		int tempSumma = 0;
//		for (int j = B.length(), int count = 0; j > 0; j--, count++) {
//			tempSumma += (A[i] - '0') * (B[j] - '0') * pow(10, count);
//		}
//		int temp = add(multiplySumma, to_string(tempSumma), res);
//		if (temp != 0) {
//			string temp;
//			for (int j = to_string(tempSumma).length(); j > -1 ; i--) {
//				
//			}
//		}
//		else {
//			for (int j = to_string(tempSumma).length() - 1; j > -1; i--) {
//
//			}
//		}
//	}
//}

int main() {
	string firstA;
	string firstB;
	char A[1000] = {};
	char B[1000] = {};
	char res[1000] = {};
	std::cin >> firstA;
	std::cin >> firstB;
	for (int i = 0; i < firstA.length(); i++) {
		A[i] = firstA[i];
	}
	for (int i = 0; i < firstB.length(); i++) {
		B[i] = firstB[i];
	}
	int temp = add(A, B, res, firstA.length(), firstB.length());
	
	if (temp != 0) {
		for (int i = max(strlen(A), strlen(B)); i != -1; i--) {
			cout << (int)res[i];
		}
	}

	else {
		for (int i = max(strlen(A), strlen(B)); i != -1; i--) {
			cout << (int)res[i];
		}
	}

	cout << endl;
	//multiply(A, B, res);
}