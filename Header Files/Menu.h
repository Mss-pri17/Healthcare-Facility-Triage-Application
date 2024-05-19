/*/////////////////////////////////////////////////////////////////////////
						  MILESTONE 1
Full Name  : POTPOURRI FAJILAGOT
Student ID#: 122976236
Email      : pfajilagot@myseneca.ca
Section    : NHH
Description: MS1(MENU Header)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
/***********************************************************************/
#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

namespace seneca
{
	class Menu
	{
	private:
		char* m_text;
		int m_numOptions;
	public:
		//This constructor is designed to initialize a Menu object.
		Menu(const char* menuContent, int numberOfTabs = 0);
		//Deallocates the dynamically allocated memory.
		virtual ~Menu();

		//Makes sure the Menu can not be copied or assigned to another Menu object.
		Menu(const Menu&) = delete; // Disable copy constructor
		Menu& operator=(const Menu&) = delete; // Disable assignment operator

		//The display method is responsible for presenting the Menu content to the user.
		std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
		//Make sure that the entered value is validated as an integer.
		int& operator>>(int& Selection);
	};
}
#endif //!SENECA_MENU_H_

