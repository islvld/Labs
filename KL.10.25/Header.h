#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Time {
public:
    Time(int m, int s) : minutes(m), seconds(s) {}
    int minutes;
    int seconds;

    Time operator-(int s) {
        int newSeconds = seconds - s;
        if (newSeconds < 0) {
            minutes -= 1;
            newSeconds += 60;
        }
        return Time(minutes, newSeconds);
    }

    bool operator==(const Time& other) {
        return minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.minutes << ":" << t.seconds;
        return os;
    }
};

class TimeIntervals {
public:
    void addInterval(Time t) {
        intervals.push_back(t);
    }

    void deleteInterval(Time t) {
        for (auto it = intervals.begin(); it != intervals.end(); ) {
            if (*it == t) {
                it = intervals.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void increaseIntervals(Time t) {
        for (auto& interval : intervals) {
            if (interval == t) {
                interval = interval - 90;
            }
        }
    }

    void insertIntervals(int n, int k) {
        Time t(0, 0);
        auto it = intervals.begin();
        advance(it, n);
        intervals.insert(it, k, t);
    }

    void writeToFile(string fileName) {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }
        for (auto& interval : intervals) {
            outFile << interval.minutes << "," << interval.seconds << endl;
        }
        outFile.close();
    }

    void readFromFile(string fileName) {
        ifstream inFile(fileName);
        if (!inFile) {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }
        intervals.clear();
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            int m, s;
            char comma;
            if (iss >> m >> comma >> s) {
                intervals.push_back(Time(m, s));
            }
        }
        inFile.close();
    }

private:
    vector<Time> intervals;
};
