#include "../../include/daos/group_dao.hpp"

GroupDao::GroupDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::vector<Group> GroupDao::findAll() {
  std::vector groups = storage->get_all<Group>();
  return groups;
}

std::optional<Group> GroupDao::getByID(int id_group) {
  std::vector<Group> groups = storage->get_all<Group>(
      sqlite_orm::where(sqlite_orm::eq(&Group::getIdGroup, id_group)));

  std::optional<Group> group = std::nullopt;

  if (groups.size() == 1) {
    group = groups[0];
  }

  return group;
}

int GroupDao::save(Group group) {
  int id_group = storage->insert(group);
  return id_group;
}

void GroupDao::deleteById(int id_group) {
  if (!exists(id_group)) {
    throw IdNotFoundException("Error: Non-existent Group to delete.");
  }

  storage->remove<Group>(id_group);
}

void GroupDao::update(int id_group, Group group) {
  if (!exists(id_group)) {
    throw IdNotFoundException("Error: Non-existent Group to delete.");
  }

  group.setIdGroup(id_group);
  storage->update(group);
}

bool GroupDao::exists(int id_group) {
  std::vector<Group> groups = storage->get_all<Group>(
      sqlite_orm::where(sqlite_orm::eq(&Group::getIdGroup, id_group)));

  return groups.size() == 1;
}
