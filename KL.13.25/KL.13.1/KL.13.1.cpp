#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    Time(int h, int m) : hours(h), minutes(m) {}
    void display() const {
        cout << hours << ":" << minutes << endl;
    }
};

bool compare_time(const Time& t1, const Time& t2) {
    return (t1.hours < t2.hours) || (t1.hours == t2.hours && t1.minutes < t2.minutes);
}

int main() {
    list<Time> times;
    times.push_back(Time(10, 30));
    times.push_back(Time(9, 45));
    times.push_back(Time(11, 15));
    times.push_back(Time(8, 0));
    times.push_back(Time(12, 0));

    // Найти минимальный элемент и добавить его в конец контейнера
    auto min_it = min_element(times.begin(), times.end(), compare_time);
    times.push_back(*min_it);

    // Найти элемент с заданным ключом и удалить его из контейнера
    auto key = Time(9, 45);
    auto key_it = find_if(times.begin(), times.end(), [&key](const Time& t) {return compare_time(t, key) == false && compare_time(key, t) == false; });
    if (key_it != times.end()) {
        times.erase(key_it);
    }

    // К каждому элементу добавить сумму минимального и максимального элементов контейнера
    auto minmax = minmax_element(times.begin(), times.end(), compare_time);
    auto sum = minmax.first->hours * 60 + minmax.first->minutes + minmax.second->hours * 60 + minmax.second->minutes;
    for_each(times.begin(), times.end(), [sum](Time& t) {t.hours = t.hours * 60 + t.minutes + sum / 60; t.minutes = (t.minutes + sum % 60) % 60; t.hours = t.hours / 60; });

    // Вывод
    cout << "Final list of times:" << endl;
    for_each(times.begin(), times.end(), [](const Time& t) {t.display(); });

    return 0;
}
