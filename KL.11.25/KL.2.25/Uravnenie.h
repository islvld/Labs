#include <iostream>
#include <string>
using namespace std;
class Uravnenie
{
	double A, B, C;
public:
	Uravnenie(); // конструктор без параметров
	Uravnenie(double, double, double); // конструктор с параметрами
	Uravnenie(const Uravnenie&); // консутруктор копирования
	~Uravnenie(); // деструктор
	double get_A(); // селектор
	void set_A(double); // модификатор
	double get_B();
	void set_B(double);
	double get_C();
	void set_C(double);
	void show(); // просмотр атрибутов
};