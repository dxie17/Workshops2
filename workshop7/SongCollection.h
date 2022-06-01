// Workshop: 7
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/20
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_SONGCOLLECTION_H_
#define SDDS_SONGCOLLECTION_H_
#include <string>
#include <vector>
#include <list>
namespace sdds{

    struct Song
    {
        std::string m_artist{};
        std::string m_title{};
        std::string m_album{};
        double m_price=0.0;
        size_t m_year=0;
        size_t m_length=0;
    };

    class SongCollection{
        std::vector<Song> m_song{};
    public:
        SongCollection();
        SongCollection(const char* filename);
        void sort(const std::string&str);
        void cleanAlbum();
        bool inCollection(const std::string &artist) const;
        std::list<Song> getSongsForArtist(const std::string& artist) const;
        void deleteSpaceBeginEnd(std::string& str);
        void display(std::ostream& out) const;
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif