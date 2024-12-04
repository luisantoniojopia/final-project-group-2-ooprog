#include "role_menu.h"

RoleMenu::RoleMenu() {
    // Constructor definition if needed. Empty if no specific initialization is required.
}

int RoleMenu::menu() {
    bool condition = true;
    int choice;
    string enterPassword;

    // Create a VenueManager object for AdminMenu
    VenueManager vm;

    while(condition) {
        reset();  // Reset the menu or screen (inherited from BaseMenu)
        cout << "- Please enter your role: -\n\n";
        cout << "1 - User\n";
        cout << "2 - Admin\n";
        cout << "3 - Exit system\n";
        cout << ": ";
        cin >> choice;

        switch(choice) {
            case 1: {
                reset();  // Reset for User choice
                // UserAccount ua;
                // ua.registerOrLogIn(); // Uncomment and implement when needed
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
                        AdminMenu am(vm);
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