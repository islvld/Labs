#include <iostream>
#include <list>
#include <string>

using namespace std;

//H(k)=k mod M пусть M- это 64
// Результат функции будет использоваться в качестве индекса хеш-таблицы.
// Поэтому size_t (беззнаковый тип!)

size_t HashFuction(const string& fio, size_t M)
{
    size_t sum = 0;
    for (int i = 0; i < fio.length(); i++)
    {
        sum += (unsigned int)fio[i];
    }
    sum = sum % M;
    return sum;
}

struct Person // Структура для записи информации о студенте (фио, группа, рейтинг)
{
    string fio;
    string numP;
    string adress;
};
struct HashTable // Структура для хранения хеш-код и список с информацией о людях типа Person
{
    list<Person> information;
};  

Person make_person(Person* persons, int n)
{
    string fioStr;
    int a = 0;

    // Для заполнения информацию о студентах рандомно
    string surname[10] = { "Иванов", "Сидоров", "Петров", "Петухов", "Байбурин", "Андреев", "Кузнецов", "Богатырев", "Печкин", "Саночкин" };
    string name[10] = { "Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Андрей", "Иосиф" };
    string patronymics[10] = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович" };
    int numP[11] = { 0,1,2,3,4,5,6,7,8,9,10 };

    //Заполнение массива persons
    for (int i = 0; i < n; i++)
    {
        fioStr.clear();
        a = rand() % 10;
        fioStr += surname[a] + ' ';
        a = rand() % 10;
        fioStr += name[a] + ' ';
        a = rand() % 10;
        fioStr += patronymics[a];

        persons[i].fio = fioStr;

        //rand() % 10;  // ??
        persons[i].numP = numP[rand() % 10 - 1];

        persons[i].adress = rand() % 100;
    }
    return *persons;
}

int main()
{
    setlocale(0, "");
    Person person1;
    list<Person>::iterator j;
    int n, size_ht = 0;
    cout << "Введите число записей : ";
    cin >> n;

    Person* persons = new Person[n]; // Массив для хранения информации о студентах

    make_person(persons, n);

    for(int i = 0; i < n; i++)
    {
        cout << persons[i].fio << " " << persons[i].numP << " " << persons[i].adress << endl;
    }

    //строим хеш таблицу из записей
    cout << "Введите размер таблицы";
    cin >> size_ht;
    HashTable* table = new HashTable[size_ht];//массив с записями кодов хеш-таблицы
    int cod = 0;
    for (int i = 0; i < n; i++)
    {
        cod = HashFuction(persons[i].fio, size_ht);

        table[cod].information.push_back(persons[i]);
    }
    for (int i = 0; i < size_ht; i++)
    {
        cout << "Хеш-код " << i << ", размер списка " << table[i].information.size() << ":\n";
        for (j = table[i].information.begin(); j != table[i].information.end(); ++j)
        {
            cout << '\t' << j->fio << " " << j->numP << " " << j->adress << endl;
        }
    }

    delete[] table;
    delete[] persons;

    system("pause");
}