#include "Doctor.h"
#include "Appointment.h"


//=============== constructeur   ===============
Hospital::Doctor::Doctor(const string& id, const string& passw, const string& firstName, const string& lastName, int age, const string& phone, const string& specialty)
	:Person(id,passw,firstName,lastName,age,phone), specialty(specialty)

{
}
//============= Authentification    ==============================
bool Hospital::Doctor::authenticate(const string& idInput, const string& codeInput)
{
	return (idInput == this->getId() && codeInput == this->getPassword());
}


//=============  Display Infos Doctor  =======================
void Hospital::Doctor::display() const
{
	std::cout << "Doctor: " << getFirstName() << " " << getLastName() << endl; //on a pas besoin de toutes les infos (l'age, numero de tele,.....)
	std::cout << "Specialty: " << this->specialty << endl;
	
}


