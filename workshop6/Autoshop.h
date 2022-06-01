// Workshop: 6
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/14
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds
{
    class Autoshop{
        std::vector<Vehicle*> m_vehicles{};
    public:
        Autoshop();
        ~Autoshop();
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        template<typename T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for (unsigned int i = 0; i < m_vehicles.size(); i++) {
                if (test(m_vehicles[i]))
                    vehicles.push_back(m_vehicles[i]);
            }
        }
    };
    std::ostream& operator<<(std::ostream& out, const Autoshop& autoshop);
}
#endif