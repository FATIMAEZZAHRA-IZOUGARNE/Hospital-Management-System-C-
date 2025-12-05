#include "Schedule.h"

namespace Hospital {

  
    // ===== Add a slot =====
    void Schedule::addSlot(const string& slot)
    {
        slots.push_back(slot);
        availability.push_back(true);
    }

    // ===== Book a slot =====
    bool Schedule::bookSlot(const string& slot)
    {
        for (int i = 0; i < slots.size(); i++) {
            if (slots[i] == slot && availability[i]) {
                availability[i] = false;
                return true;
            }
        }
        return false;
    }

    // ===== Display =====
   // ===== Display all slots =====
    void Schedule::display() const {
        cout << "\n--- Available Slots ---\n";
        bool anyFree = false;

        for (int i = 0; i < slots.size(); ++i) {
            cout << i + 1 << " - " << slots[i]
                << " [" << (availability[i] ? "Available" : "Booked") << "]\n";
            if (availability[i]) anyFree = true;
        }

        if (!anyFree) cout << "No available slots.\n";
    }

}
