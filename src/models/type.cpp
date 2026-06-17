#include "../../include/models/type.hpp"

Type::Type(std::string _description): 
    description(std::move(_description)) {}

Type::Type(int _id_type, std::string _description): 
    id_type(_id_type), 
    description(std::move(_description)) {}