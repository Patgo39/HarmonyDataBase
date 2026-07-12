#include "../../include/daos/group_dao.hpp"

GroupDao::GroupDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::optional<Performer> GroupDao::getPerformerByID(int id_performer){
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  std::optional<Performer> performer = std::nullopt;

  if (performers.size() == 1) {
    performer = performers[0];
  }

  return performer;
}

bool GroupDao::existsPerformer(int id_performer){
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  return performers.size() == 1;
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
  int id = group.getIdGroup();
  if(!existsPerformer(id)){
    throw IdNotFoundException("The id for a group must be a valid id in performers table.");
  }

  if(exists(id)){
    std::string msg = std::format("There is an existing group with id = {}", id);
    throw PrimaryKeyViolationException(msg);
  }

  std::optional<Performer> p = getPerformerByID(id);
  if(p.value().getIntType() != 2){
    std::string message = std::format("You must set performer type = 2 in register {}" 
      " before creating a new register in the Group table.", id);
    throw ConstraintViolationException(message);
  }

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
