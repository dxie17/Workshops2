// Workshop: 4
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/24
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include "Reservation.h"
namespace sdds
{
    class ConfirmationSender
    {
        const sdds::Reservation**m_res;
        int m_numOfReservations;
    public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& c);
        ConfirmationSender(ConfirmationSender&& c) noexcept;
        ConfirmationSender& operator = (const ConfirmationSender& c);
      /*  ConfirmationSender& operator = (ConfirmationSender&& c) noexcept;*/
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& con);
}
#endif