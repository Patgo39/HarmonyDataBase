#include "../../include/models/group.hpp"

Group::Group(std::string _name, std::string _start_date, std::string _end_date): 
    name(std::move(_name)), 
    start_date(std::move(_start_date)), 
    end_date(std::move(_end_date)) {}

Group::Group(int _id_group, std::string _name, std::string _start_date, std::string _end_date): 
    id_group(_id_group), 
    name(std::move(_name)), 
    start_date(std::move(_start_date)), 
    end_date(std::move(_end_date)) {}