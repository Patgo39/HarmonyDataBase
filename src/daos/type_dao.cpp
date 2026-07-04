#include "../../include/daos/type_dao.hpp"

TypeDao::TypeDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::vector<Type> TypeDao::findAll() {
  std::vector types = storage->get_all<Type>();
  return types;
}

std::optional<Type> TypeDao::getByID(int id_type) {
  std::vector<Type> types = storage->get_all<Type>(
      sqlite_orm::where(sqlite_orm::eq(&Type::id_type, id_type)));

  std::optional<Type> type = std::nullopt;

  if (types.size() == 1) {
    type = types[0];
  }

  return type;
}

int TypeDao::save(Type type) {
  int id_type = storage->insert(type);
  return id_type;
}

void TypeDao::deleteById(int id_type) {
  if (!exists(id_type)) {
    throw IdNotFoundException("Error: Non-existent Type to delete.");
  }

  storage->remove<Type>(id_type);
}

void TypeDao::update(int id_type, Type type) {
  if (!exists(id_type)) {
    throw IdNotFoundException("Error: Non-existent Type to update.");
  }

  type.id_type = id_type;
  storage->update(type);
}

bool TypeDao::exists(int id_type) {
  std::vector<Type> types = storage->get_all<Type>(
      sqlite_orm::where(sqlite_orm::eq(&Type::id_type, id_type)));

  return types.size() == 1;
}