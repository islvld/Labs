#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    setlocale(0, "");
    string m[12] = { "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентярь", "октябрь", "ноябрь", "декабрь" };
    int k = 0;
    int count = 0;
    /*создаем объект F1, который создаст файл file.txt
     циклом for заполнеяем файл из массива m[12]] */
    ofstream F1("file.txt", ios_base::trunc);
    for (int i = 0; i < 12; i++) {
        F1 << m[i] << endl;
    }
    ofstream F2("file2.txt", ios_base::trunc);
    for (int i = 0; i < 12; i++) {
        string s;
        s = m[i];
        const int length = s.length();
        char* char_array = new char[length + 1];
        strcpy(char_array, s.c_str());
        if (s[0] != 'а')
        {
            while (k == 0) 
            {
                count = s.length();
                k++;
            }
            F2 << m[i] << endl;
        }
    }
    cout << endl;
    cout << "Символов в первом слове: " << count << endl;
    cout << "Готово!";
    return 0;
}
