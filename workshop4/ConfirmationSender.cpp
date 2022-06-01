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
#include "ConfirmationSender.h"
using namespace std;
namespace sdds
{
    ConfirmationSender::ConfirmationSender(){
        m_res =nullptr;
        m_numOfReservations = 0;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& c) :m_res{}, m_numOfReservations{ 0 } {
        if(this!=&c)
            *this = c;
    }

    ConfirmationSender::~ConfirmationSender(){
        delete[]m_res;
    }

    ConfirmationSender& ConfirmationSender::operator= (const ConfirmationSender& c) {
        if (this != &c) {
            delete[]m_res;
            m_numOfReservations = c.m_numOfReservations;
            m_res = new const Reservation*[m_numOfReservations];
            for (int i = 0; i < m_numOfReservations; i++)
                m_res[i] = c.m_res[i];
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& c)noexcept :m_res{}, m_numOfReservations{0}{
        if (this != &c) {
            *this = std::move(c);
            c.m_res = nullptr;
            c.m_numOfReservations = 0;
        }
    }

    //ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& c) noexcept {
    //    if (this != &c) {
    //        m_numOfReservations = c.m_numOfReservations;
    //        delete[]m_res;
    //        m_res = c.m_res;
    //        c.m_res = nullptr;
    //        c.m_numOfReservations = 0;
    //    }
    //    return *this;
    //}

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
        bool existIn=false;
        int exsitNullptr = -1;
        for (int i = 0; i < m_numOfReservations; i++) {
            if (m_res[i] == &res) existIn = true;
            if (m_res[i] == nullptr) exsitNullptr = i;
        }
        if (!existIn) {
            if (exsitNullptr > 0)m_res[exsitNullptr] = &res;
            else if (exsitNullptr < 0) {
                ConfirmationSender addOne;
                addOne.m_numOfReservations = m_numOfReservations + 1;
                addOne.m_res=new const Reservation * [addOne.m_numOfReservations];
                for (int i = 0; i < m_numOfReservations; i++)
                    addOne.m_res[i] = m_res[i];
                addOne.m_res[addOne.m_numOfReservations - 1] = &res;
                *this = addOne;
            }
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
        bool existIn = false;
        int position = -1;
        for (int i = 0; i < m_numOfReservations; i++) {
            if (m_res[i] == &res) {
                existIn = true;
                position = i;
            }
        }    
        if (existIn) {
            ConfirmationSender deductOne;
            deductOne.m_numOfReservations = m_numOfReservations - 1;
            deductOne.m_res = new const Reservation * [deductOne.m_numOfReservations];
            int i;
            for (i = 0; i < position; i++)
                deductOne.m_res[i] = m_res[i];
            for(i=position;i< deductOne.m_numOfReservations;i++)
                deductOne.m_res[i] = m_res[i+1];
            *this = std::move(deductOne);
        }
        return *this;
    }


    std::ostream& ConfirmationSender::display(std::ostream& ostr) const{

        ostr << "--------------------------" << std::endl;
        ostr << "Confirmations to Send" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (m_numOfReservations == 0)
            ostr << "There are no confirmations to send!" << std::endl;
        else if (m_numOfReservations > 0) {
            for (int i = 0; i < m_numOfReservations; i++)
                ostr << *m_res[i];
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& con){
        return con.display(ostr);
    }
}