#pragma once

#include <iostream>
#include <vector>

#include "base_account.h"
#include "base_register_and_log_in.h"
using namespace std;

class UserAccount : public BaseAccount, public BaseRegisterAndLogIn {
public:
	struct UserAccountsCollection {
		string username;
		string password;
	};
	
	vector<UserAccountsCollection> UserAccounts;
	
	UserAccountsCollection getUserAccount(int i) {
		return UserAccounts[i];
	}
	
    void create() override {
    	string username, password;
    	
        cout << "- User Create Account -\n\n";

		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);
		
		if(isUsernameTaken(username)) {
			cout << "Username already taken. Please choose a different one.\n\n" << endl;
			reset();
			return;
		}
		
		cout << "Enter password: ";
		getline(cin, password);
		
		UserAccounts.push_back({username, password});
		cout << "Registration successful!" << endl;
		
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
    	string username, password;
        cout << "- User log In account -\n\n";
		
		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);
		
		cout << "Enter password: ";
		getline(cin, password);
		
		for (size_t i = 0; i < UserAccounts.size(); i++) {
            if (UserAccounts[i].username == username && UserAccounts[i].password == password) {

                return i;
            }
        }
		
		cout << "Invalid username or password.\n\n" << endl;
        reset();
        return -1; // Return -1 if login fails

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
    
    bool isUsernameTaken(const string& username) const {
        for (const auto& account : UserAccounts) {
            if (account.username == username) {
                return true;
            }
        }
        return false;
    }
};