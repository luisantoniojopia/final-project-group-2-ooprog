#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

#include "base_account.h"
using namespace std;

class BaseAccount;

class Venue : public BaseAccount {
public:
    struct VenueDetails {
        char venueType;
        string venueName;
        string venueSize;
        int venueCapacity;
        double venueRate;
        string venueDescription;
    };

    void displayVenues(const vector<VenueDetails>& venues) const {
        if (venues.empty()) {
            cout << "No venues available.\n";
            return;
        }

        // Display header
        cout << left << setw(10) << "Type" << setw(25) << "Venue Name" << setw(10) << "Size" << setw(10) << "Capacity" << setw(15) << "Rate" << "Description\n";
        cout << string(80, '-') << endl;

        // Display each venue's details
        for (size_t i = 0; i < venues.size(); ++i) {
            const VenueDetails& venue = venues[i];
            cout << left << setw(10) << venue.venueType
                 << setw(25) << venue.venueName
                 << setw(10) << venue.venueSize
                 << setw(10) << venue.venueCapacity
                 << setw(15) << fixed << setprecision(2) << venue.venueRate
                 << venue.venueDescription << endl;
        }
    }

    vector<VenueDetails> venueListsCollection = {
        {'I', "Grand Canvas", "BIG", 100, 25000, "A expansive open space is perfect for all types of events."},
        {'I', "Midscale Canvas", "MEDIUM", 50, 14000, "A cozy space for smaller gatherings."},
        {'I', "Snug Canvas", "SMALL", 25, 6000, "An intimate venue is perfect for private events."},
        {'I', "KTV Lounge", "SMALL", 20, 10000, "A karaoke space is ideal for music lovers."},
        {'I', "The Forum", "SMALL", 15, 10000, "A professional meeting place is perfect for business events."},
        {'O', "Open Area", "BIG", 100, 22000, "A spacious outdoor venue is great for large gatherings."},
        {'O', "Backyard Haven", "SMALL", 20, 12000, "An inviting backyard is perfect for casual events."},
        {'O', "Rooftop Terrace", "MEDIUM", 40, 35000, "An expansive rooftop for unforgettable views."},
        {'O', "Tiny Cabin", "SMALL", 6, 20000, "An Escape to this charming tiny cabin in nature."},
        {'O', "MultiSports Court", "MEDIUM", 10, 4000, "A versatile sports court is ideal for active events."}
    };
    vector<VenueDetails> predefinedVenues;
    vector<VenueDetails> customVenues;
    VenueDetails venueDetails;

    // Constructor
    Venue(string u, string p, string pn, string e, char type, const string& name, const string& size, int capacity, double rate, const string& description)
        : BaseAccount(u, p, pn, e), venueDetails({type, name, size, capacity, rate, description}) {}

    // Default constructor
    Venue() : BaseAccount(), venueDetails({'I', "Default Venue", "SMALL", 50, 1000, "Default Description"}) {
    }

    // Setters
    void setVenueType(char type) { venueDetails.venueType = type; }
    void setVenueName(const string& name) { venueDetails.venueName = name; }
    void setVenueSize(const string& size) { venueDetails.venueSize = size; }
    void setVenueCapacity(int capacity) { venueDetails.venueCapacity = capacity; }
    void setVenueRate(double rate) { venueDetails.venueRate = rate; }
    void setVenueDescription(const string& description) { venueDetails.venueDescription = description; }

    // Getters
    char getVenueType() const { return venueDetails.venueType; }
    string getVenueName() const { return venueDetails.venueName; }
    string getVenueSize() const { return venueDetails.venueSize; }
    int getVenueCapacity() const { return venueDetails.venueCapacity; }
    double getVenueRate() const { return venueDetails.venueRate; }
    string getVenueDescription() const { return venueDetails.venueDescription; }

    vector<VenueDetails>& getCustomVenues() {
        return customVenues;
    }

    vector<VenueDetails>& getPredefinedVenues() {
        return venueListsCollection;
    }

