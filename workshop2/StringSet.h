// Workshop: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/02
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_STRINGSET_H_
#define SDDS_STRINGSET_H_
#include<string>
namespace sdds
{
    class StringSet
    {
        std::string *m_string;
        unsigned int m_number;
    public:
        StringSet();
        StringSet(char *name);
        ~StringSet();
        StringSet(const StringSet& s);
        StringSet& operator=(const StringSet& s);
        StringSet(StringSet&& s) noexcept;
        StringSet& operator=(StringSet&& s) noexcept;
        auto size();
        std::string operator[](size_t i);
    };
}
#endif