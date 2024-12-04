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
	AdminMenu() ;

	int menu() override {
		reset();
		bool condition = true;
		int choice;

		while(condition) {
			cout << "Welcome to the back end of this system!\n\n";
			cout << "- Choose a menu: -\n";
			cout << "1 - Manage Account Section\n";
			cout << "2 - Manage Venue Section\n";
			cout << "3 - Manage Reservation Section\n";
			cout << "4 - Manage Payment Section\n";
			cout << "5 - Manage Payment Record Section\n";
			cout << "6 - Generate Report Section\n";
			cout << "7 - Return\n";
			cout << ": ";
			cin >> choice;

			switch(choice) {
				case 1: {
					reset();
					bool MAScondition = true;
					int MASchoice;

					while(MAScondition) {
						cout << "Manage Account Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Manage Admin Account\n";
						cout << "2 - Manage User Account\n";
						cout << "3 - Return\n";
						cout << ": ";
						cin >> MASchoice;

						switch(MASchoice) {
							case 1: {
								reset();
								bool MAAcondition = true;
								int MAAchoice;

								while(MAAcondition) {
									cout << "Manage Admin Account\n\n";
									cout << "- Choose a menu: -\n";
									cout << "1 - Create Admin Account\n";
									cout << "2 - View Admin Account\n";
									cout << "3 - Update Admin Account\n";
									cout << "4 - Remove Admin Account\n";
									cout << "5 - Return\n";
									cout << ": ";
									cin >> MAAchoice;

									switch(MAAchoice) {
										case 1: {
											reset();
											AdminAccount aa("", "", "", "");
											aa.create();
											break;
										}
										case 2: {
											reset();
											AdminAccount aa("", "", "", "");
											aa.view();
											break;
										}
										case 3: {
											reset();
											AdminAccount aa("", "", "", "");
											aa.update();
											break;
										}
										case 4: {
											reset();
											AdminAccount aa("", "", "", "");
											aa.remove();
											break;
										}
										case 5: {
											MAAcondition = false;
											break;
										}
										default:
											cout << "Invalid choice. Please try again.\n";
									}
								}
								reset();
								break;
							}
							case 2: {
								reset();
								bool MUAcondition = true;
								int MUAchoice;

								while(MUAcondition) {
									cout << "Manage User Account\n\n";
									cout << "- Choose a menu: -\n";
									cout << "1 - Create User Account\n";
									cout << "2 - View User Account\n";
									cout << "3 - Update User Account\n";
									cout << "4 - Remove User Account\n";
									cout << "5 - Return\n";
									cout << ": ";
									cin >> MUAchoice;

									switch(MUAchoice) {
										case 1: {
											reset();
											// UserAccount ua;
											// ua.create();
											break;
										}
										case 2: {
											reset();
											// UserAccount ua;
											// ua.view();
											break;
										}
										case 3: {
											reset();
											// UserAccount ua;
											// ua.update();
											break;
										}
										case 4: {
											reset();
											// UserAccount ua;
											// ua.remove();
											break;
										}
										case 5: {
											MUAcondition = false;
											break;
										}
										default:
											cout << "Invalid choice. Please try again.\n";
									}
								}
								reset();
								break;
							}
							case 3: {
								MAScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
						}
					}
					reset();
					break;
				}
				case 2: {
					reset();
					bool MVScondition = true;
					int MVSchoice;
					Venue v("", "", "", "", ' ', "", "", 0, 0.0, "");

					while(MVScondition) {
						cout << "Manage Venue Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Create Venue\n";
						cout << "2 - View Venue\n";
						cout << "3 - Update Venue\n";
						cout << "4 - Remove Venue\n";
						cout << "5 - Return\n";
						cout << ": ";
						cin >> MVSchoice;

						switch(MVSchoice) {
							case 1: {
								reset();
								venueManager.addVenue();
								break;
							}
							case 2: {
								reset();
								venueManager.listVenues();
								break;
							}
							case 3: {
								reset();
								int index;
								cout << "Enter venue index to update: ";
								cin >> index;
								venueManager.updateVenue(index - 1);
								break;
							}
							case 4: {
								reset();
								int index;
								cout << "Enter venue index to remove: ";
								cin >> index;
								venueManager.removeVenue(index - 1);
								break;
							}
							case 5: {
								MVScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
							}
						}
						reset();
						break;
					}
				case 3: {
					reset();
					bool MRScondition = true;
					int MRSchoice;

					while(MRScondition) {
						cout << "Manage Reservation Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Create Reservation\n";
						cout << "2 - View Reservation\n";
						cout << "3 - Update Reservation\n";
						cout << "4 - Remove Reservation\n";
						cout << "5 - Return\n";
						cout << ": ";
						cin >> MRSchoice;

						switch(MRSchoice) {
							case 1: {
								reset();
								// Reservation r;
								// r.create();
								break;
							}
							case 2: {
								reset();
								// Reservation r;
								// r.view();
								break;
							}
							case 3: {
								reset();
								// Reservation r;
								// r.update();
								break;
							}
							case 4: {
								reset();
								// Reservation r;
								// r.remove();
								break;
							}
							case 5: {
								MRScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
							}
						}
						reset();
						break;
					}
				case 4: {
					reset();
					bool MPMScondition = true;
					int MPMSchoice;

					while(MPMScondition) {
						cout << "Manage Payment Method Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Create Payment Method\n";
						cout << "2 - View Payment Method\n";
						cout << "3 - Update Payment Method\n";
						cout << "4 - Remove Payment Method\n";
						cout << "5 - Return\n";
						cout << ": ";
						cin >> MPMSchoice;

						switch(MPMSchoice) {
							case 1: {
								reset();
								// PaymentMethod pm;
								// pm.create();
								break;
							}
							case 2: {
								reset();
								// PaymentMethod pm;
								// pm.view();
								break;
							}
							case 3: {
								reset();
								// PaymentMethod pm;
								// pm.update();
								break;
							}
							case 4: {
								reset();
								// PaymentMethod pm;
								// pm.remove();
								break;
							}
							case 5: {
								MPMScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
							}
						}
						reset();
						break;
					}
				case 5: {
					reset();
					bool MPRScondition = true;
					int MPRSchoice;

					while(MPRScondition) {
						cout << "Manage Payment Record Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Pending Payment Method\n";
						cout << "2 - Overdue Payment Method\n";
						cout << "3 - Completed Payment Method\n";
						cout << "4 - Delete Payment Method\n";
						cout << "5 - Return\n";
						cout << ": ";
						cin >> MPRSchoice;

						switch(MPRSchoice) {
							case 1: {
								reset();
								// PaymentRecord pr;
								// pr.pendingPayment();
								break;
							}
							case 2: {
								reset();
								// PaymentRecord pr;
								// pr.overduePayment();
								break;
							}
							case 3: {
								reset();
								// PaymentRecord pr;
								// pr.completedPayment();
								break;
							}
							case 4: {
								reset();
								// PaymentRecord pr;
								// pr.deletePayment();
								break;
							}
							case 5: {
								MPRScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
							}
						}
						reset();
						break;
					}
				case 6: {
					reset();
					bool MRScondition = true;
					int MRSchoice;

					while(MRScondition) {
						cout << "Manage Report Section\n\n";
						cout << "- Choose a menu: -\n";
						cout << "1 - Create Report\n";
						cout << "2 - View Report\n";
						cout << "3 - Update Report\n";
						cout << "4 - Delete Report\n";
						cout << "5 - Return\n";
						cout << ": ";
						cin >> MRSchoice;

						switch(MRSchoice) {
							case 1: {
								reset();
								// Report r;
								// r.create();
								break;
							}
							case 2: {
								reset();
								// Report r;
								// r.view();
								break;
							}
							case 3: {
								reset();
								// Report r;
								// r.update();
								break;
							}
							case 4: {
								reset();
								// Report r;
								// r.remove();
								break;
							}
							case 5: {
								MRScondition = false;
								break;
							}
							default:
								cout << "Invalid choice. Please try again.\n";
							}
						}
						reset();
						break;
					}
				case 7: {
					return -1;
				}
				default:
					cout << "Invalid choice. Please try again.\n";
			}
		}
	}
};