    void create() override {
        char venueType;
        string venueName, venueSize, venueDescription;
        int venueCapacity;
        double venueRate;

        cout << "\n- Create Venue -\n";
        cout << "Enter type of venue (I = Indoor, O = Outdoor): ";
        cin >> venueType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter venue name: ";
        getline(cin, venueName);

        cout << "Enter venue size (SMALL, MEDIUM, BIG): ";
        getline(cin, venueSize);

        cout << "Enter venue capacity (pax): ";
        cin >> venueCapacity;

        cout << "Enter venue daily rate: ";
        cin >> venueRate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter venue description: ";
        getline(cin, venueDescription);

        // Add the new venue to the custom venues list
        customVenues.push_back({venueType, venueName, venueSize, venueCapacity, venueRate, venueDescription});
        cout << "Venue successfully created.\n";
        reset();
    }

    void view() override {
        cout << "\n- View All Venues -\n";

        // Display Predefined Venues
        cout << "\nPredefined Venues:\n";
        if (venueListsCollection.empty()) {
            cout << "No predefined venues available.\n";
        } else {
            displayVenues(venueListsCollection);
        }

        // Display Custom Venues
        cout << "\nCustom Created Venues:\n";
        if (customVenues.empty()) {
            cout << "No custom venues available.\n";
        } else {
            displayVenues(customVenues);
        }

        reset();
    }

    void updateVenueDetails(int index) {
        // Check if the index is within the valid range
        if (index < 0 || index >= customVenues.size()) {
            cout << "Invalid venue index. No venue updated.\n";
            return;
        }

        // Reference the venue to update
        VenueDetails &venueToUpdate = customVenues[index];

        // Declare variables for user input
        char venueType;
        string venueName, venueSize, venueDescription;
        int venueCapacity;
        double venueRate;

        // Ask the user for the new details
        cout << "\n- Update Venue -\n";

        cout << "Enter new type of venue (I = Indoor, O = Outdoor): ";
        cin >> venueType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        cout << "Enter new venue name: ";
        getline(cin, venueName);

        cout << "Enter new venue size (SMALL, MEDIUM, BIG): ";
        getline(cin, venueSize);

        cout << "Enter new venue capacity (pax): ";
        cin >> venueCapacity;

        cout << "Enter new venue daily rate: ";
        cin >> venueRate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        cout << "Enter new venue description: ";
        getline(cin, venueDescription);

        // Update the venue details with the new information
        venueToUpdate.venueType = venueType;
        venueToUpdate.venueName = venueName;
        venueToUpdate.venueSize = venueSize;
        venueToUpdate.venueCapacity = venueCapacity;
        venueToUpdate.venueRate = venueRate;
        venueToUpdate.venueDescription = venueDescription;

        // Inform the user that the venue has been successfully updated
        cout << "Venue details successfully updated.\n";
    }

    void update() override {
        cout << "- Update Venue -\n\n";
        cout << "Select venue type to update:\n";
        cout << "1. Predefined Venue\n";
        cout << "2. Custom Venue\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice == 1) {
            // Update predefined venue
            if (venueListsCollection.empty()) {
                cout << "No predefined venues available to update.\n";
                return;
            }

            displayVenues(venueListsCollection);
            int index;
            cout << "Enter the number of the predefined venue to update: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > venueListsCollection.size()) {
                cout << "Invalid selection.\n";
                return;
            }

            VenueDetails& venue = venueListsCollection[index - 1];
            updateVenueDetails(index);
            cout << "Predefined venue successfully updated.\n";
        } else if (choice == 2) {
            // Update custom venue
            if (customVenues.empty()) {
                cout << "No custom venues available to update.\n";
                return;
            }

            displayVenues(customVenues);
            int index;
            cout << "Enter the number of the custom venue to update: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > customVenues.size()) {
                cout << "Invalid selection.\n";
                return;
            }

            VenueDetails& venue = customVenues[index - 1];
            updateVenueDetails(index);
            cout << "Custom venue successfully updated.\n";
        } else {
            cout << "Invalid choice. Please select 1 or 2.\n";
        }
        reset();
    }

    void remove() override {
        cout << "- Remove Venue -\n\n";

        // reset();
    }
};