#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <optional>

class Person{

public:
  int id_person = 0;
  std::optional<std::string> stage_name;
  std::optional<std::string> real_name;
  std::optional<std::string> birth_date;
  std::optional<std::string> death_date;
  
  Person() = default;
  Person(std::string _stage_name, std::string _real_name, std::string _birth_date, std::string _death_date);
  Person(int _id_person, std::string _stage_name, std::string _real_name, std::string _birth_date, std::string _death_date);
  
};

#endif
