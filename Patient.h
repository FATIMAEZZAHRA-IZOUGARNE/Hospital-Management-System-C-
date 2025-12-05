#pragma once

#include "Person.h"
#include "Payment.h"
#include "IAuthentification.h"
#include "Bed.h"
#include "Insurance.h"
#include <vector>
#include <iostream>
using namespace Hospital;

namespace Hospital {

	class Appointment; // <-- forward declaration
	class Patient : public Person, public IAuthentification
	{
	private:
		string category;   // "Normal", "Severe", "Handicap"
		string bloodType;  // "A+", "O-", "B+", etc.
		Insurance* insurance = nullptr;
		Bed* bed = nullptr;
		vector<Payment*> payments;       // plusieurs paiements possibles
		vector<Appointment*> appointments;
	public:
		// Constructor
		Patient(const string& id = "", const string& passw="", const string& firstName = "", const string& lastName = "",
			int age = 0, const string& address = "", const string& phone = "",
			const string& category = "Normal", const string& bloodType = "O+");

		// Methods
		void addAppointment(Appointment* rdv);
		void addPayment(Payment* payment);

		Appointment* getNextAppointment() const;  // lire le prochain rendez-vous
		void assignBed(Bed* b);

		virtual void display() const override;



		// ===== GETTERS ===== 
		const string& getCategory() const { return category; }
		const string& getBloodType() const { return bloodType; }
		Bed* getBed() const { return bed; }

		Insurance* getInsurance() const { return insurance; }

		bool authenticate(const string& idInput, const string& codeInput) override;

		
	};
}


