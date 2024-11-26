#pragma once

#include <iostream>


class BaseMenu {
public:
    virtual void menu() = 0;

    void reset() {
        std::cout << std::endl;
        system("pause");
        system("cls");
    }
};