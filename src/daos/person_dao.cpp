#include "../../include/daos/person_dao.hpp"

PersonDao::PersonDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}


std::optional<Performer> PersonDao::getPerformerByID(int id_performer){
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  std::optional<Performer> performer = std::nullopt;

  if (performers.size() == 1) {
    performer = performers[0];
  }

  return performer;
}

bool PersonDao::existsPerformer(int id_performer){
  std::vector<Performer> performers =
      storage->get_all<Performer>(sqlite_orm::where(
          sqlite_orm::eq(&Performer::getIdPerformer, id_performer)));

  return performers.size() == 1;
}


std::vector<Person> PersonDao::findAll() {
  std::vector persons = storage->get_all<Person>();
  return persons;
}

std::optional<Person> PersonDao::getByID(int id_person) {
  std::vector<Person> persons = storage->get_all<Person>(
      sqlite_orm::where(sqlite_orm::eq(&Person::getIdPerson, id_person)));

  std::optional<Person> person = std::nullopt;

  if (persons.size() == 1) {
    person = persons[0];
  }

  return person;
}

int PersonDao::save(Person person) {
  int id = person.getIdPerson();
  if(!existsPerformer(id)){
    throw IdNotFoundException("The id for a person must be a valid id in performers table.");
  }

  if(exists(person.getIdPerson())){
    std::string msg = std::format("There is an existing person with id = {}", person.getIdPerson());
    throw PrimaryKeyViolationException(msg);
  }

  std::optional<Performer> p = getPerformerByID(id);
  if(p.value().getIntType() != 1){
    std::string message = std::format("You must set performer type = 1 in register {}" 
      "before creating a new register in the Person table.", id);
    throw ConstraintViolationException(message);
  }

  int id_person = storage->insert(person);
  return id_person;
}

void PersonDao::deleteById(int id_person) {
  if (!exists(id_person)) {
    throw IdNotFoundException("Error: Non-existent Person to delete.");
  }

  storage->remove<Person>(id_person);
}

void PersonDao::update(int id_person, Person person) {
  if (!exists(id_person)) {
    throw IdNotFoundException("Error: Non-existent Person to update.");
  }

  person.setIdPerson(id_person);
  storage->update(person);
}

bool PersonDao::exists(int id_person) {
  std::vector<Person> persons = storage->get_all<Person>(
      sqlite_orm::where(sqlite_orm::eq(&Person::getIdPerson, id_person)));

  return persons.size() == 1;
}