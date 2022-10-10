#include <iostream>
using namespace std;

int main() {
	string A;
	string B;
	char res[1000] = {};
	std::cin >> A;
	std::cin >> B;
	int minSize = min(A.length(), B.length());
	int maxSize = max(A.length(), B.length());
	int tempLen = minSize;
	int temp = 0;
	/*tempA = A[3 - 1];
	cout << (tempA.c_str() - '0');*/
	for (int i = 0; i < minSize; i++) {
		//std::cout << A << " " << A % 10 << " " << 123 % 10;
		char tempA = A[tempLen - 1];
		char tempB = B[tempLen - 1];
		tempLen -= 1;
		A = A.substr(0, tempLen);
		B = B.substr(0, tempLen);
		if ((tempA - '0') + (tempB - '0') <= 9) {
			res[1000 - i - 1] = (char) (tempA - '0') + (tempB - '0') + temp;
			temp = 0;
		}
		else if ((tempA - '0') + (tempB - '0') > 9) {
			temp = ((tempA - '0') + (tempB - '0')) / 10;
			res[1000 - i - 1] = (char) (tempA - '0') + (tempB - '0');
		}
	}
	bool flag = false;
	//TODO исправить вывод
	for (int i = 1; i < 1000; i++) {
		if (flag) {
			cout << res[i]- '0';
		}
		else if (res[i] != '\0' && !flag) {
			flag = true;
			cout << (res[i] - '0');
		}

	}
}