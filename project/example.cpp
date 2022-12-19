#include <iostream>
#include <vector>
#include <string>

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
    this->othersNumbersGenerate();
    for (int i = 0; i <= m_actionsCount; i++){
        std::cout << m_numbersMas[i] << " ";
    }
    std::cout << std::endl;
    this->manyDivision();
    for (int i = 0; i <= m_actionsCount; i++){
        std::cout << m_numbersMas[i] << " ";
    }
    std::cout << std::endl;
    this->exampleBuild();
    std::cout << this->getExample() << std::endl;

}

example::~example() {
    delete[] m_numbersMas;
    delete[] m_actions;
}

// изменяет массив m_actions, добавляя в него номера действий
void example::actionsGenerate(const bool actions[4]) {
    std::cout << "Генерация действий..." << std::endl;
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
        int tempRandomIndex = numbers::getRandomNumber(0, newTempActionsLen - 1, count * static_cast<int>(newActions[count]));

        if (newActions[tempRandomIndex] <= static_cast<Actions>(3) && newActions[tempRandomIndex] >= static_cast<Actions>(0)) {
            m_actions[count] = static_cast<int>(newActions[tempRandomIndex]);
            count++;

        }
    }
    std::cout << "Действия сгенерированы:" ;
    for (unsigned short i = 0; i < m_actionsCount ; i++) {
        std::cout << " "  << m_actions[i];
    }
    std::cout << std::endl;
    delete[] newActions;
}

// изменяет массив m_numbersMas, добавляя в него числа
void example::othersNumbersGenerate() {
    // сделать связь с прошлыми значениями
    std::cout << "Вывод чисел: " << std::endl;
    for (unsigned short i = 0; i < m_actionsCount; i++){
        int &currentAction = m_actions[i];
        int firstNumber = 0;
        int secondNumber = 0;
        firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * (m_minNumber * i));
        secondNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * (m_maxNumber * i));
        m_numbersMas[i] = firstNumber;
        m_numbersMas[i + 1] = secondNumber;
        std::cout << firstNumber << " " << secondNumber << std::endl;
    }

}

// изменяет массив m_numberMas, добавляя в него числа, которые участвуют в делении
void example::manyDivision(){
    int tempIndex;
    int count = 0;
    for (int i = 0; i <= m_actionsCount; i++){
        // если прошлыми действиям было не деление и текущее - не деление
        if (!count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            continue;
        }
        // если текущее действие - деление
        else if (m_actions[i] == static_cast<int>(Actions::DIVISION)){
            tempIndex = i;
            count++;
        }
        // если прошлыми действиям было деление и текущее - не деление
        else if (abs(m_actions[i]) > 3 && count || count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            bool flag = false;
            std::vector<int> dividerDividers = {};

            //TODO сделать не более 10 раз проверку
            while (!flag){
                int maxDivider = numbers::getRandomNumber((abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber) - 50: abs(m_minNumber) - 50, (abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber): abs(m_minNumber), count + 100);

                if (numbers::getRandomDivider(maxDivider) == maxDivider){
                    continue;
                }
                int tempMaxDivider = maxDivider;
                dividerDividers.push_back(maxDivider);
                std::cout << maxDivider << std::endl;
                while (tempMaxDivider > 1){
                    for (int j = 2; j <= tempMaxDivider; j++){
                        if (tempMaxDivider % j == 0){
                            dividerDividers.push_back(j);
                            tempMaxDivider /= j;
                            break;
                        }
                    }
                }
                if (dividerDividers.size() - 1>= count){
                    flag = true;
                }
                else{
                    dividerDividers.clear();
                }
            }
            for (int j = 0; j < dividerDividers.size(); j++){
                std::cout << dividerDividers[j] << " ";
            }
            std::cout << std::endl;
            int difference = static_cast<int>(dividerDividers.size()) - count;
            for (int j = 0; j < difference - 2; j++){
                int tempSize = static_cast<int>(dividerDividers.size());
                dividerDividers[numbers::getRandomNumber(1, tempSize - 2, tempSize)] *= dividerDividers[tempSize - 1];
                dividerDividers.resize(tempSize - 1);
            }
            std::cout << "Итог: ";
            for (int j = tempIndex - count, tempCount = 0; j <= tempIndex; j++, tempCount++){
                m_numbersMas[j + 1] = dividerDividers[tempCount];
                std::cout << m_numbersMas[j + 1] << " ";
            }
            std::cout << std::endl;
            count = 0;
        }
    }
}

// сборка готового примера в строку для вывода пользователю
void example::exampleBuild(){
    m_readyExample = "";
    for (int i = 0; i < m_actionsCount; i++){
        auto currentAction = static_cast<Actions>(m_actions[i]);
//        if (currentAction == Actions::DIVISION && static_cast<Actions>(m_actions[i - 1]) != Actions::DIVISION) {
//            m_readyExample += '(' + std::to_string(m_numbersMas[i]) + ' ';
//        }
//        else if (static_cast<Actions>(m_actions[i - 1]) == Actions::DIVISION && currentAction != Actions::DIVISION || currentAction == Actions::DIVISION && static_cast<Actions>(m_actions[i + 1]) != Actions::DIVISION /*|| i == m_actionsCount && static_cast<Actions>(m_actions[i + 1]) == Actions::DIVISION*/){
//            m_readyExample += std::to_string(m_numbersMas[i]) + ')' + ' ';
//        }
//        else if (m_numbersMas[i] < 0){
//            m_readyExample += '(' + std::to_string(m_numbersMas[i]) + ')' + ' ';
//        }
//        else {
//            m_readyExample += std::to_string(m_numbersMas[i]) + ' ';
//        }
        if (static_cast<Actions>(m_actions[i - 1]) != Actions::DIVISION && currentAction == Actions::DIVISION){
            m_readyExample += '(' + std::to_string(m_numbersMas[i]) + ' ';
        }
        else if (static_cast<Actions>(m_actions[i - 1]) == Actions::DIVISION && currentAction != Actions::DIVISION){
            m_readyExample += std::to_string(m_numbersMas[i]) + ')' + ' ';
        }
        else {
            m_readyExample += std::to_string(m_numbersMas[i]) + ' ';
        }
        switch (currentAction) {
            case Actions::ADDITION:
                m_readyExample += "+ ";
                break;
            case Actions::SUBTRACTION:
                m_readyExample += "- ";
                break;
            case Actions::MULTIPLICATION:
                m_readyExample += "* ";
                break;
            case Actions::DIVISION:
                m_readyExample += "/ ";
                break;
        }
    }
    if (static_cast<Actions>(m_actions[m_actionsCount - 1]) == Actions::DIVISION){
        m_readyExample += std::to_string(m_numbersMas[m_actionsCount]) + ')';
    }
    else{
        m_readyExample += std::to_string(m_numbersMas[m_actionsCount]);
    }
}

// геттер примера для вывода пользователю
std::string example::getExample() {
    return m_readyExample;
}

