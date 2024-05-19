/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage Header File
Filename: PreTriage.h
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
/***********************************************************************/
#ifndef SENECA_PRE_TRIAGE_H
#define SENECA_PRE_TRIAGE_H

#include "Patient.h"
#include "Time.h"
#include "Menu.h"

namespace seneca {
    const int MAX_LINEUP= 100;
    class PreTriage {
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run();

    private:
        char* m_dataFilename;
        Patient* m_lineup[MAX_LINEUP]={};
        int m_lineupSize;
        Time m_contagionTestAverageWaitTime;
        Time m_triageAverageWaitTime;

        int indexOfFirstInLine(char type) const;
        void setAverageWaitTime(const Patient& p);
        Time getWaitTime(const Patient& p) const;
        void load();
        void save() ;
        void Register();
        void admit();
        void lineup() const;
    };
}
#endif // !SENECA_PRE_TRIAGE_H


