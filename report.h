#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;

class Report : public BaseAccount {
public:
    void view() override {
        cout << "- Generate Report -\n\n";

        reset();
        bool condition = true;
        int choice;

        while(condition) {
            cout << "1 - User Reports\n";
            cout << "2 - Venue Reports\n";
            cout << "3 - Reservation Reports\n";
            cout << "4 - Payment Reports\n";
            cout << "5 - Exit system\n";
            cout << ": ";
            cin >> choice;
            reset();

            switch(choice) {
                case 1: {
                    // vector
                    break;
                }
                case 2: {
                    // vector
                    break;
                }
                case 3: {
                    // vector
                    break;
                }
                case 4: {
                    // vector
                    break;
                }
                case 5: {
                    // return
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};