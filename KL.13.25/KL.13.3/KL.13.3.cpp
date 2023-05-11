#include <iostream>
#include <set>
#include <algorithm>

struct Time {
    int hours;
    int minutes;

    Time(int h, int m) : hours(h), minutes(m) {}

    void print() const {
        std::cout << hours << ":" << minutes << std::endl;
    }

    bool operator<(const Time& other) const {
        return hours < other.hours || (hours == other.hours && minutes < other.minutes);
    }
};

int main() {
    std::set<Time> times = { Time(10, 30), Time(9, 0), Time(12, 15), Time(8, 45) };

    // Найти минимальный элемент и добавить его в конец контейнера
    auto min_time = *std::min_element(times.begin(), times.end());

    times.insert(min_time);

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
    auto minmax = std::minmax_element(times.begin(), times.end());

    int min_hours = minmax.first->hours;
    int min_minutes = minmax.first->minutes;
    int max_hours = minmax.second->hours;
    int max_minutes = minmax.second->minutes;

    std::for_each(times.begin(), times.end(), [min_hours, min_minutes, max_hours, max_minutes](const Time& t) {
        const_cast<Time&>(t).hours += min_hours + max_hours;
        const_cast<Time&>(t).minutes += min_minutes + max_minutes;
        });

    // Выводим элементы множества на экран
    for (const auto& t : times) {
        t.print();
    }

    return 0;
}
