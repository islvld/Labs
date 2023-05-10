#include <iostream>
#include <vector>
#include <algorithm>

// пользовательский тип MyType, который имеет единственное поле value типа int, операторы сравнения < и >, которые используются при удалении элементов вектора.
// getAverage() и removeElementsGreaterThanAverage() выполняются задачи по нахождению среднего арифметического и удалению элементов больших среднего арифметического соответственно.
//В main() создается вектор r и заполняется элементами.
//вызывается функция removeElementsGreaterThanAverage() для удаления элементов, больших среднего арифметического, и выводится измененный вектор.
// 
// определяем пользовательский тип
struct MyType {
    int value;

    MyType(int value) : value(value) {}

    bool operator<(const MyType& other) const {
        return value < other.value;
    }

    bool operator>(const MyType& other) const {
        return value > other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyType& obj) {
        os << obj.value;
        return os;
    }
};

// определяем глобальные функции для выполнения задания
double getAverage(const std::vector<MyType>& data) {
    double sum = 0;
    for (const MyType& x : data) {
        sum += x.value;
    }
    return sum / data.size();
}

void removeElementsGreaterThanAverage(std::vector<MyType>& data) {
    double average = getAverage(data);
    data.erase(std::remove_if(data.begin(), data.end(), [&](const MyType& x) { return x > average; }), data.end());
}

int main() {
    // создаем вектор и заполняем его элементами
    std::vector<MyType> myVector;
    myVector.push_back(MyType(5));
    myVector.push_back(MyType(3));
    myVector.push_back(MyType(8));
    myVector.push_back(MyType(4));
    myVector.push_back(MyType(6));

    // выводим на экран исходный вектор
    std::cout << "Original vector: ";
    for (const MyType& x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // удаляем элементы большие среднего арифметического
    removeElementsGreaterThanAverage(myVector);

    // выводим на экран измененный вектор
    std::cout << "Modified vector: ";
    for (const MyType& x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
