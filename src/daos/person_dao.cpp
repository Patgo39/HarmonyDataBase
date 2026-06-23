#include "../../include/daos/person_dao.hpp"

PersonDao::PersonDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                  sqlite_orm::make_table("persons",
                     sqlite_orm::make_column("id_person", 
                        &Person::getIdPerson,
                        &Person::setIdPerson, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("stage_name",
                            &Person::getStageName,
                            &Person::setStageName),
                     sqlite_orm::make_column("real_name",
                            &Person::getRealName,
                            &Person::setRealName),
                     sqlite_orm::make_column("birth_date",
                            &Person::getBirthDate,
                            &Person::setBirthDate),
                     sqlite_orm::make_column("death_date",
                            &Person::getDeathDate,
                            &Person::setDeathDate)))
    )
{
    storage.sync_schema();
}

std::vector<Person> PersonDao::findAll() {
    std::vector persons = storage.get_all<Person>();
    return persons;
}

std::optional<Person> PersonDao::getByID(int id_person) {
    std::vector<Person> persons = storage.get_all<Person>(
                sqlite_orm::where(sqlite_orm::eq(&Person::getIdPerson, id_person)));

    std::optional<Person> person = std::nullopt;

    if(persons.size() == 1) {
        person = persons[0];
    }

    return person;
}
    
int PersonDao::save(Person person) {
    int id_person = storage.insert(person);
    return id_person;
}
    
void PersonDao::deleteById(int id_person) {
    if(!exists(id_person)) {
        throw IdNotFoundException("Error: Non-existent Person to delete.");
    }

    storage.remove<Person>(id_person);
}
    
void PersonDao::update(int id_person, Person person) {
    if(!exists(id_person)) {
        throw IdNotFoundException("Error: Non-existent Person to update.");
    }

    person.setIdPerson(id_person);
    storage.update(person);
}
    
bool PersonDao::exists(int id_person) {
    std::vector<Person> persons = storage.get_all<Person>(
    sqlite_orm::where(sqlite_orm::eq(&Person::getIdPerson, id_person)));
    
    return persons.size() == 1;
}