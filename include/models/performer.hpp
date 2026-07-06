#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include "../utils/string_utils.hpp"
#include <stdexcept>
#include <string>

class Performer {
  int id_performer;
  int id_type;
  std::string name;

public:
  Performer();

  int getIdPerformer() const;
  void setIdPerformer(int idPerformer_);

  int getIdType() const;
  void setIdType(int idType_);

  std::string getName() const;
  void setName(const std::string &name_);
};

#endif