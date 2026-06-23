#ifndef ROLA_HPP
#define ROLA_HPP

#include <string>
#include <stdexcept>
#include <chrono>
#include <ctime>

class Rola {
    int id_rola;
    int id_performer;
    int id_album;
    std::string path;
    std::string title;
    int track;
    int year;
    std::string genre;

    int getCurrentYear() const;

public:
    Rola();

    int getIdRola() const;
    void setIdRola(int idRola_);

    int getIdPerformer() const;
    void setIdPerformer(int idPerformer_);

    int getIdAlbum() const;
    void setIdAlbum(int idAlbum_);

    std::string getPath() const;
    void setPath(const std::string &path_);

    std::string getTitle() const;
    void setTitle(const std::string &title_);

    int getTrack() const;
    void setTrack(int track_);

    int getYear() const;
    void setYear(int year_);

    std::string getGenre() const;
    void setGenre(const std::string &genre_);
};

#endif