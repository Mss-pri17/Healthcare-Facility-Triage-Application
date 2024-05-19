
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>

#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace seneca {
    Menu::Menu(const char* menuContent, int numberOfTabs)
    {
        m_numOptions = numberOfTabs;
        m_text = new char[strlen(menuContent) + 1];
        strcpy(m_text, menuContent);
    }
    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }
  
    ostream& Menu::displayMethod(ostream& ostr) const
    {
        string indent(m_numOptions * 3, ' '); // 3 spaces per tab
       
        // Create a string stream from the menu text
        istringstream menuStream(m_text);
        string line;
        while (std::getline(menuStream, line)) {
            ostr << indent << line << std::endl;
        }
       
        // Print the prompt
        cout << indent << "0- Exit" << endl << indent << "> ";

        return ostr;

    }
    int& Menu::operator>>(int& Selection) {
        displayMethod();
        int value = Selection;
        bool isValidInteger = false;
        while (!isValidInteger) {
            if (!(cin >> value)) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            // Check if the input has trailing characters
            else if (cin.peek() != '\n') {
                cout << "Only enter an integer, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            else if (value < 0 || value > 3) {
                cout << "Invalid value entered, retry [0 <= value < " << m_numOptions << "]: ";
            }

            else {
                if (value == 0) {
                    // Exit the sub-menu if input is 0
                    Selection = value;
                    return Selection;
                }
                isValidInteger = true;
            }

        }

        Selection = value;
        return Selection;
    }

};
