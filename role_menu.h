#pragma once

#include <iostream>
#include "admin_account.h"
#include "admin_menu.h"
#include "base_menu.h"
#include "venue_manager.h"

using namespace std;

class RoleMenu : public BaseMenu {
private:
    const string adminPassword = "yuripogi";  // Admin password

public:
    // Constructor (if needed)
    RoleMenu();

    // Function to display the menu and handle user interaction
    int menu() override;
};