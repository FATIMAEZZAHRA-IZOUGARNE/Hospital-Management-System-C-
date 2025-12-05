#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class DateTime: public Date
{
private:
	int hour;
	int minute;
public:
	DateTime(int day = 1, int month = 01, int year = 2000, int h = 1, int min = 30);
	virtual void display() const override;


	//----- les operateurs
	bool operator<(const DateTime& other) const;
	bool operator==(const DateTime& other) const;

	~DateTime(){}

};

