// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include<string>
#include<stdexcept>

namespace sdds
{
    template<typename T>
    class Collection
    {
        std::string m_name{};
        T* m_type = nullptr;
        unsigned int m_size = 0;
        void (*m_observer)(const Collection<T>& ct, const T& t) {};
    public:
        Collection();
        ~Collection();
        Collection(const std::string& name);
        const std::string& name() const;
        size_t size() const;
        void setObserver(void (*observer)(const Collection<T>&ct, const T&t));
        Collection<T> & operator+=(const T& item);
        T& operator[](size_t idx) const;
        T* operator[](const std::string& title) const;
        std::ostream& display(std::ostream& ostr) const;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& ostr, const Collection<T>& ct) {
        return ct.display(ostr);
    }

    template<typename T>
    Collection<T>::Collection() {}

    template<typename T>
    Collection<T>::~Collection() {
        delete[] m_type;
    }

    template<typename T>
    Collection<T>::Collection(const std::string& name) {
        m_name = name;
    }

    template<typename T>
    const std::string& Collection<T>::name() const {
        return m_name;
    }

    template<typename T>
    inline size_t Collection<T>::size() const {
        return m_size;
    }

    template<typename T>
    void Collection<T>::setObserver(void (*observer)(const Collection<T>& ct, const T& t)) {
        m_observer = observer;
    }

    template<typename T>
    inline Collection<T>& Collection<T>::operator+=(const T& item) {
        bool exist = false;
        for (unsigned int i = 0; i < m_size; i++) {
            if (m_type[i].title() == item.title()) exist = true;
        }
        if (!exist) {
            m_size++;
            T* m_newType=nullptr;
            m_newType= new T[m_size];
            for (unsigned int i = 0; i < m_size - 1; i++)
                m_newType[i] = m_type[i];
            m_newType[m_size - 1] = item;
            delete[]m_type;
            m_type = std::move(m_newType);
            if (m_observer) m_observer(*this, item);
        }
        return *this;
    }

    template<typename T>
    T& Collection<T>::operator[](size_t idx) const {
        if (idx >= m_size || idx < 0){
            std::string str = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
            std::out_of_range exc(str);
            throw exc;
        }   
        else return m_type[idx];
    }
    
    template<typename T>
    T* Collection<T>::operator[](const std::string& title) const {
        T* p = nullptr;
        unsigned int i;
        for (i = 0; i < m_size && m_type[i].title() != title; i++);
        if (i >= 0 && i < m_size)
            p = &m_type[i];
        return p;
    }

    template<typename T>
    std::ostream& Collection<T>::display(std::ostream& ostr) const {
        for (unsigned int i = 0; i < m_size; i++)
            ostr << m_type[i];
        return ostr;
    }
}
#endif