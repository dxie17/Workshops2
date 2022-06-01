// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include<string>
namespace sdds
{
    class Book
    {
        std::string m_author{};
        std::string m_title{};
        std::string m_countryOfPublication{};
        std::string m_description{};
        int m_yearOfPublication=0;
        double m_price{};
    public:
        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        };
        Book();
        Book(const std::string& strBook);
        const std::string& title() const;
        const std::string& country() const;
        size_t year() const;
        double& price();
        void deleteSpaceBeginEnd(std::string& str);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Book& b);
}
#endif