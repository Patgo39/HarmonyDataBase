#include "../../include/models/performer.hpp"

Performer::Performer(int _id_type, std::string _name)
    : id_type(_id_type), name(std::move(_name)) {}

Performer::Performer(int _id_performer, int _id_type, std::string _name)
    : id_performer(_id_performer), id_type(_id_type), name(std::move(_name)) {}