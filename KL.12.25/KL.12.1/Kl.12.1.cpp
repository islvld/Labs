#include <iostream>
#include <set>

using namespace std;

// В этом коде функция insertAt() принимает ассоциативный контейнер типа set<int>, ключ элемента,
//который нужно добавить, и позицию, на которую нужно добавить элемент.

void insertAt(set<int>& mySet, int key, int pos) {
    // Ищем элемент с заданным ключом
    auto it = mySet.find(key);

    // Если элемент найден
    if (it != mySet.end()) {
        // Удаляем его из исходной позиции
        mySet.erase(it);

        // Вставляем его на заданную позицию
        auto newIt = mySet.begin();
        std::advance(newIt, pos);
        mySet.insert(newIt, key);
    }
}

int main() {
    set<int> mySet = { 1, 2, 3, 4, 5 };

    // Выводим исходное состояние контейнера
    cout << "Before insert:" << endl;
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Добавляем элемент с ключом 3 на позицию 2
    insertAt(mySet, 3, 2);

    // Выводим новое состояние контейнера
    cout << "After insert:" << endl;
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
