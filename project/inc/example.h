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
    long long m_result;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]);

    ~example();

    // измен€ет массив m_actions, добавл€€ в него номера действий
    void actionsGenerate(const bool actions[4]);

    // измен€ет массив m_numberMas, добавл€€ в него числа, которые участвуют в делении
    void manyDivision();

    // измен€ет массив m_numbersMas, добавл€€ в него числа
    void othersNumbersGenerate();

    // сборка готового примера в строку дл€ вывода пользователю
    void exampleBuild();

    // геттер примера дл€ вывода пользователю
    std::string getExample();

    // ¬ычисление результата
    void calcResult();

    // геттер результата
    long long getResult();
};