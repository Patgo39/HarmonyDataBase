#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include <chrono>
#include <stdexcept>

class Album{
    int id_album;
    std::string path;
    std::string name;
    int year;

    public:
    Album();

    int getIdAlbum() const;
    void setIdAlbum(int idAlbum);

    std::string getPath() const;
    void setPath(const std::string &path_);

    std::string getName() const;
    void setName(const std::string &name_);

    int getYear() const;
    void setYear(int year_);

    
    

};

#endif  