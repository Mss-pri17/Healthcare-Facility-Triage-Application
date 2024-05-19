/*/////////////////////////////////////////////////////////////////////////
                          MILESTONE 4
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: TriagePatient Implementation File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "TriagePatient.h"
#define MAXSYMPTOMS 512
using namespace std;
namespace seneca {

    int nextTriageTicket = 1;//

    void TriagePatient::init(const TriagePatient& other) {
        if (other.m_symptoms != nullptr) { //if the other TriagePatient has non-null symptoms
            m_symptoms = new char[strlen(other.m_symptoms) + 1];
            strcpy(m_symptoms, other.m_symptoms);
        }
        else {
            m_symptoms = nullptr; // Set the symptoms to nullptr if the other TriagePatient has no symptoms
        }
    }

    TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
        nextTriageTicket++; 
        m_symptoms = nullptr;
    }

    TriagePatient::~TriagePatient() {
        delete[]m_symptoms;
    }

    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other) {
        init(other);
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            //avoid self-assignment 
            Patient::operator=(other);
            delete[] m_symptoms;
            init(other);
        }
        return *this;
    }

    char TriagePatient::type() const
    {
        return 'T';
    }

    ostream& TriagePatient::write(ostream& os) const
    {
        if (&os == &cout) { //if the output stream is cout
            os << "TRIAGE" << endl;
            Patient::write(os);
            os << "Symptoms: " << m_symptoms << endl;
        }
        else if (&os == &clog) {//if the output stream is clog
            Patient::write(os);
        }
        else {//for any other output stream (csv)
            Patient::write(os);
            os << "," << m_symptoms;
        }
        return os;
    }

    istream& TriagePatient::read(istream& is) {
        Patient::read(is); // Call the base class read function

        if (&is != &std::cin) { // If the input stream is not cin (reading from a file)
            is.ignore();

            char m_tempSymptoms[MAXSYMPTOMS];
            is.get(m_tempSymptoms, MAXSYMPTOMS, '\n');
            is.ignore(1000, '\n');

            m_symptoms = new char[strlen(m_tempSymptoms) + 1];
            strcpy(m_symptoms, m_tempSymptoms);
            nextTriageTicket = number() + 1;
        }
        else { // If the input stream is cin (reading from the console)
            cout << "Symptoms: ";
            char m_tempSymptoms[MAXSYMPTOMS];
            is.get(m_tempSymptoms, MAXSYMPTOMS);
            is.ignore(1000, '\n');

            if (is.fail()) { // If the input stream fails, deallocate the symptoms memory and set the pointer to nullptr
                delete[] m_symptoms;
                m_symptoms = nullptr;
            }
            else { // Otherwise, allocate memory for the symptoms and copy the contents
                m_symptoms = new char[strlen(m_tempSymptoms) + 1];
                strcpy(m_symptoms, m_tempSymptoms);
            }
        }
        return is;
    }
}