#include <iostream>

using namespace std;

class PAIR {
    int first;
    int second;
public:
    // Конструктор
    PAIR(int a = 0, int b = 0) {
        first = a;
        second = b;
    }

    // Методы изменения полей
    void setFirst(int a) {
        first = a;
    }
    void setSecond(int b) {
        second = b;
    }

    // Операция сложения пар
    PAIR operator+(PAIR p) {
        return PAIR(first + p.first, second + p.second);
    }

    // Метод вывода пары чисел на экран
    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

class MONEY : public PAIR {
    int rubles;
    int kopeks;
public:
    // Конструктор
    MONEY(int r = 0, int k = 0) {
        rubles = r;
        kopeks = k;
    }

    // Методы изменения полей
    void setRubles(int r) {
        rubles = r;
    }
    void setKopeks(int k) {
        kopeks = k;
    }

    // Операция сложения денежных сумм
    MONEY operator+(MONEY m) {
        int sumRubles = rubles + m.rubles;
        int sumKopeks = kopeks + m.kopeks;
        if (sumKopeks >= 100) {
            sumKopeks -= 100;
            sumRubles++;
        }
        return MONEY(sumRubles, sumKopeks);
    }

    // Операция вычитания денежных сумм
    MONEY operator-(MONEY m) {
        int diffRubles = rubles - m.rubles;
        int diffKopeks = kopeks - m.kopeks;
        if (diffKopeks < 0) {
            diffKopeks += 100;
            diffRubles--;
        }
        return MONEY(diffRubles, diffKopeks);
    }

    // Операция деления денежной суммы на число
    MONEY operator/(int n) {
        int divRubles = rubles / n;
        int divKopeks = (kopeks / n) + ((rubles % n) * 100 / n);
        return MONEY(divRubles, divKopeks);
    }

    // Метод вывода денежной суммы на экран
    void display() {
        cout << rubles << " руб. " << kopeks << " коп." << endl;
    }
};

int main() {
    setlocale(0, "");
    // Тестирование класса PAIR
    PAIR p1(2, 3);
    PAIR p2(4, 5);
    PAIR p3 = p1 + p2;
    p1.display();
    p2.display();
    p3.display();

    // Тестирование класса MONEY
    MONEY m1(10, 50);
    MONEY m2(3, 70);
    MONEY m3 = m1 + m2;
    MONEY m4 = m1 - m2;
    MONEY m5 = m1 / 2;
    m1.display();
    m2.display();
    m3.display();
}
