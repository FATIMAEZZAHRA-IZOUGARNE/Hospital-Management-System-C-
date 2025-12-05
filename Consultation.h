#pragma once
//#include "Patient.h"
//#include "Doctor.h"
#include "DateTime.h"
#include <iostream>
using namespace std;

namespace Hospital {
    class Patient; // forward declaration
    class Doctor;  // forward declaration

	class Consultation
	{
	private:
		DateTime date;
		Patient* patient;
		Doctor* doctor;

		string diagnosis;
		string prescription;
		bool isFinished;  // true si consultation terminée
	public:
        // ===== Constructors =====
        Consultation(Patient* p, Doctor* d, const DateTime& dt);



        // ===== Methods =====
        void finish();  // marque la consultation comme terminée
        void display() const;

        // ===== Getters =====
        const string& getDiagnosis() const { return diagnosis; }
        const string& getPrescription() const { return prescription; }
        bool getStatus() const { return isFinished; }
        const DateTime& getDate() const { return date; }
        Patient* getPatient() const { return patient; }
        Doctor* getDoctor() const { return doctor; }


	};
}


