#include <iostream>
#include <vector>


#include <numbersFunc.h>

namespace numbers {
    //TODO �������� ������� �������� �� ������� �����

    // ���������� ���������� ����� � ��������� �� minNumber �� maxNumber
    int getRandomNumber(const int minNumber, const int maxNumber, int n) {
        if (n % 2 == 0){
            std::srand(time(NULL) + n * (n + 1000));
            return (rand() % (maxNumber - minNumber + 1) + minNumber);
        }
        else{
            std::srand(time(NULL) + n * n * (n + 1000));
            return (rand() % (maxNumber - minNumber + 1) + minNumber);
        }

    }

// ���������� ���������� �������� ��� ����� number
    int getRandomDivider(int number){
        std::vector<int> dividers;
        for (int i = 2; i < pow(abs(number), 0.5) + 1; i++){
            if (abs(number) % i == 0){
                dividers.push_back(i);
            }
        }

        if (dividers.empty()){
            if (!number){
                // ��� ����
                return 0;
            }
            if (abs(number) <= 3  && abs(number) >= 1){
                // ����� �� 1 �� 3
                return number;
            }
            else {
                std::cout << number << " - ������� �����!" << std::endl;
                return number;
            }
        }
        if (getRandomNumber(0, 1, 1)){
            if (number < 0 && getRandomNumber(0, 1, 2)){
                return -dividers[getRandomNumber(0, (int)(dividers.size() - 1), number)];
            }
            return dividers[getRandomNumber(0, (int)(dividers.size() - 1), number)];
        }
        else{
            if (number < 0 && getRandomNumber(0, 1, 3)){
                return -number / dividers[getRandomNumber(0, (int)(dividers.size() - 1), number)];
            }
            return number / dividers[getRandomNumber(0, (int)(dividers.size() - 1), number)];
        }

        //TODO ���� ��� �� ��� ��� ������?
//        dividers.clear();
//        dividers.shrink_to_fit();
    }
}
