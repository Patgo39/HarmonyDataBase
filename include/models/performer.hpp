#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include <string>
#include <optional>

class Performer {
public:
    int id_performer = 0;
    std::optional<int> id_type;
    std::optional<std::string> name;

    Performer() = default;
    Performer(int, std::string);
    Performer(int, int, std::string);
};

#endif