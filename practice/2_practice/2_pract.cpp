#include <iostream>
#include <string>
#include <algorithm>

void add(std::string A, std::string B, std::string &res) {
	int i = 0;
	res = "";
	int temp = 0;
	int plus = 0;
	int maxLength = std::max(A.length(), B.length());
	for (int j = 0; j < maxLength; j++) {
		res += "";
	}

	std::string invertA = A;
	std::string invertB = B;
	std::reverse(invertA.begin(), invertA.end());
	std::reverse(invertB.begin(), invertB.end());

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
	if (multiA == "0" || multiB == "0") {
		multiResult = "0";
		return;
	}

	multiResult = "0";
	std::string invertMultiA = multiA;
	std::reverse(invertMultiA.begin(), invertMultiA.end());

	for (int i = 0; i < multiA.length(); i++) {
		std::string firstResult = "0";

		for (int j = 0; j < invertMultiA[i] - '0'; j++) {
			add(firstResult, multiB, firstResult);
		}

		for (int j = 0; j < i; j++) {
			firstResult = firstResult + "0";
		}

		add(multiResult, firstResult, multiResult);
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string A;
	std::string B;
	std::string addResult;
	std::string multiResult;
	std::cout << "Введите первое число...\n>>> ";
	std::cin >> A;
	std::cout << "\nВведите второе число...\n>>> ";
	std::cin >> B;

	add(A, B, addResult);
	std::cout << "\nРезультат сложения: ";
	std::cout << addResult << "\n\n";
	
	multiply(A, B, multiResult);
	std::cout << "Результат умножения: ";
	std::cout << multiResult << std::endl;
	
	return 0;
}