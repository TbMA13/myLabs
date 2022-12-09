#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>
#include <chrono>

int getRandomNumber(const int minNumber, const int maxNumber) {
    //TODO добавить каждый раз прошлый элемент ко времени
    std::srand(time(NULL));
    return (rand() % (maxNumber - minNumber + 1) + minNumber);
}

class example {
private:
    int m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    int *m_numbersMas = nullptr;
    int *m_actions = nullptr;
    //short* m_brackets = nullptr;
public:
    example(int actionsCount, int minNumber, int maxNumber, const bool actions[4]) {
        m_actionsCount = actionsCount;
        m_minNumber = minNumber;
        m_maxNumber = maxNumber;
        m_numbersMas = new int[m_actionsCount + 1];
        m_actions = new int[m_actionsCount];
        //m_brackets = new short[m_actionsCount];
        this->generate(actions);
    }

    ~example() {
        delete[] m_numbersMas;
        delete[] m_actions;
    }

    void generate(const bool actions[4]) {
        short count = 0;
        while (count < m_actionsCount){
            short temp = getRandomNumber(0, 3);
            if (actions[temp]) {
                //TODO  что-то неправильно работает в генерации
                m_actions[count] = temp;
                std::cout << m_actions[count] << " " << temp << std::endl;
                count++;

            }
        }
        std::cout << "Сгенерированы действия" << std::endl;


    }
};

//	char getRandomAction() {
		//return (int)result;
//	}


int main() {
//    int tempMas[10] = {};
//    tempMas[0] = 11;
//    for (int i = 0; i < 10; i++){
//        std::chrono::milliseconds sleepTime(750);
//        std::this_thread::sleep_for(sleepTime);
//        std::cout << getRandomNumber(1, 12) << std::endl;
//    }
//    return 0;
//    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//TODO добавить приветствие
	int minNumber = 0;
	int maxNumber = 15;
	std::cout << "Первое число\n";
//	std::cin >> minNumber;
    std::cout << "Второе число\n";
//	std::cin >> maxNumber;
	// check min and max

	/*bool add;
	bool sub;
	bool multi;
	bool division;*/
	// хотя бы одно
    bool actions[4] = {true, true, true, true};
    std::cout << "Выбор действий\n";
//	std::cin >> actions[0];
//	std::cin >> actions[1];
//	std::cin >> actions[2];
//	std::cin >> actions[3];
	int actionsCount = 3;
    std::cout << "Количество действий\n";
//	std::cin >> actionsCount;
	int examplesCount = 3;
    std::cout << "Количество примеров\n";
//	std::cin >> examplesCount;
	example test(actionsCount, minNumber, maxNumber, actions);
	//std::string studentName; // Взять user name?
//	system("pause");

    return 0;
	for (int i = 0; i < examplesCount; i++) {

	}
}