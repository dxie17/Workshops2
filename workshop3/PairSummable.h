// Workshop: 3
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/10
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_PAIRSUMMABLE_H_
#define SDDS_PAIRSUMMABLE_H_
#include <string>
#include "Pair.h"
namespace sdds
{
    template<typename V, typename K>
    class PairSummable : public Pair<V, K>
    {
        static size_t m_minWidth;
        static V m_initial;
    public:
        PairSummable() {};
        PairSummable(const K& key, const V& value = m_initial);
        bool isCompatibleWith(const PairSummable<V, K>& b) const;
        PairSummable<V, K>& operator+=(const PairSummable<V, K>& p);
        void display(std::ostream& os) const;
    };

    template<typename V, typename K>
    V  PairSummable<V, K>::m_initial = {};

    template<typename V, typename K>
    size_t PairSummable<V, K>::m_minWidth = {};

    template<typename V, typename K>
    PairSummable<V, K>::PairSummable(const K& key, const V& value) :Pair<V, K>(key, value) {
        if (key.size() > m_minWidth)
            m_minWidth = key.size();
    }

    template<typename V, typename K>
    bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const {
        return this->key() == b.key();
    }

    template<>
    PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator +=
        (const PairSummable<std::string, std::string>& p) {
            if (this->value() == "" ) 
                *this = PairSummable<std::string, std::string>(this->key(), p.value());
            else 
                *this = PairSummable<std::string, std::string>(this->key(), this->value() + ", " +p.value());
        return *this;
    }

    template<typename V, typename K >
    PairSummable<V, K>& PairSummable<V, K>::operator +=(const PairSummable<V, K>& p) {
        *this = PairSummable<V, K>(this->key(), this->value() + p.value());
        return *this;
    }

    template<typename V, typename K>
    void PairSummable<V, K>::display(std::ostream& os) const {
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(m_minWidth+1);
        Pair<V, K>::display(os);
        os.unsetf(std::ios::left);
        os.setf(std::ios::right);
    }

    template<typename V, typename K>
    std::ostream& operator<<(std::ostream& os, const PairSummable<V, K>& pair) {
        pair.PairSummable<V, K>::display(os);
        return os;
    }
}
#endif