#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	if (a > b and b > c){
		cout << a - b - c;
	} 
	else if (b > a and (b % c == 0)) {
		cout << ((b / c) + b - a);
	}
	else {
		cout << a + b + c;
	}
	//second();
}

void second() {
	int N;
	cin >> N;
	switch (N)
	{
	case 0:
		cout << "Всё хорошо!";
		break;
	case (1):
		cout << "Неверное чтение файла";
		break;
	case (3):
		cout << "Не все поля определены";
		break;
	default:
		cout << "Ошибка ввода";
		break;
	}
}