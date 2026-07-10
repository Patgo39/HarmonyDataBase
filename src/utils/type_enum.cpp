#include "../../include/utils/type_enum.hpp"

namespace type_operation{
  std::string get_type_as_string(Type t){
    std::string type_string = "";
    switch (t)
    {
    case Type::PERSON:
      type_string = "Person";
      break;
    case Type::GROUP:
      type_string = "Group";
      break;
    default:
      type_string = "Unknown";
    }
    return type_string;
  }

  Type get_type_from_string(std::string s){
    str_utils::convert_string_to_lowercase(s);
    Type t;
    if(s == "person"){
      t = Type::PERSON;
    }else if(s == "group"){
      t = Type::GROUP;
    }else{
      t = Type::UNKNOWN;
    }
    return t;
  }
}