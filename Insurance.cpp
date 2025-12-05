#include "Insurance.h"

Hospital::Insurance::Insurance(const string& nameIn, double rate, bool isActive):
    nameIn(nameIn), coverageRate(rate), active(isActive)
{
    if (coverageRate < 0) coverageRate = 0;
    if (coverageRate > 1) coverageRate = 1;
}

double Hospital::Insurance::applyDiscount(double amount) const
{
    if (!this->active) return amount; // pas d'assurance active
    return amount * (1.0 - this->coverageRate);
}

void Hospital::Insurance::display() const
{
    std::cout << "Insurance: " << this->nameIn << endl;
    std::cout << "Coverage Rate: " << (this->coverageRate * 100) << endl;
    std::cout << "Status: " << (this->active ? "Active" : "Inactive") << endl;
}
