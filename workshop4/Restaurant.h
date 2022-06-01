// Workshop: 4
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/24
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include "Reservation.h"
namespace sdds
{
    class Restaurant
    {
        Reservation* m_res=nullptr;
        int m_numOfReservations = 0;
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant&r);
        Restaurant(Restaurant&& r) noexcept;
        Restaurant& operator = (const Restaurant& r);
        Restaurant& operator = (Restaurant&& r) noexcept;
        ~Restaurant();
        size_t size() const;
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Restaurant& r);
}
#endif