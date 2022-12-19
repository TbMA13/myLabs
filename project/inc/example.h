#pragma once

class example {
private:
    unsigned short m_actionsCount;

    int m_minNumber;
    int m_maxNumber;
    //TODO ����������� ����� ������
    int* m_numbersMas;
    int* m_actions;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]);

    ~example();

    // �������� ������ m_actions, �������� � ���� ������ ��������
    void actionsGenerate(const bool actions[4]);

    // �������� ������ m_numbersMas, �������� � ���� �����
    void numbersGenerate();

    void manyDivision();
};