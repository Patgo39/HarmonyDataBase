#include "../../include/daos/performer_dao.hpp"

PerformerDao::PerformerDao(){
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::vector<Performer> PerformerDao::findAll() {
  std::vector performers = storage->get_all<Performer>();
  return performers;
}

std::optional<Performer> PerformerDao::getByID(int id_performer) {
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  std::optional<Performer> performer = std::nullopt;

  if (performers.size() == 1) {
    performer = performers[0];
  }

  return performer;
}

int PerformerDao::save(Performer performer) {
  int id_performer = storage->insert(performer);
  return id_performer;
}

void PerformerDao::deleteById(int id_performer) {
  if (!exists(id_performer)) {
    throw IdNotFoundException("Error: Non-existent Performer to delete.");
  }

  storage->remove<Performer>(id_performer);
}

void PerformerDao::update(int id_performer, Performer performer) {
  if (!exists(id_performer)) {
    throw IdNotFoundException("Error: Non-existent Performer to update.");
  }

  performer.setIdPerformer(id_performer);
  storage->update(performer);
}

bool PerformerDao::exists(int id_performer) {
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  return performers.size() == 1;
}