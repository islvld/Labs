#pragma once
#include <iostream>
#include <string>
#include "Print.h"
using namespace std;

class Magazine : public Print {
private:
    string title;
    string author;
    int pages;
public:
    Magazine(string t, string a, int p) : title(t), author(a), pages(p) {}
    void input() override {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter number of pages: ";
        cin >> pages;
    }
    void output() const override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Number of pages: " << pages << endl;
    }
};



