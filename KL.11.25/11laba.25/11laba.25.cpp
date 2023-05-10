#include <iostream>
#include <fstream>
#include <list>
using namespace std;

struct point
{
    int key;
    point* next;
    point* prev;
};

point* make_point(int n) // Создание списка
{
    point* first, * last, *p;
    first = last = NULL;
    for (int i = 0; i < n; i++)
    {
        p = new point();
        cout << "Введите значение: ";
        cin >> p->key;
        p->prev = last; // Заполнение в обратном порядке
        last = p;
        /*p = new point();
        cout << "Введите значение: ";
        cin >> p->key;
        p->next = first;
        first = p;*/ 
    }
    return last;
}

void print(point* first)
{
    if (first == NULL)
        cout << "Список пустой" << endl;
    else
    {
        point* p = first;
        while (p != NULL)
        {
            cout << p->key << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void printbeh(point* first)
{
    point* last;
    while (first->next != NULL)
    {
        first = first->next;
    }
    last = first;
    if (last == NULL)
        cout << "Список пустой" << endl;
    else
    {
        point* p = last;
        while (p != NULL)
        {
            cout << p->key << " ";
            p = p->prev;
        }
        cout << endl;
    }
}

point* get_last(point* first)
{
    while (first->next != NULL)
    {
        first = first->next;
    }

    return first;
}

point* delete_element(point* first, int number)
{
    if (first == NULL)
    {
        cout << "Список пустой" << endl;
        return first;
    }

    if (number < 1)
    {
        cout << "Неверный номер элемента" << endl;
        return first;
    }

    if (number == 1)
    {
        point* temp = first;
        first = first->next;
        delete temp;
    }
    else
    {
        int i = 1;
        point* p = first;

        while (p != NULL && i < number - 1)
        {
            i++;
            p = p->next;
        }

        if (p == NULL)
            cout << "Неверный номер элемента" << endl;
        else
        {
            point* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

    return first;
}

point* add_elements(point* first, int number, int k)
{
    if (first == NULL)
    {
        return first;
    }
    if (number < 1)
    {
        cout << "Неверный номер элемента" << endl;
        return first;
    }

    if (number == 1)
    {
        point* beg_new_list = make_point(k);
        point* end_new_list = get_last(beg_new_list);

        end_new_list->next = first;
        first = beg_new_list;
    }
    else
    {
        int i = 1;
        point* p = first;

        while (p != NULL && i < number - 1)
        {
            i++;
            p = p->next;
        }

        if (p == NULL)
            cout << "Неверный номер элемента" << endl;
        else
        {
            point* beg_new_list = make_point(k);
            point* end_new_list = get_last(beg_new_list);

            end_new_list->next = p->next;
            p->next = beg_new_list;
        }
    }

    return first;
}

void free_list(point** first)
{
    point* p = *first, * t;
    while (p != NULL)
    {
        t = p->next;
        delete p;
        p = t;
    }

    *first = NULL;
}

void save_to_file(point* first, const char* filename)
{
    if (first == NULL)
    {
        cout << "Сохранено в файл." << endl;
        return;
    }

    ofstream file(filename);
    point* p = first;

    while (p != NULL)
    {
        file << p->key;
        if (p->next != NULL)
            file << " ";
        p = p->next;
    }

    file.close();
}

point* read_file(const char* filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
        return NULL;
    }

    point* beg = NULL, * p, * pred = NULL;

    int num;
    while (!file.eof())
    {
        file >> num;

        p = new point();
        p->key = num;
        p->next = NULL;

        if (beg == NULL)
            beg = p;
        else
            pred->next = p;

        pred = p;
    }

    file.close();

    return beg;
}

int main()
{
    setlocale(LC_ALL, "rus");

    point* beg = NULL;

    int oper;

    do
    {
        system("cls");

        cout << "1.Создать список, заполняя его с конца" << endl;
        cout << "2.Удалить элемент с заданным номером" << endl;
        cout << "3.Вставка элементов" << endl;
        cout << "4.Вывод списка" << endl;
        cout << "5.Сохранение в файл" << endl;
        cout << "6.Загрузка из файла" << endl;
        cout << "0.Выход" << endl;

        cin >> oper;

        switch (oper)
        {
        case 1:
        {
            int n;
            cout << "Кол-во эл-тов списка = ";
            cin >> n;
            beg = make_point(n);
            print(beg);
            break;
        }
        case 2:
        {
            print(beg);

            int number;
            cout << "Введите номер: ";
            cin >> number;

            beg = delete_element(beg, number);
            print(beg);
            break;
        }
        case 3:
        {
            print(beg);

            int number;
            cout << "Введите номер: ";
            cin >> number;

            int k;
            cout << "Сколько элементов добавить: ";
            cin >> k;

            beg = add_elements(beg, number, k);
            print(beg);
            break;
        }
        case 4:
        {
            printbeh(beg);
            break;
        }
        case 5:
        {
            char filename[200];
            cout << "Введите название файла: ";
            cin >> filename;

            save_to_file(beg, filename);
            free_list(&beg);
            print(beg);
            break;
        }
        case 6:
        {
            char filename[200];
            cout << "Введите название файла: ";
            cin >> filename;

            beg = read_file(filename);
            print(beg);
            break;
        }

        default:
            break;
        }

        if (oper != 0)
            system("pause");

    } while (oper != 0);

    free_list(&beg);
}
