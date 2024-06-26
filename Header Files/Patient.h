#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
	class Patient : public IOAble {
	private:
		char* name;
		int ohip;
		Ticket ticket;
		void init(const Patient& source);
	public:
		Patient(int ticketNumber);
		Patient(const Patient& other);
		Patient& operator=(const Patient& other);
		virtual ~Patient();

		virtual char type() const=0;
		bool operator==(char type) const;
		bool operator==(const Patient& other) const;

		void setArrivalTime();
		Time time() const;
		int number() const;
		operator bool() const;
		
		operator const char* () const;
		virtual ostream& write(std::ostream& os) const;
		virtual istream& read(std::istream& is);
		
	};
}
#endif
