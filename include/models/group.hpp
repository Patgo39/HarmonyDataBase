#ifndef GROUP_HPP
#define GROUP_HPP

#include <string>
#include <optional>

class Group {
public:
    int id_group = 0;
    std::optional<std::string> name;
    std::optional<std::string> start_date;
    std::optional<std::string> end_date;

    Group() = default;
    Group(std::string, std::string, std::string);
    Group(int, std::string, std::string, std::string);
};

#endif