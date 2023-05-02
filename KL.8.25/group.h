#pragma once
#include "Print.h"
class Group {
private:
    int capacity;
    int size;
    Print** elements;
public:
    Group(int capacity) : capacity(capacity), size(0), elements(new Print* [capacity]) {}
    ~Group() {
        for (int i = 0; i < size; i++) {
            delete elements[i];
        }
        delete[] elements;
    }
    void addElement(Print* element) {
        if (size < capacity) {
            elements[size] = element;
            size++;
        }
    }
    void removeElement(int index) {
        if (index >= 0 && index < size) {
            delete elements[index];
            for (int i = index; i < size - 1; i++) {
                elements[i] = elements[i + 1];
            }
            size--;
        }
    }
    void displayElements() const {
        for (int i = 0; i < size; i++) {
            elements[i]->output();
            cout << endl;
        }
    }
};
