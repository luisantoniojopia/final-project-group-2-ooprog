#pragma once

#include <iostream>

#include "admin_account.h"
#include "admin_menu.h"
#include "base_menu.h"

using namespace std;

class RoleMenu : public BaseMenu {
private:
    const string adminPassword = "yuripogi";

public:
    int menu() override {
        bool condition = true;
        int choice;
        string enterPassword;

        while(condition) {
            reset();
            cout << "- Please enter your role: -\n\n";
            cout << "1 - User\n";
            cout << "2 - Admin\n";
            cout << "3 - Exit system\n";
            cout << ": ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    reset();
                    // UserAccount ua;
                    // ua.registerOrLogIn();
                    break;
                }
                case 2: {
                    cout << "\nEnter admin password: ";
                    cin >> enterPassword;

                    if (enterPassword == adminPassword) {
                        cout << "\nAccess granted!\n";
                        reset();
                        AdminAccount ac("", "", "", "");
                        int acc = ac.registerOrLogIn();
                        if (acc != -1) {
                            AdminAccount* admin = AdminAccount::getAdminAccounts()[acc];
                            cout << "Login successful! Welcome, " << admin->getUsername() << "!\n\n";
                            reset();
                            AdminMenu am;
                            am.menu();
                        }
                    } else {
                        cout << "Incorrect password. Access denied.\n";
                    }
                    break;
                }
                case 3: {
                    condition = false;
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};
