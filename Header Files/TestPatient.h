/*/////////////////////////////////////////////////////////////////////////
						  MILESTONE 4
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: TestPatient Header File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_TESTPATIENT_H_
#define SENECA_TESTPATIENT_H_

#include "Patient.h"


namespace seneca {
	extern int nextTestTicket; //Declaration with external linkage,global variable for next test ticket number

	class TestPatient :public Patient {
	public:
		// Passes the current value of nextTestTicket to the base class Patient constructor
		TestPatient(); //default constructor
		virtual char type() const override; //overrides virtual function in patient type
		std::ostream& write(std::ostream& os)const; //overrides write function
		std::istream& read(std::istream& is); //overrides read function
		virtual ~TestPatient();
	};
}
#endif //SENECA_TESTPATIENT_H_
