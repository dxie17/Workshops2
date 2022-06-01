// Workshop: 7
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/20
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include "SongCollection.h"
using namespace std;
namespace sdds
{
    SongCollection::SongCollection() {}

    SongCollection::SongCollection(const char* filename){
       
        fstream fin(filename);
        if (!fin)
            throw string("Can't open the file [") + filename + "]";
        else {
            while(!fin.eof()){
                Song song;
                char temp[26]{};
                size_t cnt = 1;
                while (cnt < 4) {
                    temp[0] = '\0';
                    fin.read(temp, 25);
                    string str = temp;
                    deleteSpaceBeginEnd(str);
                    switch (cnt) {
                    case 1:
                        song.m_title = str;
                        break;
                    case 2:
                        song.m_artist = str;
                        break;
                    case 3:
                        song.m_album = str;
                        break;
                    }
                    cnt++;
                }

                temp[0] = '\0';
                fin.read(temp, 5);
                song.m_year = atoi(temp);
                
                temp[0] = '\0';
                fin.read(temp, 5);
                song.m_length = atoi(temp);
                
                temp[0] = '\0';
                fin.read(temp, 5);
                song.m_price = atof(temp);

                m_song.push_back(song);

                fin.ignore(1000, '\n');
            }
            fin.close();
        }   
    }
   
    void SongCollection::sort(const std::string& str){
        auto compare = [=](const Song&s1,const Song &s2) {
            return (str == "title" && s1.m_title < s2.m_title)
                || (str == "album" && s1.m_album < s2.m_album)
                || (str == "length" && s1.m_length < s2.m_length);
        };
        std::sort(m_song.begin(), m_song.end(), compare);
    }

    void SongCollection::cleanAlbum(){
        for (Song& song : m_song) {
            if(song.m_album=="[None]")
                song.m_album = "";
        }
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const{
        std::list<Song> songsOfArtist{};
        for (const Song& song : m_song) {
            if (song.m_artist == artist)
                songsOfArtist.push_back(song);
        }
        return songsOfArtist;
    }

    bool SongCollection::inCollection(const std::string& artist) const{
        bool exist = false;
        for (const Song& song : m_song) {
            if (song.m_artist == artist) {
                exist = true;
            }     
        }
        return exist;
    }

    void SongCollection::deleteSpaceBeginEnd(std::string& str) {
        if (str != "") {
            if (str.find_first_not_of(" ") != string::npos) {
                int posBegin = str.find_first_not_of(" ");
                int posEnd = str.find_last_not_of(" ");
                str = str.substr(posBegin, posEnd - posBegin + 1);
            }
            else str = "";
        }
    }

    void SongCollection::display(std::ostream& out) const {
        size_t total = 0, hour = 0, minute = 0, second = 0;
        for (const Song& song : m_song) {
            out << song<<endl;
            total += song.m_length;
        }
        hour = (total-total % 3600)/3600;
        second = total%3600%60;
        minute = (total % 3600 - second) / 60;
        out << setw(89) << setfill('-') << '\n' << setfill(' ');
        out << "| " << right << setw(77) << "Total Listening Time: " 
            << hour<<":"<<minute <<":"<<second<< " |\n";
            
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        size_t minute = 0, second = 0;
        second = theSong.m_length % 60;
        minute = (theSong.m_length - second) / 60;
        out << "| "<< left << setw(20) << theSong.m_title
            << " | " << left << setw(15) << theSong.m_artist
            << " | " << left << setw(20) << theSong.m_album
            << " | " << right << setw(6) << (theSong.m_year? std::to_string(theSong.m_year) : "")
            << " | " << minute << ":" <<setfill('0')<<setw(2)<< second<<setfill(' ')
            << " | " << theSong.m_price <<right<< " |";
        return out;
    }
}