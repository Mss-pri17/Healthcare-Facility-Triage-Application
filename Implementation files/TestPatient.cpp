
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TestPatient.h"

using namespace std;
namespace seneca {
	 int nextTestTicket = 1; //definition of the global variable

	TestPatient::TestPatient() :Patient(nextTestTicket) {
		//Default constructor,passes nexTestTicket to the base class patient constructor
		nextTestTicket++; 
	}

	char TestPatient::type()const {
		return 'C'; //returns 'C' for the contagion test
	}

	ostream& TestPatient::write(ostream& os) const {
		if (&os == &cout) {
			os << "Contagion TEST" << endl; //Inserts this if ostream is cout
		}
		Patient::write(os); //Calls the base class Patient's write function
		//os << "," << nextTestTicket;
		return os; 
	}

	istream& TestPatient::read(istream& is) {
		Patient::read(is);
		if (&is != &std::cin) {
			nextTestTicket = Patient::number() + 1;
		}
		return is;
		
	}
	TestPatient::~TestPatient() {};
}

