#include "../../include/models/person.hpp"

std::string Person::getCurrentDate() const {
  std::time_t now = std::time(nullptr);
  std::tm localTime = *std::localtime(&now);
  std::stringstream ss;
  ss << std::put_time(&localTime, "%Y-%m-%d");
  return ss.str();
}

void Person::validateDate(const std::string &date) const {
  static const std::regex date_pattern(
      R"(^([0-9]{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
  if (!std::regex_match(date, date_pattern)) {
    throw std::invalid_argument(
        "Year has an invalid format. Must be YYYY-MM-DD with valid month/day.");
  }
}

Person::Person() : id_person(0), stage_name("Unknown"), real_name("Unknown") {
  std::string current = getCurrentDate();
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
  stage_name = stageName_.empty() ? "Unknown" : stageName_;
}

std::string Person::getRealName() const { return real_name; }

void Person::setRealName(const std::string &realName_) {
  real_name = realName_.empty() ? "Unknown" : realName_;
}

std::string Person::getBirthDate() const { return birth_date; }

void Person::setBirthDate(const std::string &birthDate_) {
  validateDate(birthDate_);
  birth_date = birthDate_;
}

std::string Person::getDeathDate() const { return death_date; }

void Person::setDeathDate(const std::string &deathDate_) {
  validateDate(deathDate_);
  death_date = deathDate_;
}