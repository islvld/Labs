﻿#include <iostream>
#include <string>
#include <vector>

class PRINT {
public:
    std::string name;
    std::string author;
public:
    virtual void input() = 0;
    virtual void output() = 0;

};

class GROUP {
private:
    std::vector<PRINT*> group;
public:
    void add(PRINT* p) {
        group.push_back(p);
    }
    void remove(int index) {
        group.erase(group.begin() + index);
    }
    void print_all() {
        for (int i = 0; i < group.size(); i++) {
            std::cout << "Element #" << i + 1 << std::endl;
            group[i]->output();
            std::cout << std::endl;
        }
    }
    void print_names() {
        for (int i = 0; i < group.size(); i++) {
            std::cout << group[i]->name << std::endl;
        }
    }
};


class MAGAZIN : public PRINT {
private:
    int pages;
    GROUP group;
public:
    void input() override {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter author: ";
        std::cin >> author;
        std::cout << "Enter number of pages: ";
        std::cin >> pages;
    }
    void output() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Number of pages: " << pages << std::endl;
    }
    void add(PRINT* p) {
        group.add(p);
    }
    void remove(int index) {
        group.remove(index);
    }
    void print_all() {
        group.print_all();
    }
    void print_names() {
        group.print_names();
    }
};

class GroupDialog : public MAGAZIN {
public:
    GroupDialog() {}
    ~GroupDialog() {}

    void OnAddEvent() {
        PRINT* p = new MAGAZIN();
        p->input();
        add(p);
    }

    void OnRemoveEvent(int index) {
        remove(index);
    }

    void OnPrintAllEvent() {
        print_all();
    }

    void OnPrintNamesEvent() {
        print_names();
    }
};

int main() {
    GroupDialog* group_dialog = new GroupDialog();
    char command = ' ';
    int n = 0;
    while (command != 'q') {
        std::cout << "Enter command: ";
        std::cin >> command;
        switch (command) {
        case 'm':
            std::cout << "Enter group size: ";
            std::cin >> n;
            for (int i = 0; i < n; i++) {
                PRINT* p = new MAGAZIN();
                p->input();
                group_dialog->add(p);
            }
            break;
        case '+':
            group_dialog->OnAddEvent();
            break;
        case '-':
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            group_dialog->OnRemoveEvent(index - 1);
            break;
        case 's':
            group_dialog->OnPrintAllEvent();
            break;
        case 'z':
            group_dialog->OnPrintNamesEvent();
            break;
        case 'q':
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid command!" << std::endl;
            break;
        }
    }
    return 0;
}
