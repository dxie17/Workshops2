// Workshop: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/09/25
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include"event.h"
using namespace std;
unsigned int g_sysClock = 0;

namespace sdds
{
    void Event::setEmpty(){
        m_time = 0;
        m_description=nullptr;
    }

    Event::Event() {
        setEmpty();
    }

    Event::Event(const Event& e){
        setEmpty();
        m_time = e.m_time;
        if (e.m_description != nullptr) {
            m_description = new char[strlen(e.m_description) + 1];
            strcpy(m_description, e.m_description);
        }
    }

    Event::~Event(){
        delete[] m_description;
    }

    Event& Event::operator=(const Event& e){
        if (this != &e) {
            m_time = e.m_time;
            if (e.m_description != nullptr) {
                delete[]m_description;
                m_description = new char[strlen(e.m_description) + 1];
                strcpy(m_description, e.m_description);
            }
        }
        return *this;
    }

    void Event::set(const char* p){     
        if (p != nullptr) {
            delete[]m_description;
            m_description = new char[strlen(p) + 1];
            strcpy(m_description, p);
            m_time = g_sysClock;
        }
        else  m_description[0] = '\0';
    }

    void Event::display(){
        static unsigned int counter=0;
        counter++;
        int hour = 0, minute = 0,second=0;
        hour = m_time / 3600;
        minute = (m_time - hour * 3600) / 60;
        second = m_time - hour * 3600 - minute * 60;
        if(m_description[0]=='\0')
            std::cout<< setw(2) << setfill(' ') << counter << ". | No Event |" << std::endl;
        else
            std::cout << setw(2) << setfill(' ') << counter  << ". " <<setw(2)<<setfill('0')<<hour<<":"
            << setw(2) << setfill('0') << minute<<":" << setw(2) << setfill('0') << second 
            << " => " << m_description << std::endl;
    }
}