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

        //--------- getters-----------
        const vector<string>& getSlots() const { return slots; }
    };

}

