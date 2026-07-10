#ifndef PERFORMER_DAO_HPP
#define PERFORMER_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../exceptions/id_not_found_exception.hpp"
#include "../exceptions/constraint_violation_exception.hpp"
#include "../db/database_conection_manager.hpp"
#include "../models/performer.hpp"
#include "dao_interface.hpp"
#include <stdexcept>

class PerformerDao : public DaoInterface<Performer> {
  std::shared_ptr<harmony_storage> storage;

  bool existsPerson(int id_person);
  bool existsGroup(int id_group);
public:
  PerformerDao();
  ~PerformerDao() = default;
  std::vector<Performer> findAll() override;
  std::optional<Performer> getByID(int id_performer) override;
  int save(Performer performer) override;
  void deleteById(int id_performer) override;
  void update(int id_performer, Performer performer) override;
  bool exists(int id_performer) override;
};

#endif