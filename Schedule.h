#pragma once
#include <iostream>
#include "DateTime.h"
#include "vector"

namespace Hospital {

    class Schedule {
    private:
        vector<string> slots;
        vector<bool> availability;     // true = libre, false = réservé
        int count;
        int capacity;

    public:
        ~Schedule(){}

        void addSlot(const string& dt);
        bool bookSlot(const string& dt);
        void display() const;

        bool isAvailable(int index) const {
            if (index < 0 || index >= slots.size()) return false;
            return availability[index];
        }

        string getSlot(int index) const {
            if (index >= 0 && index < slots.size())
                return slots[index];
            return "";
        }
        //--------- getters-----------
        const vector<string>& getSlots() const { return slots; }
        const vector<bool>& getAvailability() const { return availability; }
    };

}
