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
#include <chrono>
#include"TimedEvents.h"
using namespace std;
namespace sdds
{
    TimedEvents::TimedEvents(){
        m_number=0;
    }

    void TimedEvents::startClock(){
        m_startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(std::string name){
        m_event[m_number].m_name = name;
        m_event[m_number].m_unitOfTime = "nanoseconds";
        m_event[m_number].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
        m_number++;
    }

    void TimedEvents::stopClock(){
        m_endTime = std::chrono::steady_clock::now();
    }

    std::ostream& operator <<(std::ostream& cout, const TimedEvents& t) {
        cout << "--------------------------" << std::endl;
        cout << "Execution Times:" << std::endl;
        cout << "--------------------------" << std::endl;
        for (unsigned int i = 0; i < t.m_number; i++)
            cout << setw(21) << setfill(' ') <<std::left<< t.m_event[i].m_name <<" " 
            << setw(13) << setfill(' ') << std::right << t.m_event[i].m_duration.count() << " " 
            << t.m_event[i].m_unitOfTime << endl;
        cout << "--------------------------" << std::endl;
        return cout;
    }
}