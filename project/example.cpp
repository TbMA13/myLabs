#include <iostream>
#include <vector>
#include <string>

#include <logger.h>
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
    m_result = 0;

    this->actionsGenerate(actions);
    this->othersNumbersGenerate();

    this->manyDivision();
    logger::write("Текущие числа: "); logger::newLine();
    for (int i = 0; i <= m_actionsCount; i++){
        logger::write(std::to_string(m_numbersMas[i]) + " ");
    }
    logger::newLine();

    logger::write("Текущие действия: "); logger::newLine();
    for (int i = 0; i < m_actionsCount; i++){
        logger::write(std::to_string(m_actions[i]) + " ");
    }
    logger::newLine(); logger::newLine();
    this->exampleBuild();
    std::cout << this->getExample() << std::endl;
    this->calcResult();
    logger::write(m_readyExample); logger::newLine();
    logger::write(std::to_string(m_result)); logger::newLine();
    std::cout << this->getResult() << std::endl;

}

example::~example() {
    delete[] m_numbersMas;
    delete[] m_actions;
}

// изменяет массив m_actions, добавляя в него номера действий
void example::actionsGenerate(const bool actions[4]) {
    logger::write("Генерация действий..."); logger::newLine();
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
        int tempRandomIndex = numbers::getRandomNumber(0, newTempActionsLen - 1, count + 11);

        if (newActions[tempRandomIndex] <= static_cast<Actions>(3) && newActions[tempRandomIndex] >= static_cast<Actions>(0)) {
            m_actions[count] = static_cast<int>(newActions[tempRandomIndex]);
            count++;

        }
    }
    logger::write("Действия сгенерированы:");
    for (unsigned short i = 0; i < m_actionsCount ; i++) {
        logger::write(" " + std::to_string(m_actions[i]));
    }
    logger::newLine(); logger::newLine();
    delete[] newActions;
}

// изменяет массив m_numbersMas, добавляя в него числа
void example::othersNumbersGenerate() {
    // сделать связь с прошлыми значениями
    logger::write("Генерация всех чисел..."); logger::newLine();
    for (unsigned short i = 0; i < m_actionsCount; i++){
        int &currentAction = m_actions[i];
        int firstNumber = 0;
        int secondNumber = 0;
        firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * ((int)&m_minNumber * i));
        secondNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, (i + 1) * ((int)&m_maxNumber * (i + 1)));
        m_numbersMas[i] = firstNumber;
        m_numbersMas[i + 1] = secondNumber;
        logger::write(std::to_string(firstNumber) + " " + std::to_string(secondNumber)); logger::newLine();
    }
    logger::newLine();
}

// изменяет массив m_numberMas, добавляя в него числа, которые участвуют в делении
void example::manyDivision(){
    logger::write("Генерация деления..."); logger::newLine();
    int n = 11;
    int tempIndex;
    int count = 0;
    for (int i = 0; i <= m_actionsCount; i++){

        // если прошлыми действиям было не деление и текущее - не деление
        if (!count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            n *= 2;
            continue;
        }

        // если текущее действие - деление
        else if (m_actions[i] == static_cast<int>(Actions::DIVISION)){
            n *= 3;
            tempIndex = i;
            count++;
        }

        // если прошлыми действиям было деление и текущее - не деление
        else if (abs(m_actions[i]) > 3 && count || count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            n *= 4;
            bool flag = false;
            std::vector<int> dividers = {};
            //TODO сделать не более 10 раз проверку
            while (!flag){
                int maxDivider = numbers::getRandomNumber((abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber) - (m_maxNumber - m_minNumber) / 2: abs(m_minNumber) - (m_maxNumber - m_minNumber) / 2, (abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber): abs(m_minNumber), n +1);
                n += 11;
                if (numbers::getRandomDivider(maxDivider) == maxDivider){
                    continue;
                }
                int tempMaxDivider = maxDivider;
                dividers.push_back(maxDivider);
//                logger::write(std::to_string(maxDivider)); logger::newLine();
                while (tempMaxDivider > 1){
                    for (int j = 2; j <= tempMaxDivider; j++){
                        if (tempMaxDivider % j == 0){
                            dividers.push_back(j);
                            tempMaxDivider /= j;
                            break;
                        }
                    }
                }
                if (dividers.size() - 1 >= count){
                    flag = true;
                }
                else{
                    dividers.clear();
                }
            }
            logger::write("Все делители:"); logger::newLine();
            for (int dividerDivider : dividers){
                logger::write(std::to_string(dividerDivider) + " ");
            }
            logger::newLine(); logger::newLine();
            int difference = static_cast<int>(dividers.size()) - count;
            for (int j = 0; j < difference - 2; j++){
                int tempSize = static_cast<int>(dividers.size());
                dividers[numbers::getRandomNumber(1, tempSize - 2, tempSize)] *= dividers[tempSize - 1];
                dividers.resize(tempSize - 1);
            }
            logger::write("Итог: ");
            for (int j = tempIndex - count, tempCount = 0; j <= tempIndex; j++, tempCount++){
                m_numbersMas[j + 1] = dividers[tempCount];
                logger::write(std::to_string(m_numbersMas[j + 1]) + " ");
            }
            logger::newLine(); logger::newLine();
            count = 0;
        }
    }
}

