// Workshop: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/02
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_
#include <chrono>
#include <string>
namespace sdds{
    struct Event{
        std::string m_name="";
        std::string m_unitOfTime="";
        std::chrono::steady_clock::duration m_duration{};
    };

    class TimedEvents{
        unsigned int m_number;
        Event m_event[10]{};
        std::chrono::steady_clock::time_point m_startTime{};
        std::chrono::steady_clock::time_point m_endTime{};
    public:
        TimedEvents();
        void startClock();
        void addEvent(std::string name);
        void stopClock();
        friend std::ostream& operator <<(std::ostream& cout, const TimedEvents&t);
    };
}
#endif