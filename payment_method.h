#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;


class PaymentMethod : public BaseAccount {
public:
    void create() override {
        cout << "- Create Payment Method -\n\n";

        reset();
    }

    void view() override {
        cout << "- View Payment Method -\n\n";

        reset();
    }

    void update() override {
        cout << "- Update Payment Method -\n\n";

        reset();
    }

    void remove() override {
        cout << "- Remove Payment Method -\n\n";

        reset();
    }
};