#pragma once
#include "Person.h"
#include "Schedule.h"
#include "IAuthentification.h"
#include <string>
#include <vector>
#include <iostream>

namespace Hospital {

    class Appointment;
    class Doctor : public Person, public IAuthentification
    {
    private:
        string specialty;   // "Cardiology", "Pediatrics", ...
        bool available;          // true = doctor can take appointments
        Schedule schedule;
        vector<Appointment*> appointments;

    public:

        // Constructor
        Doctor(const string& id = "",
            const string& passw="",
            const string& firstName = "",
            const string& lastName = "",
            int age = 0,
            const string& phone = "",
            const string& specialty = "");
            

        // ===== METHODS =====
        void display() const override;
        virtual bool authenticate(const string& idInput, const string& codeInput) override;

        void addAppointment(Appointment* a) { appointments.push_back(a); }

        // ===== GETTERS =====
        const string& getSpecialty() const { return specialty; }
        bool isAvailable() const { return available; }
        const vector<Appointment*>& getAppointments() const { return appointments; }

        Schedule& getSchedule() { return schedule; }

    };

}

