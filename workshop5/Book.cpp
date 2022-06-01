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
#include "Book.h"
using namespace std;
namespace sdds
{
    Book::Book() {}

    Book::Book(const std::string& strBook) {
        std::string temp = strBook;
        if (temp != "") {
            m_author = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);

            m_title = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);

            m_countryOfPublication = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);

            deleteSpaceBeginEnd(m_author);
            deleteSpaceBeginEnd(m_title);
            deleteSpaceBeginEnd(m_countryOfPublication);

            m_price = std::stod(temp.substr(0, temp.find_first_of(",")).c_str());
            temp = temp.erase(0, temp.find_first_of(",") + 1);

            m_yearOfPublication = std::atoi(temp.substr(0, temp.find_first_of(",")).c_str());
            m_description = temp.erase(0, temp.find_first_of(",") + 1);

            deleteSpaceBeginEnd(m_description);
        }
    }

    const std::string& Book::title() const{
        return m_title;
    }

    const std::string& Book::country() const{
        return m_countryOfPublication;
    }

    size_t Book::year() const{
        return m_yearOfPublication;
    }

    double& Book::price(){
        return m_price;
    }

    void Book::deleteSpaceBeginEnd(std::string& str) {
        if (str != "") {
            int posBegin = str.find_first_not_of(" ");
            int posEnd = str.find_last_not_of(" ");
            str = str.substr(posBegin, posEnd - posBegin + 1);
        }
    }

    std::ostream& Book::display(std::ostream& ostr) const {
        /*ostr<< right << setw(20) << m_author << " | "
            << right << setw(22) << m_title << " | "
            << right << setw(5) << m_countryOfPublication << " | "
            << right << setw(4) << m_yearOfPublication << " | "
            << right << setw(6) <<fixed << setprecision(2) << m_price << " | "
            << left  << m_description << std::endl;*/
        ostr << right << setw(20) << m_author << " | "
            << right << setw(22) << m_title << " | "
            << setw(5) << m_countryOfPublication << " | "
            << setw(4) << m_yearOfPublication << " | "
            << setw(6) << fixed << setprecision(2) << m_price << " | "
            << left << m_description << endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& b) {
        return b.display(ostr);
    }
}