#pragma once

#include <iostream>
using namespace std;

class BaseMenu {
public:
    virtual ~BaseMenu() = default;  // Virtual destructor for polymorphism

    virtual int menu() = 0;         // Pure virtual function

    void reset();                   // Declaration of the `reset` function
};