#pragma once
#include <iostream>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Bed.h"
#include "Appointment.h"
#include "Payment.h"

using namespace std;

namespace Hospital {

    class HospitalManager {
    private:
        vector<Patient*> patients;
        vector<Doctor*> doctors;
        vector<Bed*> beds;
        vector<Appointment*> appointments;

    public:
        // ===== Constructor & Destructor =====
        HospitalManager() = default;
        ~HospitalManager();

        // ===== Methods to add entities =====
        void addPatient(Patient* p);
        void addDoctor(Doctor* d);
        void addBed(Bed* b);
        void addAppointment(Appointment* a);

        // ===== Search / Retrieve =====
        Patient* findPatientById(const string& id);
        Doctor* findDoctorByLname(const string& lname);

        // ===== Display =====
        void displayPatients() const;
        void displayDoctors() const;
        void displayBeds() const;
        void displayAppointments() const;

        // ===== Payment Options =====
        void payBeforeAppointment(Patient* patient, double serviceCost);
        void payAfterConsultation(Patient* patient, double serviceCost);

        //== getter============
        const std::vector<Doctor*>& getDoctors() const { return doctors; }

    };

}

