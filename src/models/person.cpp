#include "../../include/models/person.hpp"

Person::Person(std::string _stage_name, std::string _real_name, std::string _birth_date, std::string _death_date): 
  stage_name(std::move(_stage_name)), 
  real_name(std::move(_real_name)), 
  birth_date(std::move(_birth_date)), 
  death_date(std::move(_death_date)) {}

Person::Person(int _id_person, std::string _stage_name, std::string _real_name, std::string _birth_date, std::string _death_date): 
  id_person(_id_person), 
  stage_name(std::move(_stage_name)), 
  real_name(std::move(_real_name)), 
  birth_date(std::move(_birth_date)), 
  death_date(std::move(_death_date)) {}

