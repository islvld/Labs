// Вариант        Данные	     Ключ(string)	Хэш - функция	 Метод рехеширования
//    5    ФИО, №паспорта, адрес     ФИО        H(k)=k mod M        Метод цепочек

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string rfio[100] = { "БатинВладиславВладимирирович", "ПетровКонстантинДмитриевич", "ЗубовАлександрАнатольевич", "КудымовАнтонАлександрович", "БредневМаксимПавлович"};

int collisions_cnt = 0;
int HASH_MAX = 100;

int rndmNumP()
{
	return rand() % 900001 + 100000;
}

// Структура элемента хэш-таблицы
struct Person
{
	Person()
	{
		fio  = "NULL";
		numP = NULL;
		adress = "NULL";
		prev = next = NULL;
	}
	string fio;
	int numP;
	string adress;
	Person* next, * prev;
};

// Структура хэш-таблицы
struct hash_table
{
	Person* array;
	hash_table(int size)
	{
		array = new Person[size];
	}
	~hash_table()
	{
		delete[] array;
	}
	void add(Person temp, const int size);
	void pop(string fio, const int size);
	void find_index(string fio, const int size);
};

// Хэш-функция
unsigned int hash_function(string str)
{
	int sum = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		sum += str[i];
	}
	return sum % HASH_MAX;
}

// Поиск элемента по индексу
void hash_table::find_index(string fio, const int size)
{
	int hash = hash_function(fio);
	int index = hash;
	while (array[index].fio != fio && index < size)
	{
		index++;
	}
	if (index >= size)
	{
		index = 0;
		while (array[index].fio != fio && index < hash)
		{
			index++;
		}
		if (index >= hash)
		{
			cout << "\nДанного человека нет\n";
		}
		else
		{
			cout << "\nДанный человек содержится по индексу " << index;
		}
	}
}
void hash_table::add(Person temp, const int size)
{
	int hash = hash_function(temp.fio);
	int index = hash;
	if (array[index].fio == "NULL")
	{
		array[index] = temp;
		return;
	}
	else
	{
		return;
	}
}
void hash_table::pop(string fio, const int size)
{
	int index = hash_function(fio);
	if (array[index].fio == fio)
	{
		array[index] = Person();
	}
	else
	{
		while (index < size)
		{
			if (array[index].fio == fio)
			{
				array[index] = Person();
			}
			index++;
		}
		if (index >= size)
		{
			index = 0;
			while (index < size)
			{
				if (array[index].fio == fio)
				{
					array[index] = Person();
				}
				index++;
			}
		}
	}
}

// Вывод информации о конкретном объекте
void show_person(const Person Temp) 
{
	cout << "\nФИО : " << Temp.fio;
	cout << "\nНомер паспорта : " << Temp.numP;
	cout << "\nАдрес : " << Temp.adress;
	cout << endl;
}

// Вывод массива, переданного в функцию
void print_person(const Person* const array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Номер " << i + 1 << " : ";
		show_person(array[i]);
	}
}

// Заполнение элемента
Person fill_person()
{
	Person one;
	one.fio = rfio[rand() % 5];
	one.numP = rndmNumP();
	one.adress = "г.Пермь, ул. Мира 152а, кв. 6";
	return one;
}

int main()
{
	system("chcp 1251 >> null");
	setlocale(0, "");
	srand(time(NULL));

	Person array[100];

	for (int i = 0; i++; i < 100)
	{
		array[i] = fill_person();
	}

	for (int i = 0; i++; i < 5)
	{
		show_person(array[i]);
		cout << "___________________________________________" << endl;
	}
}