// сборка готового примера в строку для вывода пользователю
void example::exampleBuild(){
    m_readyExample = "";
    for (int i = 0; i < m_actionsCount; i++){
        auto currentAction = static_cast<Actions>(m_actions[i]);
        if (static_cast<Actions>(m_actions[i - 1]) != Actions::DIVISION && currentAction == Actions::DIVISION){
            m_readyExample += '(' + std::to_string(m_numbersMas[i]) + ' ';
        }
        else if (static_cast<Actions>(m_actions[i - 1]) == Actions::DIVISION && currentAction != Actions::DIVISION){
            m_readyExample += std::to_string(m_numbersMas[i]) + ')' + ' ';
        }
        else if (m_numbersMas[i] < 0){
            m_readyExample += '(' + std::to_string(m_numbersMas[i]) + ')' + ' ';
        }
        else {
            m_readyExample += std::to_string(m_numbersMas[i]) + ' ';
        }
        // добавляет действие
        // / ; + ; - ; *
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
    else if (m_numbersMas[m_actionsCount] < 0){
        m_readyExample += '(' + std::to_string(m_numbersMas[m_actionsCount]) + ')';
    }
    else{
        m_readyExample += std::to_string(m_numbersMas[m_actionsCount]);
    }
}

// геттер примера для вывода пользователю
std::string example::getExample() {
    return m_readyExample;
}

// Вычисление результата
void example::calcResult() {
    Actions currentAction;
    std::vector<Actions> newTempActions = {};
    std::vector<int> newTempNumbers = {};
    // Считает все действия деления и объединяет их в одно число. (190 / 5 / 2) ---> 19
    for (int i = 0; i < m_actionsCount; i++){
        currentAction = static_cast<Actions>(m_actions[i]);
        switch (currentAction) {
            case Actions::DIVISION:
            {
                int temp = m_numbersMas[i];
                int count = 1;
                for (int j = i; static_cast<Actions>(m_actions[j]) == Actions::DIVISION && j < m_actionsCount; j++){
                    temp /= m_numbersMas[j + 1];
                    count++;
                }
                newTempNumbers.push_back(temp);
                if (i + count - 1 < m_actionsCount) {
                    newTempActions.push_back(static_cast<Actions>(m_actions[i + count - 1]));
                }
                i += count - 1;
                break;
            }
            default:
                newTempActions.push_back(currentAction);
                newTempNumbers.push_back(m_numbersMas[i]);
                break;
        }
    }
    newTempNumbers.push_back(m_numbersMas[m_actionsCount]);
    newTempNumbers.resize(newTempActions.size() + 1);

    logger::write("Объединение деления"); logger::newLine();
    logger::write("Числа: ");
    for (auto it:newTempNumbers){
        logger::write(std::to_string(it) + " ");
    }
    logger::newLine();
    logger::write("Действия: ");
    for (auto it:newTempActions){
        logger::write(std::to_string(static_cast<int>(it)) + " ");
    }
    logger::newLine(); logger::newLine();



    std::vector<Actions> newActions = {};
    std::vector<long long> newNumbers = {};
    // подсчёт всех умножений, и объединение каждого в одно число
    for (int i = 0; i < newTempActions.size(); i++){
        currentAction = newTempActions[i];
        switch (currentAction) {
            case Actions::MULTIPLICATION:
            {
                long long temp = newTempNumbers[i];
                int count = 1;

                for (int j = i; j < newTempActions.size() && newTempActions[j] == Actions::MULTIPLICATION; j++) {
                    temp *= newTempNumbers[j + 1];
                    count++;
                }
                newNumbers.push_back(temp);
                if (i + count - 1 < newTempActions.size()){
                    newActions.push_back(newTempActions[i + count - 1]);
                }
                i += count - 1;
                break;
            }
            default:
                newActions.push_back(currentAction);
                newNumbers.push_back(newTempNumbers[i]);
                break;
        }
    }
    newNumbers.push_back(newTempNumbers[newTempNumbers.size() - 1]);
    newNumbers.resize(newActions.size() + 1);

    logger::write("Объединение умножения"); logger::newLine();
    logger::write("Числа: ");
    for (auto it:newNumbers){
        logger::write(std::to_string(it) + " ");
    }
    logger::newLine();
    logger::write("Действия: ");
    for (auto it:newActions){
        logger::write(std::to_string(static_cast<int>(it)) + " ");
    }
    logger::newLine();
    // итоговый подсчёт
    m_result += newNumbers[0];
    for (int i = 0; i < newActions.size(); i++){
        currentAction = newActions[i];
        switch (currentAction) {
            case Actions::ADDITION:
            {
                m_result += newNumbers[i + 1];
                break;
            }
            case Actions::SUBTRACTION:
            {
                m_result -= newNumbers[i + 1];
                break;
            }
            default:
                break;
        }
    }
}

// геттер результата
long long example::getResult() {
    return m_result;
}

