#pragma once

class example {
private:
    unsigned short m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    int *m_numbersMas = nullptr;
    int *m_actions = nullptr;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]);

    ~example();

    // изменяет массив m_actions, добавляя в него номера действий
    void actionsGenerate(const bool actions[4]);

    // изменяет массив m_numbersMas, добавляя в него числа
    void numbersGenerate();
};