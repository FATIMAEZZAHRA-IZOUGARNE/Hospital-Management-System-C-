#include <iostream>
#include "HospitalSystemManager.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
using namespace std;
using namespace Hospital;

int main() {
    HospitalManager manager;

    // ================================
    // Création des créneaux pour TOUS les médecins
    // ================================
   

    bool running = true;

    while (running) {
        cout << "\n=== Main Menu ===\n";
        cout << "1 - Doctor Interface\n";
        cout << "2 - Patient Interface\n";
        cout << "3 - Quit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        // ================================
        // DOCTOR INTERFACE
        // ================================
        if (choice == 1) {
            bool doctorMenu = true;
            Doctor* connectedDoctor = nullptr;

            while (doctorMenu) {
                if (!connectedDoctor) {
                    cout << "\n--- Doctor Menu ---\n";
                    cout << "1 - Authenticate\n";
                    cout << "2 - Create Doctor\n";
                    cout << "0 - Back\n";
                    cout << "Choice: ";

                    int d;
                    cin >> d;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- IMPORTANT

                    if (d == 1) {
                        string id, pass;
                        cout << "ID: "; getline(cin, id);
                        cout << "Password: "; getline(cin, pass);

                        Doctor* dFound = manager.findDoctorByLname(id);
                        if (dFound && dFound->authenticate(id, pass)) {
                            cout << "Authentication successful.\n";
                            connectedDoctor = dFound;
                        }
                        else {
                            cout << "Authentication failed.\n";
                        }
                    }
                    else if (d == 2) {
                        string id, pass, fname, lname, phone, spec;
                        int age;

                        cout << "New Doctor :" << endl;

                        std::cout << "ID: "; std::getline(cin, id);
                        std::cout << "Password: "; std::getline(cin, pass);
                        std::cout << "First name: "; std::getline(cin, fname);
                        std::cout << "Last name : "; std::getline(cin, lname);
                        std::cout << "Age: ";
                        cin >> age;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- vide le '\n'
                        std::cout << "Phone number : "; std::getline(cin, phone);
                        std::cout << "Specialty : "; std::getline(cin, spec);

                        Doctor* d = new Doctor(id, pass, fname, lname, age, phone, spec);
                        manager.addDoctor(d);

                        cout << "Doctor created successfully.\n";
                    }
                    else if (d == 0) doctorMenu = false;
                }
                else {
                    // DOCTOR CONNECTED
                    cout << "\n--- Doctor Interface ---\n";
                    cout << "1 - View My Info\n";
                    cout << "2 - View My Appointments\n";
                    cout << "0 - Logout\n";
                    cout << "Choice: ";

                    int d2;
                    cin >> d2;

                    if (d2 == 1) connectedDoctor->display();
                    else if (d2 == 2) connectedDoctor->getAppointments();
                    else if (d2 == 0) connectedDoctor = nullptr;
                }
            }
        }

        // ================================
        // PATIENT INTERFACE
        // ================================
        else if (choice == 2) {
            bool patientMenu = true;
            Patient* connectedPatient = nullptr;

            while (patientMenu) {
                if (!connectedPatient) {
                    cout << "\n--- Patient Menu ---\n";
                    cout << "1 - Authenticate\n";
                    cout << "2 - Create Patient\n";
                    cout << "0 - Back\n";
                    cout << "Choice: ";

                    int p;
                    cin >> p;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- vide le '\n'

                    if (p == 1) {
                        string id, pass;
                        cout << "ID: "; getline(cin, id);
                        cout << "Password: "; getline(cin, pass);

                        Patient* f = manager.findPatientById(id);
                        if (f && f->authenticate(id, pass)) {
                            cout << "Authentication successful.\n";
                            connectedPatient = f;
                        }
                        else {
                            cout << "Authentication failed.\n";
                        }
                    }
                    else if (p == 2) {
                        string id, pass, fname, lname, phone, category, blood, address;
                        int age;

                        cout << "Enter Patient Info:\n";

                        cout << "ID: "; getline(cin,id);
                        cout << "Password: "; getline(cin, pass);
                        cout << "First Name: "; getline(cin, fname);
                        cout << "Last Name: "; getline(cin, lname);
                        cout << "Age: "; cin>> age;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- vide le '\n'

                        cout << "Address: "; getline(cin,address);
                        cout << "Phone: "; getline(cin, phone);
                        cout << "Category: "; getline(cin, category);
                        cout << "Blood Type: "; getline(cin, blood);

                        Patient* pNew = new Patient(id, pass, fname, lname, age, address, phone, category, blood);
                        manager.addPatient(pNew);

                        cout << "Patient created successfully.\n";
                    }
                    else if (p == 0) patientMenu = false;
                }
                else {
                    // PATIENT CONNECTED
                    cout << "\n--- Patient Interface ---\n";
                    cout << "1 - View My Info\n";
                    cout << "2 - Reserve Appointment\n";
                    cout << "3 - View My next Appointment\n";
                    cout << "0 - Logout\n";
                    cout << "Choice: ";

                    int p2;
                    cin >> p2;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- vide le '\n'

                    // View info
                    if (p2 == 1) connectedPatient->display();

                    // Reserve appointment
                    else if (p2 == 2) {

                        vector<Doctor*> docs = manager.getDoctors();

                        cout << "\nChoose a doctor by LAST NAME:\n";
                        for (int i = 0; i < docs.size(); i++)
                            cout << i + 1 << " - " << docs[i]->getLastName() << " (" << docs[i]->getSpecialty() << ")\n";

                        int index;
                        cin >> index;

                        Doctor* d = docs[index - 1];

                        cout << "\nAvailable Slots:\n";
                        d->getSchedule().display();

                        cout << "Enter desired slot (format: DD-MM-YYYY HH:MM): ";
                        string chosenSlot;
                        cin.ignore(); // pour consommer le '\n' restant
                        getline(cin, chosenSlot);

                        if (!d->getSchedule().bookSlot(chosenSlot)) {
                            cout << "❌ Slot already booked or invalid!\n";
                        }
                        else {
                            Appointment* a = new Appointment(connectedPatient, d, chosenSlot);

                            connectedPatient->addAppointment(a);
                            d->addAppointment(a);
                            manager.addAppointment(a);

                            cout << "✔ Appointment reserved successfully!\n";
                            double montant = 250.0;
                            std::cout << "Amount to pay: " << montant << " MAD\n";
                        }
                    }

                    else if (p2 == 3) connectedPatient->getNextAppointment();
                    else if (p2 == 0) connectedPatient = nullptr;
                }
            }
        }

        else if (choice == 3) {
            running = false;
            cout << "Exiting program...\n";
        }

        else cout << "Invalid choice.\n";
    }

    return 0;
}
