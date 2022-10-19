#include <iostream>
#include <string>
#include <algorithm>

void add(std::string A, std::string B, std::string &res) {
	int i = 0;
	res = "";
	int maxLength = std::max(A.length(), B.length());
	for (int j = 0; j < maxLength; j++) {
		res += "";
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
}

void multiply(std::string multiA, std::string multiB, std::string& multiResult) {
	multiResult = "0";
	//std::string invertA = A;
	//std::string invertB = B;
	//std::reverse(invertA.begin(), invertA.end());
	//std::reverse(invertB.begin(), invertB.end());
	if (multiA == "0" || multiB == "0") {
		multiResult = "0";
		return;
	}
	std::string invertMultiA = multiA;
	std::reverse(invertMultiA.begin(), invertMultiA.end());
	for (int i = 0; i < multiA.length(); i++) {
		//std::string firstResult = "0";
		std::string secondResult = "0";
		for (int j = 0; j < invertMultiA[i] - '0'; j++) {
			add(secondResult, multiB, secondResult);
		}
		for (int j = 0; j < i; j++) {
			secondResult = secondResult + "0";
		}
		add(multiResult, secondResult, multiResult);
	}
}

int main() {
	std::string A;
	std::string B;
	std::string addResult;
	std::string multiResult;
	std::cin >> A;
	std::cin >> B;
	/*add(A, B, addResult);
	std::cout << addResult << std::endl;*/
	multiply(A, B, multiResult);
	std::cout << multiResult;
	return 0;
}