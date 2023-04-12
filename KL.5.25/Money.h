#pragma once
#include "Pair.h"
class Money : public Pair
{
public:
	Money() { rub = 0; kop = 0; }
	~Money() { };
	void Show() override;//функция для просмотра атрибутов класса с помощью указателя
	Money(int F, int S) : Pair(F,S) { rub = F; kop = S; }
	Money(const Money& Money) { rub = Money.rub; kop = Money.kop; }//копирование
	int Get_rub() { return rub; }
	int Get_kop() { return kop; }
	void Set_rub(int R) { rub = R; }
	void Set_kop(int K) { kop = K; }
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator/(const Money&);
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
protected:
	int rub;
	int kop;
};

