#pragma once

#include <iostream>

#include "base_account.h"
using namespace std;

class Reservation : public BaseAccount {
public:
    string askVenue;
    int askReservedDates;

    void create() override {
        cout << "- Create Reservation -\n\n";

        cout << "I. Preferred Venue\n";
        cout << "\tIndoor Venues\n";
        cout << "\t\tI1 - Grand Canvas (100 pax)\n";
        cout << "\t\tI2 - Midscale Canvas (50 pax)\n";
        cout << "\t\tI3 - Snug Canvas (25 pax)\n";
        cout << "\t\tI4 - KTV Lounge (20 pax)\n";
        cout << "\t\tI5 - The Forum (15 pax)\n";

        cout << "\tOutdoor Venues\n";
        cout << "\t\tO1 - Open Area (100 pax)\n";
        cout << "\t\tO2 - Backyard Haven (20 pax)\n";
        cout << "\t\tO3 - Rooftop Terrace (40 pax)\n";
        cout << "\t\tO4 - Tiny Cabin (6 pax)\n";
        cout << "\t\tO5 - Multi-Sports Court\n";

        cout << "\tEnter the venue code: ";
        getline(cin, askVenue);
        cout << "\n\n";

        // validation
            // if number of input > characters
            // You entered an invalid venue code. Kindly enter exactly 2 characters only.
            //
            // if input did not match
            // You entered [input], not not included in our list. Kindly enter another code.
            //
            // if input matches
            // You reserved for [venue name].

        cout << "II. Reservation Date\n";
        cout << "\tEnter the number of days of your reservation: ";
        // getline(cin, askReservedDates);
        cout << "\n\n";

        // validation
            // if input is negative
            // You entered an invalid input. Kindly enter a positive value.
            //
            // if input is positive integer
            // You reserved for [num] day/s.

        cout << "\tEnter the date of your reservation: ";
        // getline

        // validation
            // if input is wrong
            // You entered an invalid date. Kindly follow the format [format].
            //
            // if input matches
            // You reserved for [venue date].

        // if input is 2 or more days
        cout << "For 2 or more days, choose your preferred set-up\n";
        cout << "\t\tD1 - Separate Dates\n\t\tD2 - Date Range\n\n";
        cout << "\tEnter your preference: ";
        // getline

        // validation
            // if number of input > characters
            // You entered an invalid code. Kindly enter exactly 2 characters only.
            //
            // if input did not match
            // You entered [input], not not included in our list. Kindly enter another code.
            //
            // if input matches
            // You have chosen [input]. Kindly add more details about the date afterwards.

        // if input is D1 - Separate Dates
        // loop to number of days

        cout << "\tEnter the date of your reservation: ";
        // getline

        // validation
            // if input is wrong
            // You entered an invalid date. Kindly follow the format [format].
            //
            // if input matches
            // You reserved for [venue date].

        // if input is D2 - Date Range
        cout << "\tEnter the start date of your reservation: ";
        // getline

        // validation
            // if input is wrong
            // You entered an invalid date. Kindly follow the format [format].
            //
            // if input matches
            // You reserved for [start date] until [end date]

        cout << "III. Reservation Time\n";
        cout << "\tOur packages include 8 hours of exclusive use of your chosen venue, billed at the daily rate.\n\n";
        cout << "\tEnter the start time of your reservation: ";
        // getline

        // validation

        cout << "IV. Payment Method\n";
        cout << "\tChoose your preferred mode of payment\n";
        cout << "\t\tPM1 - Cash\n";
        cout << "\t\tPM2 - Credit/Debit Card\n";
        cout << "\t\tPM3 - Bank Transfer\n";
        cout << "\tEnter your preferred method code: ";
        // getline

        // validation
            // if number of input > characters
            // You entered an invalid code. Kindly enter exactly 3 characters only.
            //
            // if input did not match
            // You entered [input], not not included in our list. Kindly enter another code.
            //
            // if input matches
            // You have chosen [input] as mode of payment. Kindly add more details about the payment afterwards.

        cout << "V. Payment Schedule\n";
        cout << "\tChoose your preferred payment plan\n";
        cout << "\t\tPS1 - Full Payment";
        cout << "\t\tPS2 - 50/50 Split\n";
        cout << "\t\tPS3 - Monthly Installments\n";
        cout << "\tEnter your payment schedule: ";
        // getline

        // validation
            // if number of input > characters
            // You entered an invalid code. Kindly enter exactly 3 characters only.
            //
            // if input did not match
            // You entered [input], not not included in our list. Kindly enter another code.
            //
            // if input matches
            // You have chosen [input] as payment schedule. Kindly coordinate with the admin to process your payment.

        reset();
    }

    void view() override {
        cout << "- View Reservation -\n\n";

        reset();
    }

    void update() override {
        cout << "- Update Reservation -\n\n";

        reset();
    }

    void remove() override {
        cout << "- Remove Reservation -\n\n";

        reset();
    }
};