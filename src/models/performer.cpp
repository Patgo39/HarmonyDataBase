#include "../../include/models/performer.hpp"

Performer::Performer() : id_performer(0), type(Type::UNKNOWN), name("Unknown") {}

int Performer::getIdPerformer() const { return id_performer; }

void Performer::setIdPerformer(int idPerformer_) {
  if (idPerformer_ <= 0)
    throw std::invalid_argument("Id can't be zero or negative.");
  id_performer = idPerformer_;
}

int Performer::getIntType() const{ return static_cast<int>(type);}
Type Performer::getType() const {return type;}
void Performer::setIntType(int type_){
  if(type_ < 1 || type_ > 3){
    throw std::invalid_argument("Valid Type values are: 1:PERSON, 2:GROUP, 3:UNKNOWN");
  }

  switch (type_)
  {
  case 1:
    type = Type::PERSON;
    break;
  case 2:
    type = Type::GROUP;
    break;
  default:
    type = Type::UNKNOWN;
  }
}

std::string Performer::getName() const { return name; }

void Performer::setName(const std::string &name_) {
  if (str_utils::is_white_spaces(name_)) {
    name = "Unknown";
  } else {
    name = str_utils::apply_name_format_to_string(name_);
  }
}