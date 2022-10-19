#include <iostream>
#include <string>
#include <algorithm>
//int add(string A, string B, char res[1000], string &addResult) {
//	string newA = A;
//	string newB = B;
//	std::fill(res, res+1000, 0);
//	int minSize = min(A.length(), B.length());
//	int maxSize = max(A.length(), B.length());
//	int tempLen = minSize;
//	int temp = 0;
//	addResult = "";
//	for (int i = 0; i < minSize; i++) {
//		char tempA;
//		char tempB;
//		if (A.length() > B.length()) {
//			tempA = A[tempLen - 1 + maxSize - minSize];
//			tempB = B[tempLen - 1];
//			tempLen--;
//			A = A.substr(0, tempLen + maxSize - minSize);
//			B = B.substr(0, tempLen);
//		}
//		else {
//			tempA = A[tempLen - 1];
//			tempB = B[tempLen - 1 + maxSize - minSize];
//			tempLen--;
//			B = B.substr(0, tempLen + maxSize - minSize);
//			A = A.substr(0, tempLen);
//		}
//		if ((tempA - '0') + (tempB - '0') + temp <= 9) {
//			addResult += (int)((tempA - '0') + (tempB - '0') + temp);
//			res[i] = (tempA - '0') + (tempB - '0') + temp;
//			temp = 0;
//		}
//		else if ((tempA - '0') + (tempB - '0') + temp > 9) {
//			addResult += (int)((tempA - '0') + (tempB - '0') + temp) % 10;
//			res[i] = ((tempA - '0') + (tempB - '0') + temp) % 10;
//			temp = ((tempA - '0') + (tempB - '0') + temp) / 10;
//		}
//	}
//	if (newA.length() == newB.length()) {
//		if (temp != 0) {
//			addResult += to_string(temp);
//			res[minSize] = temp;
//		}
//	}
//	if (newA.length() > newB.length()) {
//		for (int i = 0; i < maxSize - minSize; i++) {
//			char tempA = newA[maxSize - minSize - 1];
//			tempLen--;
//			newA = newA.substr(0, tempLen);
//			
//			if (((tempA - '0') + temp) <= 9) {
//				addResult += (int)((tempA - '0') + temp);
//				res[i + minSize] = ((tempA - '0') + temp);
//			}
//			else {
//				addResult += (int)((tempA - '0') + temp) % 10;
//				addResult += (int)((tempA - '0') + temp) / 10;
//				res[i + minSize] = ((tempA - '0') + temp) % 10;
//				res[i + minSize + 1] = ((tempA - '0') + temp) / 10;
//			}
//
//		}
//	}
//	else {
//		for (int i = 0; i < maxSize - minSize; i++) {
//			char tempB = newB[maxSize - minSize - 1];
//			tempLen--;
//			newB = newB.substr(0, tempLen);
//
//			if (((tempB - '0') + temp) <= 9) {
//				addResult += (int)((tempB - '0') + temp);
//				res[i + minSize] = ((tempB - '0') + temp);
//			}
//			else {
//				addResult += (int)((tempB - '0') + temp) % 10;
//				addResult += (int)((tempB - '0') + temp) / 10;
//				res[i + minSize] = ((tempB - '0') + temp) % 10;
//				res[i + minSize + 1] = ((tempB - '0') + temp) / 10;
//			}
//		}
//	}
//	return temp;
//
//}
//
//std::string add(const std::string& A, const std::string& B)
//{
//	std::string res = "";
//	int overflow = 0;
//	int i = 0;
//	while (i < A.length() && i < B.length())
//	{
//		res += (((A[i] - 48) + (B[i] - 48) + overflow) % 10 + 48);
//		if ((A[i] - 48) + (B[i] - 48) + overflow > 9)
//			overflow = true;
//		i++;
//	}
//	// число B закончилось
//	while (i < A.length())
//	{
//		res += (((A[i] - 48) + overflow) % 10 + 48);
//		if ((A[i] - 48) + overflow > 9)
//			overflow = true;
//		i++;
//	}
//	// число А закончилось
//	while (i < B.length())
//	{
//		res += (((B[i] - 48) + overflow) % 10 + 48);
//		if ((B[i] - 48) + overflow > 9)
//			overflow = true;
//		i++;
//	}
//	// если есть переход на последнем разряде, то
//	if (overflow > 0)
//		res = '1' + res;
//
//	return res;
//}

//void multiply(string A, string B, char res[1000]) {
//	string multiplySumma = "";
//	for (int i = 0; i < 1000; i++) {
//		multiplySumma += '0';
//	}
//	for (int i = A.length() - 1; i > -1; i--) {
//		int tempSumma = 0;
//		for (int j = B.length(), int count = 0; j > 0; j--, count++) {
//			tempSumma += (A[i] - '0') * (B[j] - '0') * pow(10, count);
//		}
//		int temp = add(multiplySumma, to_string(tempSumma), res);
//		if (temp != 0) {
//			string temp;
//			for (int j = to_string(tempSumma).length(); j > -1; i--) {
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

std::string add(std::string A, std::string B, std::string res) {
	int i = 0;
	res = "";
	int maxLength = std::max(A.length(), B.length());
	for (int j = 0; j < maxLength; j++) {
		res += " ";
	}
	std::string invertA = A;
	std::string invertB = B;
	std::reverse(invertA.begin(), invertA.end());
	std::reverse(invertB.begin(), invertB.end());
	int temp = 0;
	int plus = 0;
	while (i < invertA.length() && i < invertB.length()) {
		temp = (invertA[i] - '0') + (invertB[i] - '0') + plus;
		res += (temp % 10) + '0';
		if (((invertA[i] - '0') + (invertB[i] - '0') + plus) > 9) {
			plus = 1;
		}
		else {
			plus = 0;
		}
		i++;
	}
	while (i < invertA.length()) {
		temp = (invertA[i] - '0') + plus;
		res += (temp % 10) + '0';
		if (((invertA[i] - '0') + plus) > 9) {
			plus = temp / 10;
		}
		else {
			plus = 0;
		}
		i++;
	}
	while (i < invertB.length()) {
		temp = (invertB[i] - '0') + plus;
		res += (temp % 10) + '0';
		if (((invertB[i] - '0') + plus) > 9) {
			plus = temp / 10;
		}
		else {
			plus = 0;
		}
		i++;
	}
	if (plus) {
		res += plus + '0';
	}
	std::reverse(res.begin(), res.end());
	return res;
}

int main() {
	std::string A;
	std::string B;
	std::string addResult;
	char res[1000] = {};
	std::cin >> A;
	std::cin >> B;
	std::cout << add(A, B, addResult);
	//std::cout << add(A, B);
	return 0;

	//int temp = add(A, B, res, addResult);
	/*if (temp != 0) {
		for (int i = max(A.length(), B.length()); i != -1; i--) {
			cout << (int)res[i];
		}
	}
	else {
		for (int i = max(A.length(), B.length()) - 1; i != -1; i--) {
			
			cout << (int)res[i];
		}
	}*/
	std::cout << addResult;
	std::cout << std::endl;
	//multiply(A, B, res);
}