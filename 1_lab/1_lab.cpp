#include <iostream>
int main()
{
    setlocale(LC_ALL, "");
    float A;
    float B;
    float c;
    float PI = acos(-1);
    std::cout << "Введите сторону A:\n>>> ";
    std::cin >> A ;
    std::cout << "Введите сторону B:\n>>> ";
    std::cin >> B;
    std::cout << "Введите угол между сторонами A и B:\n>>> ";
    std::cin >> c;
    float result = 0.5 * A * B * sin(c * PI / 180);
    std::cout << result;

}