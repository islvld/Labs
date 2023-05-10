// Реализуем контейнер - список с элементами типа float

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void add_remove_list() {
    list<float> myList = { 1.5f, 2.5f, 3.5f, 4.5f, 5.5f };
    myList.push_front(0.5f); // Добавляем элемент в начало списка
    myList.push_back(6.5f); // Добавляем элемент в конец списка

    // Удаляем элемент со значением 3.5f
    myList.remove(3.5f);

    // Выводим элементы списка
    for (auto it = myList.begin(); it != myList.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Находим минимальный элемент и добавляем его на позицию 2
    auto min_it = min_element(myList.begin(), myList.end());
    myList.insert(next(myList.begin()), *min_it);

    // Находим среднее арифметическое
    float sum = 0.0f;
    for (auto it = myList.begin(); it != myList.end(); it++) {
        sum += *it;
    }
    float average = sum / myList.size();

    // Удаляем элементы, большие среднего арифметического
    for (auto it = myList.begin(); it != myList.end();) {
        if (*it > average) {
            it = myList.erase(it);
        }
        else {
            it++;
        }
    }

    // Домножаем каждый элемент на максимальный элемент
    float max_val = *max_element(myList.begin(), myList.end());
    for (auto& x : myList) {
        x *= max_val;
    }

    // Выводим измененные элементы списка
    for (auto it = myList.begin(); it != myList.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    add_remove_list();
    return 0;
}
