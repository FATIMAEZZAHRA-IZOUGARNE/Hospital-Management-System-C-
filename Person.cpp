#include "Person.h"

Hospital::Person::Person(const string& id, const string& passw, const string& firstName, const string& lastName, int age, const string& address, const string& phone):
	id(id), password(passw), firstName(firstName), lastName(lastName), age(age), address(address), phone(phone)
{
}

void Hospital::Person::display() const
{
    cout << "ID: " <<this->id << endl;
    cout << "Name: " << this->firstName << " " << lastName << endl;
    cout << "Age: " << this->age << endl;
    cout << "Address: " << this->address << endl;
    cout << "Phone: " << this->phone << endl;
}
