#include <iostream>
#include <vector>
#include <algorithm>
// Реализован контейнер, который хранит элементы класса Time
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    friend bool operator<(const Time& t1, const Time& t2) {
        if (t1.hours < t2.hours)
            return true;
        else if (t1.hours == t2.hours && t1.minutes < t2.minutes)
            return true;
        else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds < t2.seconds)
            return true;
        else
            return false;
    }

    friend bool operator>(const Time& t1, const Time& t2) {
        if (t1.hours > t2.hours)
            return true;
        else if (t1.hours == t2.hours && t1.minutes > t2.minutes)
            return true;
        else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds > t2.seconds)
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        out << t.hours << ":" << t.minutes << ":" << t.seconds;
        return out;
    }
};

// Функция для добавления элементов в контейнер
void addElements(vector<Time>& times) {
    times.push_back(Time(10, 20, 30));
    times.push_back(Time(8, 30, 45));
    times.push_back(Time(12, 0, 0));
    times.push_back(Time(6, 15, 0));
}

// Функция для удаления элементов из контейнера
void deleteElements(vector<Time>& times) {
    times.erase(times.begin() + 2); // Удалить элемент с индексом 2
}

// Функция для нахождения максимального и минимального времени в контейнере
void findMinMaxTime(const vector<Time>& times) {
    Time minTime = *min_element(times.begin(), times.end());
    Time maxTime = *max_element(times.begin(), times.end());

    cout << "Min Time: " << minTime << endl;
    cout << "Max Time: " << maxTime << endl;
}

int main() {
    vector<Time> times;
    addElements(times);
    deleteElements(times);
    findMinMaxTime(times);
    return 0;
}

