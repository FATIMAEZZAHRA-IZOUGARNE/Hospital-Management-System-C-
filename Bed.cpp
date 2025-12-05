#include "Bed.h"

Hospital::Bed::Bed(int number): bedNumber(number)
{
}

int Hospital::Bed::getNumber() const
{
	return bedNumber;
}

void Hospital::Bed::display() const
{
	cout << "Bed number :" << this->bedNumber << endl;
}
