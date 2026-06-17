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
    Rola(int, int, std::string, std::string, int, int, std::string);
    Rola(int, int, int, std::string, std::string, int, int, std::string);
};

#endif