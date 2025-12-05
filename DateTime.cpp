#include "DateTime.h"

DateTime::DateTime(int day, int month, int year, int h, int min)
    : Date(day,month,year), hour(h), minute(min)
{
}


void DateTime::display() const
{
	Date::display();
	cout << this->hour << " : " << this->minute << endl;
}



bool DateTime::operator<(const DateTime& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    if (day != other.day) return day < other.day;
    if (hour != other.hour) return hour < other.hour;
    return minute < other.minute;
}

bool DateTime::operator==(const DateTime& other) const {
    return (day == other.day &&
        month == other.month &&
        year == other.year &&
        hour == other.hour &&
        minute == other.minute);
}
