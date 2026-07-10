#include <string>
#include "string_utils.hpp"

enum class Type{
  PERSON = 1,
  GROUP = 2,
  UNKNOWN = 3
};

namespace type_operation{
  std::string get_type_as_string(Type t);
  Type get_type_from_string(std::string s);
}