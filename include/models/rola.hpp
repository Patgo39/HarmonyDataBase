#ifndef ROLA_HPP
#define ROLA_HPP

#include <string>
#include <optional>

class Rola {
public:
    int id_rola = 0;
    std::optional<int> id_performer;
    std::optional<int> id_album;
    std::optional<std::string> path;
    std::optional<std::string> title;
    std::optional<int> track;
    std::optional<int> year;
    std::optional<std::string> genre;

    Rola() = default;
    Rola(int _id_performer, int _id_album, std::string _path, std::string _title, int _track, int _year, std::string _genre);
    Rola(int _id_rola, int _id_performer, int _id_album, std::string _path, std::string _title, int _track, int _year, std::string _genre);
};

#endif