/*/////////////////////////////////////////////////////////////////////////
                          MILESTONE 3
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: Time Header File

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_
#include<iostream>
#include "Utils.h"
using namespace std;
namespace seneca
{
    class Time
    {
    private:
        unsigned int minutes;
    public:
        //This method resets the Time object to the current time using the U.getTime() method.
        Time& reset();
        //This constructor initializes a Time object
        Time(unsigned int min = 0u);
        //This method writes the time into ostream in the HH:MM format
        std::ostream& writeMethod(std::ostream& ostr) const;
        //This method reads the time from istream in the H:M format. 
        std::istream& readMethod(std::istream& istr);
        //This operator overloads the cast to unsigned int for the Time class.
        operator unsigned int() const;
        //This operator overloads the multiplication assignment *= for the Time class.
        Time& operator*=(int val);
        //This operator overloads the subtraction assignment -= for the Time class. 
        Time& operator-=(const Time& D);
        //This operator performs the same calculation as the subtraction assignment -= overload, except that it does not have a side effect
        Time operator-(const Time& T) const;
        //Overload the insertion operator to be able to insert a Time object into an ostream object as described in the write method.
        friend ostream& operator<<(ostream& os, const Time& T);
        //Overload the extraction operator to be able to extract data from an istream object into the Time object as described in the read method.
        friend istream& operator>>(istream& is, Time& T);
    };

}
#endif // !SENECA_TIME_H
