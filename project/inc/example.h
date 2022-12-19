#pragma once

class example {
private:
    unsigned short m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    //TODO реализовать через вектор
    int* m_numbersMas;
    int* m_actions;

    std::string m_readyExample;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]);

    ~example();

    // изменяет массив m_actions, добавляя в него номера действий
    void actionsGenerate(const bool actions[4]);

    // изменяет массив m_numberMas, добавляя в него числа, которые участвуют в делении
    void manyDivision();

    // изменяет массив m_numbersMas, добавляя в него числа
    void othersNumbersGenerate();

    // сборка готового примера в строку для вывода пользователю
    void exampleBuild();

    // геттер примера для вывода пользователю
    std::string getExample();
};