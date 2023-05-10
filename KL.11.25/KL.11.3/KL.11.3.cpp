#include <iostream>
#include <vector>
#include <algorithm>

//Метод fill() заполняет вектор элементами
//метод addMinToPosition() находит минимальный элемент в векторе и добавляет его на заданную позицию
//метод removeElementsLessThan() удаляет все элементы в векторе, которые меньше заданного значения
//метод print() выводит вектор на экран.

template <typename T>
class MyVector {
private:
    std::vector<T> data;
public:
    MyVector() {}

    void fill(int size) {
        for (int i = 0; i < size; ++i) {
            T value;
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> value;
            data.push_back(value);
        }
    }

    void addMinToPosition(int pos) {
        T minElement = *std::min_element(data.begin(), data.end());
        data.insert(data.begin() + pos, minElement);
    }

    void removeElementsLessThan(T value) {
        data.erase(std::remove_if(data.begin(), data.end(), [&](T x) { return x < value; }), data.end());
    }

    void print() {
        for (const T& x : data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyVector<int> myVector;
    myVector.fill(5);
    myVector.print();

    myVector.addMinToPosition(2);
    myVector.print();

    myVector.removeElementsLessThan(3);
    myVector.print();

    return 0;
}
