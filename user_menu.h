// #pragma once
//
// #include <iostream>
// #include "base_menu.h"
// #include "payment_method.h"
// #include "payment_record.h"
// #include "report.h"
// #include "reservation.h"
// #include "user_account.h"
// #include "venue.h"
// using namespace std;
//
// class UserMenu : public BaseMenu {
// public:
//     int menu() override {
//         reset();
//         bool condition = true;
//         int choice;
//
//         while(condition) {
//             cout << "Welcome to the Venue Reservation Management System!\n\n";
//             cout << "- Choose a menu: -\n";
//             cout << "1 - Search Venues\n";
//             cout << "2 - Create Reservations\n";
//             cout << "3 - View Reservations\n";
//             cout << "4 - Update Reservations\n";
//             cout << "5 - Delete Reservations\n";
//             cout << "6 - Exit system\n";
//             cout << ": ";
//             cin >> choice;
//             reset();
//
//             switch(choice) {
//                 case 1: {
//                     Venue v;
//                     v.view();
//                     break;
//                 }
//                 case 2: {
//                     Reservation r;
//                     r.create();
//                     break;
//                 }
//                 case 3: {
//                     Reservation r;
//                     r.view();
//                     break;
//                 }
//                 case 4: {
//                     Reservation r;
//                     r.update();
//                     break;
//                 }
//                 case 5: {
//                     Reservation r;
//                     r.remove();
//                     break;
//                 }
//                 case 6: {
//                     cout << "Exiting system. Thank you for using VRMS!";
//                     exit(0);
//                     break;
//                 }
//                 default:
//                     cout << "Invalid choice. Please try again.\n";
//             }
//         }
//     }
// };