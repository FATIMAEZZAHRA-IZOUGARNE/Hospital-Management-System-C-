#include "Payment.h"
#include "Insurance.h"
#include <iostream>

using namespace Hospital;
using namespace std;

// ===== Constructeur =====
Hospital::Payment::Payment(const string& m, double a, Insurance* ins) 
	: method(m), amount(a), insurance(ins)
{
}

// ===== Compute final amount =====
double Hospital::Payment::computeFinalAmount() const
{
	if (insurance)
		return amount - insurance->applyDiscount(amount);

	return amount;
}

// ===== Pay =====
void Hospital::Payment::pay() const
{
	cout << "Payment of " << computeFinalAmount()
		<< " using " << method << endl;
}

// ===== display =====
void Hospital::Payment::display() const
{

	cout << "Method: " << method << endl;
	cout << "Amount: " << amount << endl;

	if (insurance)
		insurance->display();
}

//==========get amount========
double Hospital::Payment::getAmount() const
{
	return amount;
}

//==========get method========
const std::string& Hospital::Payment::getMethod() const
{
	return method;
	// TODO: insert return statement here
}


//===========set method=======================
void Hospital::Payment::setMethod(const std::string& m)
{
	method = m;
}

