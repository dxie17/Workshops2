// Workshop: 4
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/10/24
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Restaurant.h"
#include "Reservation.h"
using namespace std;
namespace sdds
{
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
        m_numOfReservations = cnt;
        m_res = new Reservation[cnt];
        for (unsigned int i = 0; i < cnt; i++) {
            m_res[i] = *reservations[i];
        }
    }

    Restaurant::Restaurant(const Restaurant& r){
        *this = r;
    }

    Restaurant& Restaurant::operator= (const Restaurant& r) {
        if (this != &r) {
            delete[]m_res;
            m_numOfReservations = r.size();
            m_res = new Reservation[m_numOfReservations];
            for (int i = 0; i < m_numOfReservations; ++i)
                m_res[i] = r.m_res[i];
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& r)noexcept {
        *this = r;
        r.m_res = nullptr;
        r.m_numOfReservations = 0;
    }


    Restaurant& Restaurant::operator=(Restaurant&& r) noexcept {
        if (this != &r) {
            m_numOfReservations = r.m_numOfReservations;
            delete[]m_res;
            m_res = r.m_res;
            r.m_res = nullptr;
            r.m_numOfReservations = 0;
        }
        return *this;
    }

    Restaurant::~Restaurant(){
        delete[] m_res;
    }

    size_t Restaurant::size() const{
        return m_numOfReservations;
    }
    std::ostream& Restaurant::display(std::ostream& ostr) const {
        static int call_cnt = 0;
        call_cnt++;
        ostr << "--------------------------" << std::endl;
        ostr << "Fancy Restaurant (" << call_cnt << ")" << std::endl;
        ostr << "--------------------------" << std::endl;
        if(m_numOfReservations==0)
            ostr << "This restaurant is empty!" << std::endl;
        else if (m_numOfReservations > 0) {
            for (int i = 0; i < m_numOfReservations; i++)
                ostr << m_res[i];
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Restaurant& r) {
        return r.display(ostr);
    }
}