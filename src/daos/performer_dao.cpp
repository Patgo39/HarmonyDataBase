#include "../../include/daos/performer_dao.hpp"

PerformerDao::PerformerDao(){
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}


bool PerformerDao::existsPerson(int id_person){
  std::vector<Person> persons = storage->get_all<Person>(
      sqlite_orm::where(sqlite_orm::eq(&Person::getIdPerson, id_person)));

  return persons.size() == 1;
}
bool PerformerDao::existsGroup(int id_group){
  std::vector<Group> groups = storage->get_all<Group>(
      sqlite_orm::where(sqlite_orm::eq(&Group::getIdGroup, id_group)));

  return groups.size() == 1;
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

  if(existsPerson(id_performer)){
    throw ConstraintViolationException("Error: Action non valid. You must delete the register in"
      "Person table before deleting the performer.");
  }
  if(existsGroup(id_performer)){
    throw ConstraintViolationException("Error: Action non valid. You must delete the register in"
      "Group table before deleting the performer.");
  }

  storage->remove<Performer>(id_performer);
}

void PerformerDao::update(int id_performer, Performer performer) {
  if (!exists(id_performer)) {
    throw IdNotFoundException("Error: Non-existent Performer to update.");
  }

  if(existsPerson(id_performer) && performer.getIntType() != 1){
    throw ConstraintViolationException("Error: Action non valid. You must delete the register in"
      "Person's table before modifying performer's type value.");
  }
  if(existsGroup(id_performer) && performer.getIntType() != 2){
    throw ConstraintViolationException("Error: Action non valid. You must delete the register in"
      "Group's table before modifying performer's type value.");
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