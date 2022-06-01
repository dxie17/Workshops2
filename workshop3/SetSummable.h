// Workshop: 3
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/10
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
#include <string>
#include "Set.h"
namespace sdds
{
    template<const size_t N, typename T>
    class SetSummable : public Set<N, T>
    {
    public:

        T accumulate(const std::string& filter)const;
    };

    template<const size_t N, typename T>
    T SetSummable<N, T>::accumulate(const std::string& filter) const {
        T temp(filter);
        for (unsigned int i = 0; i < this->size(); i++) {
            if (this->get(i).isCompatibleWith(temp))
                temp += this->get(i);
        }
        return temp;
    }
}
#endif