#pragma once

#include <iostream>
#include <vector>
#include "base_account.h"
#include "base_register_and_log_in.h"
#include "user_account.h"

using namespace std;

class AdminAccount : public BaseAccount, public BaseRegisterAndLogIn {
protected:
	const string adminPassword;  // A constant password for the admin account
	static vector<AdminAccount*> AdminAccounts;  // Static vector to store admin accounts

public:
	// Constructor to initialize AdminAccount with username, password, phone number, and email
	AdminAccount(string u, string p, string pn, string e);

	// Default constructor
	AdminAccount();

	// Static function to get all admin accounts
	static vector<AdminAccount*> getAdminAccounts();

	// Override: Create a new Admin account
	void create() override;

	// Override: View existing Admin accounts
	void view() override;

	// Override: Update an Admin account
	void update() override;

	// Override: Remove an Admin account
	void remove() override;

	// Override: Log in an Admin account
	int logIn() override;

	// Override: Handle Register or Log In process for Admin
	int registerOrLogIn() override;

	// Helper function to check if a username is already taken
	bool isUsernameTaken(const string& username) const;
};