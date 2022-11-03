#include <iostream>

int main() {
	long long number;
	std::cin >> number;
	for (int i = 0; i < 8; i++) {
		std::cout << (int)*((unsigned char*)(&number) + i) << " ";
	}
}