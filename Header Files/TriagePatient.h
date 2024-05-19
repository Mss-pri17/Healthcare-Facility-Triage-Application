/*/////////////////////////////////////////////////////////////////////////
                          MILESTONE 4
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: TriagePatient Header File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_TRIAGEPATIENT_H_
#define SENECA_TRIAGEPATIENT_H_

#include "Patient.h"

namespace seneca {
    extern int nextTriageTicket;

    class TriagePatient : public Patient {
    private:
        char* m_symptoms;
        void init(const TriagePatient& other); //used to perform a deep copy of the 'symptoms' variable during  during object construction and assignment.
    public:
        // Passes the current value of nextTriageTicket to the base class Patient constructor
        TriagePatient();

        // Deallocates the dynamically allocated memory for the symptoms member variable
       virtual ~TriagePatient();

        // Calls the init function to perform a deep copy of the symptoms member variable
        TriagePatient(const TriagePatient& other); //copy constructor

        TriagePatient& operator=(const TriagePatient& other); //copy assignment operator
        virtual char type() const override;

        //Overriden virtual function to write the TriagePatient information to the output stream
        std::ostream& write(std::ostream& os) const override;

        // Overridden virtual function to read the TriagePatient information from the input stream
        std::istream& read(std::istream& is) override;

    };
}
#endif //!SENECA_TRIAGEPATIENT_H_