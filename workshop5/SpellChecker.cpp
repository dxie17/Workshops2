// Workshop: 5
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/6
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"
using namespace std;
namespace sdds
{

    SpellChecker::SpellChecker() {}

    SpellChecker::SpellChecker(const char* filename) {
        fstream fin(filename);
        if (!fin) 
            throw "Bad file name!";   
        else {
            int cnt = 0;
            while (fin >> m_badwords[cnt] && fin >> m_goodwords[cnt])
                cnt++;
            fin.close();
        }
    }
    void SpellChecker::operator()(std::string& text){
        if (text != "") {
            for (int i = 0; i < 6; i++) {
                string::size_type position=-1;
                do {
                    position = text.find(m_badwords[i]);
                    if (position != text.npos) {
                        text.replace(position,m_badwords[i].length(), m_goodwords[i]);
                        m_cnt[i]++;
                    }
                } while (position != text.npos);
            }
        }
    }
        
    void SpellChecker::showStatistics(std::ostream& out) const{
        out << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < 6; i++)
            out << right << setw(15) << m_badwords[i] 
            <<": "<< m_cnt[i]<<" replacements" << endl;
    }
}