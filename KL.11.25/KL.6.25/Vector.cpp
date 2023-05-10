#include "Vector.h"

Vector::Vector(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
//конструктор копирования
Vector::Vector(const Vector& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
//деструктор
Vector::~Vector()
{
	delete[]data;
	data = 0;
}
//операция присваивания
Vector& Vector::operator=(const Vector& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}
//операция доступа по индексу
int& Vector::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция для умножения векторов
Vector Vector::operator*(Vector& k)//*вектор
{
	Vector temp(size);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] * k.data[i];
	return temp;
}
//операция для получения длины вектора
int Vector::operator()()
{
	int len = size;
	return len;
}
//операции для ввода-выода
ostream& operator<<(ostream& out, const Vector& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Vector& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}
