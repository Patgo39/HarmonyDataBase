#ifndef IN_GROUP_DAO_HPP
#define IN_GROUP_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../daos/group_dao.hpp"
#include "../daos/person_dao.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../exceptions/model_format_exception.hpp"
#include "../models/group.hpp"
#include "../models/in_group.hpp"
#include "../models/person.hpp"
#include <utility>

class InGroupDao {
  std::shared_ptr<harmony_storage> storage;

public:
  InGroupDao();

  std::vector<InGroup> findAll();
  std::vector<InGroup> getByIdPerson(int id_person);
  std::vector<InGroup> getByIdGroup(int id_group);
  std::optional<InGroup> getByCompositeID(int id_person, int id_group);
  std::pair<int, int> save(InGroup in_group);
  void deleteByIdPerson(int id_person);
  void deleteByIdGroup(int id_group);
  void deleteByCompositeId(int id_person, int id_group);
  void update(int id_person, int id_group, InGroup in_group);
  bool existsByIdPerson(int id_person);
  bool existsByIdGroup(int id_group);
  bool existsComposite(int id_person, int id_group);
};

#endif