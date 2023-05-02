#pragma once
#include <iostream>
#include "Object.h"
#include <iostream>
using namespace std;

class Print 
{
public:
    virtual void input() = 0;
    virtual void output() const = 0;
};

