/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage Implementation File
Filename: PreTriage.cpp
Version 1.0
Author   Potpourri P.Fajilagot
Revision History
-----------------------------------------------------------
Date      Reason
2024/04/06  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/ 
/***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

#include "PreTriage.h"
#include "Utils.h"
#include "TriagePatient.h"
#include "TestPatient.h"

namespace seneca {
    PreTriage::PreTriage(const char* dataFilename)
        : m_dataFilename(nullptr), m_lineupSize(0), m_contagionTestAverageWaitTime(Time(15)), m_triageAverageWaitTime(Time(5))
    {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);

        load();
    }

    PreTriage::~PreTriage() {
        save();
        for (int i = 0; i < m_lineupSize; i++) {
            delete m_lineup[i];
        }
        delete[]m_dataFilename;
    }

    void PreTriage::run() {
        const char* menuContent = "General Healthcare Facility Pre-Triage Application\n"
            "1- Register\n"
            "2- Admit\n"
            "3- View Lineup\n";
        Menu menu(menuContent, 0);

        int selection;
        do {
            menu >> selection;
            switch (selection) {
            case 1:
                Register();
                break;
            case 2:
                admit();
                break;
            case 3:
                lineup();
                break;
            case 0:

                break;
            default:
                std::cout << "Invalid selection, try again." << std::endl;
            }
        } while (selection != 0);
    }
    int PreTriage::indexOfFirstInLine(char type) const {
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == type) {
                return i;
            }
        }
        return -1;
    }

        void PreTriage::setAverageWaitTime(const Patient& patient) {
        int CT = U.getTime();
        Time PTT = patient.time();
        int PTN = patient.number();

        if (patient.type() == 'C') {
            m_contagionTestAverageWaitTime = ((CT - PTT) + (m_contagionTestAverageWaitTime * (PTN - 1))) / PTN;
        }
        else if (patient.type() == 'T') {
            m_triageAverageWaitTime = ((CT - PTT) + (m_triageAverageWaitTime * (PTN - 1))) / PTN;
        }
    }

    Time PreTriage::getWaitTime(const Patient& patient) const {
        char Type = patient.type();
        int waitTime = (Type == 'C') ? m_contagionTestAverageWaitTime : m_triageAverageWaitTime;
        int patientCount = 0;

        for (int i = 0; i < m_lineupSize ; i++) {
            if (m_lineup[i]->type() == Type) {
                patientCount++;
            }
        }

        return waitTime * patientCount;

    }

    void PreTriage::load() {
        std::cout << "Loading data..." << std::endl;

        // Open the file
        ifstream file(m_dataFilename);
        if (!file.is_open()) {
            std::cout << "No data or bad data file!\n" << std::endl;
            return;
        }
        // Read the average wait times
        file >> m_contagionTestAverageWaitTime;
        file.ignore(1000, ',');
        file >> m_triageAverageWaitTime;
        file.ignore(1000, '\n');

        m_lineupSize = 0;

        // Read the patient records
        while (m_lineupSize < MAX_LINEUP && !file.eof()) {
            Patient* newPatient = nullptr;

            char type{};
            file >> type;
            file.ignore(1000, ',');

            if (type == 'C') {
                newPatient = new TestPatient();
            }
            else if (type == 'T') {
                newPatient = new TriagePatient();
            }
            else {
                break;
            }
            if (newPatient) {
                if (newPatient->read(file)) {
                    m_lineup[m_lineupSize++] = newPatient;
                }
                else {
                    delete newPatient;
                }
            }
        };

        if (!file.eof()) {
            std::cout << "Warning: number of records exceeded " << MAX_LINEUP << std::endl;
            if (m_lineupSize == MAX_LINEUP) {
                std::cout << m_lineupSize << " Records imported...\n\n";
            }
        }
        else if (m_lineupSize == 0) {
            std::cout << "No data or bad data file!\n\n";
        }
        else {
            std::cout << m_lineupSize << " Records imported...\n\n";
        }
        file.close();

    }


    void PreTriage::save() {
        ofstream file(m_dataFilename);

        if (!file.is_open()) {
            cout << "Unable to open file!" << endl;
            return;
        }
            
            // Print the number of records saved for each type of patient
            int contagionCount = 0, triageCount = 0;
            cout << "Saving lineup..." << std::endl;
            // Write the average wait times
            file << m_contagionTestAverageWaitTime << "," << m_triageAverageWaitTime << "\n";

            for (int i = 0; i < m_lineupSize; i++) {
                (m_lineup[i])->write(file) << "\n";
                    if (m_lineup[i]->type() == 'C') {
                        contagionCount++;
                    }
                    else if (m_lineup[i]->type() == 'T') {
                        triageCount++;
                    }
            }
            
            std::cout << contagionCount << " Contagion Tests and " << triageCount << " Triage records were saved!" << std::endl;
        
        file.close();
    }
    void PreTriage::Register() {
        if (m_lineupSize == MAX_LINEUP) {
            cout << "Line up full!" << endl;
            return;
        }
        Menu menu("Select Type of Registration:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;

        cin.ignore(1000, '\n');

        if (selection == 1) {
            m_lineup[m_lineupSize] = new TestPatient();
        }
        else if (selection == 2) {
            m_lineup[m_lineupSize] = new TriagePatient();
        }
        else if (selection == 0) {
            return;
        }
        else {
            cout << "Invalid selection!" << endl;
            return;
        }

        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        cin >> *m_lineup[m_lineupSize];
        cout << endl;

        cout << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
        cout << "******************************************" << endl;
        cout << endl;

        m_lineupSize++;
    }

    void PreTriage::admit() {
        Menu menu("Select Type of Admittance:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;
        if (selection == 0) {
            return;
        }
        char type = (selection == 1) ? 'C' : 'T';

        int index = indexOfFirstInLine(type);
        if (index == -1) {
            cout << "Lineup is empty!" << endl;
            return;
        }

        cout << "\n******************************************\n";
        cout << "Call time: [";
                 Time time;
                 cout << time.reset(); 
                 cout << "]" << endl;
        cout << "Calling at for " << *m_lineup[index];
        cout << "******************************************\n\n";

        setAverageWaitTime(*m_lineup[index]);
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    void PreTriage::lineup()const{
        Menu menu("Select The Lineup:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;
        if (selection == 0) {
            return;
        }

        char type = (selection == 1) ? 'C' : 'T';
        cout << "Row - Patient name                                          OHIP     Tk #  Time\n";       
        cout << "-------------------------------------------------------------------------------" << std::endl;
        int count = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == type) {
              //  std::cout << ++count << " - " << *m_lineup[i] << std::endl;
                clog.setf(ios::left);
                clog.fill(' ');
                clog.width(4);
                clog << count + 1;
                clog << "- ";
                clog.unsetf(ios::left);

                clog << (*m_lineup[i]) << endl;
                count++;
            }
        }
        if (count == 0) {
            std::cout << "Line up is empty!" << std::endl;
        }
        std::cout << "-------------------------------------------------------------------------------\n" ;
    }
}
