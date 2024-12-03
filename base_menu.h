#pragma once

#include <iostream>
using namespace std;

class BaseMenu {
public:
    virtual ~BaseMenu() = default;

    virtual int menu() = 0;

    void reset() {
        cout << endl;
        system("pause");
        system("cls");
    }
};