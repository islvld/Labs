#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<float> mySet;

// Функция добавления элемента в заданную позицию
void addElement(float element, int position) {
    auto it = mySet.begin();
    for (int i = 0; i < position; i++) {
        it++;
    }
    mySet.insert(it, element);
}

// Функция нахождения среднего арифметического
float findAverage() {
    float sum = 0;
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        sum += *it;
    }
    return sum / mySet.size();
}

// Функция домножения каждого элемента на максимальный элемент контейнера
vector<float> multiplyElementsByMax() {
    float maxElement = *mySet.rbegin();
    vector<float> result;
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        result.push_back(*it * maxElement);
    }
    return result;
}

int main() {
    // Добавление элементов в контейнер
    mySet.insert(1.2);
    mySet.insert(2.3);
    mySet.insert(3.4);
    mySet.insert(4.5);

    // Вывод элементов контейнера до изменений
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Добавление минимального элемента в заданную позицию
    float minElement = *mySet.begin();
    addElement(minElement, 2);

    // Вывод элементов контейнера после добавления минимального элемента
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Удаление элементов, больших среднего арифметического
    float average = findAverage();
    auto it = mySet.begin();
    while (it != mySet.end()) {
        if (*it > average) {
            it = mySet.erase(it);
        }
        else {
            it++;
        }
    }

    // Вывод элементов контейнера после удаления элементов, больших среднего арифметического
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Домножение каждого элемента на максимальный элемент контейнера
    vector<float> newSet = multiplyElementsByMax();

    // Вывод элементов нового контейнера после домножения каждого элемента на максимальный элемент контейнера
    for (auto it = newSet.begin(); it != newSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
