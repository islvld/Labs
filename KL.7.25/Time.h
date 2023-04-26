#pragma once
#include <iostream>

class Time {
private:
    int hours; // часы
    int minutes; // минуты
    int seconds; // секунды
public:
    Time() : hours(0), minutes(0), seconds(0) {} // конструктор по умолчанию
    Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {} // конструктор, принимающий часы, минуты и секунды
    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {} // конструктор копирования
    ~Time() {} // деструктор

    Time& operator=(const Time& other) { // оператор присваивания
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t) { // оператор вывода
        os << t.hours << ":" << t.minutes << ":" << t.seconds;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& t) { // оператор ввода
        is >> t.hours >> t.minutes >> t.seconds;
        return is;
    }

    Time operator*(const Time& other) const { // оператор умножения времени
        int total_seconds = hours * 3600 + minutes * 60 + seconds; // переводим первое время в секунды
        int other_total_seconds = other.hours * 3600 + other.minutes * 60 + other.seconds; // переводим второе время в секунды
        int result_total_seconds = total_seconds * other_total_seconds; // перемножаем секунды
        int result_hours = result_total_seconds / 3600; // переводим обратно в часы
        int result_minutes = (result_total_seconds % 3600) / 60; // переводим обратно в минуты
        int result_seconds = result_total_seconds % 60; // переводим обратно в секунды
        return Time(result_hours, result_minutes, result_seconds);
    }
};
