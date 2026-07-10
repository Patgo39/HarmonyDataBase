#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include "../utils/string_utils.hpp"
#include "../utils/type_enum.hpp"
#include <stdexcept>
#include <string>

class Performer {
  int id_performer;
  Type type;
  std::string name;

public:
  Performer();

  int getIdPerformer() const;
  void setIdPerformer(int idPerformer_);

  int getIntType() const;
  void setIntType(int type_);

  Type getType() const;

  std::string getName() const;
  void setName(const std::string &name_);
};

#endif