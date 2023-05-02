#include <iostream>
#include <cstdlib>
#include "vector.h"

int main() {
    try {
        Vector v(5);
        for (int i = 0; i < v.size(); i++) {
            v[i] = rand() % 10;
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        int product = v * v;
        std::cout << "Product: " << product << std::endl;

        Vector v2 = v + 2;
        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << " ";
        }
        std::cout << std::endl;

        Vector v3(4);
        for (int i = 0; i < v3.size(); i++) {
            v3[i] = rand() % 10;
            std::cout << v3[i] << " ";
        }
        std::cout << std::endl;

        int product2 = v * v3;
        std::cout << "Product2: " << product2 << std::endl;

        Vector v4 = v + 6;
        for (int i = 0; i < v4.size(); i++) {
            std::cout << v4[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const error& e) {
        std::cerr << "Error: " << e.message() << std::endl;
    }

    return 0;
}

