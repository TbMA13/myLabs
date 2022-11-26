#include <iostream>
#include <stdlib.h>
#include <time.h>

class example {
private:
	int m_actionsCount;
	
	int m_minNumber;
	int m_maxNumber;

	int* m_numbersMas = nullptr;
	int* m_actions = nullptr;
	//short* m_brackets = nullptr;
public:
	example(int actionsCount, int minNumber, int maxNumber, const bool* actions[4]) {
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
	void generate(const bool* actions[4]) {

		
	}

	int getRandomNumber() {
		std::srand(time(NULL));
		return rand() % (m_maxNumber - m_minNumber + 1) + m_minNumber;
	}

	char getRandomAction() {
		//return (int)result;
	}
};

int main() {
	/*std::srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		std::cout << rand() % (10 + 10 + 1) - 10 << std::endl;
	}*/
	return 0;
	//TODO добавить приветствие
	int minNumber;
	int maxNumber;
	std::cin >> minNumber;
	std::cin >> maxNumber;
	// check min and max
	bool actions[4] = {};
	/*bool add;
	bool sub;
	bool multi;
	bool division;*/
	// хотя бы одно
	std::cin >> actions[0];
	std::cin >> actions[1];
	std::cin >> actions[2];
	std::cin >> actions[3];
	int actionsCount;
	std::cin >> actionsCount;
	int examplesCount;
	std::cin >> examplesCount;
	//std::string studentName; // Взять user name?
	return 0;
	for (int i = 0; i < examplesCount; i++) {

	}
}