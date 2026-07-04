#ifndef PERSON_HPP
#define PERSON_HPP

#include <ctime>
#include <iomanip>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

class Person {
  int id_person;
  std::string stage_name;
  std::string real_name;
  std::string birth_date;
  std::string death_date;

  void validateDate(const std::string &date) const;
  std::string getCurrentDate() const;

public:
  Person();

  int getIdPerson() const;
  void setIdPerson(int idPerson_);

  std::string getStageName() const;
  void setStageName(const std::string &stageName_);

  std::string getRealName() const;
  void setRealName(const std::string &realName_);

  std::string getBirthDate() const;
  void setBirthDate(const std::string &birthDate_);

  std::string getDeathDate() const;
  void setDeathDate(const std::string &deathDate_);
};

#endif