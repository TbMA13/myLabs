#include <iostream>
#include <cstdlib>
#include <windows.h>
//#include <ctime>

//#include <numbersFunc.h>
#include <example.h>

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//TODO �������� �����������

    //TODO �������� (!)���� ��������

	int minNumber = 0;
	int maxNumber = 500;
	std::cout << "������ �����: " << minNumber << std::endl;
//	std::cin >> minNumber;
    std::cout << "������ �����: " << maxNumber << std::endl;
//    std::cin >> maxNumber;
	// check min and max
	/*bool add;
	bool sub;
	bool multi;
	bool division;*/
	// ���� �� ����
    bool actions[4] = {true, 0, 0, true};
    std::cout << "����� ��������:";

    //TODO ��������
    for (auto it : actions){
        std::cout << " " << it;
    }
    std::cout << std::endl;
//	std::cin >> actions[0];
//	std::cin >> actions[1];
//	std::cin >> actions[2];
//	std::cin >> actions[3];
	int actionsCount = 8;
    std::cout << "���������� ��������: " << actionsCount << std::endl;
//	std::cin >> actionsCount;
	int examplesCount = 3;
    std::cout << "���������� ��������: " << examplesCount << std::endl;
//	std::cin >> examplesCount;
    std::cout << std::endl;
	example test(actionsCount, minNumber, maxNumber, actions);
//	std::string studentName;
    system("pause");
    return 0;
}