#pragma once
#include <iostream>
#include "Magazine.h"
#include "group.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Group group(5);
    Magazine* m1 = new Magazine("Title 1", "Author 1", 100);
    Magazine* m2 = new Magazine("Title 2", "Author 2", 200);
    Magazine* m3 = new Magazine("Title 3", "Author 3", 300);
    group.addElement(m1);
    group.addElement(m2);
    group.addElement(m3);
    group.displayElements();
    group.removeElement(1);
    group.displayElements();
    return 0;
}