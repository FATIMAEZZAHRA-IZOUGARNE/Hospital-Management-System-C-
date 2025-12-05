#pragma once
#include <iostream>
using namespace std;


namespace Hospital {
      
    class Insurance {
    private:
        string nameIn;
        double coverageRate; // 0.0 à 1.0
        bool active;

    public:
        // ===== Constructor =====
        Insurance(const string& nameIn = "", double rate = 0.0, bool isActive = true);
        ~Insurance(){}

        // ===== Methods =====
        double applyDiscount(double amount) const;
        void display() const;

        // ===== Getters =====
        const std::string& getName() const { return nameIn; }
        double getCoverageRate() const { return coverageRate; }
        bool isActive() const { return active; }

        

    };

}
