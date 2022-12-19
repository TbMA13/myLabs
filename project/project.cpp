#include <iostream>
#include <cstdlib>
#include <windows.h>
//#include <fstream>

//#include <numbersFunc.h>
#include <example.h>

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //TODO надо записать файл лога
//    std::ofstream logFile;
//    logFile.open("log.txt");
	//TODO добавить приветствие

    //TODO проверка (!)ВСЕХ значений

	int minNumber = 0;
	int maxNumber = 1000;
	std::cout << "Первое число: " << minNumber << std::endl;
//	std::cin >> minNumber;
    std::cout << "Второе число: " << maxNumber << std::endl;
//    std::cin >> maxNumber;
	// check min and max
	/*bool add;
	bool sub;
	bool multi;
	bool division;*/
	// хотя бы одно
    bool actions[4] = {true, true, true, true};
    std::cout << "Выбор действий:";

    //TODO уточнить
    for (auto it : actions){
        std::cout << " " << it;
    }
    std::cout << std::endl;
//	std::cin >> actions[0];
//	std::cin >> actions[1];
//	std::cin >> actions[2];
//	std::cin >> actions[3];
	int actionsCount = 7;
    std::cout << "Количество действий: " << actionsCount << std::endl;
//	std::cin >> actionsCount;
	int examplesCount = 3;
    std::cout << "Количество примеров: " << examplesCount << std::endl;
//	std::cin >> examplesCount;
    std::cout << std::endl;
	example test(actionsCount, minNumber, maxNumber, actions);
//	std::string studentName;
    system("pause");
    return 0;
}