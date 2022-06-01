// Workshop: 6
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/14
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_
#include <string>
#include "Car.h"
namespace sdds
{
    class Racecar:public Car{
        double m_booster=0.0;
    public:
        Racecar();
        Racecar(std::istream& in);
        double topSpeed()const;
        void deleteSpaceBeginEnd(std::string& str);
        void display(std::ostream& out) const;
    };
    std::ostream& operator<<(std::ostream& out, const Racecar& racecar);
}
#endif