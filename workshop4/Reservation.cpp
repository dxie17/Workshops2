// Workshop: 4
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/24
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Reservation.h"
using namespace std;
namespace sdds
{
    void Reservation::setEmpty() {
        m_id = "";
        m_name = "";
        m_email = "";
        m_numberOfPeople = 0;
        m_day = 0;
        m_hour = 0;
    }
    Reservation::Reservation() {
        setEmpty();
    }

    void Reservation::update(int day, int time){
        m_day = day;
        m_hour = time;
    }

    Reservation& Reservation::operator= (const Reservation& r) {
        if (this != &r) {
            m_id = r.m_id;
            m_name = r.m_name;
            m_email = r.m_email;
            m_numberOfPeople = r.m_numberOfPeople;
            m_day = r.m_day;
            m_hour = r.m_hour;
        }
        return *this;
    }

    void Reservation::deleteSpaceBeginEnd(std::string& str) {
        int posBegin = str.find_first_not_of(" ");
        int posEnd = str.find_last_not_of(" ");
        str = str.substr(posBegin, posEnd - posBegin + 1);
    }

    Reservation::Reservation(const std::string& res) {
        setEmpty();
        std::string temp = res;
        
        m_id = temp.substr(0, temp.find_first_of(":"));
        temp = temp.erase(0, temp.find_first_of(":")+1);

        m_name = temp.substr(0, temp.find_first_of(","));
        temp = temp.erase(0, temp.find_first_of(",")+1);

        m_email = temp.substr(0, temp.find_first_of(","));
        temp = temp.erase(0, temp.find_first_of(",")+1);

        deleteSpaceBeginEnd(m_id);
        deleteSpaceBeginEnd(m_name);
        deleteSpaceBeginEnd(m_email);

        m_numberOfPeople = std::atoi(temp.substr(0, temp.find_first_of(",")).c_str());
        temp = temp.erase(0, temp.find_first_of(",")+1);

        m_day = std::atoi(temp.substr(0, temp.find_first_of(",")).c_str());
        temp = temp.erase(0, temp.find_first_of(",")+1);

        m_hour = std::atoi(temp.c_str());
    }

    std::ostream& Reservation::display(std::ostream& ostr) const{
        string people = "",activity="",email="<" + m_email + ">";
        m_numberOfPeople > 1 ? people = " people" : people = " person";
        if (m_hour >= 6 && m_hour <= 9)
            activity = "Breakfast";
        else if (m_hour >= 11 && m_hour <= 15)
            activity = "Lunch";
        else if (m_hour >= 17 && m_hour <= 21)
            activity = "Dinner";
        else
            activity = "Drinks";
        ostr <<"Reservation " << right << setw(10) << m_id <<": " 
            << right << setw(20) << m_name << "  " 
            << left << setw(20) << email << "    "<< activity 
            << " on day "<< m_day << " @ " << m_hour << ":00 for "
            << m_numberOfPeople << people << "." << std::endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Reservation& res){
        return res.display(ostr);
    }
}
