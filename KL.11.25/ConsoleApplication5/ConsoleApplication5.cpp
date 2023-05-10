#include <iostream>
#include <fstream>
using namespace std;

struct point
{
    int key;
    point* next;
};

point* make_point(int n)
{
    point* first, * p;
    first = NULL;
    for (int i = 0; i < n; i++)
    {
        p = new point();
        cout << "Введите значение: ";
        cin >> p->key;
        p->next = first;
        first = p;
    }
    return first;
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

point* get_last(point* first)
{
    while (first->next != NULL)
    {
        first = first->next;
    }

    return first;
}

point* delete_element(point* first)
{
    if (first == NULL)
    {
        cout << "Список пустой" << endl;
        return first;
    }

    
    int i = 1;
    point* p = first;
    if (p == NULL)
        cout << "Неверный номер элемента" << endl;
    else
    {
        point* temp = p;
        p->next = NULL;
        delete temp;
    }
    
    return first;
}

struct point* add_elements(point* first)
{
    point* beg_new_list = make_point(1);
    point* end_new_list = get_last(beg_new_list);

    end_new_list->next = first;
    first = beg_new_list;
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

        cout << "1.Создать список" << endl;
        cout << "2.Удалить элемент(STACK)" << endl;
        cout << "3.ТЕХРАБОТЫ" << endl;
        cout << "4.Вставка элемента" << endl;
        cout << "5.Вывод списка" << endl;
        cout << "6.Сохранение в файл" << endl;
        cout << "7.Загрузка из файла" << endl;
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
            beg = delete_element(beg);
            print(beg);
            break;
        }
        case 3:
        {
            cout << "NO WORK DOLBAN\n";
            break;
        }
        case 4:
        {
            print(beg);

            beg = add_elements(beg);
            print(beg);
            break;
        }
        case 5:
        {
            print(beg);
            break;
        }
        case 6:
        {
            char filename[200];
            cout << "Введите название файла: ";
            cin >> filename;

            save_to_file(beg, filename);
            free_list(&beg);
            print(beg);
            break;
        }
        case 7:
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
