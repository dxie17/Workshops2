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
#include <sstream>
#include "Car.h"
using namespace std;
namespace sdds
{
    Car::Car() {}

    Car::Car(std::istream& in):Vehicle() {
        std::string temp = "";
        std::getline(in,temp,'\n');
        if (temp != "") {
            string tag = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);
            deleteSpaceBeginEnd(tag);
            if (tag.length() == 1) {
                if (tag[0] == 'c' || tag[0] == 'C')
                    m_tag = Tag::car;
                else if (tag[0] == 'r' || tag[0] == 'R')
                    m_tag = Tag::racecar;
            }
            m_maker = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);
            deleteSpaceBeginEnd(m_maker);
            string condition = temp.substr(0, temp.find_first_of(","));
            temp = temp.erase(0, temp.find_first_of(",") + 1);
            deleteSpaceBeginEnd(condition);
            if (condition.length() == 0)
                m_condition = Condition::newType;
            else if (condition.length() == 1) {
                if (condition[0] == 'n' || condition[0] == 'N')
                    m_condition = Condition::newType;
                else if (condition[0] == 'u' || condition[0] == 'U')
                    m_condition = Condition::usedType;
                else if (condition[0] == 'b' || condition[0] == 'B')
                    m_condition = Condition::brokenType;
                
            }

            if (temp.find_first_of(",") == string::npos){
                deleteSpaceBeginEnd(temp);
                if(temp.find_first_not_of("0123456789+-.")== string::npos)
                    m_topSpeed = std::stod(temp.c_str());
            }
                
            else {
                string topSpeed= temp.substr(0, temp.find_first_of(","));
                deleteSpaceBeginEnd(topSpeed);
                if (topSpeed.find_first_not_of("0123456789+-.") == string::npos)
                    m_topSpeed = std::stod(topSpeed.c_str());
                
                temp = temp.erase(0, temp.find_first_of(",") + 1);
                in.clear();
                int offset = temp.length();
                in.seekg(-offset,ios::end);
            }  
        }
        if (m_tag != Tag::none && m_maker != ""
            && m_condition != Condition::none
            && m_topSpeed > 0.0) {
            m_isValid = true;
        }
        else throw "Invalid record!";
    }

    bool Car::isValid() const{
        return m_isValid;
    }

    void Car::deleteSpaceBeginEnd(std::string& str) {
        if (str != "") {
            if (str.find_first_not_of(" ") != string::npos) {
                int posBegin = str.find_first_not_of(" ");
                int posEnd = str.find_last_not_of(" ");
                str = str.substr(posBegin, posEnd - posBegin + 1);
            }
            else str = "";
        }
    }

    std::string Car::maker() const{
        return m_maker;
    }

    std::string Car::condition() const{
        string ret = "";
        switch (m_condition) {
            case Condition::newType:
                ret = "new";
                break;
            case Condition::brokenType:
                ret = "broken";
                break;
            case Condition::usedType:
                ret = "used";
                break;
            default:
                ret = "none";
                break;
        }
        return ret;
    }

    double Car::topSpeed() const{
        return m_topSpeed;
    }

    void Car::display(std::ostream& out) const {
        out << "| " << right << setw(10) << maker()<<" | " 
            << left << setw(6) << condition() << " | "
            << right << setw(6) << fixed <<setprecision(2)<< topSpeed() <<" |";
    }

    std::ostream& operator<<(std::ostream& out, const Car& car) {
        car.display(out);
        return out;
    }
}