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
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds{
    Vehicle* createInstance(std::istream& in){
        std::string oneLine = "";
        Vehicle* ret = nullptr;
        if (std::getline(in, oneLine)) {
            int posNotBlank = oneLine.find_first_not_of(" ");
            std::stringstream ss;
            ss.str(oneLine);
            if (oneLine[posNotBlank] == 'c' || oneLine[posNotBlank] == 'C')
                ret = new Car(ss);
            else if (oneLine[posNotBlank] == 'r' || oneLine[posNotBlank] == 'R')
                ret = new Racecar(ss);
            else throw oneLine[posNotBlank];
        }
        return ret;
    }
}