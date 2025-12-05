#include "Patient.h"
#include "Appointment.h"

//=========================== constructeur=======================================
Hospital::Patient::Patient(const string& id, const string& passw, const string& firstName, const string& lastName,
    int age, const string& address, const string& phone,
    const string& category, const string& bloodType)
    : Person(id, passw, firstName, lastName, age, address, phone), category(category), bloodType(bloodType) {
}

//========================== Authentificate =====================================
bool Hospital::Patient::authenticate(const string& idInput, const string& codeInput)
{
    return (idInput == this->getId() && codeInput == this->getPassword());
}


//========================== Add appointment ds le tableau de pointeur Vector 1===============================
void Hospital::Patient::addAppointment(Appointment* rdv)
{
    appointments.push_back(rdv);
}

//===========================Add payment ds le tableau Vector 2====================================
void Hospital::Patient::addPayment(Payment* payment)
{
    payments.push_back(payment);
}

//=========================== For each patient we will see his nex appointment ===================================
Appointment* Hospital::Patient::getNextAppointment() const
{
    return appointments.empty() ? nullptr : appointments.front();
}


//=========================== For each Patient we can assigne to him an empty bed if it's available==============================
void Hospital::Patient::assignBed(Bed* b)
{
    this->bed = b;

    if (bed) {
        std::cout << "Bed Assigned: "<< this->bed->bedNumber<< std::endl;
    }
    else {
        std::cout << "Bed Assigned: None" << std::endl;
    }
}

//======================= Infos of a patient================
void Hospital::Patient::display() const
{
    Person::display(); // display The informations of the Base Class - Persen
    std::cout << "Category: " << this->category << endl;
    std::cout << "Blood Type: " << this->bloodType << endl;
    cout << "Assigned bed :" << this->getBed() << endl;
}



