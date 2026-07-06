#include "../../include/models/person.hpp"


Person::Person() : 
  id_person(0), 
  stage_name("Unknown"), 
  real_name("Unknown") {
  std::string current = time_utils::get_current_date();
  birth_date = current;
  death_date = current;
}

int Person::getIdPerson() const { return id_person; }

void Person::setIdPerson(int idPerson_) {
  if (idPerson_ <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_person = idPerson_;
}

std::string Person::getStageName() const { return stage_name; }

void Person::setStageName(const std::string &stageName_) {
  if (str_utils::is_white_spaces(stageName_)) {
    stage_name = "Unknown";
  } else {
    stage_name = str_utils::delete_extreme_whitespaces(stageName_);
  }
}

std::string Person::getRealName() const { return real_name; }

void Person::setRealName(const std::string &realName_) {
  if (str_utils::is_white_spaces(realName_)) {
    real_name = "Unknown";
  } else {
    real_name = str_utils::delete_extreme_whitespaces(realName_);
  }
}

std::string Person::getBirthDate() const { return birth_date; }

void Person::setBirthDate(const std::string &birthDate_) {
  if(!time_utils::is_date_string_valid(birthDate_)){
    throw std::invalid_argument("Birth date does not comply with the format {YYYY-MM-DD}");
  }
  birth_date = birthDate_;
}

std::string Person::getDeathDate() const { return death_date; }

void Person::setDeathDate(const std::string &deathDate_) {
  if(!time_utils::is_date_string_valid(deathDate_)){
    throw std::invalid_argument("Death date does not comply with the format {YYYY-MM-DD}");
  }
  death_date = deathDate_;
}