/* Citation and Sources...
Final Project Milestone 5
Module: IOAble Implementation File
Filename: IOAble.h
Version 1.0
Author   Potpourri P.Fajilagot
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_IOABLE_H_
#define SENECA_IOABLE_H_
#include <iostream>
namespace seneca {
	class IOAble {
	public:
		// For future ostream outputs. It receives a reference of an ostream and returns a reference of an ostream. 
		virtual std::ostream& write(std::ostream& ostr) const = 0;//This function is incapable of changing the current object.
		//For future istream inputs. It receives a reference of istream and returns a reference of an istream.
		virtual std::istream& read(std::istream& istr) = 0;
		//Empty virtual destructor.
		virtual ~IOAble() {}

	};
	//HELPER OVERLOADS:
	//Overload the insertion operator to be able to insert the information of an IOAble object into ostream.
	std::ostream& operator<<(std::ostream& ostr, const IOAble& oWrite);
	//Overload the extraction operator to be able to extract information from an istream
	std::istream& operator>>(std::istream& istr, IOAble& iRead);

}

#endif //!SENECA_IOABLE_H_