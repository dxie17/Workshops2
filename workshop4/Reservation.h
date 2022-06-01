// Workshop: 4
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/24
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_
#include<string>
namespace sdds
{
    class Reservation
    {
        std::string m_id;
        std::string m_name;
        std::string m_email;
        int m_numberOfPeople;
        int m_day;
        int m_hour;
        void setEmpty();
    public:
        
        Reservation();
        void update(int day, int time);
        Reservation& operator = (const Reservation& r);
        Reservation(const std::string& res);
        void deleteSpaceBeginEnd(std::string& str);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Reservation& res);
}
#endif