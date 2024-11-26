#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;

class Venue : public BaseAccount {
public:
    void create() override {
        cout << "- Create Venue -\n\n";

        reset();
    }

    void view() override {
        cout << "- View Venue -\n\n";

        reset();
    }

    void update() override {
        cout << "- Update Venue -\n\n";

        reset();
    }

    void remove() override {
        cout << "- Remove Venue -\n\n";

        reset();
    }
};