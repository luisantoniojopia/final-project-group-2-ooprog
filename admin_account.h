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
	// vector<Venue> adminVenues;
	// vector<UserAccount*> UserAccounts; // Stores user accounts objects

public:
	AdminAccount(string u, string p, string pn, string e)
		: BaseAccount(u, p, pn, e), adminPassword("yuripogi") {}

	AdminAccount();

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
		// do this in table format

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

    string usernameToUpdate;
    cout << "Enter the username of the account you want to update: ";
    cin.ignore();
    getline(cin, usernameToUpdate);

    // Search for the account
    AdminAccount* accountToUpdate = nullptr;
    for (auto& account : AdminAccounts) {
        if (account->getUsername() == usernameToUpdate) {
            accountToUpdate = account;
            break;
        }
    }

    if (!accountToUpdate) {
        cout << "Account not found.\n";
        reset();
        return;
    }

    int choice;
		bool condition = true;
    while (condition) {
        cout << "What would you like to update?\n";
        cout << "1 - Username\n";
        cout << "2 - Password\n";
        cout << "3 - Phone Number\n";
        cout << "4 - Email\n";
        cout << "5 - Return\n";
        cout << ": ";
        cin >> choice;

        cin.ignore(); // To handle the newline character left by `cin`

        switch (choice) {
            case 1: {
                string newUsername;
                cout << "Enter new username: ";
                getline(cin, newUsername);

                // Check if the new username is already taken
                if (isUsernameTaken(newUsername)) {
                    cout << "Username already taken. Please choose a different one.\n";
                } else {
                    accountToUpdate->setUsername(newUsername);
                    cout << "Username updated successfully!\n";
                }
                break;
            }
            case 2: {
                string newPassword;
                cout << "Enter new password: ";
                getline(cin, newPassword);
                accountToUpdate->setPassword(newPassword);
                cout << "Password updated successfully!\n";
                break;
            }
            case 3: {
                string newPhoneNumber;
                cout << "Enter new phone number: ";
                getline(cin, newPhoneNumber);
                accountToUpdate->setPhoneNumber(newPhoneNumber);
                cout << "Phone number updated successfully!\n";
                break;
            }
            case 4: {
                string newEmail;
                cout << "Enter new email: ";
                getline(cin, newEmail);
                accountToUpdate->setEmail(newEmail);
                cout << "Email updated successfully!\n";
                break;
            }
            case 5: {
                cout << "Returning to main menu...\n";
                reset();
                return;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

	void remove() override {
		cout << "- Admin Remove Account -\n\n";

		string usernameToRemove;
		cout << "Enter the username of the account to remove: ";
		cin.ignore();
		getline(cin, usernameToRemove);

		// Loop through AdminAccounts vector
		for (auto it = AdminAccounts.begin(); it != AdminAccounts.end();) {
			if ((*it)->getUsername() == usernameToRemove) {
				char confirmation;
				cout << "Are you sure you want to delete the account \"" << usernameToRemove << "\"? (y/n): ";
				cin >> confirmation;

				if (confirmation == 'y' || confirmation == 'Y') {
					delete *it; // Free memory
					AdminAccounts.erase(it); // Remove the pointer from the vector
					cout << "Account \"" << usernameToRemove << "\" has been removed successfully.\n";
				} else {
					cout << "Account deletion canceled.\n";
				}
				reset();
				return; // Exit the method after processing
			} else {
				++it; // Increment only if not erased
			}
		}

		// If no account matches the username
		cout << "Account \"" << usernameToRemove << "\" not found.\n";
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