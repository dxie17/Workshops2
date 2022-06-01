// Workshop: 3
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/10
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
namespace sdds
{
    template<const size_t N, typename T>
    class Set
    {
        T m_data[N]{};
        size_t m_size{};
    public:
        Set();
        size_t size() const;
        const T& get(size_t idx) const;
        void operator+=(const T& item);
    };

    template<const size_t N, typename T>
    Set<N, T>::Set()  {
        m_size = 0;
    }

    template<const size_t N, typename T>
    size_t Set<N,T>::size() const {
        return m_size;
    }

    template<const size_t N, typename T>
    const T& Set<N, T>::get(size_t idx) const{
        return m_data[idx];
    }

    template<const size_t N, typename T>
    void Set<N, T>::operator+=(const T& item){
        if (m_size < N) {
            m_data[m_size] = item;
            m_size++;
        }
    }
}
#endif