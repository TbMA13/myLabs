#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <numbersFunc.h>


enum Actions{
  ADDITION = 0,
  SUBTRACTION = 1,
  MULTIPLICATION = 2,
  DIVISION = 3
};

class example {
private:
    unsigned short m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    int *m_numbersMas = nullptr;
    int *m_actions = nullptr;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]) {
        m_actionsCount = actionsCount;
        m_minNumber = minNumber;
        m_maxNumber = maxNumber;
        m_numbersMas = new int[m_actionsCount + 1];
        m_actions = new int[m_actionsCount];
        this->actionsGenerate(actions);
        this->numbersGenerate();
    }

    ~example() {
        delete[] m_numbersMas;
        delete[] m_actions;
    }

    // �������� ������ m_actions, �������� � ���� ������ ��������
    void actionsGenerate(const bool actions[4]) {
        std::cout << "��������� ��������..." << std::endl;
        short count = 0;
        short newTempActionsLen = (short)actions[0] + (short)actions[1] + (short)actions[2] + (short)actions[3];

        auto* newActions = new short[newTempActionsLen];
        for (short i = 0; i < 4; i++){
            if (actions[i]) {
                newActions[count] = i;
                count++;
            }
        }
        count = 0;
        while (count < m_actionsCount) {
            // TODO ��� ������ � ��������???
            short tempRandomIndex = numbers::getRandomNumber(0, newTempActionsLen - 1, count * (int)newActions);

            if (newActions[tempRandomIndex] <= 3 && newActions[tempRandomIndex] >= 0) {
                m_actions[count] = newActions[tempRandomIndex];
                count++;

            }
        }
        std::cout << "�������� �������������:" ;
        for (short i = 0; i < m_actionsCount ; i++) {
            std::cout << " "  << m_actions[i];
        }
        std::cout << std::endl;
        delete[] newActions;
    }

    // �������� ������ m_numbersMas, �������� � ���� �����
    void numbersGenerate()
    {
        // ������� ����� � �������� ����������
        std::cout << "����� �����: " << std::endl;
        for (short i = 0; i < m_actionsCount; i++){
            int &currentAction = m_actions[i];
            int firstNumber = 0;
            int secondNumber = 0;
            if (currentAction == Actions::DIVISION) {
                firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * (int)&i);
                secondNumber = numbers::getRandomDivider(firstNumber);
                short count = 0;
                while (!secondNumber && count < 5) {
                    firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, count * (int)&firstNumber);
                    secondNumber = numbers::getRandomDivider(firstNumber);
                    count++;
                }
                if (!secondNumber){
                    secondNumber = firstNumber;
                }

            }
            else if (currentAction == Actions::MULTIPLICATION || currentAction == Actions::ADDITION || currentAction == Actions::SUBTRACTION){
                firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i*(int)&m_minNumber*(int)&i);
                secondNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i*(int)&m_maxNumber*(int)&i);
            }
            m_numbersMas[i] = firstNumber;
            m_numbersMas[i + 1] = secondNumber;
            std::cout << firstNumber << " " << secondNumber << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
//    SetConsoleCP(8); SetConsoleOutputCP(8);
	//TODO �������� �����������
    //TODO �������� (!)���� ��������
	int minNumber = -1000;
	int maxNumber = 0;
	std::cout << "������ �����\n";
//	std::cin >> minNumber;
    std::cout << "������ �����\n";
    //	std::cin >> maxNumber;
	// check min and max
	/*bool add;
	bool sub;
	bool multi;
	bool division;*/
	// ���� �� ����
    bool actions[4] = {true, true, true, true};
    std::cout << "����� ��������\n";
//	std::cin >> actions[0];
//	std::cin >> actions[1];
//	std::cin >> actions[2];
//	std::cin >> actions[3];
	int actionsCount = 5;
    std::cout << "���������� ��������\n";
//	std::cin >> actionsCount;
	int examplesCount = 3;
    std::cout << "���������� ��������\n";
//	std::cin >> examplesCount;
	example test(actionsCount, minNumber, maxNumber, actions);
//	std::string studentName;
    //TODO ����� user name?
    system("pause");
    return 0;
}