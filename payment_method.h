#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "base_account.h"
using namespace std;

class PaymentMethod : public BaseAccount {
private:
    vector<string> paymentCodes;           // Stores payment method codes
    vector<string> paymentNames;           // Stores payment method names
    vector<bool> paymentStatuses;          // Stores availability (true = available, false = unavailable)
public:
    PaymentMethod() {
        // Initialize with predefined methods
        paymentCodes = {"CA", "CD", "BT"};
        paymentNames = {"Cash", "Credit/Debit Card", "Bank Transfer"};
        paymentStatuses = {true, true, true};
    }

    void displayMethods(bool showStatus = false) const {
        cout << "Current Payment Methods:\n";
        for (size_t i = 0; i < paymentCodes.size(); ++i) {
            cout << "  " << paymentCodes[i] << " - " << paymentNames[i];
            if (showStatus) {
                cout << " (" << (paymentStatuses[i] ? "Available" : "Unavailable") << ")";
            }
            cout << endl;
        }
    }

    int findMethodIndex(const string& code) const {
        // Manual search for the payment method code
        for (size_t i = 0; i < paymentCodes.size(); ++i) {
            if (paymentCodes[i] == code) {
                return i;
            }
        }
        return -1; // Not found
    }

    // Create a new payment method
    void create() override {
        cout << "- Create Payment Method -\n\n";
        displayMethods();
        cout << "\nAdd a New Mode of Payment [Y/N]: ";
        char choice;
        cin >> choice;
        if (toupper(choice) == 'Y') {
            string code, method;
            cout << "Enter Code (e.g., PA for PayPal): ";
            cin >> code;
            cout << "Enter Payment Method Name: ";
            cin.ignore();
            getline(cin, method);

            // Add the new method to the vectors
            paymentCodes.push_back(code);
            paymentNames.push_back(method);
            paymentStatuses.push_back(true);
            cout << "Payment method added successfully!\n\n";
        }
    }

    // View all payment methods
    void view() override {
        cout << "- View Payment Method -\n\n";
        displayMethods();
        cout << endl;
    }

    // Update an existing payment method
    void update() {
        cout << "- Update Payment Method -\n\n";
        displayMethods(true);
        cout << "\nWhat to update:\n"
             << "1. Payment Method Status\n"
             << "Choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string code, status;
            cout << "Enter Payment Method Code: ";
            cin >> code;
            int index = findMethodIndex(code);
            if (index != -1) {
                cout << "Status (A - Available, U - Unavailable): ";
                cin >> status;
                if (toupper(status[0]) == 'A') {
                    paymentStatuses[index] = true;
                    cout << "Payment method set to Available.\n";
                } else if (toupper(status[0]) == 'U') {
                    paymentStatuses[index] = false;
                    cout << "Payment method set to Unavailable.\n";
                } else {
                    cout << "Invalid status. No changes made.\n";
                }
            } else {
                cout << "Payment method code not found.\n";
            }
        }
    }

    // Delete a payment method
    void remove() override {
        cout << "- Remove Payment Method -\n\n";
        displayMethods();
        cout << "\nEnter the Payment Method Code to delete: ";
        string code;
        cin >> code;
        int index = findMethodIndex(code);
        if (index != -1) {
            // Manual removal by shifting elements
            for (size_t i = index; i < paymentCodes.size() - 1; ++i) {
                paymentCodes[i] = paymentCodes[i + 1];
                paymentNames[i] = paymentNames[i + 1];
                paymentStatuses[i] = paymentStatuses[i + 1];
            }
            paymentCodes.pop_back();
            paymentNames.pop_back();
            paymentStatuses.pop_back();
            cout << "Payment method deleted successfully.\n\n";
        } else {
            cout << "Payment method code not found.\n";
        }
    }
};