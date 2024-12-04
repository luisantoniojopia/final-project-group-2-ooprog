#pragma once

#include <iostream>
#include "base_menu.h"
#include "admin_account.h"
#include "reservation.h"
#include "venue.h"
#include "venue_manager.h"
// #include "payment_method.h"
// #include "payment_record.h"
// #include "report.h"
// #include "user_account.h"

using namespace std;

class AdminMenu : public BaseMenu {
private:
	VenueManager& venueManager;

public:
	AdminMenu(VenueManager& vm); // Constructor that takes VenueManager as reference

	int menu() override; // Override the menu function from BaseMenu

	// Additional helper functions can be added if needed.
};