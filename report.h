#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;

class Report : public BaseAccount {
public:
    void create() override {
        cout << "- Create Report -\n\n";

        reset();
    }

    void view() override {
        cout << "- View Report -\n\n";

        reset();
    }

    void update() override {
        cout << "- Update Report -\n\n";

        reset();
    }

    void remove() override {
        cout << "- Remove Report -\n\n";

        reset();
    }
};