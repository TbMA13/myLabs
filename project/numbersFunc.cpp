#include <numbersFunc.h>
#include <vector>
#include <thread>

namespace numbers {
    // нахождение случайного числа в диапазоне от minNumber до maxNumber
    int getRandomNumber(const int minNumber, const int maxNumber, int n) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::srand(time((NULL)) - n);
        return (rand() % (maxNumber - minNumber + 1) + minNumber);
    }

// нахождение случайного делителя для числа number
    int getRandomDivider(int number){
        std::vector<int> dividers = {};

        for (int i = 2; i < pow(abs(number), 0.5) + 1; i++){
            // поиск делителей до корня из числа + 1
            if (abs(number) % i == 0){
                dividers.push_back(i);

            }
        }
        if (dividers.empty()){
            return 0;
        }
        if (getRandomNumber(0, 1, 1)){
            return dividers[getRandomNumber(0, dividers.size() - 1, 1)];
        }
        else{

            return number / dividers[getRandomNumber(0, dividers.size() - 1, 1)];
        }
        dividers.clear();
        dividers.shrink_to_fit();
    }
}
