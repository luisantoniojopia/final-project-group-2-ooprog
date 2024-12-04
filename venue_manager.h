#pragma once

#include <vector>
#include <iostream>
#include "venue.h"

using namespace std;

class VenueManager {
private:
    vector<Venue> venues; // Centralized list of all venues

public:
    // Default constructor
    VenueManager() {}

    // Add a venue
    void addVenue() {
        Venue newVenue;
        newVenue.create();
        venues.push_back(newVenue);
        cout << "Venue added successfully.\n";
    }

    // List all venues
    void listVenues() {
        if (venues.empty()) {
            cout << "No venues available.\n";
            return;
        }
        for (size_t i = 0; i < venues.size(); ++i) {
            cout << "Venue " << i + 1 << ":\n";
            venues[i].view(); // Call Venue's overridden view method
        }

        // Access custom and predefined venues directly using getters
        for (size_t i = 0; i < venues.size(); ++i) {
            cout << "\nVenue " << i + 1 << " Details:\n";

            // Access predefined venues and display them
            const std::vector<Venue::VenueDetails>& predefinedVenues = venues[i].getPredefinedVenues();
            if (!predefinedVenues.empty()) {
                cout << "Predefined Venues:\n";
                venues[i].displayVenues(predefinedVenues); // Display predefined venues
            } else {
                cout << "No predefined venues available.\n";
            }

            // Access custom venues and display them
            const std::vector<Venue::VenueDetails>& customVenues = venues[i].getCustomVenues();
            if (!customVenues.empty()) {
                cout << "Custom Venues:\n";
                venues[i].displayVenues(customVenues); // Display custom venues
            } else {
                cout << "No custom venues available.\n";
            }
        }
    }

    // Update a specific venue
    bool updateVenue(int index) {
        if (index < 0 || index >= venues.size()) {
            cout << "Invalid index.\n";
            return false;
        }
        venues[index].update(); // Call Venue's overridden update method
        cout << "Venue updated successfully.\n";
        return true;
    }

    // Remove a venue
    bool removeVenue(int index) {
        if (index < 0 || index >= venues.size()) {
            cout << "Invalid index.\n";
            return false;
        }
        venues[index].remove(); // Call Venue's overridden remove method
        venues.erase(venues.begin() + index);
        cout << "Venue removed successfully.\n";
        return true;
    }
};