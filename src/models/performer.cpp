#include "../../include/models/performer.hpp"

Performer::Performer() : id_performer(0), id_type(3), name("Unknown") {}

int Performer::getIdPerformer() const { return id_performer; }

void Performer::setIdPerformer(int idPerformer_) {
  if (idPerformer_ <= 0)
    throw std::invalid_argument("Id can't be zero or negative.");
  id_performer = idPerformer_;
}

int Performer::getIdType() const { return id_type; }

void Performer::setIdType(int idType_) {
  if (idType_ <= 0)
    throw std::invalid_argument("Id can't be zero or negative.");
  id_type = idType_;
}

std::string Performer::getName() const { return name; }

void Performer::setName(const std::string &name_) {
  name = name_.empty() ? "Unknown" : name_;
}