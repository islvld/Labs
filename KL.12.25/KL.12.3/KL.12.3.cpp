#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Глобальная функция для заполнения вектора
void fill_vector(vector<int>& v) {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Введите элемент: ";
        cin >> x;
        v.push_back(x);
    }
}

// Глобальная функция для вывода вектора на экран
void print_vector(const vector<int>& v) {
    cout << "Вектор: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Глобальная функция для домножения каждого элемента вектора на максимальный элемент
void multiply_by_max(vector<int>& v) {
    if (v.empty()) {
        return;
    }
    int max_elem = *max_element(v.begin(), v.end());
    for (int& x : v) {
        x *= max_elem;
    }
}

// Глобальная функция для удаления элементов вектора, которые равны максимальному элементу
void remove_max(vector<int>& v) {
    if (v.empty()) {
        return;
    }
    int max_elem = *max_element(v.begin(), v.end());
    v.erase(remove(v.begin(), v.end(), max_elem), v.end());
}

// Глобальная функция для заполнения ассоциативного контейнера
void fill_map(map<int, int>& m) {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key, value;
        cout << "Введите ключ и значение: ";
        cin >> key >> value;
        m[key] = value;
    }
}

// Глобальная функция для вывода ассоциативного контейнера на экран
void print_map(const map<int, int>& m) {
    cout << "Ассоциативный контейнер:" << endl;
    for (const auto& kv : m) {
        cout << kv.first << " -> " << kv.second << endl;
    }
}

int main() {
    setlocale(0, "");
    vector<int> v;
    fill_vector(v); // заполнить вектор
    print_vector(v); // вывод
    multiply_by_max(v); // * max
    print_vector(v);
    remove_max(v); // удалить max
    print_vector(v);

    map<int, int> m;
    fill_map(m); // заполнить контейнер
    print_map(m);

    return 0;
}
