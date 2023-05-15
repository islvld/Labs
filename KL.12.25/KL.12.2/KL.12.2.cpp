#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

class Time {
public:
    Time() {}
    Time(int h, int m) : hours(h), minutes(m) {}
    int hours;
    int minutes;
};

bool operator<(const Time& t1, const Time& t2) {
    if (t1.hours < t2.hours) {
        return true;
    }
    else if (t1.hours == t2.hours && t1.minutes < t2.minutes) {
        return true;
    }
    return false;
}

void insertMinElement(map<Time, int>& m, Time minTime, Time posTime) {
    auto it = m.find(minTime);
    if (it != m.end()) {
        m.erase(it);
        m.insert(pair<Time, int>(posTime, 1));
    }
}

void removeGreaterAverage(map<Time, int>& m) {
    int totalMinutes = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        totalMinutes += (it->first.hours * 60) + it->first.minutes;
    }
    double average = (double)totalMinutes / m.size();
    auto it = m.begin();
    while (it != m.end()) {
        if (((it->first.hours * 60) + it->first.minutes) > average) {
            it = m.erase(it);
        }
        else {
            it++;
        }
    }
}

int main() {
    map<Time, int> m;
    m.insert(pair<Time, int>(Time(10, 30), 1));
    m.insert(pair<Time, int>(Time(9, 15), 2));
    m.insert(pair<Time, int>(Time(14, 0), 3));
    m.insert(pair<Time, int>(Time(11, 45), 4));
    m.insert(pair<Time, int>(Time(8, 0), 5));

    // Insert min element at position
    Time minTime = (*m.begin()).first;
    Time posTime(13, 45);
    insertMinElement(m, minTime, posTime);

    // Remove elements greater than average
    removeGreaterAverage(m);

    // Print elements
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first.hours << ":" << it->first.minutes << endl;
    }

    return 0;
}
