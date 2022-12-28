#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <example.h>
#include <logger.h>


int main() {
    logger::setOutputFile("output.log");
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //TODO �������� (!)���� ��������
	int minNumber = -200;
	int maxNumber = 200;
    logger::write("������ �����: " + std::to_string(minNumber)); logger::newLine();

    logger::write("������ �����: " + std::to_string(maxNumber)); logger::newLine();

	/*
    bool add;
	bool sub;
	bool multi;
	bool division;
	���� �� ���� */
    bool actions[4] = {true, true, true, true};
    logger::write("����� ��������:");
    //TODO ��������
    for (auto it : actions){
        logger::write(" " + std::to_string(static_cast<int>(it)));
    }
    logger::newLine();

	int actionsCount = 7;
    logger::write("���������� ��������: " + std::to_string(actionsCount)); logger::newLine();

	int examplesCount = 3;
    logger::write("���������� ��������: " + std::to_string(examplesCount)); logger::newLine(); logger::newLine();

    example test(actionsCount, minNumber, maxNumber, actions);
    system("pause");
    return 0;
}