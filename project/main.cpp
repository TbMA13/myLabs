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

enum Actions{
  ADDITION = 0,
  SUBTRACTION = 1,
  MULTIPLICATION = 2,
  DIVISION = 3
};

class example {
private:
    int m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    int *m_numbersMas = nullptr;
    int *m_actions = nullptr;
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
        std::cout << "Генерация действий..." << std::endl;
        short count = 0;
        short newTempActionsLen = actions[0] + actions[1] + actions[2] + actions[3];
        short* newActions = new short[newTempActionsLen];
        for (short i = 0; i < sizeof(actions); i++){
            if (actions[i]) {
                newActions[newTempActionsLen - sizeof(newActions)] = i;
                newTempActionsLen += 1;
            }
        }
        newTempActionsLen = sizeof(newActions);
        while (count < m_actionsCount) {
            std::chrono::milliseconds sleepTime(650);
            std::this_thread::sleep_for(sleepTime);
            short tempRandomNumber = getRandomNumber(0, newTempActionsLen - 1);

            if (actions[tempRandomNumber]) {
                m_actions[count] = tempRandomNumber;
                count++;

            }
        }
        std::cout << "Действия сгенерированы:" ;
        for (short i = 0; i < sizeof(newActions) - 1; i++) {
            std::cout << " "  << m_actions[i];
        }
        delete[] newActions;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//TODO добавить приветствие
    //TODO проверка (!)ВСЕХ значений
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
//	std::string studentName;
    //TODO Взять user name?
    return 0;
}