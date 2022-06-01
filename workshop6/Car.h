// Workshop: 6
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/14
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <string>
#include "Vehicle.h"
namespace sdds{
    enum class Condition{
        newType,
        usedType,
        brokenType,
        none
    };
    enum class Tag{
        car,
        racecar,
        none
    };
    class Car:public Vehicle{
        Tag m_tag{ Tag::none};
        std::string m_maker{};
        Condition m_condition{Condition::none};
        double m_topSpeed=0.0;
        bool m_isValid = false;
    public:
        Car();
        Car(std::istream& in);
        bool isValid()const;
        void deleteSpaceBeginEnd(std::string& str);
        std::string maker() const;
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
    std::ostream& operator<<(std::ostream& out, const Car& car);
}
#endif