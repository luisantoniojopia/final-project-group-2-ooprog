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
protected:
    char venueType;
    string venueName;
    string venueSize;
    int venueCapacity;
    double venueRate;
    string venueDescription;

public:
    // Constructor
    Venue(string u, string p, string pn, string e, char type, const string& name, const string& size, int capacity, double rate, const string& description)
        : BaseAccount(u, p, pn, e), venueType(type), venueName(name), venueSize(size), venueCapacity(capacity), venueRate(rate), venueDescription(description) {}

    // Setters
    void setVenueType(char type) { venueType = type; }
    void setVenueName(const string& name) { venueName = name; }
    void setVenueSize(const string& size) { venueSize = size; }
    void setVenueCapacity(int capacity) { venueCapacity = capacity; }
    void setVenueRate(double rate) { venueRate = rate; }
    void setVenueDescription(const string& description) { venueDescription = description; }

    // Getters
    char getVenueType() const { return venueType; }
    string getVenueName() const { return venueName; }
    string getVenueSize() const { return venueSize; }
    int getVenueCapacity() const { return venueCapacity; }
    double getVenueRate() const { return venueRate; }
    string getVenueDescription() const { return venueDescription; }

    void create() override {
        cout << "- Create Venue -\n\n";

        // reset();
    }

    void view() override {
        cout << "- View Venue -\n\n";

        // reset();
    }

    void update() override {
        cout << "- Update Venue -\n\n";

        // reset();
    }

    void remove() override {
        cout << "- Remove Venue -\n\n";

        // reset();
    }
};