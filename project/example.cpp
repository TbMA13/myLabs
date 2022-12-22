#include <iostream>
#include <vector>
#include <string>
#include <thread>

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

    this->calcResult();
    std::cout << this->getResult() << std::endl;

}

example::~example() {
    delete[] m_numbersMas;
    delete[] m_actions;
}

// �������� ������ m_actions, �������� � ���� ������ ��������
void example::actionsGenerate(const bool actions[4]) {
    std::cout << "��������� ��������..." << std::endl;
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
        // TODO ��� ������ � ��������???
        int tempRandomIndex = numbers::getRandomNumber(0, newTempActionsLen - 1, count + 11);

        if (newActions[tempRandomIndex] <= static_cast<Actions>(3) && newActions[tempRandomIndex] >= static_cast<Actions>(0)) {
            m_actions[count] = static_cast<int>(newActions[tempRandomIndex]);
            count++;

        }
    }
    std::cout << "�������� �������������:" ;
    for (unsigned short i = 0; i < m_actionsCount ; i++) {
        std::cout << " "  << m_actions[i];
    }
    std::cout << std::endl;
    delete[] newActions;
}

// �������� ������ m_numbersMas, �������� � ���� �����
void example::othersNumbersGenerate() {
    // ������� ����� � �������� ����������
    std::cout << "����� �����: " << std::endl;
    for (unsigned short i = 0; i < m_actionsCount; i++){
        int &currentAction = m_actions[i];
        int firstNumber = 0;
        int secondNumber = 0;
        firstNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, i * ((int)&m_minNumber * i));
        secondNumber = numbers::getRandomNumber(m_minNumber, m_maxNumber, (i + 1) * ((int)&m_maxNumber * (i + 1)));
        m_numbersMas[i] = firstNumber;
        m_numbersMas[i + 1] = secondNumber;
        std::cout << firstNumber << " " << secondNumber << std::endl;
    }

}

// �������� ������ m_numberMas, �������� � ���� �����, ������� ��������� � �������
void example::manyDivision(){
    int n = 11;
    int tempIndex;
    int count = 0;
    for (int i = 0; i <= m_actionsCount; i++){
        // ���� �������� ��������� ���� �� ������� � ������� - �� �������
        if (!count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            n *= 2;
            continue;
        }
        // ���� ������� �������� - �������
        else if (m_actions[i] == static_cast<int>(Actions::DIVISION)){
            n *= 3;
            tempIndex = i;
            count++;
        }
        // ���� �������� ��������� ���� ������� � ������� - �� �������
        else if (abs(m_actions[i]) > 3 && count || count && m_actions[i] != static_cast<int>(Actions::DIVISION)){
            n *= 4;
            bool flag = false;
            std::vector<int> dividerDividers = {};
            //TODO ������� �� ����� 10 ��� ��������
            while (!flag){
                int maxDivider = numbers::getRandomNumber((abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber) - (m_maxNumber - m_minNumber) / 2: abs(m_minNumber) - (m_maxNumber - m_minNumber) / 2, (abs(m_maxNumber) > abs(m_minNumber))? abs(m_maxNumber): abs(m_minNumber), n +1);
//                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                n += 11;
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
            for (int dividerDivider : dividerDividers){
                std::cout << dividerDivider << " ";
            }
            std::cout << std::endl;
            int difference = static_cast<int>(dividerDividers.size()) - count;
            for (int j = 0; j < difference - 2; j++){
                int tempSize = static_cast<int>(dividerDividers.size());
                dividerDividers[numbers::getRandomNumber(1, tempSize - 2, tempSize)] *= dividerDividers[tempSize - 1];
                dividerDividers.resize(tempSize - 1);
            }
            std::cout << "����: ";
            for (int j = tempIndex - count, tempCount = 0; j <= tempIndex; j++, tempCount++){
                m_numbersMas[j + 1] = dividerDividers[tempCount];
                std::cout << m_numbersMas[j + 1] << " ";
            }
            std::cout << std::endl;
            count = 0;
        }
    }
}

// ������ �������� ������� � ������ ��� ������ ������������
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
        // ��������� ��������
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

// ������ ������� ��� ������ ������������
std::string example::getExample() {
    return m_readyExample;
}

// ���������� ����������
void example::calcResult() {
    Actions currentAction;

    std::vector<Actions> newTempActions = {};
    std::vector<int> newTempNumbers = {};
    // ������� ��� �������� ������� � ���������� �� � ���� �����. (190 / 5 / 2) ---> 19
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

    // ���
    std::cout << "������ �������" << std::endl;
    for (auto it:newTempNumbers){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    for (auto it:newTempActions){
        std::cout << static_cast<int>(it) << " ";
    }
    std::cout << std::endl;


    std::vector<Actions> newActions = {};
    std::vector<long long> newNumbers = {};
    // ������� ���� ���������, � ����������� ������� � ���� �����
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

    // ���
    std::cout << "������ ���������" << std::endl;
    for (auto it:newNumbers){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    for (auto it:newActions){
        std::cout << static_cast<int>(it) << " ";
    }
    std::cout << std::endl;


    // �������� �������
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

// ������ ����������
long long example::getResult() {
    return m_result;
}

