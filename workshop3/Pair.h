// Workshop: 3
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/10
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>
#include <iomanip>
namespace sdds
{
    template<typename V, typename K>
    class Pair
    {
        V m_value;
        K m_key;
    public:
        Pair();
        Pair(const K& key, const V& value);
        const V& value() const;
        const K& key() const;
        void display(std::ostream& os) const;
    };

    template<typename V, typename K>
    Pair<V,K>::Pair() {
        m_value = {};
        m_key = {};
    }

    template<typename V, typename K>
    Pair<V, K>::Pair(const K& key, const V& value) {
        m_key = key;
        m_value = value;
    }

    template<typename V, typename K>
    const V& Pair<V, K>::value() const {
        return m_value;
    }

    template<typename V, typename K>
    const K& Pair<V, K>::key() const {
        return m_key;
    }

    template<typename V, typename K>
    void Pair<V, K>::display(std::ostream& os) const {
        os  << this->key() << ": " << value() << std::endl;
    }
    
    template<typename V, typename K>
    std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
        pair.display(os);
        return os;
    }
}
#endif