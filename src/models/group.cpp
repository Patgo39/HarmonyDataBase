#include "../../include/models/group.hpp"

Group::Group() : id_group(0), name("Unknown") {
  std::string current = time_utils::get_current_date();
  start_date = current;
  end_date = current;
}

int Group::getIdGroup() const { return id_group; }

void Group::setIdGroup(int idGroup) {
  if (idGroup <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_group = idGroup;
}

std::string Group::getName() const { return name; }

void Group::setName(const std::string &name_) {
  if (str_utils::is_white_spaces(name_)) {
    name = "Unknown";
  } else {
    name = str_utils::delete_extreme_whitespaces(name_);
  }
}

std::string Group::getStartDate() const { return start_date; }

void Group::setStartDate(const std::string &startDate_) {
  if(!time_utils::is_date_string_valid(startDate_)){
    throw std::invalid_argument("Start date does not comply with the format {YYYY-MM-DD}");
  }
  start_date = startDate_;
}

std::string Group::getEndDate() const { return end_date; }

void Group::setEndDate(const std::string &endDate_) {
  if(!time_utils::is_date_string_valid(endDate_)){
    throw std::invalid_argument("Start date does not comply with the format {YYYY-MM-DD}");
  }
  end_date = endDate_;
}