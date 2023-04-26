#include <iostream>
#include "Vector.h"
#include "Time.h"

int main()
{
    Vector<int> v1(5, 2); // создаем вектор размера 5, заполненный двойками
    Vector<int> v2(5, 3); // создаем вектор размера 5, заполненный тройками

    // выводим элементы векторов
    for (int i = 0; i < v1.get_size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < v2.get_size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    Vector<int> v3 = v1 * v2; // производим поэлементное умножение векторов
    // выводим элементы результата
    for (int i = 0; i < v3.get_size(); i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;
    Time t1(1, 10, 0);
    Time t2(1, 5, 15);
    Time t3 = t1 * t2;
    std::cout << t3 << std::endl; // выводим произведение временных интервалов

    return 0; 
}
