#ifndef GROUP_DAO_HPP
#define GROUP_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../exceptions/constraint_violation_exception.hpp"
#include "../exceptions/primary_key_violation_exception.hpp"
#include "../models/group.hpp"
#include "dao_interface.hpp"
#include "performer_dao.hpp"
#include <stdexcept>
#include <memory>

class GroupDao : public DaoInterface<Group> {
  std::shared_ptr<harmony_storage> storage;

  std::optional<Performer> getPerformerByID(int id_performer);
  bool existsPerformer(int id_performer);
public:
  GroupDao();
  ~GroupDao() = default;
  std::vector<Group> findAll() override;
  std::optional<Group> getByID(int id_group) override;
  int save(Group group) override;
  void deleteById(int id_group) override;
  void update(int id_group, Group group) override;
  bool exists(int id_group) override;
};

#endif