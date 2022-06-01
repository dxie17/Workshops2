// Workshop: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/09/25
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_
extern unsigned g_sysClock;

namespace sdds
{
    class Event
    {  
        char *m_description;
        unsigned int m_time;
        void setEmpty();
    public:
        Event();
        ~Event();
        Event(const Event &e);
        Event& operator =(const Event& e);
        void set(const char * p=nullptr);
        void display();
    };
}
#endif