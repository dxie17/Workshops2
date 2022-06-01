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
#include "Racecar.h"
using namespace std;
namespace sdds
{

    Racecar::Racecar() {}

    Racecar::Racecar(std::istream& in):Car(in){
        std::string temp = "";
        std::getline(in, temp);
        m_booster= std::stod(temp.c_str());
    }

    double Racecar::topSpeed() const{
        return this->Car::topSpeed() * (1 + m_booster);
    }

    void Racecar::deleteSpaceBeginEnd(std::string& str) {
        if (str != "") {
            if (str.find_first_not_of(" ") != string::npos) {
                int posBegin = str.find_first_not_of(" ");
                int posEnd = str.find_last_not_of(" ");
                str = str.substr(posBegin, posEnd - posBegin + 1);
            }
            else str = "";
        }
    }

    void Racecar::display(std::ostream& out) const {
        out << "| " << right << setw(10) << this->maker() << " | "
            << left << setw(6) << condition() << " | "
            << right << setw(6) << fixed << setprecision(2) << Racecar::topSpeed() << " |*";
    }

    std::ostream& operator<<(std::ostream& out, const Racecar& racecar) {
         racecar.display(out);
         return out;
    }
}