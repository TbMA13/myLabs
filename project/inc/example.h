#pragma once

class example {
private:
    unsigned short m_actionsCount;

    int m_minNumber;
    int m_maxNumber;

    //TODO ����������� ����� ������
    int* m_numbersMas;
    int* m_actions;

    std::string m_readyExample;
public:
    example(unsigned short actionsCount, int minNumber, int maxNumber, const bool actions[4]);

    ~example();

    // �������� ������ m_actions, �������� � ���� ������ ��������
    void actionsGenerate(const bool actions[4]);

    // �������� ������ m_numberMas, �������� � ���� �����, ������� ��������� � �������
    void manyDivision();

    // �������� ������ m_numbersMas, �������� � ���� �����
    void othersNumbersGenerate();

    // ������ �������� ������� � ������ ��� ������ ������������
    void exampleBuild();

    // ������ ������� ��� ������ ������������
    std::string getExample();
};