// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Movie.h"
using namespace std;
namespace sdds
{

    Movie::Movie() {}

    Movie::Movie(const std::string& strMovie) {
        std::string temp = strMovie;
        if (temp != "") {
            m_title = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);
            deleteSpaceBeginEnd(m_title);

            m_yearOfRelease= std::atoi(temp.substr(0, temp.find_first_of(",")).c_str());
            
            m_description = temp.erase(0, temp.find_first_of(",") + 1);
            deleteSpaceBeginEnd(m_description);
        }
    }

    const std::string& Movie::title() const {
        return m_title;
    }

    void Movie::deleteSpaceBeginEnd(std::string& str) {
        if (str != "") {
            int posBegin = str.find_first_not_of(" ");
            int posEnd = str.find_last_not_of(" ");
            str = str.substr(posBegin, posEnd - posBegin + 1);
        }
    }

    std::ostream& Movie::display(std::ostream& ostr) const {
        ostr<< right << setw(40) << m_title << " | "
            << right << setw(4) << m_yearOfRelease << " | "
            << left << m_description << std::endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Movie& m) {
        return m.display(ostr);
    }
}