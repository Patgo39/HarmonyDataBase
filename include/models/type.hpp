#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <optional>

class Type {
public:
    int id_type = 0;
    std::optional<std::string> description;

    Type() = default;
    Type(std::string);
    Type(int, std::string);
};

#endif