#include <iostream>

int main() {
	long long A;
	long long B;
	long long res = 0;
	std::cin >> A;
	std::cin >> B;
	int minSize = 0;
	long long tempA = A;
	long long tempB = A;
	while (tempA > 0 && tempB > 0) {
		tempA /= 10;
		tempB /= 10;
		minSize++;
	}
	for (int i = 0; i < minSize; i++) {
		//std::cout << A << " " << A % 10 << " " << 123 % 10;
		tempA = A % 10;
		tempB = B % 10;
		A /= 10;
		B /= 10;
		res += (tempA + tempB) * pow(10, i);
	}
	res += (A + B) * pow(10, minSize);
	std::cout << res;
}