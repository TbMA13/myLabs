#include <iostream>

#include <example.h>
#include <numbersFunc.h>

enum class Actions{
    ADDITION = 0,
    SUBTRACTION = 1,
    MULTIPLICATION = 2,
    DIVISION = 3
};


example::example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]) {
    m_actionsCount = actionsCount;
    m_minNumber = minNumber;
    m_maxNumber = maxNumber;
    m_numbersMas = new int[m_actionsCount + 1];
    m_actions = new int[m_actionsCount];
    this->actionsGenerate(actions);
    this->numbersGenerate();
}

example::~example() {
    delete[] m_numbersMas;
    delete[] m_actions;
}

// измен€ет массив m_actions, добавл€€ в него номера действий
void example::actionsGenerate(const bool actions[4]) {
    std::cout << "√енераци€ действий..." << std::endl;
    short count = 0;
    int newTempActionsLen = (int)actions[0] + (int)actions[1] + (int)actions[2] + (int )actions[3];

    auto* newActions = new Actions[newTempActionsLen];
    for (short i = 0; i < 4; i++){
        if (actions[i]) {
            newActions[count] = static_cast<Actions>(i);
            count++;
        }
    }
    count = 0;
    while (count < m_actionsCount) {
        // TODO что делать с рандомом???
        int tempRandomIndex = numbers::getRandomNumber(0, newTempActionsLen - 1, count * (int)newActions);

        if (newActions[tempRandomIndex] <= static_cast<Actions>(3) && newActions[tempRandomIndex] >= static_cast<Actions>(0)) {
            m_actions[count] = static_cast<int>(newActions[tempRandomIndex]);
            count++;

        }
    }
    std::cout << "ƒействи€ сгенерированы:" ;
    for (unsigned short i = 0; i < m_actionsCount ; i++) {
        std::cout << " "  << m_actions[i];
    }
    std::cout << std::endl;
    delete[] newActions;
}

// измен€ет массив m_numbersMas, добавл€€ в него числа
void example::numbersGenerate() {
    // сделать св€зь с прошлыми значени€ми
    std::cout << "¬ывод чисел: " << std::endl;
    for (unsigned short i = 0; i < m_actionsCount; i++){
        int &currentAction = m_actions[i];
        int firstNumber = 0;
        int secondNumber = 0;
        if (currentAction == (int)Actions::DIVISION) {
            firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * (int)&i);
            secondNumber = numbers::getRandomDivider(firstNumber); // возвращает 0, если firstNumber = 0
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
        else if (static_cast<Actions>(currentAction) == Actions::MULTIPLICATION || static_cast<Actions>(currentAction) == Actions::ADDITION || static_cast<Actions>(currentAction) == Actions::SUBTRACTION){
            firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i*(int)&m_minNumber*(int)&i);
            secondNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i*(int)&m_maxNumber*(int)&i);
        }
        m_numbersMas[i] = firstNumber;
        m_numbersMas[i + 1] = secondNumber;
        std::cout << firstNumber << " " << secondNumber << std::endl;
    }
}