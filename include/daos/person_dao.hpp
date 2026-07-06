#ifndef PERSON_DAO_HPP
#define PERSON_DAO_HPP

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/person.hpp"
#include "dao_interface.hpp"

class PersonDao : public DaoInterface<Person> {
  std::shared_ptr<harmony_storage> storage;

public:
  PersonDao();

  std::vector<Person> findAll() override;
  std::optional<Person> getByID(int id_person) override;
  int save(Person person) override;
  void deleteById(int id_person) override;
  void update(int id_person, Person person) override;
  bool exists(int id_person) override;
};

#endif