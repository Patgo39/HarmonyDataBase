#ifndef PERSON_DAO_HPP
#define PERSON_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../exceptions/constraint_violation_exception.hpp"
#include "../exceptions/primary_key_violation_exception.hpp"
#include "../models/person.hpp"
#include "dao_interface.hpp"
#include <stdexcept>
#include <memory>

class PersonDao : public DaoInterface<Person> {
  std::shared_ptr<harmony_storage> storage;

  std::optional<Performer> getPerformerByID(int id_performer);
  bool existsPerformer(int id_performer);
public:
  PersonDao();
  ~PersonDao() = default;
  std::vector<Person> findAll() override;
  std::optional<Person> getByID(int id_person) override;
  int save(Person person) override;
  void deleteById(int id_person) override;
  void update(int id_person, Person person) override;
  bool exists(int id_person) override;
};

#endif