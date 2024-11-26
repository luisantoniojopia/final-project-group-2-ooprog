#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;

class Reservation : public BaseAccount {
public:
    void create() override {
        cout << "- Create Reservation -\n\n";

        reset();
    }

    void view() override {
        cout << "- View Reservation -\n\n";

        reset();
    }

    void update() override {
        cout << "- Update Reservation -\n\n";

        reset();
    }

    void remove() override {
        cout << "- Remove Reservation -\n\n";

        reset();
    }
};