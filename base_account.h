#pragma once

#include <iostream>

#include "admin_account.h"
#include "user_account.h"
#include "reservation.h"
using namespace std;

class BaseAccount {
public:
    virtual void create() = 0;
    virtual void view() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;

    vector<AdminAccount*>  AdminAccounts; // Stores admin accounts objects
    vector<UserAccount*> UserAccounts; // Stores user accounts objects
    vector<Reservation*> reservationList; // Stores reservation objects
    // venue vector
    // payment method vector
    // payment record vector

    void reset() {
        cout << endl;
        system("pause");
        system("cls");
    }
};