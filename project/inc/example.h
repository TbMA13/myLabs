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

    // �������� ������ m_actions, �������� � ���� ������ ��������
    void actionsGenerate(const bool actions[4]);

    // �������� ������ m_numbersMas, �������� � ���� �����
    void numbersGenerate();
};