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
  Person(std::string, std::string, std::string, std::string);
  Person(int, std::string, std::string, std::string, std::string);
  
};

#endif
