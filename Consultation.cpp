#include "Consultation.h"
#include "Patient.h"
#include "Doctor.h"

Hospital::Consultation::Consultation(Patient* p, Doctor* d, const DateTime& dt): 
	patient(p), doctor(d), date(dt), diagnosis(""), prescription(""), isFinished(false)
{
}

void Hospital::Consultation::finish()
{
	this->isFinished = true;
}

void Hospital::Consultation::display() const
{
    std::cout << "======== Consultation Details =======" << endl;
    std::cout << "Date: ";
    date.display();  // display DateTime

    if (patient)
        std::cout << "Patient: " << patient->getFirstName() << " " << patient->getLastName() << endl;
    else
        std::cout << "Patient: None" << endl;

    if (doctor)
        std::cout << "Doctor: " << doctor->getFirstName() << " " << doctor->getLastName() << endl;
    else
        std::cout << "Doctor: None" << endl;

    std::cout << "Diagnosis: " << diagnosis << endl;
    std::cout << "Prescription: " << prescription << endl;
    std::cout << "Status: " << (isFinished ? "Finished" : "Pending") << endl;
    std::cout << "==================================================================" << endl;
}
