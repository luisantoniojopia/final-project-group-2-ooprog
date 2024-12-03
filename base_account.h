#pragma once

#include <iostream>

#include "reservation.h"
using namespace std;

class BaseAccount {
private:
    string username;
    string password;
    string phoneNumber;
    string email;

public:
    // Constructor
    BaseAccount(string u, string p, string pn, string e)
        : username(u), password(p), phoneNumber(pn), email(e) {}

    // Getters
    string getUsername() { return username; }
    string getPassword() { return password; }
    string getPhoneNumber() { return phoneNumber; }
    string getEmail() { return email; }

    // Setters
    void setUsername(string u) { username = u; }
    void setPassword(string p) { password = p; }
    void setPhoneNumber(string pn) { phoneNumber = pn; }
    void setEmail(string e) { email = e; }

    // Vectors
    vector<Reservation*> reservationList; // Stores reservation objects
    // venue vector
    // payment method vector
    // payment record vector

    // Abstraction in CRUD
    virtual void create() = 0;
    virtual void view() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;

    static void reset() {
        cout << endl;
        system("pause");
        system("cls");
    }

    virtual ~BaseAccount() = default;
};