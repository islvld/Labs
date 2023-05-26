#include <iostream>
using namespace std;
class PAIR {
    int first;
    int second;
public:
    // �����������
    PAIR(int a = 0, int b = 0) {
        first = a;
        second = b;
    }

    // ������ ��������� �����
    void setFirst(int a) {
        first = a;
    }
    void setSecond(int b) {
        second = b;
    }

    // �������� �������� ���
    PAIR operator+(PAIR p) {
        return PAIR(first + p.first, second + p.second);
    }

    // ����� ������ ���� ����� �� �����
    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};
class MONEY : public PAIR {
    int rubles;
    int kopeks;
public:
    // �����������
    MONEY(int r = 0, int k = 0) {
        rubles = r;
        kopeks = k;
    }

    // ������ ��������� �����
    void setRubles(int r) {
        rubles = r;
    }
    void setKopeks(int k) {
        kopeks = k;
    }

    // �������� �������� �������� ����
    MONEY operator+(MONEY m) {
        int sumRubles = rubles + m.rubles;
        int sumKopeks = kopeks + m.kopeks;
        if (sumKopeks >= 100) {
            sumKopeks -= 100;
            sumRubles++;
        }
        return MONEY(sumRubles, sumKopeks);
    }

    // �������� ��������� �������� ����
    MONEY operator-(MONEY m) {
        int diffRubles = rubles - m.rubles;
        int diffKopeks = kopeks - m.kopeks;
        if (diffKopeks < 0) {
            diffKopeks += 100;
            diffRubles--;
        }
        return MONEY(diffRubles, diffKopeks);
    }

    // �������� ������� �������� ����� �� �����
    MONEY operator/(int n) {
        int divRubles = rubles / n;
        int divKopeks = (kopeks / n) + ((rubles % n) * 100 / n);
        return MONEY(divRubles, divKopeks);
    }

    // ����� ������ �������� ����� �� �����
    void display() {
        cout << rubles << " ���. " << kopeks << " ���." << endl;
    }
};