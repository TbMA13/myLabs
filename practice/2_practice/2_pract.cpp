#include <iostream>
#include <string>
using namespace std;

int add(string A, string B, char res[1000]) {
	string newA = A;
	string newB = B;
	res[1000] = {};
	int minSize = min(A.length(), B.length());
	int maxSize = max(A.length(), B.length());
	int tempLen = minSize;
	int temp = 0;
	for (int i = 0; i < minSize; i++) {
		char tempA;
		char tempB;
		if (A.length() > B.length()) {
			tempA = A[tempLen - 1 + maxSize - minSize];
			tempB = B[tempLen - 1];
			tempLen--;
			A = A.substr(0, tempLen + maxSize - minSize);
			B = B.substr(0, tempLen);
		}
		else {
			tempA = A[tempLen - 1];
			tempB = B[tempLen - 1 + maxSize - minSize];
			tempLen--;
			B = B.substr(0, tempLen + maxSize - minSize);
			A = A.substr(0, tempLen);
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
	if (newA.length() == newB.length()) {
		if (temp != 0) {
			res[minSize] = temp;
		}
	}
	if (newA.length() > newB.length()) {
		for (int i = 0; i < maxSize - minSize; i++) {
			char tempA = newA[maxSize - minSize - 1];
			tempLen--;
			newA = newA.substr(0, tempLen);
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
			char tempB = newB[maxSize - minSize - 1];
			tempLen--;
			newB = newB.substr(0, tempLen);

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

void multiply(string A, string B, char res[1000]) {
	string multiplySumma = "";
	for (int i = 0; i < 1000; i++) {
		multiplySumma += '0';
	}
	for (int i = A.length() - 1; i > - 1; i--) {
		int tempSumma = 0;
		for (int j = B.length(), int count = 0; j > 0; j--, count++) {
			tempSumma += (A[i] - '0') * (B[j] - '0') * pow(10, count);
		}
		int temp = add(multiplySumma, to_string(tempSumma), res);
		if (temp != 0) {
			string temp;
			for (int j = to_string(tempSumma).length(); j > -1 ; i--) {
				
			}
		}
		else {
			for (int j = to_string(tempSumma).length() - 1; j > -1; i--) {

			}
		}
	}
}

int main() {
	string A;
	string B;
	char res[1000] = {};
	std::cin >> A;
	std::cin >> B;
	int temp = add(A, B, res);
	if (temp != 0) {
		for (int i = max(A.length(), B.length()); i != -1; i--) {
			cout << (int)res[i];
		}
	}
	else {
		for (int i = max(A.length(), B.length()) - 1; i != -1; i--) {

			cout << (int)res[i];
		}
	}

	cout << endl;
	multiply(A, B, res);
}