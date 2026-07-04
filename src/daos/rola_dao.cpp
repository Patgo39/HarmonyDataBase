#include "../../include/daos/rola_dao.hpp"

RolaDao::RolaDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::vector<Rola> RolaDao::findAll() {
  std::vector rolas = storage->get_all<Rola>();
  return rolas;
}

std::optional<Rola> RolaDao::getByID(int id_rola) {
  std::vector<Rola> rolas = storage->get_all<Rola>(
      sqlite_orm::where(sqlite_orm::eq(&Rola::getIdRola, id_rola)));

  std::optional<Rola> rola = std::nullopt;

  if (rolas.size() == 1) {
    rola = rolas[0];
  }

  return rola;
}

int RolaDao::save(Rola rola) {
  int id_rola = storage->insert(rola);
  return id_rola;
}

void RolaDao::deleteById(int id_rola) {
  if (!exists(id_rola)) {
    throw IdNotFoundException("Error: Non-existent Rola to delete.");
  }

  storage->remove<Rola>(id_rola);
}

void RolaDao::update(int id_rola, Rola rola) {
  if (!exists(id_rola)) {
    throw IdNotFoundException("Error: Non-existent Rola to update.");
  }

  rola.setIdRola(id_rola);
  storage->update(rola);
}

bool RolaDao::exists(int id_rola) {
  std::vector<Rola> rolas = storage->get_all<Rola>(
      sqlite_orm::where(sqlite_orm::eq(&Rola::getIdRola, id_rola)));

  return rolas.size() == 1;
}