/*/////////////////////////////////////////////////////////////////////////
                          MILESTONE 4
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: Patient Implementation File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Patient.h"
#include "Time.h"
#include "Utils.h"
#define MAX_NAME 50

using namespace std;
namespace seneca {

    Patient::Patient(int ticketNumber) : ticket(ticketNumber) {
        name = nullptr;
        ohip = 0;
    }
    void Patient::init(const Patient& source) {
        ohip = source.ohip;
        ticket = source.ticket;
        if (source.name != nullptr) {
            name = new char[MAX_NAME + 1];
            strncpy(name, source.name, MAX_NAME);
            name[MAX_NAME] = '\0';
        }
        else {
            name = nullptr;
        }
    }

    Patient::Patient(const Patient& other) : ticket(other.ticket) {
        init(other);
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            delete[] name;
            init(other);
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] name;
        name = nullptr;
    }

    char Patient::type() const {
        return 'W';
    }



    bool Patient::operator==(char type) const {
        return (this->type() == type);
    }

    bool Patient::operator==(const Patient& other) const {
        return (type() == other.type());
    }

    void Patient::setArrivalTime() {
        ticket.resetTime();
    }

    Time Patient::time()const {
        return ticket.time(); // Return Time object.As in main there was an overload <<A.time(). This overload will call helper function in Time.cpp => then call write
    };

    int Patient::number() const {
        return ticket.number();
    }

    Patient::operator bool() const {
        return (name != nullptr && ohip != 0);
    }
    Patient::operator const char* () const {
        return name;
    }

    ostream& Patient::write(ostream& os) const {
        if (&os == &cout) {
            if (!(*this)) {
                os << "1.Invalid Patient Record" << endl;
            }
            else
            {
                cout << ticket << endl;
                cout << name << ", OHIP: " << ohip << std::endl;
            }
        }
        else if (&os == &clog) {
            if (!(*this)) {
                os << "2.Invalid Patient Record" << endl;
            }
            else {//linear line              
                os.setf(ios::left);
                os.fill('.');
                os.width(53);
                os << name << ohip;
                os.unsetf(ios::left);
                os.setf(ios::right);
                os.fill(' ');
                os.width(5);
                os << ticket.number() << " " << ticket.time();
                os.unsetf(ios::right);
            }
        }
        else {
          //comma separated line
                os << type() << "," << name << "," << ohip << "," << ticket.number() << "," << ticket.time();
        }

        return os;
    }

    std::istream& Patient::read(std::istream& is) {
        //check whether the info is being extracted from the console
        if (&is == &cin) {
            string tempName;
            cout << "Name: ";
            getline(cin, tempName); //checker for console input,ensures that the input stream waits for the user to enter the name

            if (is.fail()) {
                delete[] name;
                name = nullptr;
                return is;
            }

            delete[]name;
            name = new char[tempName.length() + 1];
            strcpy(name, tempName.c_str());

            cout << "OHIP: ";

            bool isValidInteger = false;
            while (!isValidInteger) {
                if (!(cin >> ohip)) {
                    cout << "Bad integer value, try again: ";
                    is.clear();
                    is.ignore(10000, '\n');
                }
                else if (ohip < 100000000 || ohip > 999999999) {
                    cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                    is.clear();
                    is.ignore(10000, '\n');
                }
                else {
                    isValidInteger = true;
                    is.clear();
                    is.ignore(10000, '\n');
                }
            }


        }//perform actions for reading from file stream
        else {
            char nOfPatient[MAX_NAME + 1];
            is.get(nOfPatient, MAX_NAME + 1, ',');
            is.ignore(1, ','); // Ignore the comma

            delete[] name;
            name = nullptr;
            name = new char[strlen(nOfPatient) + 1];
            strcpy(name, nOfPatient);

            is >> ohip;
            is.ignore(1000, ','); // Ignore the comma
            ticket.read(is);
        }
        return is;
    }
}

