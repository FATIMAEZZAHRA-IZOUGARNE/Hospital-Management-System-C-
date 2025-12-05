#pragma once
#include <iostream>
using namespace std;

namespace Hospital {
	class Person 
	{
    private:
        string id;
        string password;
        string firstName;
        string lastName;
        int age;
        string address;
        string phone;
    public:
        // Constructor
        Person(const string& id = "", const string& passw="", const string& firstName = "", const string& lastName = "",
            int age = 0, const string& address = "", const string& phone = "");

        // Display method
        virtual void display() const;

        // Virtual destructor
        virtual ~Person() {}


        const string& getId() const { return id; }
        const string& getPassword() const { return password; }
        const string& getFirstName() const { return this->firstName; }
        const string& getLastName() const { return this->lastName; }
        int getAge() const { return this->age; }
        const string& getPhone() const { return this->phone; }

	};
}


