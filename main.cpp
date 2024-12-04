// Question 1: Both AdminMenu() & registerLogIn() can access create() & logIn() but to where create() & logIn() goes back to when one of AdminMenu() & registerLogIn() accesses them? 
// possible solution: make a new class HAHA
// Question 2: Medjo complex ang vectors and how one account holds all information, we might need a master class na nagsstore ng master vector for each account

// Note 1: AdminMenu am; am.menu();
//		   UserMenu um; um.menu();
//                         - AdminMenu & UserMenu interface is finished!! Thought not yet accessible because need ba madaanan ang question 2.
//                         - Use the syntax in Note 1: sa int main if gusto mo matry yung interface.
// Note 2: We can implement setter and getters for updating items? Because vectors are for pushbacks?
// test comment

#include <iostream>
#include <string>

#include "admin_account.h"
#include "user_account.h"
#include "admin_menu.h"
#include "base_menu.h"
#include "venue_manager.h"

using namespace std;

class RoleMenu : public BaseMenu {
private:
	const string adminPassword = "yuripogi";

public:

	int menu() override {
		bool condition = true;
		int choice;
		string enterPassword;

		while(condition) {
			reset();
			cout << "- Please enter your role: -\n\n";
			cout << "1 - User\n";
	        cout << "2 - Admin\n";
	        cout << "3 - Exit system\n";
	        cout << ": ";
	        cin >> choice;

	        switch(choice) {
	        	case 1: {
	        		reset();
	        		// UserAccount ua;
		        	// ua.registerOrLogIn();
	        		break;
	        	}
	        	case 2: {
	        		cout << "\nEnter admin password: ";
	        		cin >> enterPassword;

						if (enterPassword == adminPassword) {
	            		cout << "\nAccess granted!\n";
	                    reset();
		        		AdminAccount ac;
	        			int acc = ac.registerOrLogIn();
						if (acc != -1) {
							AdminAccount* admin = AdminAccount::getAdminAccounts()[acc];
							cout << "Login successful! Welcome, " << admin->getUsername() << "!\n\n" << endl;
							reset();
							AdminMenu am;
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
};

void welcome () {
	cout << "Finals program - Jopia & Lat\n\n";
}

int main() {
	welcome();
	RoleMenu rm;
	rm.menu();
	return 0;
}
