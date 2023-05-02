#include <iostream>
#include <fstream>
#include <vector>

//Этот код сначала сохраняет и загружает временные интервалы из бинарного файла с помощью функций `save_times()` и `load_times()`. 
//Затем выполняются операции, описанные в задании : удаление записей, увеличение всех записей с определенным значением и добавление новых записей в определенную позицию.
//Функции `remove_greater_times()`, `add_time()` и `insert_times()` реализуют соответствующие операции.
// Код также выводит состояние временных интервалов после каждой операции.
//В конце измененные временные интервалы сохраняются в бинарном файле `times_modified.bin`

class Time {
public:
    int minutes;
    int seconds;

    Time(int minutes = 0, int seconds = 0) : minutes(minutes), seconds(seconds) {}

    void print() const {
        std::cout << minutes << ":" << seconds;
    }

    void subtract_seconds(int s) {
        int total_seconds = minutes * 60 + seconds;
        total_seconds -= s;
        if (total_seconds < 0) {
            total_seconds = 0;
        }
        minutes = total_seconds / 60;
        seconds = total_seconds % 60;
    }

    bool operator==(const Time& other) const {
        return minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.minutes << ":" << time.seconds;
    return os;
}

std::istream& operator>>(std::istream& is, Time& time) {
    char colon;
    is >> time.minutes >> colon >> time.seconds;
    return is;
}

void save_times(const std::vector<Time>& times, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);
    if (!outfile) {
        std::cerr << "Error: could not open file " << filename << " for writing" << std::endl;
        return;
    }
    for (const auto& time : times) {
        outfile.write(reinterpret_cast<const char*>(&time), sizeof(time));
    }
    outfile.close();
}

std::vector<Time> load_times(const std::string& filename) {
    std::ifstream infile(filename, std::ios::in | std::ios::binary);
    if (!infile) {
        std::cerr << "Error: could not open file " << filename << " for reading" << std::endl;
        return std::vector<Time>();
    }
    std::vector<Time> times;
    Time time;
    while (infile.read(reinterpret_cast<char*>(&time), sizeof(time))) {
        times.push_back(time);
    }
    infile.close();
    return times;
}

void remove_greater_times(std::vector<Time>& times, const Time& threshold) {
    auto new_end = std::remove_if(times.begin(), times.end(), [&](const Time& time) {
        return time.minutes > threshold.minutes || (time.minutes == threshold.minutes && time.seconds > threshold.seconds);
        });
    times.erase(new_end, times.end());
}

void add_time(std::vector<Time>& times, const Time& value) {
    for (auto& time : times) {
        if (time == value) {
            time.minutes += 1;
            time.seconds += 30;
            if (time.seconds >= 60) {
                time.minutes += 1;
                time.seconds -= 60;
            }
        }
    }
}

void insert_times(std::vector<Time>& times, const std::vector<Time>& new_times, int position) {
    auto it = times.begin() + position;
    times.insert(it, new_times.begin(), new_times.end());
}

int main()
{
    std::vector<Time> times = { Time(1, 0), Time(2, 30), Time(3, 15), Time(4, 0) };
    save_times(times, "times.bin");

    times = load_times("times.bin");

    if (times.empty()) {
        return 1;
    }

    std::cout << "Original times: ";
    for (const auto& time : times) {
        time.print();
        std::cout << " ";
    }
    std::cout << std::endl;

    // Remove times greater than 3:00
    Time threshold(3, 0);
    remove_greater_times(times, threshold);
    std::cout << "Times after removing those greater than " << threshold << ": ";
    for (const auto& time : times) {
        time.print();
        std::cout << " ";
    }
    std::cout << std::endl;

    // Add 1:30 to all times with value 2:30
    Time value_to_add(2, 30);
    add_time(times, value_to_add);
    std::cout << "Times after adding " << value_to_add << " to all with that value: ";
    for (const auto& time : times) {
        time.print();
        std::cout << " ";
    }
    std::cout << std::endl;

    // Insert 2 new times after the second time
    std::vector<Time> new_times = { Time(5, 0), Time(6, 0) };
    insert_times(times, new_times, 1);
    std::cout << "Times after inserting new ones: ";
    for (const auto& time : times) {
        time.print();
        std::cout << " ";
    }
    std::cout << std::endl;

    save_times(times, "times_modified.bin");
    return 0;
}