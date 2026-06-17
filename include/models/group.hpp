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
    Group(std::string _name, std::string _start_date, std::string _end_date);
    Group(int _id_group, std::string _name, std::string _start_date, std::string _end_date);
};

#endif