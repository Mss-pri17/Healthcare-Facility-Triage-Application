/*/////////////////////////////////////////////////////////////////////////
                          MILESTONE 3
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: TIME Implementation File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {

    // Method to reset the Time object to the current system time
    Time& Time::reset() {
        this-> minutes = U.getTime(); // Set the number of minutes to the current system time
        return *this; // Return a reference to the current object
    }

    // Constructor to initialize a Time object with a specified number of minutes (default is 0)
    Time::Time(unsigned int min) : minutes(min) {}

    // Method to write the time in HH:MM format to the ostream  
    ostream& Time::writeMethod(std::ostream& ostr)const {
        int hour = minutes / 60;
        int minute = minutes % 60;

        ostr << setfill('0')
            << setw(2) << hour
            << ":" << setw(2) << minute;
        return ostr;
    }

    istream& Time::readMethod(istream& istr)
    {
        int hour = 0;
        int minute = 0;
        char characters[2];

        istr >> hour;
        istr.get(characters, 2, '\n');
        // Check if the input format is correct (H:M), if not set failbit
        if (characters[0] != ':') {
            istr.setstate(ios::failbit);// Set failbit if format is incorrect
        }
        istr >> minute;
        minutes = hour * 60 + minute;
        return istr;

    }
    // Cast operator to convert Time object to unsigned int (number of minutes)
    Time::operator unsigned int() const {
        return minutes; 
    }

    // Overload the multiplication assignment operator *= for Time objects
    Time& Time::operator*=(int val) {
        minutes *= val; 
        return *this; 
    }

    // Overload the subtraction assignment operator -= for Time objects
    Time& Time::operator-=(const Time& D) {
        if (this->minutes < D.minutes)
            minutes += 1440;
        minutes -= D.minutes;
        return *this;
    }

    // Overload the subtraction operator - for Time objects
    Time Time::operator-(const Time& T) const {
        Time result(*this);
        result -= T;
        return result;
    }

    // Overload the insertion operator << to write Time objects to ostream
    ostream& operator<<(ostream& os, const Time& T) {
        T.writeMethod(os); 
        return os;
    }

    // Overload the extraction operator >> to read Time objects from istream
    istream& operator>>(istream& is, Time& T) {
        T.readMethod(is); 
        return is;
    }

}