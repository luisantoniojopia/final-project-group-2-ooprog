#include "base_account.h"
#include <iostream>
using namespace std;

// Default constructor
BaseAccount::BaseAccount() {
    username = "";
    password = "";
    phoneNumber = "";
    email = "";
}

BaseAccount::BaseAccount(const string &string, const std::string &basic_string, const std::string &pn,
    const std::string &string1) {
}

// Getter and Setter for username
string BaseAccount::getUsername() {
    return username;
}

void BaseAccount::setUsername(string u) {
    username = u;
}

// Getter and Setter for password
string BaseAccount::getPassword() {
    return password;
}

void BaseAccount::setPassword(string p) {
    password = p;
}

// Getter and Setter for phoneNumber
string BaseAccount::getPhoneNumber() {
    return phoneNumber;
}

void BaseAccount::setPhoneNumber(string pn) {
    phoneNumber = pn;
}

// Getter and Setter for email
string BaseAccount::getEmail() {
    return email;
}

void BaseAccount::setEmail(string e) {
    email = e;
}

// Static reset function
void BaseAccount::reset() {
    cout << endl;
    system("pause");
    system("cls");
}

// Destructor (default one is sufficient for this example, but it's defined here for clarity)
BaseAccount::~BaseAccount() {
    // Custom cleanup if necessary
}
