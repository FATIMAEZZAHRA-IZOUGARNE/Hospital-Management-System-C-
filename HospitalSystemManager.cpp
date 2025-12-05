#include "HospitalSystemManager.h"

namespace Hospital {

    // ===== Destructor =====
    HospitalManager::~HospitalManager() {
        for (auto p : patients) delete p;
        for (auto d : doctors) delete d;
        for (auto b : beds) delete b;
        for (auto a : appointments) delete a;
    }

    // ===== Add Entities =====
    void HospitalManager::addPatient(Patient* p) { patients.push_back(p); }
    void HospitalManager::addDoctor(Doctor* d) 
    { 
        doctors.push_back(d);
        // Création automatique de 3 slots
        d->getSchedule().addSlot("2025-01-10 09:00");
        d->getSchedule().addSlot("2025-01-10 10:00");
        d->getSchedule().addSlot("2025-01-10 11:00");

        cout << "Doctor added with default schedule." << endl;
    }
    void HospitalManager::addBed(Bed* b) { beds.push_back(b); }
    void HospitalManager::addAppointment(Appointment* a) { appointments.push_back(a); }


    // ===== Search =====
    Patient* HospitalManager::findPatientById(const string& id) {
        for (auto p : patients) {
            if (p->getId() == id) return p;
        }
        return nullptr;
    }

    Doctor* HospitalManager::findDoctorByLname(const string& lname) {
        for (auto d : doctors) {
            if (d->getId() == lname) return d;
        }
        return nullptr;
    }

    // ===== Display =====
    void HospitalManager::displayPatients() const {
        cout << "=== Patients ===\n";
        for (auto p : patients) p->display();
    }

    void HospitalManager::displayDoctors() const {
        cout << "=== Doctors ===\n";
        for (auto d : doctors) d->display();
    }

    void HospitalManager::displayBeds() const {
        cout << "=== Beds ===\n";
        for (auto b : beds) b->display();
    }

    void HospitalManager::displayAppointments() const {
        cout << "=== Appointments ===\n";
        for (auto a : appointments) a->display();
    }

    // ===== Payment Options =====
    void HospitalManager::payBeforeAppointment(Patient* patient, double serviceCost) {
        if (!patient) return;

        Payment pay("Cash", serviceCost, patient->getInsurance());
        pay.pay();
        patient->addPayment(&pay);

        cout << "Appointment confirmed and payment done.\n";
    }

    void HospitalManager::payAfterConsultation(Patient* patient, double serviceCost) {
        if (!patient) return;

        Appointment* appt = patient->getNextAppointment();
        if (!appt || !appt->getStatus()) {
            cout << "Consultation not finished. Cannot pay now.\n";
            return;
        }

        Payment pay("Cash", serviceCost, patient->getInsurance());
        pay.pay();
        patient->addPayment(&pay);

        cout << "Payment completed. Thank you!\n";
    }

}

