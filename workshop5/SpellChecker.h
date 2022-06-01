// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include<string>
namespace sdds
{
    class SpellChecker
    {
        std::string m_badwords[6]{};
        std::string m_goodwords[6]{};
        unsigned int m_cnt[6]{};
    public:
        SpellChecker();
        SpellChecker(const char *filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif