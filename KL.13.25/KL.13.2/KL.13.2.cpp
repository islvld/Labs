#include <iostream>
#include <vector>
#include <algorithm>

struct Time {
    int hours;
    int minutes;

    Time(int h, int m) : hours(h), minutes(m) {}

    void print() const {
        std::cout << hours << ":" << minutes << std::endl;
    }
};

int main() {
    std::vector<Time> times = { Time(10, 30), Time(9, 0), Time(12, 15), Time(8, 45) };

    // Найти минимальный элемент и добавить его в конец контейнера
    auto min_time = std::min_element(times.begin(), times.end(), [](const Time& a, const Time& b) {
        return a.hours < b.hours || (a.hours == b.hours && a.minutes < b.minutes);
        });

    times.push_back(*min_time);

    // Найти элемент с заданным ключом и удалить его из контейнера
    int key_hours = 12;
    int key_minutes = 15;

    auto it = std::find_if(times.begin(), times.end(), [key_hours, key_minutes](const Time& t) {
        return t.hours == key_hours && t.minutes == key_minutes;
        });

    if (it != times.end()) {
        times.erase(it);
    }

    // К каждому элементу добавить сумму минимального и максимального элементов контейнера
    auto minmax = std::minmax_element(times.begin(), times.end(), [](const Time& a, const Time& b) {
        return a.hours < b.hours || (a.hours == b.hours && a.minutes < b.minutes);
        });

    int min_hours = minmax.first->hours;
    int min_minutes = minmax.first->minutes;
    int max_hours = minmax.second->hours;
    int max_minutes = minmax.second->minutes;

    std::for_each(times.begin(), times.end(), [min_hours, min_minutes, max_hours, max_minutes](Time& t) {
        t.hours += min_hours + max_hours;
        t.minutes += min_minutes + max_minutes;
        });

    // Выводим элементы вектора на экран
    for (const auto& t : times) {
        t.print();
    }

    return 0;
}
