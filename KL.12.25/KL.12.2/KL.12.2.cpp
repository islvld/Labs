#include <iostream>
#include <map>

using namespace std;

// В этом коде функция removeByKey() принимает ассоциативный контейнер типа map<Time, int>, ключ элемента, который нужно удалить.
// Сначала функция использует метод find() контейнера, чтобы найти элемент с заданным ключом.
// Если элемент найден, функция удаляет его из контейнера, используя метод erase().

struct Time {
    int hours;
    int minutes;

    bool operator<(const Time& other) const {
        if (hours < other.hours) {
            return true;
        }
        else if (hours == other.hours && minutes < other.minutes) {
            return true;
        }
        return false;
    }
};

void removeByKey(map<Time, int>& myMap, Time key) {
    // Ищем элемент с заданным ключом
    auto it = myMap.find(key);

    // Если элемент найден
    if (it != myMap.end()) {
        // Удаляем его
        myMap.erase(it);
    }
}

int main() {
    map<Time, int> myMap = {
        { {1, 30}, 10 },
        { {2, 15}, 20 },
        { {3, 0}, 30 }
    };

    // Выводим исходное состояние контейнера
    cout << "Before remove:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first.hours << ":" << pair.first.minutes << " - " << pair.second << endl;
    }
    cout << endl;

    // Удаляем элемент с ключом {2, 15}
    removeByKey(myMap, { 2, 15 });

    // Выводим новое состояние контейнера
    cout << "After remove:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first.hours << ":" << pair.first.minutes << " - " << pair.second << endl;
    }
    cout << endl;

    return 0;
}
