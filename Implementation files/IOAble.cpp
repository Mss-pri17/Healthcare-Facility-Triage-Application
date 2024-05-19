/* Citation and Sources...
Final Project Milestone 5.1
Module: IOAble Implementation File
Filename: IOAble.cpp
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
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace seneca {

    ostream& operator<<(ostream& ostr, const IOAble& oWrite) {
        //if (&oWrite) {
            oWrite.write(ostr);
        /*}
        else {
            ostr << "nullptr";
        }*/
        //oWrite.write(ostr);
        return(ostr);
    }

    istream& operator>>(istream& istr, IOAble& iRead) {
        iRead.read(istr);
        return(istr);
    }
}