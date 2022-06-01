// Workshop: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/02
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "StringSet.h"
using namespace std;
namespace sdds
{
    StringSet::StringSet() {
        m_string = nullptr;
        m_number=0;
    }

    StringSet::StringSet(char* name) {
        m_string = nullptr;
        m_number = 0;
        ifstream fin(name);
        if(!fin.is_open()) cout << "Cannot open file [" << name<< "]"<<endl;
        else {
            string buffer="";
            while (getline(fin, buffer, ' ') && !fin.eof())m_number++;
            m_number++;
            fin.close();
            ifstream fin(name);
            if (!fin.is_open()) cout << "Cannot open file [" << name << "]" << endl;
            else {
                m_string = new string[m_number];
                for (unsigned int i = 0; i < m_number; i++)
                    getline(fin, m_string[i],' ');
                fin.close();
            }
        }
    }

    StringSet::~StringSet() {
        delete[]m_string;
    }

    StringSet::StringSet(const StringSet& s){
        m_string = nullptr;
        *this = s;
    }

    StringSet& StringSet::operator=(const StringSet& s){
        if (this != &s) {
            m_number = s.m_number;
            if (s.m_string != nullptr) {
                delete[]m_string;
                m_string = new string[m_number];
                for (unsigned int i = 0; i < m_number; i++)
                    m_string[i] = s.m_string[i];
            }
        }
        return *this;
    }

    StringSet::StringSet(StringSet&& s) noexcept :m_string{} {
        m_number = 0;
       // m_string = nullptr;
        m_number = s.m_number;
       // m_string=s.m_string;
        s.m_string = nullptr;
       /* *this = std::move(s);*/
    }

    StringSet& StringSet::operator=(StringSet&& s) noexcept {
        if (this != &s) {
            m_number = s.m_number;
            delete[]m_string;
            m_string = s.m_string;
            s.m_string = nullptr;
        }
        return *this;
    }

    auto StringSet::size() {
        return m_number;
    }

    std::string StringSet::operator[](size_t i) {
        string returnStr = "";
        if (i >= 0 && i <= m_number && m_string!=nullptr) returnStr = m_string[i];
        return returnStr;
    }
}