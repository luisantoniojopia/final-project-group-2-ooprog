#pragma once

#include <iostream>
using namespace std;

class BaseAccount {
public:
    virtual void create() = 0;
    virtual void view() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;

    void reset() {
        cout << endl;
        system("pause");
        system("cls");
    }


};