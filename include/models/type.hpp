#ifndef TYPE_HPP
#define TYPE_HPP

#include <optional>
#include <string>

class Type {
public:
  int id_type = 0;
  std::optional<std::string> description;

  Type() = default;
  Type(std::string _description);
  Type(int _id_type, std::string _description);
};

#endif