// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include<string>
namespace sdds
{
    class Movie
    {
        std::string m_title{};
        std::string m_description{};
        int m_yearOfRelease{};
    public:
        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        };
        Movie();
        Movie(const std::string& strMovie);
        const std::string& title() const;
        void deleteSpaceBeginEnd(std::string& str);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Movie& m);
}
#endif