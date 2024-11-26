#pragma once

#include <iostream>

#include "base_account.h"
#include "base_register_and_log_in.h"

using namespace std;

class UserAccount : public BaseAccount, public BaseRegisterAndLogIn {
public:
    void create() override {
        cout << "- User Create Account -\n\n";

        reset();
    }

    void view() override {
        cout << "- User View Account -\n\n";

        reset();
    }

    void update() override {
        cout << "- User Update Account -\n\n";

        reset();
    }

    void remove() override {
        cout << "- User Remove Account -\n\n";

        reset();
    }

    int logIn() override {
        cout << "- Admin log In account -\n\n";

        reset();
    }

    int registerOrLogIn() override {
        bool condition = true;
        int choice;

        while(condition) {
            cout << "- Log In or Register: -\n\n";
            cout << "1 - Register\n";
            cout << "2 - Log In\n";
            cout << "3 - Return\n";
            cout << ": ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    reset();
                    create();
                    break;
                }
                case 2: {
                    reset();
                    return logIn();
                    break;
                }
                case 3:
                    condition = false;
                break;
                default:
                    cout << "Invalid input. Please try again.\n";
            }
        }
    }
};