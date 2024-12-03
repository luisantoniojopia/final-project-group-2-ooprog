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
	static vector<AdminAccount*>  AdminAccounts; // Stores admin accounts objects
	// vector<UserAccount*> UserAccounts; // Stores user accounts objects

public:
	AdminAccount(string u, string p, string pn, string e)
		: BaseAccount(u, p, pn, e), adminPassword("yuripogi") {}

	static vector<AdminAccount*> getAdminAccounts() {
		return AdminAccounts;
	}

	void create() override {
		cout << "- Admin Create Account -\n\n";

		string tempUsername, tempPassword, tempPhoneNumber, tempEmail;

		cout << "Enter username: ";
		cin.ignore();
		getline(cin, tempUsername);

		if (isUsernameTaken(tempUsername)) {
			cout << "Username already taken. Please choose a different one.\n\n";
			reset();
			return;
		}

		cout << "Enter password: ";
		getline(cin, tempPassword);

		cout << "Enter phone number: ";
		getline(cin, tempPhoneNumber);

		cout << "Enter email: ";
		getline(cin, tempEmail);

		// Create a new AdminAccount with the entered data
		auto* newAdmin = new AdminAccount(tempUsername, tempPassword, tempPhoneNumber, tempEmail);
		AdminAccounts.push_back(newAdmin);

		cout << "Account created successfully!\n";
		reset();
	}

	void view() override {
		cout << "- Admin View Account -\n\n";
		for (const auto& admin : AdminAccounts) {
			cout << "Username: " << admin->getUsername() << endl;
			cout << "Phone Number: " << admin->getPhoneNumber() << endl;
			cout << "Email: " << admin->getEmail() << endl;
			cout << "----------------------------\n";
		}
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
            		return -1;
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

vector<AdminAccount*> AdminAccount::AdminAccounts;