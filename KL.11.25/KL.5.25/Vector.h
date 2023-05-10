#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;
class Vector
{
public:
	Vector();//конструктор без параметров
	Vector(int);//конструктор копирования
public:
	~Vector();//деструктор
	void Add(Object*);//добавление элемента в вектор
	friend ostream& operator<<(ostream& out, const Vector&);//операция вывода
private:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};

