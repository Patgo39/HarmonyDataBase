#ifndef GROUP_DAO_HPP
#define GROUP_DAO_HPP

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/group.hpp"
#include "dao_interface.hpp"

class GroupDao : public DaoInterface<Group> {
  std::shared_ptr<harmony_storage> storage;

public:
  GroupDao();

  std::vector<Group> findAll() override;
  std::optional<Group> getByID(int id_group) override;
  int save(Group group) override;
  void deleteById(int id_group) override;
  void update(int id_group, Group group) override;
  bool exists(int id_group) override;
};

#endif