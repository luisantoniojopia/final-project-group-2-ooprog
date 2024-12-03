#pragma once

#include <iostream>
#include <vector>

#include "base_account.h"
#include "base_register_and_log_in.h"
#include "user_account.h"
using namespace std;

class AdminAccount : public BaseAccount, public BaseRegisterAndLogIn {
protected:
	const string adminPassword;
	vector<AdminAccount*>  AdminAccounts; // Stores admin accounts objects
	// vector<UserAccount*> UserAccounts; // Stores user accounts objects

public:
	AdminAccount(string u, string p, string pn, string e)
		: BaseAccount(u, p, pn, e), adminPassword("yuripogi") {}

	void create() override {
		cout << "- Admin Create Account -\n\n";
		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);

		// Put loop condition here - lets the user reenter a new username:
		if (isUsernameTaken(username)) {
            cout << "Username already taken. Please choose a different one.\n\n" << endl;
        	reset();
            return;
        }

        cout << "Enter password: ";
        getline(cin, password);

		auto* newAdmin = new AdminAccount(username, password, phoneNumber, email);
		AdminAccounts.push_back(newAdmin);

		reset();
	}

	void view() override {
		cout << "- Admin View Account -\n\n";

		reset();
	}

	void update() override {
		cout << "- Admin Update Account -\n\n";

		reset();
	}

	void remove() override {
		cout << "- Admin Remove Account -\n\n";

		reset();
	}

	int logIn() override {

		cout << "- Admin Log In -\n\n";

		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);

		cout << "Enter password: ";
		getline(cin, password);

		// Check if credentials match any AdminAccount
		for (size_t i = 0; i < AdminAccounts.size(); i++) {
			if (AdminAccounts[i]->getUsername() == username && AdminAccounts[i]->getPassword() == password) {
				cout << "Login successful!\n";
				return i; // Return index of the logged-in admin
			}
		}

		cout << "Invalid username or password.\n";
		reset();
		return -1;
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
            	case 3: {
            		condition = false;
            		break;
            	}
            	default:
            		cout << "Invalid input. Please try again.\n";
			}
		}
	}

	bool isUsernameTaken(const string& username) const {
		for (const auto& account : AdminAccounts) {
			if (account->getUsername() == username) {
				return true;
			}
		}
		return false;
	}
};