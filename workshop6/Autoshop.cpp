// Workshop: 6
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/14
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
using namespace std;
namespace sdds
{

    Autoshop::Autoshop() {}

    Autoshop::~Autoshop(){
        for (unsigned int i = 0; i < m_vehicles.size(); i++)
            delete m_vehicles[i];
    }

    Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& out) const {
        out << "--------------------------------" << endl;
        out << "| Cars in the autoshop!        |" << endl;
        out << "--------------------------------" << endl;
        for (unsigned int i = 0; i < m_vehicles.size(); i++) {
            m_vehicles[i]->display(out);
            out << std::endl;
        } 
        out << "--------------------------------" << endl;
    }

    std::ostream& operator<<(std::ostream& out, const Autoshop& autoshop) {
        autoshop.display(out);
        return out;
    }
}