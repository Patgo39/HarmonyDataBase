#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include <optional>

class Album{
    public:
    int id_album = 0;
    std::optional<std::string> path;
    std::optional<std::string> name;
    std::optional<int> year;

    Album() = default;
    Album(std::string _path, std::string _name, int _year);
    Album(int _id_album, std::string _path, std::string _name, int _year);
};

#endif