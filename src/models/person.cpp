#include "../../include/models/person.hpp"

Person::Person(std::string _stage_name, std::string _real_name,
	       std::string _birth_date,std::string _death_date){

  stage_name = _stage_name;
  real_name = _real_name;
  birth_date = _birth_date;
  death_date = _death_date;
}

Person::Person(int _id_person, std::string _stage_name, std::string _real_name,
	       std::string _birth_date,std::string _death_date){

  id_person = _id_person;
  stage_name = _stage_name;
  real_name = _real_name;
  birth_date = _birth_date;
  death_date = _death_date;
}

