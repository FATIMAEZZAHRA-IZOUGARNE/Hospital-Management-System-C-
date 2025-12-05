#pragma once
#include <iostream>
using namespace std;

namespace Hospital {
	class Bed
	{
	private:
		int bedNumber;
		friend class Patient; // Patient peut accéder aux attributs privés
	public:
		Bed(int);
		int getNumber() const;
		void display() const;
		~Bed(){}
	};
}


